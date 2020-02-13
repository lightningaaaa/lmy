1、wesnoth中的处理
hotkey::command_executor::do_execute_command // command_executor.cpp文件
    case HOTKEY_CITY_RECRUIT1:
		recruit1();
			playsingle_controller::hotkey_handler::recruit1
				menu_handler::recruit1 //menu_events.cpp 文件
		break;



2、在王国战争中
playsingle_controller::recruit()
	play_controller::do_recruit //play_controller.cpp
