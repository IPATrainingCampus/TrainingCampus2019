# 进程间通信

我们的软件系统不是一个简单的可执行程序，而是多个可执行程序同时运作的复杂软件系统，各个可执行程序之间都是通过TCP通信来完成交互。

+ 动手做
> 编写两个可执行的控制台程序，在运行时单向地发送消息，接收方将收到的消息通过控制台打印出来。
> TCP/IP通信使用Boost::Asio库实现，关于Boost::Asio如何使用，可以参考以下链接：
> [Boost Library](../Third_Party_Library/TheBoostC++Libraries.CHM),
> [Boost.Asio](https://www.boost.org/doc/libs/1_67_0/doc/html/boost_asio.html)