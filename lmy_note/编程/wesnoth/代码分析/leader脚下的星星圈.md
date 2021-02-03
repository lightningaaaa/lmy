1、有点怀疑的代码
搜索leader
unit_drawer::redraw_unit //src\units\drawer.cpp:59
	// Load the ellipse parts recolored to match team color
	ellipse_back = image::get_image(image::locator(ellipse_top), image::SCALED_TO_ZOOM);//获取图片，drawer.cpp:220
	ellipse_front = image::get_image(image::locator(ellipse_bot), image::SCALED_TO_ZOOM);
    const std::string ellipse_top = formatter() << ellipse << "-" << leader << nozoc << selected << "top.png~RC(ellipse_red>" << tc << ")";//drawer.cpp:216，路径是"image/misc/ellipse-top.png~RC(ellipse_red>red)"
	const std::string ellipse_bot = formatter() << ellipse << "-" << leader << nozoc << selected << "bottom.png~RC(ellipse_red>" << tc << ")";//drawer.cpp:217，"misc/ellipse-bottom.png~RC(ellipse_red>red)"

1.1、删掉文件后的错误打印。leader脚下没有了光环
20210201 22:37:41 error display: could not open image 'misc/ellipse-leader-top.png'
20210201 22:37:41 error display: could not open image 'misc/ellipse-leader-bottom.png'
20210201 22:37:43 error display: could not open image 'misc/ellipse-hero-top.png'
20210201 22:37:43 error display: could not open image 'misc/ellipse-hero-bottom.png'
20210201 22:37:51 error display: could not open image 'misc/ellipse-leader-selected-top.png'
20210201 22:37:51 error display: could not open image 'misc/ellipse-leader-selected-bottom.png'

src\picture.cpp
    ERR_DP << "could not open image '" << loc.get_filename() << "'" << std::endl; //582

gdb的调用栈
(gdb) p loc
$2 = (const image::locator &) @0x7fffffff9820: {index_ = 29703, val_ = {
    type_ = image::locator::FILE, is_data_uri_ = false, 
    filename_ = "misc/ellipse-leader-top.png", loc_ = {x = -1000, y = -1000}, 
    modifications_ = "", center_x_ = 0, center_y_ = 0}}
(gdb) bt
#0  0x00005555564be94b in image::load_image_file(image::locator const&)
    (loc=...) at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/picture.cpp:582
#1  0x00005555564bffd3 in image::load_from_disk(image::locator const&)
    (loc=...) at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/picture.cpp:763
#2  0x00005555564c085f in image::get_image(image::locator const&, image::TYPE)
    (i_locator=..., type=image::UNSCALED)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/picture.cpp:1005
#3  0x00005555564bebed in image::load_image_sub_file(image::locator const&)
    (loc=...) at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/picture.cpp:592
#4  0x00005555564bffe8 in image::load_from_disk(image::locator const&)
    (loc=...) at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/picture.cpp:766
#5  0x00005555564c085f in image::get_image(image::locator const&, image::TYPE)
    (i_locator=..., type=image::UNSCALED)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/picture.cpp:1005
#6  0x0000555556086944 in unit_drawer::redraw_unit(unit const&) const
    (this=0x7fffffffab10, u=...)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/units/drawer.cpp:220
#7  0x000055555644ef20 in display::draw_invalidated() (this=0x7fffc61c1180)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/display.cpp:2553
#8  0x0000555555e4d404 in game_display::draw_invalidated()
    (this=0x7fffc61c1180)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/game_display.cpp:230
#9  0x000055555644e9b2 in display::draw(bool, bool)
--Type <RET> for more, q to quit, c to continue without paging--
    (this=0x7fffc61c1180, update=true, force=true)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/display.cpp:2492
#10 0x000055555644e6e1 in display::redraw_everything() (this=0x7fffc61c1180)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/display.cpp:2431
#11 0x000055555644e8b6 in display::draw(bool, bool)
    (this=0x7fffc61c1180, update=true, force=false)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/display.cpp:2467
#12 0x000055555644e81a in display::draw() (this=0x7fffc61c1180)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/display.cpp:2449
#13 0x000055555644d53f in display::scroll_to_xy(int, int, display::SCROLL_TYPE, bool)
    (this=0x7fffc61c1180, screenxpos=1575, screenypos=1323, scroll_type=display::WARP, force=true)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/display.cpp:2110
#14 0x000055555644e10d in display::scroll_to_tiles(__gnu_cxx::__normal_iterator<map_location const*, std::vector<map_location, std::allocator<map_location> > > const&, __gnu_cxx::__normal_iterator<map_location const*, std::vector<map_location, std::allocator<map_location> > > const&, display::SCROLL_TYPE, bool, bool, double, bool) (this=0x7fffc61c1180, begin={x = 28, y = 17}, end=
  {x = 0, y = 0}, scroll_type=display::WARP, check_fogged=true, only_if_possible=false, add_spacing=0, force=true)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/display.cpp:2320
#15 0x0000555555b8b58b in display::scroll_to_tiles(std::vector<map_location, std--Type <RET> for more, q to quit, c to continue without paging--
::allocator<map_location> > const&, display::SCROLL_TYPE, bool, bool, double, bool)
    (this=0x7fffc61c1180, locs=std::vector of length 1, capacity 1 = {...}, scroll_type=display::WARP, check_fogged=true, only_if_possible=false, add_spacing=0, force=true) at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/display.hpp:555
#16 0x000055555644d92e in display::scroll_to_tile(map_location const&, display::SCROLL_TYPE, bool, bool)
    (this=0x7fffc61c1180, loc=..., scroll_type=display::WARP, check_fogged=true, force=true) at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/display.cpp:2180
#17 0x0000555556050f9c in playsingle_controller::init_gui() (this=
    0x7fffffffbc20)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/playsingle_controller.cpp:129
#18 0x0000555556046a3e in play_controller::start_game() (this=0x7fffffffbc20)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/play_controller.cpp:1100
#19 0x00005555560511a5 in playsingle_controller::play_scenario_init()
    (this=0x7fffffffbc20)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/playsingle_controller.cpp:148
#20 0x0000555556051cff in playsingle_controller::play_scenario(config const&)
    (this=0x7fffffffbc20, level=...)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/playsingle_controller.cpp:266
--Type <RET> for more, q to quit, c to continue without paging--
#21 0x0000555555e94b36 in campaign_controller::playmp_scenario(end_level_data&)
    (this=0x7fffffffc5c0, end_level=...)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/game_initialization/playcampaign.cpp:225
#22 0x0000555555e94e41 in campaign_controller::play_game()
    (this=0x7fffffffc5c0)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/game_initialization/playcampaign.cpp:290
#23 0x0000555555e88d8d in (anonymous namespace)::enter_staging_mode((anonymous namespace)::mp_workflow_helper_ptr)
    (helper=std::shared_ptr<(anonymous namespace)::mp_workflow_helper> (use count 3, weak count 0) = {...})
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/game_initialization/multiplayer.cpp:495
#24 0x0000555555e89150 in (anonymous namespace)::enter_create_mode((anonymous namespace)::mp_workflow_helper_ptr)
    (helper=std::shared_ptr<(anonymous namespace)::mp_workflow_helper> (use count 3, weak count 0) = {...})
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/game_initialization/multiplayer.cpp:521
#25 0x0000555555e8a472 in mp::start_local_game(config const&, saved_game&)
    (game_config=..., state=...)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/game_initialization/multiplay--Type <RET> for more, q to quit, c to continue without paging--
er.cpp:695
#26 0x00005555558df039 in game_launcher::play_multiplayer(game_launcher::mp_selection) (this=0x555557226790, res=game_launcher::MP_LOCAL)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/game_launcher.cpp:855
#27 0x000055555584f6d8 in do_gameloop(std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > const&)
    (args=std::vector of length 1, capacity 1 = {...})
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/wesnoth.cpp:874
#28 0x0000555555850009 in main(int, char**) (argc=1, argv=0x7fffffffe268)
    at /mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/src/wesnoth.cpp:1081
(gdb) 


2、
src\units\udisplay.cpp