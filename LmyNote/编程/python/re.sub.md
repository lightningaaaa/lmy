1、详解re.sub
https://www.cnblogs.com/nkwy2012/p/6548812.html

str=re.sub(r'hello (\w+), nihao \1','fans',input)  //patten参数的r是regular正则的意思
replacedStr = re.sub(r"hello (?P<name>\w+), nihao (?P=name)", "\g<name>", inputStr);

def f(): pass   //pass表示空函数
print(type(f()))

要注意，被替换的字符串，即参数repl，是普通的字符串，不是pattern
注意到，语法是：
re.sub(pattern, repl, string, count=0, flags=0)
即，对应的第二个参数是repl。
需要你指定对应的r前缀，才是pattern：
r"xxxx"