1、超详细的cmake教程
https://blog.csdn.net/zhuiyunzhugang/article/details/88142908
在 linux 平台下使用 CMake 生成 Makefile 并编译的流程如下：
编写 CMake 配置文件 CMakeLists.txt 。
执行命令 cmake PATH 或者 ccmake PATH 生成 Makefile 1 1ccmake 和 cmake 的区别在于前者提供了一个交互式的界面。。其中， PATH 是 CMakeLists.txt 所在的目录。
使用 make 命令进行编译。

1、几个文件编译为可执行文件
# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (Demo2)

# 指定生成目标
add_executable(Demo main.cc MathFunctions.cc)

2、如果搜寻目录下的所有文件
# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (Demo2)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable(Demo ${DIR_SRCS})

3、add_subdirectory 子文件夹也会编译
add_subdirectory(doc)
if(GETTEXT_FOUND AND ENABLE_NLS)
	add_subdirectory(po)
endif (GETTEXT_FOUND AND ENABLE_NLS)
add_subdirectory(src)

4\支持 gdb
让 CMake 支持 gdb 的设置也很容易，只需要指定 Debug 模式下开启 -g 选项： 
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

4\CMake生成的可执行文件能够gdb调试
（1）在CMakeLists.txt中加入
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
在韦诺中
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build, options are: None Debug Release Profile RelWithDebInfo MinSizeRel." FORCE)
endif(NOT CMAKE_BUILD_TYPE)

（2）重新编译
cmake -DCMAKE_BUILD_TYPE=Debug Path
然后make，可以进行gdb调试
发现CMakeCache.txt文件中有：CMAKE_BUILD_TYPE:STRING=Debug

5\CMake命令之function
https://blog.csdn.net/qq_31811537/article/details/82797051
定义一个可在CMake脚本其他位置调用的函数。
function(<name>[arg1 [arg2 [arg3 ...]]])
    COMMAND1(ARGS ...)
    COMMAND2(ARGS ...)
    ...

endfunction(<name>)

6\cmake之file
https://blog.csdn.net/tantion/article/details/84378266
file(STRINGS myfile.txt myfile)， 将输入文件的每行内容存储在变量"myfile"中。

7、CMake中的set指令详解
https://blog.csdn.net/guanguanboy/article/details/84838920
语法： SET(VAR [VALUE] [CACHE TYPE DOCSTRING [FORCE]]) 
指令功能: 用来显式的定义变量 
例子: SET (SRC_LST main.c other.c) 
说明: 用变量代替值，例子中定义SRC_LST代替后面的字符串。