# find_package
1、
https://www.jianshu.com/p/166b90a6d860  // find_package 原理
find_package采用两种模式搜索库：
Module模式：搜索CMAKE_MODULE_PATH指定路径下的FindXXX.cmake文件，执行该文件从而找到XXX库。其中，具体查找库并给XXX_INCLUDE_DIRS和XXX_LIBRARIES两个变量赋值的操作由FindXXX.cmake模块完成。
Config模式：搜索XXX_DIR指定路径下的XXXConfig.cmake文件，执行该文件从而找到XXX库。其中具体查找库并给XXX_INCLUDE_DIRS和XXX_LIBRARIES两个变量赋值的操作由XXXConfig.cmake模块完成。

https://www.jianshu.com/p/243ff97bbbc6 // cmake中find_package的查找路径

下面这个举例不好用，可能时我的cmake版本比较新？
add_executable(my_bin src/my_bin.cpp)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(my_bin, ${OpenCV_LIBS})

我的cmake使用如下宏可以：
find_package(SDL2 REQUIRED)
${SDL2_INCLUDE_DIR}
${SDL2_LIBRARY}

Cmake之深入理解find_package()的用法
https://zhuanlan.zhihu.com/p/97369704?utm_source=wechat_session