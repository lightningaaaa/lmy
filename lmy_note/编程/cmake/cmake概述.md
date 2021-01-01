1、Linux下CMake简明教程  //写的不错
https://blog.csdn.net/whahu1989/article/details/82078563

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
# 查找当前目录下的所有源文件 //不包含子目录
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)
https://www.jianshu.com/p/64da7a5f2c64  // aux_source_directory概述

# 可以将多个目录包含在 SRC_LIST 中
aux_source_directory(. SRC_LIST)
aux_source_directory(./gui/dialogs/ SRC_LIST)

# 指定生成目标
add_executable(Demo ${DIR_SRCS})

3、include_directories 。该命令是用来向工程添加多个指定头文件的搜索路径，路径之间用空格分隔。
include_directories (test_func test_func1)

4、
# 增加打印
message
https://blog.csdn.net/wq892373445/article/details/105013054?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_baidulandingword-7&spm=1001.2101.3001.4242
Android Studio 中的 CMake 3.4.1 版本 message打印日志以及输出位置
1
关键字，可以指定消息的类型：
message([<mode>] "message to display" ...)

(none)         = 重要消息
STATUS         = 附带消息
WARNING        = CMake警告，继续处理
AUTHOR_WARNING = CMake警告（dev），继续处理
SEND_ERROR     = CMake错误，继续处理，但跳过生成
FATAL_ERROR    = CMake错误，停止处理和生成
DEPRECATION    = 如果分别启用了变量CMAKE_ERROR_DEPRECATED或CMAKE_WARN_DEPRECATED，则CMake弃用错误或警告，否则无消息

简单演示上面前三种，打印一些变量值：

message("CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")
message(STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")
message(WARNING "CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}")
//添加日志打印出来
message("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA>>>")
message("当前CMake的路径是：${CMAKE_SOURCE_DIR}")


3、add_subdirectory 子文件夹也会编译，会在子目录中搜索CMakeLists.txt然后执行编译
add_subdirectory(doc)
if(GETTEXT_FOUND AND ENABLE_NLS)
	add_subdirectory(po)
endif (GETTEXT_FOUND AND ENABLE_NLS)
add_subdirectory(src)

4、cmake自带的预定义变量
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
EXECUTABLE_OUTPUT_PATH ：目标二进制可执行文件的存放位置
PROJECT_SOURCE_DIR：工程的根目录

5、静态库或者动态库的编译
add_library (testFunc_shared SHARED ${SRC_LIST})
add_library (testFunc_static STATIC ${SRC_LIST})
set_target_properties (testFunc_shared PROPERTIES OUTPUT_NAME "testFunc")
set_target_properties (testFunc_static PROPERTIES OUTPUT_NAME "testFunc")
set (LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_library: 生成动态库或静态库(第1个参数指定库的名字；第2个参数决定是动态还是静态，如果没有就默认静态；第3个参数指定生成库的源文件)
set_target_properties: 设置最终生成的库的名称，还有其它功能，如设置库的版本号等等
LIBRARY_OUTPUT_PATH: 库文件的默认输出路径，这里设置为工程目录下的lib目录

# find_package
6、
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

6、链接库
find_library(TESTFUNC_LIB testFunc HINTS ${PROJECT_SOURCE_DIR}/testFunc/lib)
add_executable (main ${SRC_LIST})
target_link_libraries (main ${TESTFUNC_LIB})

find_library: 在指定目录下查找指定库，并把库的绝对路径存放到变量里，其第一个参数是变量名称，第二个参数是库名称，第三个参数是HINTS，第4个参数是路径，其它用法可以参考cmake文档
target_link_libraries: 把目标文件与库文件进行链接

ps：在lib目录下有testFunc的静态库和动态库，find_library(TESTFUNC_LIB testFunc ...默认是查找动态库，如果想直接指定使用动态库还是静态库，可以写成find_library(TESTFUNC_LIB libtestFunc.so ...或者find_library(TESTFUNC_LIB libtestFunc.a ...

7、添加编译选项
add_compile_options(-std=c++11 -Wall)

8、添加控制选项
option(MYDEBUG "enable debug compilation" OFF)       //MYDEBUG可以对子目录生效
if (MYDEBUG)
    add_executable(main2 main2.c)
else()
    message(STATUS "Currently is not in debug mode")    
endif()

option命令，其第一个参数是这个option的名字，第二个参数是字符串，用来描述这个option是来干嘛的，第三个是option的值，ON或OFF，也可以不写，不写就是默认OFF。

cmake .. -DMYDEBUG=ON  //执行cmake命令时指定控制选项的值

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

