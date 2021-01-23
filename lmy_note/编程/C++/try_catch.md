1\C++异常处理（try catch throw）完全攻略
http://c.biancheng.net/view/422.html
不妨把 try 和其后{}中的内容称作“try块”，把 catch 和其后{}中的内容称作“catch块”。
try...catch 语句的执行过程是：
执行 try 块中的语句，如果执行的过程中没有异常拋出，那么执行完后就执行最后一个 catch 块后面的语句，所有 catch 块中的语句都不会被执行；
如果 try 块执行的过程中拋出了异常，那么拋出异常后立即跳转到第一个“异常类型”和拋出的异常类型匹配的 catch 块中执行（称作异常被该 catch 块“捕获”），执行完后再跳转到最后一个 catch 块后面继续执行。
