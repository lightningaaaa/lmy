1、
do_gameloop(const std::vector<std::string>& args)
    res = config_manager.init_game_config(game_config_manager::NO_FORCE_RELOAD);//wesnoth.cpp:698

game_config_manager::load_game_config
{
    cache_.get_config(filesystem::get_wml_location(wml_tree_root), game_config_);//game_config_manager.cpp:263
    {
	    load_configs(file_path, cfg);
        {
            if (use_cache_)
                read_cache(config_path, cfg);
                {
                    const std::string fname = cache_path + "/" +
								  cache_file_prefix_ +
								  utils::sha1(defines_string.str()).hex_digest();//config_cache.cpp:180
# gdb信息
//(gdb) p fname
$15 = "/home/kooper/.cache/wesnoth/cache-v1.14.9 (102474e5-Modified)-de117b6a225ff7da2a992a2da2cedaa2de5c2662"

                }
            else
                preproc_map copy_map(make_copy_map());
                read_configs(config_path, cfg, copy_map);
                add_defines_map_diff(copy_map);
        }
    }
    game_config_manager::set_unit_data
    {
        game_config_.merge_children("units");
        gui2::dialogs::loading_screen::progress(loading_stage::load_unit_types);
        if(config &units = game_config_.child("units"))
            unit_types.set_config(units);
    }
}


2、
#: src/gui/dialogs/loading_screen.cpp:61
msgid "Reading unit files"
msgstr "正在读取单位文件"

std::map<loading_stage, std::string> stage_names
	{ loading_stage::load_unit_types,     N_("Reading unit files") },

3、gdb
b game_config_manager.cpp:161