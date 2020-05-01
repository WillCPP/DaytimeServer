#ifndef UDP_SERVER_H
#define UDP_SERVER_H

#include <boost/asio.hpp>

class UDPServer {
public:
	UDPServer(boost::asio::io_service& io_service);

private:
	boost::asio::ip::udp::socket socket;
  	boost::asio::ip::udp::endpoint remote_endpoint;
  	std::array<char, 1> recv_buffer;

	void start_receive();

	void handle_receive(const std::error_code& error, std::size_t /*bytes_transferred*/);

  	void handle_send(std::shared_ptr<std::string> /*message*/, const std::error_code& /*error*/, std::size_t /*bytes_transferred*/);
};

#endif