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