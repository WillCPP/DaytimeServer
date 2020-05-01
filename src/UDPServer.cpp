#include "UDPServer.h"
#include "DaytimeProtocol.h"
#include <boost/asio.hpp>
#include <iostream>

using namespace std;

UDPServer::UDPServer(boost::asio::io_service& io_service) : socket(io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 13)) {
	start_receive();
}

void UDPServer::start_receive() {
	socket.async_receive_from(
		boost::asio::buffer(recv_buffer), 
		remote_endpoint,
      	std::bind(
    		&UDPServer::handle_receive,
    		this,
      		std::placeholders::_1, /*error*/
      		std::placeholders::_2  /*bytes_transferred*/
      	)
    );
}

void UDPServer::handle_receive(const std::error_code& error, std::size_t bytes_transferred) {
	if (!error || error == std::errc::message_size) {
		std::shared_ptr<std::string> message(new std::string(DaytimeProtocol::make_daytime_string()));
		cout << *message;
		socket.async_send_to(
			boost::asio::buffer(*message),
			remote_endpoint,
			std::bind(
      			&UDPServer::handle_send,
      			this,
      			message,
        		std::placeholders::_1, /*error*/
        		std::placeholders::_2  /*bytes_transferred*/
        	)
      	);
		start_receive();
	}
}

void UDPServer::handle_send(std::shared_ptr<std::string> message, const std::error_code& error, std::size_t bytes_transferred) {}