1、
出征分两种情况：AI出征、玩家出征。
不论是AI还是玩家，成功时都由unit_map::move处理。
AI出征失败由actions.cpp中的move_unit中expedite_release处理。
玩家出征失败（玩家主动取消）由mouse_events.cpp中处理（expediting_）。

2、unit_map //其中包含出征
http://www.freeors.com/bbs/forum.php?mod=viewthread&tid=20344&extra=page%3D4
出征
unit_map中处理出征是两个函数：set_recalling和move

被调用流程

一、上层调用unit_map::set_recalling(...)，通知unit_map系统进入出征状态
二、这个视玩家操作分一样处理；
2.1.1：玩家移动了出征单位，这时move被调用；
2.1.2：unit_map::move返回后，上层会调用一次set_recalling，通知unit_map出征状态结束；
2.2：玩家以鼠标右键选中某个格子，取消出征，这时set_recalling(...)被调用；

如何处理一个格子上两个单位

出征状态时，出征格子上将有两个单位：本来的都市和要出征武将。

unit_map是在set_recalling（进入出征态态）时用出征武将替换掉地图cookie及容器中node*值，这样接下调用find或是迭代单位返回的都将是出征武将；

move结束，unit_map在地图都市格子处留下原先都市cookie及容器中插入都市（为什么不是替换？原来位置是放置出征单位，已有效了，没必要替换）。set_recalling取消时，unit_map替换回都市格子处cookie及替换回容器中node*。

3、王国战争的处理
王国战争中出征的关键字Expedite
menu_handler::expedite

4、王国战争的出征处理？
menu_handler::expedite(int side_num, const map_location &last_hex)
    mouse_handler::set_expedite(artifical* expedite_city, unit& u)
        gui().place_expedite_city(*expedite_city);

4、debug模式创建单位
bool command_executor::run_queued_commands()
	std::vector<queued_command> commands = filter_command_queue();
        for(const queued_command& cmd : command_queue_) {  //遍历 command_queue_ 变量
        }
    ......
    hotkey::command_executor::execute_command_wrap
        hotkey_handler::do_execute_command
            command_executor::do_execute_command
                switch(cmd.id)
                case HOTKEY_ENDTURN: //结束回合
                    end_turn();
                    break;
                case HOTKEY_TERRAIN_DESCRIPTION://地形描述
                    terrain_description();
                    break;
                case HOTKEY_UNIT_DESCRIPTION://单位描述
                    unit_description();
                    play_controller::hotkey_handler::unit_description // at /src/hotkey/hotkey_handler.cpp:190
                        menu_handler_.unit_description();
                            const unit_map::const_iterator un = current_unit(); //获取当前unit
                                unit_map::iterator res = board().find_visible_unit(mousehandler.get_last_hex(), teams()[gui_->viewing_team()], see_all);
                            if(un != units().end()) {
                                help::show_unit_description(*un);  //显示单位对应的介绍
                            }
                    break;
                case HOTKEY_CITY_EXPEDITE: //新建出征 ---- 新增
                    expedite();
			        break;
                case HOTKEY_RENAME_UNIT://重命名单位
                    rename_unit();
                    break;
                case HOTKEY_LABEL_TERRAIN: //设置标签
                    label_terrain(false);
                    break;
                case HOTKEY_CLEAR_LABELS: //清除标签
                    clear_labels();
                    break;
                case HOTKEY_CREATE_UNIT:  //dbg创建单位
                    create_unit();
                        menu_handler::create_unit(mouse_handler& mousehandler)
                    break;
                case HOTKEY_DESELECT_HEX: //在地图上点击 右键
                    deselect_hex(); //play_controller::hotkey_handler::deselect_hex at /src/hotkey/hotkey_handler.cpp:135
                        mouse_handler_.deselect_hex();
                            select_hex(map_location(), true);  //at mouse_events.cpp:1034
                                if(selected_hex_.valid() && unit.valid() && !unit->get_hidden())
                case HOTKEY_SELECT_AND_ACTION: //左键选中单位
                    select_and_action();
                    break;


event存入，变量成员std::vector<queued_command> command_queue_;
void command_executor::queue_command(const SDL_Event& event, int index)
    const hotkey_command& command = hotkey::get_hotkey_command(hk->get_command());
    command_queue_.emplace_back(command, index, press, release);  //存入 command_queue_ 变量

貌似是事件数组
std::array<hotkey_command_temp, HOTKEY_NULL - 1> master_hotkey_list {{

调用栈
(gdb) bt
#0  0x0000555555ff86a1 in events::menu_handler::create_unit(events::mouse_handler&) (this=0x7fffffffbe88, mousehandler=...)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/menu_events.cpp:732
#1  0x000055555624aba7 in playsingle_controller::hotkey_handler::create_unit() (this=0x555557f58f30)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/hotkey/hotkey_handler_sp.cpp:83
#2  0x0000555556494983 in hotkey::command_executor::do_execute_command(hotkey::hotkey_command const&, int, bool, bool)
    (this=0x555557f58f30, cmd=..., press=true, release=false)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/hotkey/command_executor.cpp:194
#3  0x0000555556247513 in play_controller::hotkey_handler::do_execute_command(hotkey::hotkey_command const&, int, bool, bool)
    (this=0x555557f58f30, cmd=..., index=-1, press=true, release=false)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/hotkey/hotkey_handler.cpp:267
#4  hotkey::command_executor::execute_command_wrap
    at /src/hotkey/command_executor.cpp:614
#5  hotkey::command_executor::run_queued_commands()
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/hotkey/command_executor.cpp:692
#6  hotkey::run_events(hotkey::command_executor*)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/hotkey/command_executor.cpp:570
#7  controller_base::process(events::pump_info&) (this=0x7fffffffbc30)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/controller_base.cpp:254
#8  0x000055555646691b in events::pump() () at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/events.cpp:753
#9  0x0000555555d3a403 in controller_base::play_slice(bool) (this=0x7fffffffbc30, is_delay_enabled=true)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/controller_base.cpp:358
#10 0x000055555604b191 in playmp_controller::play_slice(bool) (this=0x7fffffffbc30, is_delay_enabled=true)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/playmp_controller.cpp:457
#11 0x0000555556043548 in play_controller::play_slice_catch() (this=0x7fffffffbc30)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/play_controller.cpp:1070
#12 0x0000555556049681 in playmp_controller::play_human_turn() (this=0x7fffffffbc30)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/playmp_controller.cpp:143
#13 0x000055555604fb8d in playsingle_controller::play_side_impl() (this=0x7fffffffbc30)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/playsingle_controller.cpp:391
#14 0x0000555556043c70 in play_controller::play_side() (this=0x7fffffffbc30)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/play_controller.cpp:1161
#15 0x0000555556043fc4 in play_controller::play_turn() (this=0x7fffffffbc30)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/play_controller.cpp:1202
#16 0x000055555604e13e in playsingle_controller::play_scenario_main_loop() (this=0x7fffffffbc30)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/playsingle_controller.cpp:174
#17 0x000055555604ea65 in playsingle_controller::play_scenario(config const&) (this=0x7fffffffbc30, level=...)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/playsingle_controller.cpp:271
#18 0x0000555555e92de2 in campaign_controller::playmp_scenario(end_level_data&) (this=0x7fffffffc5d0, end_level=...)


5、尝试增加快捷键 -- 出征
（5.1）
data\core\hotkeys.cfg
[hotkey]
    command=expedite
    key=a
    alt=yes
[/hotkey]

（5.2）增加宏值
src\hotkey\hotkey_command.hpp
HOTKEY_CITY_EXPEDITE,

（5.3）按键是否有效的判断
play_controller::hotkey_handler::can_execute_command
    case hotkey::HOTKEY_CITY_EXPEDITE:
		return menu_handler_.current_unit()->is_city();