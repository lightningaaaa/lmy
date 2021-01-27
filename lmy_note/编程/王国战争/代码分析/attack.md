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
            to_locs = attack_unit(attacker, defender, attacker_weapon, defender_weapon);//一次打击attacker只有一个
            == //\kingdom-src\kingdom\kingdom\actions.cpp：1358
            {
                attack dummy(attacker, defender, attack_with, defend_with, update_display, duel, move, formation);
                return dummy.perform();
                == attack::perform() //actions.cpp：1816
                {
                    unit& attacker = a_.get_unit(); // 一次打击attacker只有一个
	                unit& defender = d_.get_unit();
# 重要
                    defender.hit_points_ //防御者血量
                    if (a_.n_attacks_ > 0 && !defender_strikes_first)
			            if (!perform_hit(true)) break; //actions.cpp：2140
                        {
                            attack::perform_hit //actions.cpp：1704
                            {
# 重要
                                unit_display::unit_attack //unit_display.cpp:901
                                {
                                    attacker.set_facing(a.get_relative_dir(b_vec[0])); //获取相对方向，然后set
                                    {//kingdom-src\kingdom\librose\base_unit.cpp:185
                                    == base_unit::set_facing(map_location::DIRECTION dir) 
                                        {//正北为0，顺时针旋转
                                        //获取方向class base_unit类中facing() const { return facing_; }
                                            if (dir != map_location::NDIRECTIONS)
                                                facing_ = dir;
                                        }
                                    }
                                    unit::take_hit //unit.hpp:430
                                    { hit_points_ -= damage; return hit_points_ <= 0; }
                                }
                            }
                        }

                }
            }
    }

2、
(gdb) p attacker.loc_ //查看单位的位置
(gdb) p attacker.facing_  //朝向

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

