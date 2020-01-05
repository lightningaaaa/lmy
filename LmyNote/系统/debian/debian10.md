1、Debian 10（Buster）安装过程图文详解
Debian 项目发布了它的最新稳定版 Debian 10，其代号是 “Buster”，这个发布版将获得 5 年的支持。Debian 10 可用于 32 位和 64 位系统。这个发布版带来很多新的特色

2、debian修改系统语言为英文
https://www.cnblogs.com/cainiaopark/p/5257257.html

修改/etc/default/locale 文件里，注意，有#号的要去掉。
LANG="zh_CN.UTF-8"
LANGUAGE="zh_CN:zh"
修改为下面内容:
LANG="en_US.UTF-8"
LANGUAGE="en_US:en"

在使用的过程中有报错话，那是因为英文包没有被安装，使用下面的命令
dpkg-reconfigure locales
选择en_US.UTF-8。。。用空格选中，不要直接敲回车。
选择好之后 重启，在系统设置（GNOME，装了）勾一下英文，重启就好了