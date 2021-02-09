1、
mouse_handler::attack_enemy_(unit& attacker, unit& defender, const map_location& target_loc) //kingdom-src\kingdom\kingdom\mouse_events.cpp:1279
    dlg.show(resources::screen->video()); //mouse_events.cpp:1327
    == tdialog::show(CVideo& video, const unsigned auto_close_time) // kingdom-src\kingdom\librose\gui\dialogs\dialog.cpp:43
    {
        try
            tunit_attack::pre_show(CVideo& /*video*/, twindow& window) // kingdom-src\kingdom\kingdom\gui\dialogs\unit_attack.cpp:228
            {
                set_attacker_info(twindow& window, unit& u) // kingdom-src\kingdom\kingdom\gui\dialogs\unit_attack.cpp:79
                set_defender_info(window, defender_);
                set_weapon_info(window, bc_vector_, best_);
                { //ingdom-src\kingdom\kingdom\gui\dialogs\unit_attack.cpp：159
                    for (size_t i = 0; i < bc_vector.size(); ++i)
                        const battle_context::unit_stats& att = bc_vector[i].get_attacker_stats();
                        const battle_context::unit_stats& def = bc_vector[i].get_defender_stats();
                        str << att.damage << "-" << att.num_blows << " "  << " (" << att.chance_to_hit << "%)"; //伤害，打击次数，概率
                        if (!defw.get_cfg().empty()) {
                            str << def.damage << "-" << def.num_blows << " "  << " (" << def.chance_to_hit << "%)";//防御方的数据
            }
                }
            }
            window->set_transition(video.getSurface(), SDL_GetTicks());
            retval_ = window->show(restore_, auto_close_time); // 显示攻击力窗口
    }
    perform_attack(attacker, defender, att.attack_num, def.attack_num, rand_rng::get_last_seed()); //mouse_events.cpp:1361
    == mouse_handler::perform_attack(unit& attacker, unit& defender,
	int attacker_weapon, int defender_weapon, rand_rng::seed_t seed) //mouse_events.cpp:1720
    {
        try
            to_locs = attack_unit(attacker, defender, attacker_weapon, defender_weapon);//一次打击attacker只有一个，执行完后，状态已经为“完”
            == //\kingdom-src\kingdom\kingdom\actions.cpp：1362
            {
                attack dummy(attacker, defender, attack_with, defend_with, update_display, duel, move, formation);
                return dummy.perform();
                == attack::perform() //actions.cpp：1862
                {
                    unit& attacker = a_.get_unit(); // 一次打击attacker只有一个
	                unit& defender = d_.get_unit();
# 新增real_facing处理
                    const map_location& a = attacker.get_location();
                    const map_location& b = attacker.get_location();
                    attacker.set_real_facing(a.get_relative_dir(b));

                    defender.hit_points_ //防御者血量

                    if (a_stats_->weapon)
		                a_attackpoints_ = a_stats_->weapon->get_specials("attackpoints");//actions.cpp:2181
# 重要攻击
                    if (a_.n_attacks_ > 0 && !defender_strikes_first) //actions.cpp:2190，a_.n_attacks_会递减

# 一次打击调用多次
			            if (!perform_hit(true)) break; //actions.cpp：2145
                        {== attack::perform_hit //actions.cpp：1427 //一次打击调用多次
                            unit_info &attacker = *(attacker_turn ? &a_ : &d_), &defender = *(attacker_turn ? &d_ : &a_);
# 新增real_facing伤害增加计算
                            damage_increace_by_facing //actions.cpp：1670
# 重要，攻击显示
                            unit_display::unit_attack //unit_display.cpp:697
                            {
                                const map_location& a = attacker.get_location();//unit_display.cpp:702
                                attacker.set_facing(a.get_relative_dir(b_vec[0])); //unit_display.cpp:754获取相对方向，然后set
                                {//kingdom-src\kingdom\librose\base_unit.cpp:185
                                == base_unit::set_facing(map_location::DIRECTION dir) 
                                    {//正北为0，顺时针旋转
                                    //获取方向class base_unit类中facing() const { return facing_; }
                                        if (dir != map_location::NDIRECTIONS)
                                            facing_ = dir;
                                    }
                                }
                                add_animation // "attack"
                                add_animation2 // "defend"
                                while (damage_left[0] > 0 && !normal_animator.would_end())
        			                int step_left = (normal_animator.get_end_time() - normal_animator.get_animation_time() )/50;//查看了一次step_left=9
                                unit::take_hit //unit.hpp:430
                                { hit_points_ -= damage; return hit_points_ <= 0; }
# 动画真正演示？
                                if (!cast_tactic_state)
                            		normal_animator.start_animations();//unit_display.cpp:901
                                def_ptr_vec[i]->set_hitpoints(def_hitpoints_vec[i]); //unit_display.cpp:926，血量变为初始值，并不真正扣血
                            }
                            for (std::vector<std::pair<unit*, int> >::const_iterator loc = damage_locs.begin(); loc != damage_locs.end(); ++ loc, index_in_locs ++)
# 被攻击方真正扣血地方
                                bool dies = loc->first->take_hit(loc->second); //actions.cpp：1720

                        }

                }
            }
    }
# goto_main_context_menu 之前部队状态已经是“完”
    gui_->goto_main_context_menu();//mouse_events.cpp:1363

2、
(gdb) p attacker.loc_ //查看单位的位置
(gdb) p attacker.facing_  //朝向
(gdb) p def_ptr_vec[0]->hit_points_

3、设置完成状态？？？
(gdb) 
battle_context::unit_stats::unit_stats (this=0x55555b788e20, 
    u=<optimized out>, u_loc=..., u_attack_num=0, attacking=false, opp=..., 
    opp_loc=..., opp_weapon=0x5555571f00c0, units=...)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/actions.cpp:743
743			unit_abilities::effect dmg_effect(dmg_specials, base_damage, backstab_pos);
(gdb) 

867

#class unit的如下成员？？？表示移动力
	int total_movement() const { return max_movement_; }
	int movement_left() const { return (movement_ == 0 || incapacitated()) ? 0 : movement_; }
	void set_movement(int moves);


a_.get_unit().set_movement(a_.get_unit().movement_left() - a_.get_unit().attacks()[a_.weapon_].movement_used());//actions.cpp:1892


2、血量变化的gdb
(gdb) bt
#0  unit::take_hit (this=0x5555575d6820, damage=1)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/unit.hpp:430
#1  0x0000555555e86315 in unit_display::unit_attack (attacker=..., 
    def_ptr_vec=std::vector of length 1, capacity 1 = {...}, 
    damage_vec=std::vector of length 1, capacity 1 = {...}, 
    attack=0x555556fdd6e0, secondary_attack=0x0, swing=1, 
    hit_text_vec=std::vector of length 1, capacity 1 = {...}, drain=false, 
    stronger=false, att_text="", effecting_tactic=0x0, defender_formation=...)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/unit_display.cpp:901
#2  0x0000555555b52e0f in attack::perform_hit (this=0x7fffffff9840, 
    attacker_turn=true)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/actions.cpp:1704
#3  0x0000555555b56800 in attack::perform (this=0x7fffffff9840)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/actions.cpp:2140
#4  0x0000555555b50a07 in attack_unit (attacker=..., defender=..., 
    attack_with=2, defend_with=-1, update_display=true, duel=..., move=true, 

# 据点自动回复血量
3、
(gdb) bt
#0  unit::heal (this=0x5555570064b0, amount=20) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/unit.cpp:3181
#1  0x0000555555ba20c6 in artifical::new_turn (this=0x5555570064b0, controller=..., random=27253)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/artifical.cpp:1175
#2  0x0000555555d09d97 in play_controller::do_prefix_unit (this=0x7fffffffbe50, end_ticks=80000, replay=false, record_at_end=true)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/play_controller.cpp:2651
#3  0x0000555555d41029 in playsingle_controller::play_side (this=0x7fffffffbe50)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playsingle_controller.cpp:633
#4  0x0000555555d40d01 in playsingle_controller::play_turn (this=0x7fffffffbe50, save=true)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playsingle_controller.cpp:591
#5  0x0000555555d3fb9b in playsingle_controller::play_scenario (this=0x7fffffffbe50, story={...}, skip_replay=false)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playsingle_controller.cpp:457
#6  0x0000555555d32f2d in playsingle_scenario (game_config=..., level=0x7fffffffc870, disp=..., state_of_game=..., heros=..., 
    heros_start=..., cards=..., story={...}, skip_replay=false, end_level=...)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playcampaign.cpp:112
#7  0x0000555555d34df5 in play_game (disp=..., gamestate=..., game_config=..., heros=..., heros_start=..., cards=..., io_type=IO_NONE, 
    skip_replay=false) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/playcampaign.cpp:324
#8  0x0000555555bdbd9f in game_instance::launch_game (this=0x55555639d1a0 <create_instance<game_instance>(int, char**)::game>, 
    is_load_game=false) at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/game.cpp:1369
#9  0x0000555555bdd4cb in do_gameloop (argc=1, argv=0x7fffffffe228)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/game.cpp:1688
#10 0x0000555555bde18d in main (argc=1, argv=0x7fffffffe228)
    at /mnt/hgfs/MyCode_ShareVm/war_of_kingdom_linux/kingdom-src/kingdom/kingdom/game.cpp:1838
(gdb) 
