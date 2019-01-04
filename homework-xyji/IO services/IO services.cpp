#include <boost/asio.hpp> 
#include <iostream>
#include <string> 

boost::asio::io_service io_service; 
boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), 80); //初始化，internet网络协议，端口号80
boost::asio::ip::tcp::acceptor acceptor(io_service, endpoint); //协议和端口初始化，等待来自其他pc的传入连接，本服务器IP地址：10.164.36.80
boost::asio::ip::tcp::socket sock(io_service); 
//std::string data1 = "Hello, world!"; //需要发送的信息
//boost::array<char, 4096> buffer; 

void write_handler(const boost::system::error_code &ec, std::size_t bytes_transferred) 
{ 
//	std::cout<<"Message sends successful\r\n\r\n";
} 

void accept_handler(const boost::system::error_code &ec) 
{ 
  if (!ec) 
  { 
	std::cout<<"Connectting successfully!"<<std::endl;
	std::cout<<"Client:";
	std::cout << sock.remote_endpoint().address() << std::endl;//client ip information
	
	for(;;)
	{
		std::cout<<"Input the message to the client('exit' means exit):";
		std::string data_str;                    //the message needs to be sent，(string)
		getline(std::cin,data_str);
		char *data_char=(char *)data_str.c_str();//message:string to char
		if(strcmp(data_char,"exit"))             //not exit
		{
			boost::asio::async_write(sock, boost::asio::buffer(data_char,strlen(data_char)), write_handler);
			std::cout<<"Message sends successful\r\n";
		}
		else                                     //exit
		{break;}
	} 
  }
} 

void accept()
{
    acceptor.async_accept(sock,accept_handler);
}

int main() 
{ 

    std::cout << "Server" << std::endl;
	//try
	//{
		acceptor.listen(); 
		accept();
		io_service.run(); 
    //}
	//catch (std::exception& e)
 //   {
 //       std::cout << e.what() << std::endl;
 //   }
	//int c;
	//std::cin>>c;
	getchar();
	return 0;
} 