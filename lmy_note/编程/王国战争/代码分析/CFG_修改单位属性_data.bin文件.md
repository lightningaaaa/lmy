# data.bin的结构
1、 data.bin文件的第6个四字节是总大小值，fseek到头部24字节+此大小，然后从尾部读取数据
1.1、直接修改bin文件后，发生SIGBUS
wml_config_from_file
    

2、
[cfg]   //5字节
4字节    //低2字节是len，高2字节deep
namebuf  //len长度
[val]    //5字节
while(非[cfg]字符)
{
    len     //4字节，是 namebuf 的len
    namebuf //len长度
    value   //4字节，高16bit的高8bit是 transcnt，高16bit的低8bit是 tdidx
    len     //4字节，是valbuf的len
    valbuf  //				 
}

2.1、 transcnt 非0值的情况
while(非[cfg]字符)
{
    len     //4字节，是 namebuf 的len
    namebuf //len长度
    value   //4字节，高16bit的高8bit是 transcnt ，高16bit的低8bit是 tdidx
    len     //4字节，是valbuf的len
    valbuf  //				 
}

2、
# 代码解析
game_instance::load_game_cfg(const bool force)//game.cpp:1214
# 读取.bin文件内容
    wml_config_from_file(game_config::path + "/xwml/" + BASENAME_DATA, game_config_);//game.cpp:1243
    {==wml_config_from_file //xwml.cpp:373
        tfopen_lock lock(fname, GENERIC_READ, OPEN_EXISTING);//xwml.cpp:385
# 第6个四字节是总大小值
        posix_fread(lock.fp, &data_len, sizeof(data_len), bytertd);//xwml.cpp:414
# fseek到头部24字节+此大小，然后从尾部读取数据
        posix_fseek(lock.fp, header_len + data_len, 0);//xwml.cpp:417
# 详细解析内容 wml_config_from_data
        wml_config_from_data((uint8_t*)lock.data, data_len, namebuf, valbuf, tdomain, cfg);//xwml.cpp:439
        {==wml_config_from_data//xwml.cpp:266
            while (rdpos < data + datalen)
# "[cfg]"
                if (memcmp(rdpos, WMLBIN_MARK_CONFIG, WMLBIN_MARK_CONFIG_LEN))
			        return false;
                rdpos = rdpos + WMLBIN_MARK_CONFIG_LEN;//5
# "[val]"
                if (!memcmp(rdpos, "[val]", 5)) //xwml.cpp:307
# 非"[cfg]" 才会进入while
                    while ((rdpos < data + datalen) && memcmp(rdpos, "[cfg]", 5))//xwml.cpp:311
# transcnt
                        if (transcnt)
                            if (tdidx)//xwml.cpp:334
                                cfgtmp[std::string((char *)namebuf)] = t_string((const char *)valbuf, tdomain[tdidx - 1]);
                            else
                                cfgtmp[std::string((char *)namebuf)] = t_string((const char *)valbuf);
                        else
                            cfgtmp[std::string((char *)namebuf)] = t_string((const char *)valbuf);
        }
    }
    cards_.map_from_cfg(game_config_);//game.cpp:1245
    void game_instance::set_unit_data(config& gc)
    {
    # 显示 开始界面“Reading unit files”
        loadscreen::start_stage("load unit types");
        unit_types.set_config(gc);
    }


3、transcnt和tdidx作用,和翻译有关吗？
3.1、
book.cfg
[window]
	description=_"Book dialog."
	id="book"
	[resolution]
        automatic_placement=no
		definition="screen"

3.2、wml_config_from_data 查看bin文件内容
(gdb) x/20s rdpos-55
0x7fffb257e231:	"[cfg]\006"
0x7fffb257e238:	"\001"   //deep是1
0x7fffb257e23a:	"window[val]\v"
0x7fffb257e247:	""
0x7fffb257e248:	""
0x7fffb257e249:	"description"
0x7fffb257e255:	""
0x7fffb257e256:	"\001\001\f"
0x7fffb257e25a:	""
0x7fffb257e25b:	""
0x7fffb257e25c:	"Book dialog.\002"
0x7fffb257e26a:	""
0x7fffb257e26b:	""
0x7fffb257e26c:	"id"
0x7fffb257e26f:	""
0x7fffb257e270:	""
0x7fffb257e271:	""
0x7fffb257e272:	"\004"
0x7fffb257e274:	""
0x7fffb257e275:	""
0x7fffb257e276:	"book[cfg]\n"
0x7fffb257e281:	"\002" //deep是2
0x7fffb257e283:	"resolution[val]\023"
0x7fffb257e294:	""
0x7fffb257e295:	""
0x7fffb257e296:	"automatic_placement"
0x7fffb257e2aa:	""
0x7fffb257e2ab:	""
0x7fffb257e2ac:	""
0x7fffb257e2ad:	"\002"

(gdb) p tdomain
$10 = std::vector of length 3, capacity 4 = {"rose-lib", "kingdom-lib", "wesnoth-hero"}

3.3、transcnt大于1的情况
(gdb) x/30s rdpos-40
0x7fffb264d8a7:	"label"
0x7fffb264d8ad:	""
0x7fffb264d8ae:	"\002\004\033"
0x7fffb264d8b2:	""
0x7fffb264d8b3:	""
0x7fffb264d8b4:	"Get one card every 25 turns"
0x7fffb264d8d0:	""
0x7fffb264d8d1:	"\002"
0x7fffb264d8d3:	"\001"
0x7fffb264d8d5:	""
0x7fffb264d8d6:	""
0x7fffb264d8d7:	"("
0x7fffb264d8d9:	""
0x7fffb264d8da:	"\002"
0x7fffb264d8dc:	"\r"
0x7fffb264d8de:	""
0x7fffb264d8df:	""
0x7fffb264d8e0:	"VIP exclusive"
0x7fffb264d8ee:	""
0x7fffb264d8ef:	"\002"
0x7fffb264d8f1:	"\001"
0x7fffb264d8f3:	""
0x7fffb264d8f4:	""
0x7fffb264d8f5:	")[cfg]\003"
0x7fffb264d8fd:	"\v"
0x7fffb264d8ff:	"row[cfg]\006"
0x7fffb264d909:	"\f"
0x7fffb264d90b:	"column[cfg]\006"
0x7fffb264d918:	"\r"
0x7fffb264d91a:	"spacer[val]\n"
(gdb) x/30s rdpos
0x7fffb264d8cf:	""
0x7fffb264d8d0:	""
0x7fffb264d8d1:	"\002"
0x7fffb264d8d3:	"\001"
0x7fffb264d8d5:	""
0x7fffb264d8d6:	""
0x7fffb264d8d7:	"("
0x7fffb264d8d9:	""
0x7fffb264d8da:	"\002"
0x7fffb264d8dc:	"\r"
0x7fffb264d8de:	""
0x7fffb264d8df:	""
0x7fffb264d8e0:	"VIP exclusive"
0x7fffb264d8ee:	""
0x7fffb264d8ef:	"\002"
0x7fffb264d8f1:	"\001"
0x7fffb264d8f3:	""
0x7fffb264d8f4:	""
0x7fffb264d8f5:	")[cfg]\003"
0x7fffb264d8fd:	"\v"
0x7fffb264d8ff:	"row[cfg]\006"
0x7fffb264d909:	"\f"
0x7fffb264d90b:	"column[cfg]\006"
0x7fffb264d918:	"\r"
0x7fffb264d91a:	"spacer[val]\n"
0x7fffb264d927:	""
0x7fffb264d928:	""
0x7fffb264d929:	"definition"
0x7fffb264d934:	""
0x7fffb264d935:	""
(gdb) 



kingdom-src\kingdom\projectfiles\VC\data\gui\app-kingdom\window\preferences.cfg
            [toggle_button]
				id = "card_button"
				definition = "default"
				
				label = _ "Get one card every 25 turns" + "(" + _ "VIP exclusive" + ")"
			[/toggle_button]

# deep作用
deep = 1 标签不缩进，内容缩进1
deep = 2 标签缩进1，内容缩进2

2、
A：为什么“scenrios”、“maps”目录名要改为“mscenarios”、“mmaps”？
Q：是为了SLG Maker。SLG Maker在查data.bin是否是最新时，加提高data.bin确实应该重编译命中率，会设置为忽略“scenrios”、“maps”（要忽略掉战役）。但此处的“scenrios”、“maps”是不能忽略的，所以改名。

SLG Maker是 editor.exe 
