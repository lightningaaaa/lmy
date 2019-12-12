1、The system is running in low-graphics mode时解决方法
ubuntu启动时进入命令行界面
按CTRL+ALT+F1
此时输入命令修改权限：
df -h
cd /etc/X11
sudo cp xorg.conf.failsafe xorg.conf
sudo reboot
可顺利进入Ubuntu