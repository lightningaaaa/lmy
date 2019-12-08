1、VMware Workstation 12专业版永久序列号：
ZU5NU-2XWD2-0806Z-WMP5G-NUHV6
VC58A-42Z8H-488ZP-8FXZX-YGRW8
FZ5XR-A3X16-H819Q-RFNNX-XG2EA

来自 <https://blog.csdn.net/u012955096/article/details/81358311> 


1、虚拟机安装ubuntu16.04系统
VMware Workstation12安装Ubuntu 16.04和VMware Tools教程，总共有三页的内容，可用
http://www.linuxidc.com/Linux/2016-11/137241.htm

2、VMware打不开？？？要检查更新？

https://blog.csdn.net/qq_41754907/article/details/102522560

3、VM15破解版
https://www.newasp.net/soft/503200.html

https://www.jb51.net/softs/638376.html

https://www.newasp.net/soft/461886.html   //好使

4、VirtualBox中安装Ubuntu到最后时卡死在：执行安装后执行的触发器update-notifier-common， ubuntu ubiquity processing trigge

https://blog.csdn.net/zjy900507/article/details/78717319
【总结】
貌似是和当前网络情况有关，估计是网络不稳定，导致了卡死。
然后可以试试拔掉网线，也许就可以解决了。
我这里有点特殊，是等待了很长时间（几十分钟，至少一二十分钟）后，结果自动又好了，然后就是显示Ubuntu安装成功了。> 

5、vmware下Ubuntu屏幕分辨率设置

https://www.cnblogs.com/hester/p/10327781.html


7、Vmware workstation中虚拟机提示获取所有权解决方法和原理

来自 <https://blog.csdn.net/hello_duhao/article/details/56007069> 
由于虚拟机在异常状态下关闭主机，会提示似乎正在使用中，如果确定是在使用请获取所有权，或者取消，无论是取消还是获取都会关闭窗口并不会打开虚拟机。
经过百度发现，删除虚拟机目录下面的lck文件夹即可打开。
操作的原理是

这个lck文件是虚拟机的磁盘锁文件，我们知道虚拟机的磁盘与主机的磁盘是共存的，只是由于采用特定的虚拟机制，使二者互不影响。在使用虚拟机时，vmware就会生成若干磁盘锁文件，用以保护当前虚拟机占用的磁盘不会被主机或者其它虚拟机占用修改。
　　在正常关闭虚拟机后，vmware会自动删除这个锁。可是少数情况下，例如主机突然崩溃、非正常关机等，vmware就不能够删除lck磁盘锁文件。所以下次再启动虚拟机时，vmware还会误认为需要启动的虚拟系统已经正在运行，就出现了提示this
virtual machine appears to be in use (虚拟机正在使用中)的错误。删除该文件后就能够恢复正常。

