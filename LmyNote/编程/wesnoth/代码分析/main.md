1、
src\wesnoth.cpp
int main(int argc, char** argv)
    启动图形化界面前的打印
    "Automatically found a possible data directory at "
    const int res = do_gameloop(args); //程序主循环？

2、游戏主循环
do_gameloop
    const std::unique_ptr<game_launcher> game(new game_launcher(cmdline_opts, args[0].c_str()));
    //https://blog.csdn.net/shaosunrise/article/details/85158249 C++ 智能指针 unique_ptr 详解与示例
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
        //loading
        if(game->is_loading())

        //初次到达主界面
        while(dlg.get_retval() == gui2::dialogs::title_screen::REDRAW_BACKGROUND) {
			dlg.show();
		}
        //点击本地游戏进入的case
        switch(dlg.get_retval())
        case gui2::dialogs::title_screen::MP_LOCAL:
			game_config::set_debug(game_config::mp_debug);
			if(!game->play_multiplayer(game_launcher::MP_LOCAL)) { //multiplayer处理
                ////
                if(res == MP_LOCAL) {
                    mp::start_local_game( //开始本地游戏
                        game_config_manager::get()->game_config(), state_);
                        enter_create_mode(workflow_helper); //开始游戏
                            dlg.show(); //进入选图界面，选图后，继续向后执行
                            if(dlg_ok)
                    		    enter_staging_mode(helper); //开始游戏
                                    dlg.show();//选择玩家等信息
                                    campaign_controller controller(helper->state, game_config_manager::get()->terrain_types());
                                    controller.set_mp_info(campaign_info.get());
                                    controller.play_game(); //开始游戏
                                        while(state_.valid()) //while循环执行
                                            playmp_scenario(end_level); //游戏进行
                                                LEVEL_RESULT res = playcontroller.play_scenario(state_.get_starting_point()); //游戏进行
                                                    play_scenario_main_loop();//场景main循环
                                                        play_controller::play_turn() //按回合进行游戏
                                                            while(gamestate_->player_number_ <= static_cast<int>(gamestate().board_.teams().size()))  //while 循环执行回合
                                                                play_side(); //执行一回合，点击完成后，退出此执行。
                                                                    gui_->parse_team_overlays(); //
                                                                    do {
                                                                        play_side_impl();//进行移动等操作，虚函数，单人
                                                                            if((current_team().is_local_human() && current_team().is_proxy_human())) //人类玩家的操作
                                                                                before_human_turn(); //人类turn前
                                                                                if (end_turn_ == END_TURN_NONE) {
                                                                                    playmp_controller::play_human_turn();//人类turn操作，有多个同名函数
                                                                                        while(!should_return_to_play_side()) {
                                                                                            process_network_data();
                                                                                            check_objectives();
                                                                                            play_slice_catch();
                                                                                                playmp_controller::play_slice
                                                                                                    playsingle_controller::play_slice
                                                                                                        controller_base::play_slice
                                                                                                            uint8_t mouse_flags = SDL_GetMouseState(&mousex, &mousey); //获取鼠标等处理
                                                                                        }
                                                                                }
                                                                                if ( !player_type_changed_ && !is_regular_game_end()) {
                                                                                    after_human_turn();//人类turn后
                                                                                }
                                                                    } while (player_type_changed_);
                } else {
                    mp::start_client(game_config_manager::get()->game_config(),
                        state_, multiplayer_server_);
                    multiplayer_server_.clear();
                }
                \///
				continue;
			}
			break;

3、移动
文件位置src\actions\move.cpp

unit_mover::do_move


4、调用栈-移动单位
(gdb) bt
#0  0x0000555555c234b2 in actions::(anonymous namespace)::unit_mover::do_move(actions::(anonymous namespace)::unit_mover::route_iterator const&, actions::(anonymous namespace)::unit_mover::route_iterator const&, unit_display::unit_mover&)
    (this=0x7fffffffa100, step_from={x = 166, y = 17}, step_to=
  {x = 165, y = 16}, animator=...)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/actions/move.cpp:513
#1  0x0000555555c25441 in actions::(anonymous namespace)::unit_mover::try_actual_movement(bool) (this=0x7fffffffa100, show=true)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/actions/move.cpp:989
#2  0x0000555555c26bda in actions::move_unit_internal(actions::undo_list*, bool, bool*, actions::(anonymous namespace)::unit_mover&)
    (undo_stack=0x7fffb84cfe80, show_move=true, interrupted=0x7fffffffa4ef, mover=...) at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/actions/move.cpp:1193
#3  0x0000555555c276e0 in actions::move_unit_and_record(std::vector<map_location, std::allocator<map_location> > const&, actions::undo_list*, bool, bool, bool*, actions::move_unit_spectator*)
    (steps=std::vector of length 6, capacity 6 = {...}, undo_stack=0x7fffb84cfe80, continued_move=true, show_move=true, interrupted=0x7fffffffa4ef, move_spectator=0x0) at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/actions/move.cpp:1279
#4  0x000055555601ef97 in events::mouse_handler::move_unit_along_route(std::vector<map_location, std::allocator<map_location> > const&, bool&)
    (this=0x7fffffffbd20, steps=std::vector of length 6, capacity 6 = {...}, interrupted=@0x7fffffffa4ef: false)
--Type <RET> for more, q to quit, c to continue without paging--
   mouse_events.cpp:1202
#5  0x000055555601ea89 in events::mouse_handler::move_unit_along_current_route() (this=0x7fffffffbd20)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/mouse_events.cpp:1147
#6  0x000055555601d74b in events::mouse_handler::move_action(bool) (this=0x7fffffffbd20, browse=false)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/mouse_events.cpp:1007
#7  0x000055555601c8a2 in events::mouse_handler::select_or_action(bool) (this=0x7fffffffbd20, browse=false)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/mouse_events.cpp:825
#8  0x0000555556245144 in play_controller::hotkey_handler::select_and_action() (this=0x5555591c6dc0)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/hotkey/hotkey_handler.cpp:122
#9  0x00005555564932b7 in hotkey::command_executor::do_execute_command(hotkey::hotkey_command const&, int, bool, bool)
    (this=0x5555591c6dc0, cmd=..., press=true, release=false) at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/hotkey/command_executor.cpp:332
#10 0x0000555556245bb7 in play_controller::hotkey_handler::do_execute_command(hotkey::hotkey_command const&, int, bool, bool)
    (this=0x5555591c6dc0, cmd=..., index=-1, press=true, release=false) at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/hotkey/hotkey_handler.cpp:267
#11 0x000055555649477a in hotkey::command_executor::execute_command_wrap(hotkey::command_executor::queued_command const&) (this=0x5555591c6dc0, command=...)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/hotkey/command_executor.cpp:614
#12 0x0000555556494ba4 in hotkey::command_executor::run_queued_commands() (this=0x5555591c6dc0)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/hotkey/command_executor.cpp:692
#13 0x0000555556494379 in hotkey::run_events(hotkey::command_executor*) (executor=0x5555591c6dc0)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/hotkey/command_executor.cpp:570
#14 0x00005555564942b4 in hotkey::mbutton_event(SDL_Event const&, hotkey::command_executor*) (event=..., executor=0x5555591c6dc0)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/hotkey/command_executor.cpp:542
#15 0x0000555555d39853 in controller_base::handle_event(SDL_Event const&) (this=0x7fffffffbbc0, event=...)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/controller_base.cpp:186
#16 0x0000555556464c1b in events::pump() () at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/events.cpp:746
#17 0x0000555555d3a223 in controller_base::play_slice(bool) (this=0x7fffffffbbc0, is_delay_enabled=true)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/controller_base.cpp:358


5、 召回和招募Recruiting, recalling
playsingle_controller::hotkey_handler::recruit //菜单中的recruit
    menu_handler::recruit
        actions::get_recruits //获取招募菜单
        if(dlg.show()) { //等待选择具体的单位
            map_location recruit_hex = last_hex;
            int index = dlg.get_selected_index();
            if (index < 0) {
                gui2::show_transient_message("", _("No unit recruited"));
                return;
            }
            do_recruit(sample_units[index]->id(), side_num, recruit_hex); //进行征招
                const unit_type* u_type = unit_types.find(name); //根据名字找到unit type
                msg = actions::find_recruit_location(side_num, loc, recruited_from, name);  //招募的位置是否在keep上
                    actions::check_recruit_location
                        const unit_map & units = resources::gameboard->units();   //获取所有的unit的信息，其中umap_是XX,lmap_是位置;
        }

调用栈
(gdb) bt
#0  0x0000555555c1c3c8 in actions::get_recruits[abi:cxx11](int, map_location const&) (side=1, recruit_loc=...)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/actions/create.cpp:60
#1  0x0000555555ff45cd in events::menu_handler::recruit(int, map_location const&) (this=0x7fffffffbe18, side_num=1, last_hex=...)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/menu_events.cpp:259
#2  0x0000555556248f80 in playsingle_controller::hotkey_handler::recruit()
    (this=0x5555591c6dc0)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/hotkey/hotkey_handler_sp.cpp:47
#3  0x0000555556492cc7 in hotkey::command_executor::do_execute_command(hotkey::hotkey_command const&, int, bool, bool)
    (this=0x5555591c6dc0, cmd=..., press=true, release=false)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/hotkey/command_executor.cpp:182
#4  0x0000555556245bb7 in play_controller::hotkey_handler::do_execute_command(hotkey::hotkey_command const&, int, bool, bool)
    (this=0x5555591c6dc0, cmd=..., index=3, press=true, release=false)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/hotkey/hotkey_handler.cpp:267
#5  0x00005555564938be in hotkey::command_executor::show_menu(std::vector<config, std::allocator<config> > const&, int, int, bool, display&)
--Type <RET> for more, q to quit, c to continue without paging--
, xloc=101, yloc=24, gui=...) at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/hotkey/command_executor.cpp:423
#6  0x0000555556246d13 in play_controller::hotkey_handler::show_menu(std::vector<config, std::allocator<config> > const&, int, int, bool, display&)
    (this=0x5555591c6dc0, items_arg=std::vector of length 9, capacity 16 = {...}, xloc=101, yloc=24, context_menu=false, disp=...)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/hotkey/hotkey_handler.cpp:479
#7  0x0000555555d3a9b4 in controller_base::show_menu(std::vector<config, std::allocator<config> > const&, int, int, bool, display&)
    (this=0x7fffffffbbc0, items_arg=std::vector of length 16, capacity 16 = {...}, xloc=101, yloc=24, context_menu=false, disp=...)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/controller_base.cpp:462
#8  0x0000555555d3a37d in controller_base::play_slice(bool) (this=0x7fffffffbbc0, is_delay_enabled=true)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/controller_base.cpp:370


6\unit_map信息
（1）
const unit_map & units = resources::gameboard->units();
namespace resources
{
	game_board           *gameboard = nullptr;
	play_controller      *controller = nullptr;
	game_data            *gamedata = nullptr;
	filter_context	     *filter_con = nullptr;
	game_events::manager *game_events = nullptr;
	game_lua_kernel            *lua_kernel = nullptr;
	persist_manager      *persist = nullptr;
	soundsource::manager *soundsources = nullptr;
	replay               *recorder = nullptr;
	::tod_manager        *tod_manager = nullptr;
	fake_unit_manager    *fake_units = nullptr;
	pathfind::manager    *tunnels = nullptr;
	actions::undo_list   *undo_stack = nullptr;
	std::shared_ptr<wb::manager> whiteboard = std::shared_ptr<wb::manager>();
	game_classification  *classification = nullptr;
	bool                 simulation_ = false;
}

class game_board : public display_context
{
    unit_map units_;
    unit_map& units()
	{
		return units_;
	}
}

（2）
文件路径：src\editor\map\map_context.cpp
void map_context::load_scenario(const config& game_config) //在加载战役和自定义地图时调用不到
    for(config& a_unit : side.child_range("unit")) {
        a_unit["side"] = i;
        units_.insert(unit::create(a_unit, true));
        	mutable umap umap_;//改变umap_
        	lmap lmap_;        //改变umap_
    }

（3）
team_builder::place_units
    unit_creator::add_unit //加载自定义地图时会调用到，其他未知

调用栈
(gdb) bt
#0  0x00005555560b31c9 in unit_creator::add_unit(config const&, vconfig const*)
    (this=0x7fffe922b570, cfg=..., vcfg=0x0)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/actions/unit_creator.cpp:173
#1  0x0000555556080840 in team_builder::place_units() (this=0x7fffbb35a5b0)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/teambuilder.cpp:287
#2  0x000055555607f5d6 in team_builder::build_team_stage_two()
    (this=0x7fffbb35a5b0)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/teambuilder.cpp:88
#3  0x000055555607f2b9 in build_team_stage_two(std::shared_ptr<team_builder>)
    (tb_ptr=std::shared_ptr<team_builder> (use count 3, weak count 0) = {...})
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/teambuilder.cpp:311
#4  0x0000555555e98fc2 in game_state::init(config const&, play_controller&)
    (this=0x7fffbb4af7a0, level=..., pc=...)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/game_state.cpp:220
#5  0x000055555603cbb4 in play_controller::<lambda()>::operator()(void) const
    (__closure=0x7fffffffb6c8)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/play_controller.cpp:220
#6  0x0000555556045109 in std::_Function_handler<void(), play_controller::init(const config&)::<lambda()> >::_M_invoke(const std::_Any_data &) (__functor=...)
    at /usr/include/c++/8/bits/std_function.h:297
#7  0x00005555558fd012 in std::function<void ()>::operator()() const
    (this=0x7fffffffb6c8) at /usr/include/c++/8/bits/std_function.h:687
#8  0x00005555558f8dff in gui2::dialogs::loading_screen::<lambda()>::operator()(--Type <RET> for more, q to quit, c to continue without paging--
void) const (__closure=0x55555dee0678)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/gui/dialogs/loading_screen.cpp:116
#9  0x00005555558fa616 in boost::detail::thread_data<gui2::dialogs::loading_screen::pre_show(gui2::window&)::<lambda()> >::run(void) (this=0x55555dee0540)
    at /usr/include/boost/thread/detail/thread.hpp:117
#10 0x00007ffff59c6f65 in  ()
    at /lib/x86_64-linux-gnu/libboost_thread.so.1.67.0
#11 0x00007ffff7e54fa3 in start_thread (arg=<optimized out>)
    at pthread_create.c:486
#12 0x00007ffff49714cf in clone ()
    at ../sysdeps/unix/sysv/linux/x86_64/clone.S:95
