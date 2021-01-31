1、
2、gdb设置朝向
# 移动开始时设置朝向
# // Don't animate, only set facing and redraw path ends
(gdb) bt
#0  base_unit::set_facing (this=0x555559e1bf30, dir=map_location::NORTH_WEST)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/base_unit.cpp:187
#1  0x0000555555e827fa in unit_display::move_unit (path=std::vector of length 4, capacity 5 = {...}, u=..., 
    teams=std::vector of length 5, capacity 8 = {...}, animate=true, dir=map_location::NORTH_WEST)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/unit_display.cpp:339
#2  0x0000555555b5e6b4 in move_unit (move_spectator=0x7fffffffa3d0, route=std::vector of length 12, capacity 12 = {...}, 
    move_recorder=0x5555563a2220 <recorder>, undo_stack=0x0, show_move=true, next_unit=0x0, continue_move=true, should_clear_shroud=true, 
    is_replay=false) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/actions.cpp:3643
#3  0x0000555555d168c7 in play_controller::move_unit (this=0x7fffffffbe50, troop=true, current_team=..., pair={...}, to=..., 
    dst_must_reachable=false) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/play_controller.cpp:4777
#4  0x0000555555f2af41 in ai::ai_default::do_move (this=0x55555fe3bce0)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/ai/default/ai.cpp:1138
#5  0x0000555555f25543 in ai::ai_default::play_turn (this=0x55555fe3bce0)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/ai/default/ai.cpp:144
#6  0x0000555555f2185e in ai::manager::play_turn ()
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/ai/manager.cpp:389
#7  0x0000555555d43cd2 in playsingle_controller::play_ai_turn (this=0x7fffffffbe50, turn_data=0x0)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playsingle_controller.cpp:1134
#8  0x0000555555d4144e in playsingle_controller::play_side (this=0x7fffffffbe50)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playsingle_controller.cpp:672
#9  0x0000555555d40fad in playsingle_controller::play_turn (this=0x7fffffffbe50, save=true)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playsingle_controller.cpp:591
#10 0x0000555555d3fe47 in playsingle_controller::play_scenario (this=0x7fffffffbe50, story={...}, skip_replay=false)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playsingle_controller.cpp:457
#11 0x0000555555d331d9 in playsingle_scenario (game_config=..., level=0x7fffffffc870, disp=..., state_of_game=..., heros=..., 
    heros_start=..., cards=..., story={...}, skip_replay=false, end_level=...)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playcampaign.cpp:112
#12 0x0000555555d350a1 in play_game (disp=..., gamestate=..., game_config=..., heros=..., heros_start=..., cards=..., io_type=IO_NONE, 
    skip_replay=false) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playcampaign.cpp:324
#13 0x0000555555bdc04b in game_instance::launch_game (this=0x55555639e1a0 <create_instance<game_instance>(int, char**)::game>, 
    is_load_game=false) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/game.cpp:1369
#14 0x0000555555bdd777 in do_gameloop (argc=1, argv=0x7fffffffe228)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/game.cpp:1688
#15 0x0000555555bde439 in main (argc=1, argv=0x7fffffffe228)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/game.cpp:1838
(gdb) 

# 移动结束时设置朝向
Thread 1 "wesnoth" hit Breakpoint 1, base_unit::set_facing (this=0x555557157bb0, dir=map_location::SOUTH) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/base_unit.cpp:187
187		if (dir != map_location::NDIRECTIONS) {
#0  base_unit::set_facing (this=0x555557157bb0, dir=map_location::SOUTH) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/base_unit.cpp:187
#1  0x0000555555e832f2 in unit_display::move_unit (path=std::vector of length 5, capacity 5 = {...}, u=..., teams=std::vector of length 5, capacity 8 = {...}, animate=true, dir=map_location::SOUTH) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/unit_display.cpp:436
#2  0x0000555555b5e6b4 in move_unit (move_spectator=0x5555571582e8, route=std::vector of length 5, capacity 5 = {...}, move_recorder=0x5555563a2220 <recorder>, undo_stack=0x7fffffffc3b0, show_move=true, next_unit=0x7fffffffbf90, continue_move=false, should_clear_shroud=true, is_replay=false) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/actions.cpp:3643
#3  0x0000555555cae07a in events::mouse_handler::move_unit_along_current_route (this=0x7fffffffbef8, caller_steps=std::vector of length 0, capacity 16, check_shroud=true, attackmove=true) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/mouse_events.cpp:1225
#4  0x0000555555cacbc1 in events::mouse_handler::left_mouse_up (this=0x7fffffffbef8, x=549, y=537, motions=false, browse=false) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/mouse_events.cpp:1035
#5  0x00007ffff74f3e2c in events::mouse_handler_base::mouse_press (this=0x7fffffffbef8, event=..., motions=false, browse=false) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/mouse_handler_base.cpp:159
#6  0x00007ffff73af0a8 in controller_base::handle_mouse_up (this=0x7fffffffbe50, button=...) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/controller_base.cpp:152
#7  0x00007ffff73cc5d4 in base_finger::process_event (this=0x7fffffffbe60, event=...) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/events.cpp:159
#8  0x00007ffff73af316 in controller_base::handle_event (this=0x7fffffffbe50, event=...) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/controller_base.cpp:206
#9  0x00007ffff73cda6a in events::pump () at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/events.cpp:605
#10 0x00007ffff73af8e1 in controller_base::play_slice (this=0x7fffffffbe50, is_delay_enabled=true) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/controller_base.cpp:347
#11 0x0000555555d43142 in playsingle_controller::play_human_turn (this=0x7fffffffbe50) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playsingle_controller.cpp:967
#12 0x0000555555d41409 in playsingle_controller::play_side (this=0x7fffffffbe50) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playsingle_controller.cpp:651
#13 0x0000555555d40fad in playsingle_controller::play_turn (this=0x7fffffffbe50, save=true) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playsingle_controller.cpp:591
#14 0x0000555555d3fe47 in playsingle_controller::play_scenario (this=0x7fffffffbe50, story={...}, skip_replay=false) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playsingle_controller.cpp:457
#15 0x0000555555d331d9 in playsingle_scenario (game_config=..., level=0x7fffffffc870, disp=..., state_of_game=..., heros=..., heros_start=..., cards=..., story={...}, skip_replay=false, end_level=...) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playcampaign.cpp:112
#16 0x0000555555d350a1 in play_game (disp=..., gamestate=..., game_config=..., heros=..., heros_start=..., cards=..., io_type=IO_NONE, skip_replay=false) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playcampaign.cpp:324
#17 0x0000555555bdc04b in game_instance::launch_game (this=0x55555639e1a0 <create_instance<game_instance>(int, char**)::game>, is_load_game=false) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/game.cpp:1369
#18 0x0000555555bdd777 in do_gameloop (argc=1, argv=0x7fffffffe228) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/game.cpp:1688
#19 0x0000555555bde439 in main (argc=1, argv=0x7fffffffe228) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/game.cpp:1838
(gdb) 

# 第二种移动--这个一次多补移动时的中间某一步的朝向
Thread 1 "wesnoth" hit Breakpoint 1, base_unit::set_facing (this=0x7fffffff8020, dir=map_location::SOUTH_WEST) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/base_unit.cpp:187
187		if (dir != map_location::NDIRECTIONS) {
#0  base_unit::set_facing (this=0x7fffffff8020, dir=map_location::SOUTH_WEST) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/base_unit.cpp:187
#1  0x0000555555e81237 in move_unit_between (a=..., b=..., temp_unit=..., step_num=0, step_left=2, force_scroll=false) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/unit_display.cpp:97
#2  0x0000555555e83057 in unit_display::move_unit (path=std::vector of length 4, capacity 4 = {...}, u=..., teams=std::vector of length 5, capacity 8 = {...}, animate=true, dir=map_location::SOUTH_EAST) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/unit_display.cpp:419
#3  0x0000555555b5e6b4 in move_unit (move_spectator=0x7fffffff9fa0, route=std::vector of length 4, capacity 4 = {...}, move_recorder=0x5555563a2220 <recorder>, undo_stack=0x0, show_move=true, next_unit=0x0, continue_move=true, should_clear_shroud=true, is_replay=false) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/actions.cpp:3643
#4  0x0000555555d16965 in play_controller::move_unit (this=0x7fffffffbe50, troop=true, current_team=..., pair={...}, to=..., dst_must_reachable=true) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/play_controller.cpp:4794
#5  0x0000555555f2b959 in ai::ai_default::do_combat (this=0x55555aec3670, actor=0x0) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/ai/default/ai.cpp:1239
#6  0x0000555555f29d19 in ai::ai_default::do_move (this=0x55555aec3670) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/ai/default/ai.cpp:946
#7  0x0000555555f25543 in ai::ai_default::play_turn (this=0x55555aec3670) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/ai/default/ai.cpp:144
#8  0x0000555555f2185e in ai::manager::play_turn () at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/ai/manager.cpp:389
#9  0x0000555555d43cd2 in playsingle_controller::play_ai_turn (this=0x7fffffffbe50, turn_data=0x0) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playsingle_controller.cpp:1134
#10 0x0000555555d4144e in playsingle_controller::play_side (this=0x7fffffffbe50) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playsingle_controller.cpp:672
#11 0x0000555555d40fad in playsingle_controller::play_turn (this=0x7fffffffbe50, save=true) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playsingle_controller.cpp:591
#12 0x0000555555d3fe47 in playsingle_controller::play_scenario (this=0x7fffffffbe50, story={...}, skip_replay=false) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playsingle_controller.cpp:457
#13 0x0000555555d331d9 in playsingle_scenario (game_config=..., level=0x7fffffffc870, disp=..., state_of_game=..., heros=..., heros_start=..., cards=..., story={...}, skip_replay=false, end_level=...) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playcampaign.cpp:112
#14 0x0000555555d350a1 in play_game (disp=..., gamestate=..., game_config=..., heros=..., heros_start=..., cards=..., io_type=IO_NONE, skip_replay=false) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playcampaign.cpp:324
#15 0x0000555555bdc04b in game_instance::launch_game (this=0x55555639e1a0 <create_instance<game_instance>(int, char**)::game>, is_load_game=false) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/game.cpp:1369
#16 0x0000555555bdd777 in do_gameloop (argc=1, argv=0x7fffffffe228) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/game.cpp:1688
#17 0x0000555555bde439 in main (argc=1, argv=0x7fffffffe228) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/game.cpp:1838
(gdb) 

# 治疗时候设置朝向
(gdb) bt
#0  base_unit::set_facing (this=0x555557506730, dir=map_location::NDIRECTIONS)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/base_unit.cpp:187
#1  0x0000555555e89cd6 in unit_display::unit_healing (healed=..., healed_loc=..., healers=std::vector of length 1, capacity 1 = {...}, 
    healing=24) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/unit_display.cpp:1353
#2  0x0000555555b5afce in calculate_healing2 (teams=std::vector of length 5, capacity 8 = {...}, disp=..., side=1)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/actions.cpp:2938
#3  0x0000555555d0a798 in play_controller::do_prefix_unit (this=0x7fffffffbe50, end_ticks=60000, replay=false, record_at_end=true)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/play_controller.cpp:2752
#4  0x0000555555d412d5 in playsingle_controller::play_side (this=0x7fffffffbe50)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playsingle_controller.cpp:633
#5  0x0000555555d40fad in playsingle_controller::play_turn (this=0x7fffffffbe50, save=true)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playsingle_controller.cpp:591
#6  0x0000555555d3fe47 in playsingle_controller::play_scenario (this=0x7fffffffbe50, story={...}, skip_replay=false)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playsingle_controller.cpp:457
#7  0x0000555555d331d9 in playsingle_scenario (game_config=..., level=0x7fffffffc870, disp=..., state_of_game=..., heros=..., 
    heros_start=..., cards=..., story={...}, skip_replay=false, end_level=...)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playcampaign.cpp:112
#8  0x0000555555d350a1 in play_game (disp=..., gamestate=..., game_config=..., heros=..., heros_start=..., cards=..., io_type=IO_NONE, 
    skip_replay=false) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playcampaign.cpp:324
#9  0x0000555555bdc04b in game_instance::launch_game (this=0x55555639e1a0 <create_instance<game_instance>(int, char**)::game>, 
    is_load_game=false) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/game.cpp:1369
#10 0x0000555555bdd777 in do_gameloop (argc=1, argv=0x7fffffffe228)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/game.cpp:1688
#11 0x0000555555bde439 in main (argc=1, argv=0x7fffffffe228)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/game.cpp:1838
(gdb) 

# attack时设置朝向
Thread 1 "wesnoth" hit Breakpoint 1, base_unit::set_facing (this=0x555557157bb0, dir=map_location::SOUTH_WEST) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/base_unit.cpp:187
187		if (dir != map_location::NDIRECTIONS) {
#0  base_unit::set_facing (this=0x555557157bb0, dir=map_location::SOUTH_WEST) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/base_unit.cpp:187
#1  0x0000555555e84eb3 in unit_display::unit_attack (attacker=..., def_ptr_vec=std::vector of length 2, capacity 2 = {...}, damage_vec=std::vector of length 2, capacity 2 = {...}, attack=0x555558227df8, secondary_attack=0x55555abe8168, swing=1, hit_text_vec=std::vector of length 2, capacity 2 = {...}, drain=false, stronger=false, att_text="", effecting_tactic=0x0, defender_formation=...) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/unit_display.cpp:754
#2  0x0000555555b530b6 in attack::perform_hit (this=0x7fffffff98e0, attacker_turn=true) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/actions.cpp:1750
#3  0x0000555555b56af5 in attack::perform (this=0x7fffffff98e0) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/actions.cpp:2191
#4  0x0000555555b50a17 in attack_unit (attacker=..., defender=..., attack_with=1, defend_with=1, update_display=true, duel=..., move=true, formation=false) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/actions.cpp:1366
#5  0x0000555555cb0a4f in events::mouse_handler::perform_attack (this=0x7fffffffbef8, attacker=..., defender=..., attacker_weapon=1, defender_weapon=1, seed=1955481878) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/mouse_events.cpp:1733
#6  0x0000555555caebd7 in events::mouse_handler::attack_enemy_ (this=0x7fffffffbef8, attacker=..., defender=..., target_loc=...) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/mouse_events.cpp:1361
#7  0x0000555555cae47d in events::mouse_handler::attack_enemy (this=0x7fffffffbef8, attacker=..., defender=..., target_loc=...) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/mouse_events.cpp:1272
#8  0x0000555555cac1a0 in events::mouse_handler::left_mouse_up (this=0x7fffffffbef8, x=424, y=481, motions=false, browse=false) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/mouse_events.cpp:983
#9  0x00007ffff74f3e2c in events::mouse_handler_base::mouse_press (this=0x7fffffffbef8, event=..., motions=false, browse=false) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/mouse_handler_base.cpp:159
#10 0x00007ffff73af0a8 in controller_base::handle_mouse_up (this=0x7fffffffbe50, button=...) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/controller_base.cpp:152
#11 0x00007ffff73cc5d4 in base_finger::process_event (this=0x7fffffffbe60, event=...) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/events.cpp:159
#12 0x00007ffff73af316 in controller_base::handle_event (this=0x7fffffffbe50, event=...) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/controller_base.cpp:206
#13 0x00007ffff73cda6a in events::pump () at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/events.cpp:605
#14 0x00007ffff73af8e1 in controller_base::play_slice (this=0x7fffffffbe50, is_delay_enabled=true) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/controller_base.cpp:347
#15 0x0000555555d43142 in playsingle_controller::play_human_turn (this=0x7fffffffbe50) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playsingle_controller.cpp:967
#16 0x0000555555d41409 in playsingle_controller::play_side (this=0x7fffffffbe50) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playsingle_controller.cpp:651
#17 0x0000555555d40fad in playsingle_controller::play_turn (this=0x7fffffffbe50, save=true) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playsingle_controller.cpp:591
#18 0x0000555555d3fe47 in playsingle_controller::play_scenario (this=0x7fffffffbe50, story={...}, skip_replay=false) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playsingle_controller.cpp:457
#19 0x0000555555d331d9 in playsingle_scenario (game_config=..., level=0x7fffffffc870, disp=..., state_of_game=..., heros=..., heros_start=..., cards=..., story={...}, skip_replay=false, end_level=...) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playcampaign.cpp:112
#20 0x0000555555d350a1 in play_game (disp=..., gamestate=..., game_config=..., heros=..., heros_start=..., cards=..., io_type=IO_NONE, skip_replay=false) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playcampaign.cpp:324
#21 0x0000555555bdc04b in game_instance::launch_game (this=0x55555639e1a0 <create_instance<game_instance>(int, char**)::game>, is_load_game=false) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/game.cpp:1369
#22 0x0000555555bdd777 in do_gameloop (argc=1, argv=0x7fffffffe228) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/game.cpp:1688
#23 0x0000555555bde439 in main (argc=1, argv=0x7fffffffe228) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/game.cpp:1838
(gdb) 

# attack时第二次设置朝向
Thread 1 "wesnoth" hit Breakpoint 1, base_unit::set_facing (this=0x555557506730, dir=map_location::SOUTH_EAST) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/base_unit.cpp:187
187		if (dir != map_location::NDIRECTIONS) {
#0  base_unit::set_facing (this=0x555557506730, dir=map_location::SOUTH_EAST) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/librose/base_unit.cpp:187
#1  0x0000555555e84f19 in unit_display::unit_attack (attacker=..., def_ptr_vec=std::vector of length 2, capacity 2 = {...}, damage_vec=std::vector of length 2, capacity 2 = {...}, attack=0x555558227df8, secondary_attack=0x55555abe8168, swing=1, hit_text_vec=std::vector of length 2, capacity 2 = {...}, drain=false, stronger=false, att_text="", effecting_tactic=0x0, defender_formation=...) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/unit_display.cpp:756
#2  0x0000555555b530b6 in attack::perform_hit (this=0x7fffffff98e0, attacker_turn=true) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/actions.cpp:1750
