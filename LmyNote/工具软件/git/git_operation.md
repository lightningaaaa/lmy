1、git删除所有历史提交记录，成为一个干净的新仓库
把旧项目提交到git上，但是会有一些历史记录，这些历史记录中可能会有项目密码等敏感信息。如何删除这些历史记录，形成一个全新的仓库，并且保持代码不变呢？

1.切换到新的分支

   git checkout --orphan latest_branch
缓存所有文件（除了.gitignore中声名排除的）
   git add -A
提交跟踪过的文件（Commit the changes）
   git commit -am "commit message"
删除master分支（Delete the branch）
   git branch -D master
5.重命名当前分支为master（Rename the current branch to master）

   git branch -m master
6.提交到远程master分支 （Finally, force update your repository）

   git push -f origin master
8人点赞
linux


作者：网络中迷茫
链接：https://www.jianshu.com/p/0b986acd0064

3、追踪分支
https://blog.csdn.net/qq_39940866/article/details/80320328
git branch --set-upstream-to=origin/<branch> master
