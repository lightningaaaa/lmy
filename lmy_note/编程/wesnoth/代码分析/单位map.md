1、获取unit_map的接口
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

    unit_map::iterator find_unit(const map_location & loc) { return units_.find(loc); } //根据位置找单位？不知道哪个流程调用
}
2、unit_map::add
如下接口在读取地图和debug增加单位时不会被调用。unit_map::add

2、
文件路径：src\editor\map\map_context.cpp
void map_context::load_scenario(const config& game_config) //在加载战役和自定义地图时调用不到
    for(config& a_unit : side.child_range("unit")) {
        a_unit["side"] = i;
        units_.insert(unit::create(a_unit, true));
        	mutable umap umap_;//改变umap_
        	lmap lmap_;        //改变umap_
    }

3、创建unit，unit_creator::add_unit 调用
game_state::init
    team_builder::build_team_stage_one() //创建单位，阶段1，准备
        //initialize the context variables and flags, find relevant tags, set up everything
        init();
        //find out the correct qty of gold and handle gold carryover.
        gold();
        //create a new instance of team and push it to back of resources::gameboard->teams() vector
        new_team();
        //set team objectives if necessary
        objectives();
        // If the game state specifies additional units that can be recruited by the player, add them.
        previous_recruits();
        //place leader
        leader();
        //prepare units, populate obvious recall lists elements
        prepare_units();
            for (const config &su : side_cfg_.child_range("unit"))  //side的子目录中的unit
                team_builder::handle_unit
                    unit_configs_.push_back(&u);                    //unit_configs_信息填充
        build_team_stage_two    //创建单位，阶段二
            team_builder::build_team_stage_two
                team_builder::place_units
                    for (const config *u : unit_configs_)  //unit_configs_ 中存了所有unit信息？后面分析unit_configs_信息填充
                        unit_creator::add_unit             //创建unit，unit_creator.cpp 文件
                            if ( !recall_list_element ) {
                                unit_ptr new_unit = unit::create(temp_cfg, true, vcfg);
                                    unit::init              //通过cfg获取了单位的详细信息，填充单位信息
                                map_location loc = find_location(temp_cfg, new_unit.get()); //获取位置
                                if ( loc.valid() ) {
                                    //add the new unit to map
                                    board_->units().replace(loc, new_unit); //加入unit_map
                                        self_check();
                                        p->set_location(l);
                                        erase(l);
                                        return insert(p);                   //插入unit
                                }
                            }

（3.2）读取地图新建单位调用栈，创建单位和加入unit_map函数unit_map::insert
(gdb) bt
#0  0x0000555555b649d3 in unit_map::insert(boost::intrusive_ptr<unit>)
    (this=0x7fffda0b3278, p=...)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/units/map.cpp:141
#1  0x0000555555b655f4 in unit_map::replace(map_location const&, boost::intrusive_ptr<unit>) (this=0x7fffda0b3278, l=..., p=...)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/units/map.cpp:230
#2  0x00005555560b3511 in unit_creator::add_unit(config const&, vconfig const*)
    (this=0x7fffe92ab570, cfg=..., vcfg=0x0)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/actions/unit_creator.cpp:189
#3  0x000055555608095e in team_builder::place_units() (this=0x7fffda2e41d0)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/teambuilder.cpp:287
#4  0x000055555607f6f4 in team_builder::build_team_stage_two()
    (this=0x7fffda2e41d0)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/teambuilder.cpp:88
#5  0x000055555607f3d7 in build_team_stage_two(std::shared_ptr<team_builder>)
    (tb_ptr=std::shared_ptr<team_builder> (use count 3, weak count 0) = {...})
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/teambuilder.cpp:311
#6  0x0000555555e990e0 in game_state::init(config const&, play_controller&)
    (this=0x7fffda0b1d50, level=..., pc=...)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/game_state.cpp:220
#7  0x000055555603ccd2 in play_controller::<lambda()>::operator()(void) const
    (__closure=0x7fffffffb728)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/play_controller.cpp:220
--Type <RET> for more, q to quit, c to continue without paging--c
#8  0x0000555556045227 in std::_Function_handler<void(), play_controller::init(const config&)::<lambda()> >::_M_invoke(const std::_Any_data &) (__functor=...) at /usr/include/c++/8/bits/std_function.h:297
#9  0x00005555558fd012 in std::function<void ()>::operator()() const (this=0x7fffffffb728) at /usr/include/c++/8/bits/std_function.h:687
#10 0x00005555558f8dff in gui2::dialogs::loading_screen::<lambda()>::operator()(void) const (__closure=0x5555591353e8) at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/gui/dialogs/loading_screen.cpp:116
#11 0x00005555558fa616 in boost::detail::thread_data<gui2::dialogs::loading_screen::pre_show(gui2::window&)::<lambda()> >::run(void) (this=0x5555591352b0) at /usr/include/boost/thread/detail/thread.hpp:117
#12 0x00007ffff59c6f65 in  () at /lib/x86_64-linux-gnu/libboost_thread.so.1.67.0
#13 0x00007ffff7e54fa3 in start_thread (arg=<optimized out>) at pthread_create.c:486
#14 0x00007ffff49714cf in clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:95
(gdb) 

4、debug模式新建单位的调用栈
SYNCED_COMMAND_HANDLER_FUNCTION(debug_create_unit, child,  use_undo, /*show*/, error_handler)
    // Create the unit.
	unit_ptr created = unit::create(*u_type, side_num, true, gender);
    
    unit_map::unit_iterator unit_it;
    // Add the unit to the board.
	std::tie(unit_it, std::ignore) = resources::gameboard->units().replace(loc, created);
    unit_map::replace //replace的实现
        self_check();
        p->set_location(l);
        erase(l);
        return insert(p);
    unit_display::unit_recruited(loc);  //显示单位



(gdb) bt
#0  0x0000555555b8f830 in unit::init(unit_type const&, int, bool, unit_race::GENDER)
    (this=0x55555e540720, u_type=..., side=1, real_unit=true, gender=unit_race::MALE) at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/units/unit.cpp:694
#1  0x0000555555aac166 in unit::create(unit_type const&, int, bool, unit_race::GENDER) (t=..., side=1, real_unit=true, gender=unit_race::MALE)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/units/unit.hpp:138
#2  0x0000555555aa9394 in synced_command_func_debug_create_unit(config const&, bool, bool, synced_command::error_handler_function)
    (child=..., use_undo=true, error_handler=...)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/synced_commands.cpp:530
