1、github地址
https://github.com/wesnoth/wesnoth

2、官网地址
https://www.wesnoth.org/

3、中文版
http://wiki.wesnoth.org/Play/zh-Hans

4、源代码编译方法
https://wiki.wesnoth.org/CompilingWesnoth
（1）安装依赖
sudo apt build-dep wesnoth-1.12
sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev libboost-all-dev libvorbis-dev libcairo2-dev libpango1.0-dev libssl-dev libreadline-dev cmake make scons pkgconf
（2）可以使用scons或者cmake进行编译，如下使用scons
在安装文件的根目录
scons   //有报错，原因如下，在make时能看到详细原因
或
cmake .
make

fatal error:Killed signal terminated program cc1plus错误解决方法 ---虚拟机内存太小
https://blog.csdn.net/mudooo/article/details/97110256
（3）
scons install
scons uninstall
或
make install
（4）
./wesnoth

5、安装scons
https://blog.csdn.net/andyelvis/article/details/7055377