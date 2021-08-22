
/*
 * 链接：https://www.zhihu.com/question/35614219/answer/1477686611
 * const是变量类型名的一部分，即 part of type name，一个名字叫“const T”或者“T const”的类型，
 * 和T这个类型本身处于一种平级的关系，和T不同的就在于这个类型的对象自产生后就不能再更改了。
 * constexpr是声明的一部分，即 part of a declaration，他不是变量类型的一部分。
 * 当他出现在一个变量的声明中时，他要求编译器在编译期间就初始化并确定下来这个变量（否则编译报错）；
 * 当他出现在一个函数的声明中时，他要求至少有一条return路径可以（但不是必须）在编译中确定下来，
 * 即返回的是编译期常量。
 * 二者的联系就在于，在使用constexpr声明一个类型为T的变量时，constexpr会自动把这个变量定义为const T类型。
 * 即constexpr在完成它本职工作（告诉编译器这是个编译期常量）的同时，还把原来的T类型改为了const T类型。
 * 
 * 参考资料：
 * constexpr specifier (since C++11)
 * https://en.cppreference.com/w/cpp/language/constexpr
 * 
 * cv (const and volatile) type qualifiers
 * https://en.cppreference.com/w/cpp/language/cv
 */