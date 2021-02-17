1、C++-string字符串类(详解)
https://www.cnblogs.com/lifexy/p/8642163.html
const char* c_str();   

返回一个常量C字符串, 内容与本string串相同. 

注意:当本string的内容改变,或被析构后,返回的字符串也不会被改变,因为返回的字符串是从新通过new char[]出来.

参考下面代码,可以发现返回的C字符串地址和string里的字符串地址完全不同: