1、VMware 启动虚拟机黑屏(Ubuntu)

来自 <https://www.jianshu.com/p/33ed1de4c8d0> 

https://blog.csdn.net/what_about_us/article/details/81207926  //多种黑屏的解决办法
方案三：修复LSP
命令行窗口—输入netsh winsock reset—重启计算机
具体步骤（笔者的步骤，但是走了弯路，所以注意是要以管理员方式启动CMD）

2、VMware 黑屏,文件移动卡死解决方案
对于网络重置经测试 没用。
开启虚拟机发现右下角有提示 虚拟打印机功能被禁止了。
在设置中直接移除打印机即可解决无法进入系统的问题。
VMware文件的移动卡死，升级为15.1。（15.0无论重启多少次该卡死还是会卡死的，测试一下及时分配4G内存2核依然卡死。）
————————————————
原文链接：https://blog.csdn.net/Yakum0/article/details/100609217

3、启动黑屏也许是最新win10需要配合VM15.1 //如果低版本一直莫名奇妙黑屏，新版本不再黑屏，就是这个原因。191208安装VM15.1
https://blog.csdn.net/Chilly_heart/article/details/101201864