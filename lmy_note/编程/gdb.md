1、gdb调试C++
linux下如何用GDB调试c++程序
https://blog.csdn.net/stone_overlooking/article/details/78493331
list 1 或l 1  //从第一行开始显示源代码，需要有-g参数编译
b  16   //C++代码的16行设置断点

https://www.cnblogs.com/gaopang/p/11588683.html
使用gdb调试c++程序
生成dump文件
ulimit -c unlimited

2\cmake和gdb调试程序
https://www.cnblogs.com/taolusi/p/9293290.html
(1)cmake支持gdb的实现，
首先在CMakeLists.txt下加入
SET(CMAKE_BUILD_TYPE "Debug") 
在下面加入：
SET(CMAKE_CXX_FLAGS_DEBUG "ENVCXXFLAGS−O0−Wall−g−ggdb")SET(CMAKECXXFLAGSRELEASE"ENV{CXXFLAGS} -O3 -Wall")
原因是CMake 中有一个变量 CMAKE_BUILD_TYPE ,可以的取值是 Debug Release RelWithDebInfo >和 MinSizeRel。
当这个变量值为 Debug 的时候,CMake 会使用变量 CMAKE_CXX_FLAGS_DEBUG 和 CMAKE_C_FLAGS_DEBUG 中的字符串作为编译选项生成 Makefile;

3、gdb 打印字符串全部内容
https://blog.csdn.net/wh8_2011/article/details/53898848
命令set print element 0
在gdb调试时要打印出一些字符串的内容，通过
p str@str_len  打印字符串时，长度受限，测试linux机器上默认为200个，但实际输出的长度str_len可能大于该值。
结果不能够完全输出，而进行了省略，通过命令set print element 0就可以了。