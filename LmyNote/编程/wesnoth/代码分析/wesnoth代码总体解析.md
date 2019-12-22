1、卷1：第25章 韦诺之战
https://www.kancloud.cn/kancloud/open-source-architecture/53168

主要子系统包括：
WML的预处理器和解析器
抽象了底层库和系统调用的基础I/O模块：视频、音频和网络
GUI模块，包括按钮、下拉列表、菜单等控件的实现
显示模块，渲染游戏地图、单位、动画等等
人工智能(AI)模块
寻路模块，包含了许多处理六边型游戏地图的工具函数
地图生成模块，用于生成各种随机地图

不同的模块控制着游戏流程中的不同部分：
titlescreen模块：控制游戏的主菜单画面的显示
storyline模块：显示游戏中的对话、场景切换等的序列
lobby模块：在多人游戏服务器上处理游戏的显示和创建
"play game"模块：控制整个游戏的主模块


2、move
D:\MyCode_ShareVm\wesnoth_1.14.9\src\actions\move.cpp

3、
D:\MyCode_ShareVm\wesnoth_1.14.9\src\actions\vision.cpp

4、
D:\MyCode_ShareVm\wesnoth_1.14.9\src\display.hpp

5、
D:\MyCode_ShareVm\wesnoth_1.14.9\src\editor\action\mouse\mouse_action.cpp

6、
D:\MyCode_ShareVm\wesnoth_1.14.9\src\editor\map\editor_map.cpp

7、
D:\MyCode_ShareVm\wesnoth_1.14.9\src\menu_events.cpp

8、
D:\MyCode_ShareVm\wesnoth_1.14.9\src\pathfind\pathfind.cpp

9、
D:\MyCode_ShareVm\wesnoth_1.14.9\src\play_controller.hpp

