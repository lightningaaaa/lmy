1、
# [ 71%] Building C object kingdom/kingdom/CMakeFiles/wesnoth.dir/inapp_purchase.m.o
# cc: error trying to exec 'cc1obj': execvp: No such file or directory
https://blog.csdn.net/weixin_34199405/article/details/93690446
在http://forums.fedoraforum.org/showthread.php?t=267449中找到的解决方法
$LFS/sources/binutils-2.15.91.0.2/gprof/中将*.m都删除掉，毕竟.m已经预处理过了，不需要存在

https://blog.csdn.net/HelloWorld20151118/article/details/51164509/
前几日刚刚在Ubuntu12上搭建好object-c环境，但是命途多舛呀!花费了很久时间才搭建好的环境
但是却跑不了一个简单的helloworld，心累！
编译时报了如下错误：
gcc:error trying to exec 'cc1obj':execvp:No such file or directory!
原因：这个可能是你的gcc尚不支持cc1obj
解决方法：必须要安装gobjc
使用命令：sudo apt-get install gobjc即可

我的解决方法：先删掉kingdom/kingdom/inapp_purchase.m