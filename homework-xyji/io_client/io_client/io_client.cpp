#include <boost/asio.hpp> 
#include <boost/array.hpp> 
#include <iostream> 
#include <string> 

boost::asio::io_service io_service; 
boost::asio::ip::tcp::resolver resolver(io_service); 
boost::asio::ip::tcp::socket sock(io_service); 
boost::array<char, 4096> buffer; 

void read_handler(const boost::system::error_code &ec, std::size_t bytes_transferred) 
{ 
  if (!ec) 
  { 
	std::cout << "Message:";
    std::cout << std::string(buffer.data(), bytes_transferred) << std::endl; 
    sock.async_read_some(boost::asio::buffer(buffer), read_handler); 
  } 
} 

void connect_handler(const boost::system::error_code &ec) 
{ 
  if (!ec) 
  { 
	std::cout << "Connectting successfully!"<<std::endl;
	std::cout << "Receive from server:" << sock.remote_endpoint().address() << std::endl;
	sock.async_read_some(boost::asio::buffer(buffer), read_handler); 
  } 
} 

void resolve_handler(const boost::system::error_code &ec, boost::asio::ip::tcp::resolver::iterator it) 
{ 
  if (!ec) 
  { 
    sock.async_connect(*it, connect_handler); 
  } 
} 

int main() 
{
	std::cout<<"Client"<<std::endl;
	boost::asio::ip::tcp::resolver::query query("10.164.127.186", "80"); //my IPv4 address:10.164.127.186
	resolver.async_resolve(query, resolve_handler); 
	try
    {
		io_service.run(); 
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
	//io_service.run(); 
} 