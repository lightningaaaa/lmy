1、wmware ubuntu窗口大小
https://jingyan.baidu.com/article/75ab0bcba3ef18d6874db240.html
设置---display


2、ubuntu安装后分辨率只有一个选项
https://blog.csdn.net/u013764485/article/details/78007370
ubuntu 16.04安装后分辨率只有一个选项 1024x768，使用xrandr命令出现错误：xrandr: Failed to get size of gamma for output default，使用cvt命令也无法设置，修改xorg.conf也没用。

解决办法：
打开：/etc/default/grub
搜索：#GRUB_GFXMODE=640x480
编辑：640x480改成你想要的分辨率，并取消前面的#
例如：GRUB_GFXMODE=1920x1080 
更新：sudo update-grub
重启 


3、Error found when loading /etc/profile xrandr Failed to get
https://blog.csdn.net/weixin_34138377/article/details/85981645  //不行