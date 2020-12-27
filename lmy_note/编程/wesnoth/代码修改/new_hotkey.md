1、
// src\hotkey\hotkey_handler.cpp
bool play_controller::hotkey_handler::can_execute_command(const hotkey::hotkey_command& cmd, int index) const
	case hotkey::HOTKEY_UNIT_DESCRIPTION:
		return menu_handler_.current_unit().valid();
	case hotkey::HOTKEY_CITY_EXPEDITE:
		return menu_handler_.current_unit().valid() && menu_handler_.current_unit()->is_city(); //只新增is_city有问题，非单位类型--右键--奔溃
	case hotkey::HOTKEY_CITY_RECRUIT1:
		return menu_handler_.current_unit().valid() && menu_handler_.current_unit()->is_city();

2、
src\hotkey\hotkey_command.cpp
std::array<hotkey_command_temp, HOTKEY_NULL - 1> master_hotkey_list {{
	{ HOTKEY_UNIT_DESCRIPTION, "describeunit", N_("Unit Description"), false, scope_game | scope_editor, HKCAT_UNITS, "" },
	{ HOTKEY_CITY_EXPEDITE, "expedite", N_("City Expedite"), false, scope_game | scope_editor, HKCAT_UNITS, "" },  //仿照 HOTKEY_UNIT_DESCRIPTION定义
	{ HOTKEY_CITY_RECRUIT1, "recruit1", N_("City recruit1"), false, scope_game | scope_editor, HKCAT_UNITS, "" },