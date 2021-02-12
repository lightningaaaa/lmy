# data.bin的结构
1、
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

# transcnt 非0值的情况
while(非[cfg]字符)
{
    len     //4字节，是 namebuf 的len
    namebuf //len长度
    value   //4字节，高16bit的高8bit是 transcnt ，高16bit的低8bit是 tdidx
    len     //4字节，是valbuf的len
    valbuf  //				 
}

# data.bin文件的第6个四字节是总大小值，fseek到头部24字节+此大小，然后从尾部读取数据
2、直接修改bin文件后，发生SIGBUS
wml_config_from_file
# 第6个四字节是总大小值，fseek到头部24字节+此大小，然后从尾部读取数据
    posix_fread(lock.fp, &data_len, sizeof(data_len), bytertd);//xwml.cpp:414

Thread 1 "wesnoth" received signal SIGBUS, Bus error.
0x00007ffff7576037 in wml_config_from_file (
    fname="/mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/output_bin/../kingdom/projectfiles/VC/xwml/data.bin", cfg=..., 
    nfiles=0x0, sum_size=0x0, modified=0x0) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/xwml.cpp:424
424			tdname[len] = 0;
(gdb) bt
#0  0x00007ffff7576037 in wml_config_from_file (
    fname="/mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/output_bin/../kingdom/projectfiles/VC/xwml/data.bin", cfg=..., 
    nfiles=0x0, sum_size=0x0, modified=0x0) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/xwml.cpp:424
#1  0x0000555555bda2a4 in game_instance::load_game_cfg (this=0x55555639d1a0 <create_instance<game_instance>(int, char**)::game>, 
    force=false) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/game.cpp:1243
#2  0x00007ffff7352dfb in base_instance::init_config (this=0x55555639d1a0 <create_instance<game_instance>(int, char**)::game>, force=false)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/base_instance.cpp:348
#3  0x0000555555bd0c59 in game_instance::init_config (this=0x55555639d1a0 <create_instance<game_instance>(int, char**)::game>, force=false)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/game.cpp:368
#4  0x0000555555bdc893 in do_gameloop (argc=1, argv=0x7fffffffe218)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/game.cpp:1555
#5  0x0000555555bde031 in main (argc=1, argv=0x7fffffffe218)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/game.cpp:1841
(gdb) p tdname
$1 = "ype\000\000\000\000\a\000\000\000boolean\r\000\000\000\b\000\000\000rose-lib\020\000\000\000wesnoth-tk-units\v\000\000\000kingdo"
(gdb) p idx
$2 = 0
(gdb) p fname
$3 = "/mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/output_bin/../kingdom/projectfiles/VC/xwml/data.bin"
(gdb) 