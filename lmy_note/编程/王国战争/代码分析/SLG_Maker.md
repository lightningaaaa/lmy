1、
在bin文件上右键--Explorer---WML format
1、奔溃时调用栈
>	editor.exe!config::check_valid() 行 278	C++
 	editor.exe!config::child_range(const std::basic_string<char,std::char_traits<char>,std::allocator<char> > & key) 行 419	C++
 	editor.exe!tcore::init_cache() 行 1073	C++
 	editor.exe!tcore::switch_section(HWND__ * hdlgP, int to, bool init) 行 1674	C++
 	editor.exe!core_enter_ui() 行 2196	C++
 	editor.exe!title_select(do_action_t da) 行 250	C++
 	editor.exe!On_DlgDDescNotify(HWND__ * hdlgP, int DlgItem, tagNMHDR * lpNMHdr) 行 615	C++
 	editor.exe!DlgDDescProc(HWND__ * hdlgP, unsigned int uMsg, unsigned int wParam, long lParam) 行 687	C++


2、
void update_locale_dir()//
	wml_config_from_file(game_config::path + "/xwml/data.bin", editor_config::data_cfg);//kingdom-src\kingdom\kingdom\editor2\main.cpp:1342


3、
WinMain(HINSTANCE inst, HINSTANCE, LPSTR lpCmdLine, int nCmdShow)
    wml_config_from_file(game_config::path + "/xwml/data.bin", editor_config::data_cfg);//main.cpp:1467
