1、shell中调用c程序
https://jingyan.baidu.com/article/48a420570c3a83a92425042b.html

2、
a="  1 2 3 1 2 2"
c=`printf "%s\n" "$a" | ./a.out`        //a.out接收到的参数是1个。只有函数名传入了！！！
c=`./a.out $a`                          //a.out接收到的参数是7个