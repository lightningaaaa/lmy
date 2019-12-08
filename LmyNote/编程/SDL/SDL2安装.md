1、ubuntu16.04 编译出错：fatal error: SDL/SDL.h: No such file or directory
https://www.cnblogs.com/dylancao/p/9039632.html
在ubuntu 16.04编译神经网络代码时候，遇到了这样一种错误？
fatal error: SDL/SDL.h: No such file or directory
原因是SDL库没有安装，根据你使用的是SDL1还是SDL2来进行不同的安装：如下所示：
	• SDL2
sudo apt-get install libsdl2-dev
	• SDL1
sudo apt-get install libsdl1.2-dev
SDL库是什么？这个估计很多人都没有听过吧，包括我。就顺便学习一下吧。看一下wiki：
SDL（Simple DirectMedia Layer）是一套開放原始碼的跨平台多媒體開發函式庫，使用C語言寫成。SDL提供了數種控制圖像、聲音、輸出入的函式，讓開發者只要用相同或
是相似的程式碼就可以開發出跨多個平台（Linux、Windows、Mac OS X等）的應用軟體。目前SDL多用於開發游戏、模拟器、媒體播放器等多媒體應用领域。
SDL（第一版）使用GNU宽通用公共许可证為授權方式，意指動態連結（dynamic link）其函式庫並不需要開放本身的原始碼。因此諸如《雷神之鎚4》等商業遊戲也使用SDL來開發。
而第二版的SDL則改用Zlib授权來授權。
Requirements
	• make
	• libsdl2-dev
	• libsdl2-ttf-dev
	• libsdl2-image-dev
	• doxygen-gui - for docs generation (optional)
	• doxygen - for docs generation (optional)
On Debian based systems you can run (apt can by replaced with apt-get or aptitude):
sudo apt install libsdl2-dev libsdl2-ttf-dev libsdl2-image-dev

来自 <https://github.com/krystiankaluzny/Tanks> 


2、ubuntu安装sdl2
https://www.linuxidc.com/Linux/2010-07/26965.htm
SDL2的头文件在/usr/include/SDL2中

2、
https://blog.csdn.net/roisolitaire/article/details/44081573
1 SDL2-2.0.3

下载  http://www.libsdl.org/

解压  

配置安装环境（--prefix=/usr 安装到/usr下以便能直接调用） ./configure --prefix=/usr

安装 make && make install



2 freetype-2.3.11

下载  http://downloads.sourceforge.net/freetype/freetype-2.5.5.tar.bz2

解压

安装配置   ./configure --prefix=/usr

安装 make && make install

3 SDL2_image-2.0.0

下载 http://www.libsdl.org/projects/SDL_image/


解压

安装配置   ./configure --prefix=/usr

安装 make && make install

4 SDL2_gfx-1.0.1

下载  http://cms.ferzkopp.net/index.php/software/13-sdl-gfx

解压

安装配置   ./configure --prefix=/us

重新配置   autoreconf -ivf （如果没这不会报如下错误）

libtool: Version mismatch error.  This is libtool 2.4.2 Debian-2.4.2-1ubuntu1, but the  
libtool: definition of this LT_INIT comes from libtool 2.4.  
libtool: You should recreate aclocal.m4 with macros from libtool 2.4.2 Debian-2.4.2-1ubuntu1  
libtool: and run autoconf again.  
make[5]: *** 1 Error 63  
安装 make && make install


3、SDL安装
https://www.linuxidc.com/Linux/2010-07/26965.htm
Ubuntu的新得立已经包含SDL库，所以通过几个简单的命令就可以安装，比windows还傻瓜！
sudo apt-get install libsdl1.2-dev(比较大，10M左右)
附加包：
sudo apt-get install libsdl-image1.2-dev
sudo apt-get install libsdl-mixer1.2-dev
sudo apt-get install libsdl-ttf2.0-dev
sudo apt-get install libsdl-gfx1.2-dev

1、Ubuntu 18 下安装SDL2命令
apt-get install libsdl2-2.0
apt-get install libsdl2-dev
apt-get install libsdl2-mixer-dev
apt-get install libsdl2-image-dev
apt-get install libsdl2-ttf-dev
apt-get install libsdl2-gfx-dev

链接：https://www.jianshu.com/p/17ff0f40ec08

