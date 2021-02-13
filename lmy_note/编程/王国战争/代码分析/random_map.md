1、报错
not defiend group id: label
（1）
gui2::twidget::layout_init//gui/widgets/widget.cpp:167
    get_window()->add_linked_widget(linked_group_, this);
    {twindow::add_linked_widget(const std::string& id, twidget* widget) //librose/gui/widgets/window.cpp:1010
        VALIDATE(has_linked_size_group(id), err.str());
        {
            return linked_size_.find(id) != linked_size_.end();
        }
    }
    
（1.1）linked_group_设置一
    void set_linked_group(const std::string& linked_group)
	{
		linked_group_ = linked_group;
	}

(gdb)
b widget.cpp:131
p builder.linked_group


（1.2）linked_group_设置一，在某个构造函数中
twidget::twidget(const tbuilder_widget& builder)
    linked_group_(builder.linked_group)

(gdb)
b gui2::twidget::set_linked_group if $rdi != 0 && strcmp($rdi, "label")==0  //加if条件会退出
b 0x00007ffff7596692 if $rdi != 0 && strcmp($rdi, "label")==0
p linked_group



（2）
enter_create_mode //multiplayer.cpp:2967
    。。。
    gui2::twindow::draw //gui/widgets/window.cpp:697
        gui2::twindow::layout //gui/widgets/window.cpp:1087


2、
# gdb调用栈
Thread 1 "wesnoth" hit Breakpoint 1, gui2::twindow::add_linked_widget (
    this=0x5555570b1ad0, id="label", widget=0x555557479cb8)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/gui/widgets/window.cpp:1012
1012		assert(widget);
1: id = "label"
(gdb) bt
#0  gui2::twindow::add_linked_widget (this=0x5555570b1ad0, id="label", 
    widget=0x555557479cb8)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/gui/widgets/window.cpp:1012
#1  0x00007ffff76e6cb3 in gui2::twidget::layout_init (this=0x555557479cb8)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/gui/widgets/widget.cpp:167
#2  0x00007ffff765c33d in gui2::tcontrol::layout_init (this=0x555557479b00, 
    full_initialization=true)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/gui/widgets/control.cpp:218
#3  0x00007ffff766c126 in gui2::cell_layout_init (cell=..., 
    full_initialization=true)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/gui/widgets/grid.cpp:1241
#4  0x00007ffff7667bcf in gui2::tgrid::layout_init (this=0x5555570620b0, 
    full_initialization=true)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/gui/widgets/grid.cpp:636
#5  0x00007ffff76587e4 in gui2::tcontainer_::layout_init (this=0x555557061f00, 
    full_initialization=true)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/gui/widgets/container.cpp:35
#6  0x00007ffff766c126 in gui2::cell_layout_init (cell=..., full_initialization=true) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/gui/widgets/grid.cpp:1241
#7  0x00007ffff7667bcf in gui2::tgrid::layout_init (this=0x5555574b9500, full_initialization=true) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/gui/widgets/grid.cpp:636
#8  0x00007ffff766c126 in gui2::cell_layout_init (cell=..., full_initialization=true) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/gui/widgets/grid.cpp:1241
#9  0x00007ffff7667bcf in gui2::tgrid::layout_init (this=0x5555570b6b90, full_initialization=true) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/gui/widgets/grid.cpp:636
#10 0x00007ffff7698e62 in gui2::tscrollbar_container::layout_init (this=0x5555571b3e00, full_initialization=true) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/gui/widgets/scrollbar_container.cpp:152
#11 0x00007ffff766c126 in gui2::cell_layout_init (cell=..., full_initialization=true) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/gui/widgets/grid.cpp:1241
#12 0x00007ffff7667bcf in gui2::tgrid::layout_init (this=0x5555577474d0, full_initialization=true) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/gui/widgets/grid.cpp:636
#13 0x00007ffff766c126 in gui2::cell_layout_init (cell=..., full_initialization=true) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/gui/widgets/grid.cpp:1241
#14 0x00007ffff7667bcf in gui2::tgrid::layout_init (this=0x5555570b7790, full_initialization=true) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/gui/widgets/grid.cpp:636
#15 0x00007ffff766c126 in gui2::cell_layout_init (cell=..., full_initialization=true) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/gui/widgets/grid.cpp:1241
#16 0x00007ffff7667bcf in gui2::tgrid::layout_init (this=0x5555570b1c80, full_initialization=true) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/gui/widgets/grid.cpp:636
#17 0x00007ffff76587e4 in gui2::tcontainer_::layout_init (this=0x5555570b1ad0, full_initialization=true) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/gui/widgets/container.cpp:35
#18 0x00007ffff76ee348 in gui2::twindow::layout (this=0x5555570b1ad0) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/gui/widgets/window.cpp:1087
#19 0x00007ffff76ec0b1 in gui2::twindow::draw (this=0x5555570b1ad0) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/gui/widgets/window.cpp:697
#20 0x00007ffff76fa50f in boost::_mfi::mf0<void, gui2::twindow>::operator() (this=0x7fffffffae88, p=0x5555570b1ad0) at /usr/include/boost/bind/mem_fn_template.hpp:49
#21 0x00007ffff76f95bb in boost::_bi::list1<boost::_bi::value<gui2::twindow*> >::operator()<boost::_mfi::mf0<void, gui2::twindow>, boost::_bi::rrlist5<gui2::event::tdispatcher&, gui2::event::tevent, bool&, bool&, int> > (this=0x7fffffffae98, f=..., a=...) at /usr/include/boost/bind/bind.hpp:259
#22 0x00007ffff76f8695 in boost::_bi::bind_t<void, boost::_mfi::mf0<void, gui2::twindow>, boost::_bi::list1<boost::_bi::value<gui2::twindow*> > >::operator()<gui2::event::tdispatcher&, gui2::event::tevent, bool&, bool&, int> (this=0x7fffffffae88, a1=..., a2=@0x7fffffffacec: gui2::event::DRAW, a3=@0x7fffffffae3f: false, a4=@0x7fffffffae3e: false, a5=@0x7ffffffface8: 0) at /usr/include/boost/bind/bind.hpp:1354
#23 0x00007ffff76f71a3 in boost::detail::function::void_function_obj_invoker5<boost::_bi::bind_t<void, boost::_mfi::mf0<void, gui2::twindow>, boost::_bi::list1<boost::_bi::value<gui2::twindow*> > >, void, gui2::event::tdispatcher&, gui2::event::tevent, bool&, bool&, int>::invoke (function_obj_ptr=..., a0=..., a1=gui2::event::DRAW, a2=@0x7fffffffae3f: false, a3=@0x7fffffffae3e: false, a4=0) at /usr/include/boost/function/function_template.hpp:159
#24 0x00007ffff759cdcb in boost::function5<void, gui2::event::tdispatcher&, gui2::event::tevent, bool&, bool&, int>::operator() (this=0x7fffffffae80, a0=..., a1=gui2::event::DRAW, a2=@0x7fffffffae3f: false, a3=@0x7fffffffae3e: false, a4=0) at /usr/include/boost/function/function_template.hpp:768
#25 0x00007ffff759c29d in gui2::event::ttrigger::operator()(boost::function<void (gui2::event::tdispatcher&, gui2::event::tevent, bool&, bool&, int)>, gui2::event::tdispatcher&, gui2::event::tevent, bool&, bool&) (this=0x7fffffffae08, functor=..., dispatcher=..., event=gui2::event::DRAW, handled=@0x7fffffffae3f: false, halt=@0x7fffffffae3e: false) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/gui/auxiliary/event/dispatcher.cpp:142
#26 0x00007ffff759f311 in gui2::event::implementation::fire_event<boost::function<void (gui2::event::tdispatcher&, gui2::event::tevent, bool&, bool&, int)>, gui2::event::ttrigger>(gui2::event::tevent, std::vector<std::pair<gui2::twidget*, gui2::event::tevent>, std::allocator<std::pair<gui2::twidget*, gui2::event::tevent> > >&, gui2::twidget*, gui2::twidget*, gui2::event::ttrigger) (event=gui2::event::DRAW, event_chain=std::vector of length 0, capacity 0, dispatcher=0x5555570b21f0, widget=0x5555570b21f0, functor=...) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/./gui/auxiliary/event/dispatcher_private.hpp:479
#27 0x00007ffff759d613 in gui2::event::fire_event<boost::function<void (gui2::event::tdispatcher&, gui2::event::tevent, bool&, bool&, int)>, gui2::event::ttrigger>(gui2::event::tevent, gui2::twidget*, gui2::twidget*, gui2::event::ttrigger) (event=gui2::event::DRAW, dispatcher=0x5555570b21f0, widget=0x5555570b21f0, functor=...) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/./gui/auxiliary/event/dispatcher_private.hpp:559
#28 0x00007ffff759b977 in gui2::event::tdispatcher::fire (this=0x5555570b22a8, event=gui2::event::DRAW, target=..., val=0) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/gui/auxiliary/event/dispatcher.cpp:187
#29 0x00007ffff75cda77 in gui2::event::thandler::draw (this=0x5555579d6a30, force=false) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/gui/auxiliary/event/handler.cpp:635
#30 0x00007ffff75ccdf6 in gui2::event::thandler::handle_event (this=0x5555579d6a30, event=...) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/gui/auxiliary/event/handler.cpp:441
#31 0x00007ffff73cda6a in events::pump () at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/events.cpp:605
#32 0x00007ffff76ebb23 in gui2::twindow::show (this=0x5555570b1ad0, restore=true, auto_close_timeout=0) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/gui/widgets/window.cpp:613
#33 0x00007ffff7623279 in gui2::tdialog::show (this=0x7fffffffb660, video=..., auto_close_time=0) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/gui/dialogs/dialog.cpp:70
#34 0x0000555555cd951d in enter_create_mode (disp=..., game_config=..., heros=..., heros_start=..., cards=..., gamelist=..., default_controller=CNTR_LOCAL, local_players_only=true) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/multiplayer.cpp:2976
#35 0x0000555555cda5f1 in mp::start_local_game (disp=..., game_config=..., heros=..., heros_start=..., cards=..., default_controller=CNTR_LOCAL) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/multiplayer.cpp:3132
#36 0x0000555555bd8cf6 in game_instance::play_multiplayer (this=0x55555639d1a0 <create_instance<game_instance>(int, char**)::game>, random_map=true) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/game.cpp:1086
#37 0x0000555555bd4c15 in game_instance::new_campaign (this=0x55555639d1a0 <create_instance<game_instance>(int, char**)::game>, catalog=0) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/game.cpp:683
#38 0x0000555555bdd35d in do_gameloop (argc=1, argv=0x7fffffffe228) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/game.cpp:1686
#39 0x0000555555bde04b in main (argc=1, argv=0x7fffffffe228) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/game.cpp:1841
(gdb) 
