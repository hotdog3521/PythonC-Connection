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

IPC test;

using namespace std;

void a(){
	sleep(10);
	std::vector<int> returnValue = test.getData();
	for(int i = 0; i < returnValue.size(); i++) {
		std::cout<<returnValue[i]<<std::endl;
	}
}

int main () {
	test.startServer();




/*
	if(test.isServerWorking()){
		std::cout<<"working"<<std::endl;;
	}else{
		std::cout<<"not working"<<std::endl;
	}
*/

	return 0;
}