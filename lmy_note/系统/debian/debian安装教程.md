1、Debian 光盘安装简易教程
https://www.debian.cn/archives/1011

2、Debian 10（Buster）安装过程图文详解
https://www.linuxidc.com/Linux/2019-07/159336.htm

3、VMware虚拟机安装Debian 10图解  //还比较靠谱，除了在安装之前先关闭网络，否则安装很慢。还有不选择网络镜像。
https://www.cnblogs.com/dukejunior/articles/11405417.html

4、vmware中安装debian10，速度太慢
https://www.landui.com/help/show-10269.html
最近客户需要装debian10系统，因此在虚拟机上想先了解下安装步骤，结果遇到了问题。
安装步骤百度上都有,这里不详细介绍
现象描述：
在选择use a network mirror?（使用网络镜像）时，不管选择YES或者NO，vmware里都会提示安装时间超过一个小时，而如果使用hyper-v,则不会出现此问题，经过检查，看网络才知道是怎么回事，原来默认是网络下载安装包安装，vmware下载40KB/秒，hyper-v则是4MB/秒。
vmware里尝试更换中国镜像源，也不行，有些速度更慢，安装完需要10个小时，吓到我了 ：)
奇怪了,明明是镜像安装,怎么会默认网络下载安装包安装,这里没搞明白!
那么问题找到了，上述方式不行,那就找别的方法吧!怎么解决呢？
其实很简单，vmware里，电源里选关闭客户机，在设置里面找到网络适配器，已连接处的勾去掉，再开机并重新安装即可，或者在vmware右下角，找到网卡，选择断开连接，重新安装即可。
注意在DHCP配置时会配置不上，点以后配置，再点继续.
这时安装时,会使用DVD/CD安装，几分钟就安装完了。SO EASY!
