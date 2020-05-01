#include <boost/asio.hpp>
#include <iostream>
#include "UDPServer.h"

using namespace std;

int main() { 

	try {
		boost::asio::io_service io_service;
		UDPServer server(io_service);
		io_service.run();
	} catch (exception& e) {
		cerr << e.what() << "\n";
	}
	
	return 0; 
}