1、wesnoth中的处理
hotkey::command_executor::do_execute_command // command_executor.cpp文件
    case HOTKEY_CITY_RECRUIT1:
		recruit1();
			playsingle_controller::hotkey_handler::recruit1
				menu_handler::recruit1 //menu_events.cpp 文件
		break;



2、在王国战争中
http://www.freeors.com/bbs/forum.php?mod=viewthread&tid=16603&extra=page%3D4  //招募流程
玩家招募
一、玩家按下“招募”菜单/按钮，程序执行menu_handler::recruit；
二、menu_handler::recruit擦除旧菜单，显示招募对话框，gui::dialog rmenu；
三、玩家选中一个兵种，确认。程序执行menu_handler::do_recruit；
四、do_recruit执行（这个过程类似AI招募中的recruit_result::do_execute()）：
1）向游戏录像添加一事件；recorder.add_recruit(num_, recruit_location_)
2）构造一个unit_name兵种对像；
3）修改本阵营剩余金；
4）新招募武将放入可召回列表。

playsingle_controller::recruit()
	play_controller::do_recruit //play_controller.cpp
