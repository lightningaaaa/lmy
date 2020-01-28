1、方法1，此方法有可能会成功，不进行尝试了。
./CMakeLists.txt中
CMAKE_BUILD_TYPE默认值修改为 Debug
（1）编译时报错
[ 80%] Built target lua
Scanning dependencies of target wesnoth-revision_dummy
/bin/sh: 1: //mnt/hgfs/MyCode_ShareVm/wesnoth_1_14_9/utils/autorevision.sh: not found
make[2]: *** [src/CMakeFiles/wesnoth-revision_dummy.dir/build.make:57: src/CMakeFiles/wesnoth-revision_dummy] Error 127
make[1]: *** [CMakeFiles/Makefile2:468: src/CMakeFiles/wesnoth-revision_dummy.dir/all] Error 2
make: *** [Makefile:152: all] Error 2

(1.1)此报错是因为autorevision.sh格式不是unix格式，如下方式修改：
用vim打开有问题的shell脚本，输入
:set fileformat=unix
然后保存
:wq!

（1.2）进入./sh后退出使用exit
http://c.biancheng.net/view/1145.html

2、CMAKE_CXX_FLAGS_RELEASE 增加-g参数和-O0。经试验，此方法可行。
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
