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
