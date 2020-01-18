1、github地址
https://github.com/wesnoth/wesnoth

2、官网地址
https://www.wesnoth.org/

3、中文版
http://wiki.wesnoth.org/Play/zh-Hans

4、源代码编译方法
https://wiki.wesnoth.org/CompilingWesnoth
（1）安装依赖
sudo apt build-dep wesnoth-1.12  //如果是1.14版本，可以尝试修改为1.14
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

6、ubuntu上pushd命令执行错误（/bin/sh: 1: pushd: not found）解决办法
https://blog.csdn.net/yangym2002/article/details/74640415

转载yangyunmmeng2002 最后发布于2017-07-07 11:13:00 阅读数 2280  收藏
 ubuntu上pushd命令执行错误（/bin/sh: 1: pushd: not found）解决办法
查看原因：进入/bin目录，查看sh的链接文件，显示如下：表示sh命令链接到的是dash，而pushd命令需要在bash的环境中执行。
解决方法：执行sudo dpkg-reconfigure dash 命令，将dash设置为No。
再次查看：查看sh的链接已经修改为bash了。

7、解决/bin/sh^M: bad interpreter: No such file or directory
https://blog.csdn.net/sjt19910311/article/details/87966881

用vim打开有问题的shell脚本，输入

:set fileformat=unix
1
然后保存

:wq!
