1\isxdigit()判断一个字符是否是十六进制数字
http://c.biancheng.net/ref/isxdigit.html
<ctype.h> -- 函数阅读：4,880       作者：严长生
isxdigit()判断一个字符是否是十六进制数字
int isxdigit ( int c );

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main ()
{
    char str[]="fBdE";
    long int number;
    if (isxdigit(str[0]))
    {
        number = strtol (str,NULL,16);
        printf ("The hexadecimal number %lx is %ld.\n",number,number);
    }
    return 0;
}

本例中，isxdigit() 用来检测 str 字符串中第 0 个字符是否是有效的十六进制数字，如果是，那么使用 strtol() 函数将 str 转换为十进制数字。
