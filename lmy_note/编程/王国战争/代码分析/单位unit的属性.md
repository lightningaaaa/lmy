1、
(gdb) p attacker.max_movement_
(gdb) p attacker.movement_
attacks_left_
(gdb) p attacker.unit_type_
(gdb) p attacker.unit_type_->type_name_
image_ = "units/human/horseman3-defend-miss.png"
(gdb) p attacker.attacks_
(gdb) p attacker.attacks_[0].range_
$8 = "melee"
(gdb) p attacker.attacks_[0].type_
$9 = "impact"
(gdb) 


2、
(gdb) p attacker.loc_ //查看单位的位置
(gdb) p attacker.facing_  //朝向
(gdb) p def_ptr_vec[0]->hit_points_