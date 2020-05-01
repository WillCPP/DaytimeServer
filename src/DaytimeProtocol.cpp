#include "DaytimeProtocol.h"
#include <string>

using namespace std;

string DaytimeProtocol::make_daytime_string() {
  time_t now = time(0);
  return ctime(&now);
}