# 多线程编程

多线程是日常编码中经常遇到的场景，多线程的使用在多核处理器的平台上可以很大程度地提高程序运行效率。

多线程的学习首先需要从线程的创建与销毁开始，但更重要的是掌握线程同步/互斥的概念。比如在12306平台上，唯一的一张余票如果同时有多个用户进行购买，我们应当怎样避免错误的发生（两个人都买到了票，那就是超售了；或者后下单的人买到了票）？

+ 动手做
使用Boost.Thread库实现一个线程安全的队列，每当其中元素个数发生变化时，在控制台上打印出Push/Pop的元素以及进行操作的线程ID。其接口已定义在了[thread_safe_queue.h](./thread_safe_queue.h)头文件中，请完成其实现。另外创建五条线程，两条Push，三条Pop，看看运行时会发生什么？
关于Boost.Thread库如何使用，可以参考： 
[Boost Library](../Third_Party_Library/TheBoostC++Libraries.CHM), 
[Boost Thread](https://www.boost.org/doc/libs/1_68_0/doc/html/thread.html)
注意事项：
在编写代码时，尽量减少运行时变量之间的拷贝（比如形参与实参之间的拷贝）。
