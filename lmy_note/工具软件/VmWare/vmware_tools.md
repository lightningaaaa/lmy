1、安装wmware tools
（1）点击VM的--虚拟机--选择WMware tools安装
（2）在被安装的虚拟机中，cd /media/用户名/VMware Tools
cp VMwareTools*.tar.gz  /
cd /
tar -xvf VMwareTools*.tar.gz
cd /vmware-tools-distrib
./vmware-install.pl


2、VMWare工具安装失败。找不到“ depmod”节目
https://superuser.com/questions/1495637/vmware-tools-install-failure-unable-to-find-depmod-progam
因为环境变量中没有包含/usr/sbin/目录