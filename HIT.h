#ifndef HIT_H_
#define HIT_H_
#include "HIT.h"


//include these for socket programming
#include "zmq.hpp"
#include <string>
#include <iostream>
#ifndef _WIN32
#include <unistd.h>
#else
#include <windows.h>

#define sleep(n)  Sleep(n)
#endif
// This is everything that needs to be included if I use a socket
// // Add the "Ws2_32.lib" to the LINKER settings
// #pragma comment(lib, "Ws2_32.lib")

// // STD console header files
// #include <sdkddkver.h>
// #include <conio.h>
// #include <stdio.h>

// // SOCKET header files
// #include <WinSock2.h>
// #include <Windows.h>
// #include <iostream>

// #define SCK_VERSION2 0x0202

class HIT {
private:

	zmq::context_t context;
	zmq::socket_t socket;
	zmq::message_t request;

public:
	HIT() : context(1), socket(context, ZMQ_REP){

	}
    std::vector<int> work();
    void startHIT();

};
#endif