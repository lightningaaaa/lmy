1、加入unit_map
unit_map &unit_map::operator=(const unit_map &that)  //重载=号调用add？
    void unit_map::add(const map_location&l, const base_unit* base_u)
    {
        const unit* u = dynamic_cast<const unit*>(base_u);
        if (u->is_artifical()) {   //判断是否artifical
            {
                artifical_ 变量表示  //
            }
            insert(l, new artifical(*(dynamic_cast<const artifical*>(u))));
        } else {
            insert(l, new unit(*u));
        }
    }

2、artifical_ 变量设置
（2.1）
game_state::build_team
（2.2）
game_state::build_team  //在韦诺之战中貌似分拆在 class team_builder 中的build_team_stage_one等
    unit_fields_t* fields = (unit_fields_t*)(mem + offset);  //获取fields信息
    unit* new_unit;
    if (fields->artifical_) {
        new_unit = new artifical(mem + offset);
    } else {
        new_unit = new unit(units, heros, teams, mem + offset);
    }