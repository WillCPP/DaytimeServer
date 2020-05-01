#ifndef DAYTIME_PROTOCOL_H
#define DAYTIME_PROTOCOL_H

#include <string>

using namespace std;

class DaytimeProtocol {
public:
	static string make_daytime_string();
private:
	DaytimeProtocol();
};

#endif