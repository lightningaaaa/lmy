1、class unit定义
D:\MyCode_ShareVm\wesnoth_1.14.9\src\units\unit.hpp
D:\MyCode_ShareVm\War-Of-Kingdom\kingdom-src\kingdom\kingdom\unit.hpp

unit::set_hitpoints 在D:\MyCode_ShareVm\wesnoth_1.14.9\src\actions\attack.cpp 中有调用
bool attack::perform_hit(bool attacker_turn, statistics::attack_context& stats)    
    if(results_dies) {
        defender.get_unit().set_hitpoints(0);
    }

2、单位图片所在位置
\kingdom-res\app-kingdom\images\units\human

2、城市作为unit的派生类
D:\MyCode_ShareVm\War-Of-Kingdom\kingdom-src\kingdom\kingdom\artifical.hpp

http://www.freeors.com/bbs/forum.php?mod=viewthread&tid=21205&extra=page%3D3