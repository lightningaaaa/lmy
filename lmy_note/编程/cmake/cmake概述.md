1、Linux下CMake简明教程
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
# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable(Demo ${DIR_SRCS})

3、include_directories。该命令是用来向工程添加多个指定头文件的搜索路径，路径之间用空格分隔。
include_directories (test_func test_func1)

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

