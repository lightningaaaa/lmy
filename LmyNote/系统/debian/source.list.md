1、source.list文件说明
https://www.cnblogs.com/beanmoon/p/3387652.html

Debian 10（Buster）尝试设置：
deb http://mirrors.163.com/debian/ buster main non-free contrib
deb http://mirrors.163.com/debian/ buster-proposed-updates main non-free contrib
deb-src http://mirrors.163.com/debian/ buster main non-free contrib
deb-src http://mirrors.163.com/debian/ buster-proposed-updates main non-free contrib

更新软件包列表信息，升级debian
修改 /etc/apt/sources.list 之后一般会运行下面两个命令进行更新升级：
sudo apt-get update
sudo apt-get dist-upgrade
其中 ：
   update - 取回更新的软件包列表信息
   dist-upgrade - 发布版升级
第一个命令仅仅更新的软件包列表信息，所以很快就能完成。
第二个命令是全面更新发布版，一般会下载几百兆的新软件包。
其实在运行完第一个命令后系统就会提示你进行更新升级。因为修改了源，所有这次更新的改动可能会很大，比如安装某个包可能会删除太多的其他包，所有系统会提示你运行“sudo apt-get dist-upgrade”进行全面升级或使用软件包管理器中的“标记全部软件包以便升级”功能进行升级。两者效果是一样的。