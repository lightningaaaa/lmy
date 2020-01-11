1、Makefile教程（绝对经典，所有问题看这一篇足够了）
https://blog.csdn.net/weixin_38391755/article/details/80380786 //合入一篇文章
https://blog.csdn.net/haoel/article/details/2886  //原创

   .PHONY : clean
   clean :
           rm edit $(objects)
这种方法，也就是make的“隐晦规则”。上面文件内容中，“.PHONY”表示，clean是个伪目标文件。

 .PHONY : clean

       clean :

               -rm edit $(objects)

前面说过，.PHONY意思表示clean是一个“伪目标”，。而在rm命令前面加了一个小减号的意思就是，也许某些文件出现问题，但不要管，继续做后面的事