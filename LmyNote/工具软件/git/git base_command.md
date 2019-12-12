1、branch
git branch <name>  //创建分支
git branch //查看本地分支
git branch -r  //查看远端分支
git branch -a   //查看本地和远端分支
git branch -vv  //查看本地和远端分支的追踪关系以及当前的commitid

git branch -D <name>   //delete the branch
git branch -m <new_name>  //重命名当前分支为master（Rename the current branch to master）

2、branch追踪
（1）远端创建了分支，本地没有
git checkout --track origin/branch_name
or
git branch --set-upstream-to=origin/remote_branch your_branch
(2)本地创建了分支，远端没有
git push --set-upstream origin branch_name 

https://www.cnblogs.com/ampl/p/10873877.html

3、checkout
--orphan
Create a new orphan branch, named <new_branch>, started from <start_point> and switch to it. The first commit made on this new branch will have no parents and it will be the root of a new history totally disconnected from all the other branches and commits.

链接：https://blog.csdn.net/hudashi/article/details/7664482

4、commit
先git add，然后
git commit --ammend --no-edit   //修正上一次的commit

3、rm  //删除文件/文件夹
git rm file_name
git rm -r dir_name
git rm -h  //查看帮助
https://www.cnblogs.com/syq816/p/9301700.html
