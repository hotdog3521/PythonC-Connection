//
//	Hello World server in C++
//	Binds REP socket to tcp://*:5555
//	Expects "Hello" from client, replies with "World"
//
#include "zmq.hpp"
#include <string>
#include <iostream>
#ifndef _WIN32
#include <unistd.h>
#include "IPC.h"
#include "HIT.h"
#else
#include <windows.h>
#include <thread>

#define sleep(n)	Sleep(n)
#endif



int main () {
	IPC test;
	test.startServer();

	return 0;
}