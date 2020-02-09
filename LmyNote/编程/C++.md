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

4、boost::intrusive_ptr 原理介绍
https://www.cnblogs.com/edwardlost/archive/2011/02/17/1957019.html

https://blog.csdn.net/harbinzju/article/details/6754646
T* get() const;
这个成员函数返回保存的指针。它可用于你需要一个裸指针的时候，即使保存的指针为空也可以调用。这个函数不会抛出异常。

普通函数
template <class T> T* get_pointer(const intrusive_ptr<T>& p);
这个函数返回 p.get(), 它主要用于支持泛型编程。[10] 它也可以用作替代成员函数 get, 因为它可以重载为可以与裸指针或第三方智能指针类一起工作。有些人宁愿用普通函数而不用成员函数。[11] 这个函数不会抛出异常。

这种想法是出于以下原因，使用智能指针的成员函数时，很难分清它是操作智能指针还是操作它所指向的对象。例如， p.get() 和 p->get() 有完全不同的意思，不认真看还很难区别，而 get_pointer(p) 和 p->get() 则一看就知道不一样。对于你来说这是不是问题，主要取决于你的感觉和经验。

在以下情况时使用 intrusive_ptr ：
你需要把 this 当作智能指针来使用。
已有代码使用或提供了插入式的引用计数。
智能指针的大小必须与裸指针的大小相等。

5、dynamic_cast
const unit* u = dynamic_cast<const unit*>(base_u);
https://baike.baidu.com/item/dynamic_cast/4473047?fr=aladdin
dynamic_cast是将一个基类对象指针（或引用）转换到继承类指针，dynamic_cast会根据基类指针是否真正指向继承类指针来做相应处理。
dynamic_cast运算符可以在执行期决定真正的类型。如果 downcast 是安全的（也就说，如果基类指针或者引用确实指向一个派生类对象）这个运算符会传回适当转型过的指针。如果 downcast 不安全，这个运算符会传回空指针（也就是说，基类指针或者引用没有指向一个派生类对象）

另外要注意：B 要有虚函数，否则会编译出错；static_cast则没有这个限制。
这是由于运行时类型检查需要运行时类型信息，而这个信息存储在类的虚函数表（关于虚函数表的概念，详细可见<Inside c++ object model>）中，只有定义了虚函数的类才有虚函数表，没有定义虚函数的类是没有虚函数表的。

dynamic_cast 转换
https://zh.cppreference.com/w/cpp/language/dynamic_cast
若转型成功，则 dynamic_cast 返回 新类型 类型的值。若转型失败且 新类型 是指针类型，则它返回该类型的空指针。若转型失败且 新类型 是引用类型，则它抛出与类型 std::bad_cast 的处理块匹配的异常。


static_cast和dynamic_cast详解
https://blog.csdn.net/u014624623/article/details/79837849
static_cast和C的强制转化很像，但是不能转换掉expression的const、volatile、或者__unaligned属性

dynamic_cast转换方式：
dynamic_cast< type* >(e)
　type必须是一个类类型且必须是一个有效的指针
dynamic_cast< type& >(e)
type必须是一个类类型且必须是一个左值
dynamic_cast< type&& >(e)
type必须是一个类类型且必须是一个右值

6、C++ | vector 类中的 push_back( ) 函数 、（添加和删除函数）
https://blog.csdn.net/sherlock_homles/article/details/82833414
push_back函数在vector的最后添加元素，会重新申请大小

7\C++的继承
https://blog.csdn.net/qq_27563511/article/details/80934742

8\对象创建
https://www.cnblogs.com/qiumingcheng/p/7819639.html

9、构造函数和析构函数
https://www.runoob.com/cplusplus/cpp-constructor-destructor.html

C++11 继承构造函数
https://blog.csdn.net/K346K346/article/details/81703914

析构函数
https://www.cnblogs.com/liuzhenbo/p/11214276.html
