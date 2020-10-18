7、CMake中的set指令详解
https://blog.csdn.net/guanguanboy/article/details/84838920
语法： SET(VAR [VALUE] [CACHE TYPE DOCSTRING [FORCE]]) 
指令功能: 用来显式的定义变量 
例子: SET (SRC_LST main.c other.c) 
说明: 用变量代替值，例子中定义SRC_LST代替后面的字符串。