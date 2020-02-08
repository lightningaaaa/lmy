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

4、boost::intrusive_ptr原理介绍
https://www.cnblogs.com/edwardlost/archive/2011/02/17/1957019.html
https://blog.csdn.net/harbinzju/article/details/6754646
在以下情况时使用 intrusive_ptr ：
你需要把 this 当作智能指针来使用。
已有代码使用或提供了插入式的引用计数。
智能指针的大小必须与裸指针的大小相等。

5、dynamic_cast
const unit* u = dynamic_cast<const unit*>(base_u);
https://baike.baidu.com/item/dynamic_cast/4473047?fr=aladdin
dynamic_cast是将一个基类对象指针（或引用）转换到继承类指针，dynamic_cast会根据基类指针是否真正指向继承类指针来做相应处理。

6、C++ | vector 类中的 push_back( ) 函数 、（添加和删除函数）
https://blog.csdn.net/sherlock_homles/article/details/82833414
push_back函数在vector的最后添加元素，会重新申请大小
