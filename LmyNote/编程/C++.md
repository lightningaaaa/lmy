1、C++在函数声明时，后面跟个const是什么意思？
https://zhidao.baidu.com/question/510299233.html
此函数处理不会改变对象成员值，否则在编译时报错。

2、C++ 下标运算符 [] 重载
https://www.runoob.com/cplusplus/subscripting-operator-overloading.html
    config temp_cfg(cfg);  //config是class
	temp_cfg["side"] = team_.side(); //["side"]是[]重载

3、std::tuple 和 std::tie 的用法简介
https://blog.csdn.net/m0_37809890/article/details/89367406
tuple即元组，可以理解为pair的扩展，可以用来将不同类型的元素存放在一起，常用于函数的多返回值。

定义与初始化
tuple可以使用初始化列表进行赋值。
tuple<int,double,string> t3 = {1, 2.0, "3"};

访问
可以使用get<常量表达式>(tuple_name)来访问或修改tuple的元素（返回引用）

    get<0>(t3) = 4;
    cout << get<1>(t3) << endl;
会输出2

批量赋值
std::tie会将变量的引用整合成一个tuple，从而实现批量赋值。

    int i; double d; string s;
    tie(i, d, s) = t3;

