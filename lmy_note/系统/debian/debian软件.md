1、下载地址
https://blog.csdn.net/whatday/article/details/86685072

2、无法打开teminal
http://tieba.baidu.com/p/5079766050

2、debian ctrl+alt+t无法启动终端解决办法
https://blog.csdn.net/jiaqi_327/article/details/21619193
解决办法是打开系统设置->键盘->快捷键->自定义快捷键，自己添加快捷键（拖到最下面点击+号）
名称：terminal（可自己定义）
命令：gnome-terminal（debian10的默认）（其他桌面环境需要修改gnome为其他桌面环境名字即可）
新建后设置这一项的快捷键为Ctrl+Alt+T即可使用快捷键打开终端

3、打开terminal时转圈圈然后自动关闭
Debian改变系统语言环境(中文切换到英文)实例
https://blog.csdn.net/yygydjkthh/article/details/47694747

4、alt+F2打开命令行界面

5、debian 和ubuntu 安装ifconfig 命令
# apt update
# apt install net-tools

6、debian安装apt提示插入光盘
有时候，在通过apt-get install 安装软件的时候，会出现：

更换介质：请把标有“Debian GNU/Linux 7.1.0 Wheezy - Official amd64 DVD Binary-1 20130615-23:06”的盘片插入驱动器“/media/cdrom/”再按回车键
类似的提示，如果不放入CD，那么安装是不能继续下去的。

为了解决此问题，我们可以这像下面这么做：
root权限修改/etc/apt/sources.list文件，注释掉deb cdrom:开头的行。即修改成：

deb cdrom:……
然后执行：apt-get update即可。

ref: http://blog.csdn.net/no7oor/article/details/12776815
https://blog.csdn.net/qq_38238114/article/details/78523983

7、解决unable to locate package net-tools

把其他的全部注释掉（#）,用163的镜像，速度嗖嗖的。
deb http://mirrors.163.com/debian/ stretch main non-free contrib
deb http://mirrors.163.com/debian/ stretch-updates main non-free contrib
deb http://mirrors.163.com/debian/ stretch-backports main non-free contrib

deb-src http://mirrors.163.com/debian/ stretch main non-free contrib
deb-src http://mirrors.163.com/debian/ stretch-updates main non-free contrib
deb-src http://mirrors.163.com/debian/ stretch-backports main non-free contrib

deb http://mirrors.163.com/debian-security/ stretch/updates main non-free contrib
deb-src http://mirrors.163.com/debian-security/ stretch/updates main non-free contrib


文章路径：http://tieba.baidu.com/p/5503515236


8、debian 添加永久环境变量方法
添加临时环境变量方法：
export PATH=$PATH:/usr/local/....(你的环境变量路径)
永久添加环境变量，步骤如下：
#在~/.bashrc文件末尾添加如下：
PATH = $PATH:/usr/local/...(待添加路径)     //debian的/usr/sbin默认不在环境变量中，需要添加
export PATH
保存；
source ~/.bashrc
echo $PATH

https://www.cnblogs.com/xielisen/p/10605360.html


9、debian 卸载软件的三种方法
https://blog.csdn.net/ykf173/article/details/88940674
