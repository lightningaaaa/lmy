1、
src\wesnoth.cpp
int main(int argc, char** argv)
    启动图形化界面前的打印
    "Automatically found a possible data directory at "
    const int res = do_gameloop(args); //程序主循环？

2、游戏主循环
do_gameloop
    const std::unique_ptr<game_launcher> game(new game_launcher(cmdline_opts, args[0].c_str()));
    res = game->init_video();
        video().init_window();
            “Setting mode to”打印
    for(;;)
        handle_lua_script_args
            bool game_launcher::init_lua_script()
            “Checking lua scripts... ok”打印
        //campaign
        if(game->goto_campaign() == false)
        
        //multiplayer
        if(game->goto_multiplayer() == false)
            if(jump_to_multiplayer_)
		        if(play_multiplayer(MP_CONNECT)) //multiplayer的主处理
                    try {
                        if(res == MP_LOCAL) {
                            //本地游戏
                            mp::start_local_game(game_config_manager::get()->game_config(), state_);
                        } else {
                            mp::start_client(game_config_manager::get()->game_config(),state_,multiplayer_server_);
                            multiplayer_server_.clear();
                        }
                    } catch () {

                    }
