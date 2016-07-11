//
//	Hello World server in C++
//	Binds REP socket to tcp://*:5555
//	Expects "Hello" from client, replies with "World"
//
#include "zmq.hpp"
#include <string>
#include <iostream>
#include <thread>
#ifndef _WIN32
#include <unistd.h>
#include "IPC.h"
#include "HIT.h"
#else
#include <windows.h>


#define sleep(n)	Sleep(n)
#endif

IPC test;
zmq::context_t context(1);
zmq::socket_t socket(context, ZMQ_REP);

using namespace std;

void a(){
	sleep(10);
	std::vector<int> returnValue = test.getData();
	for(int i = 0; i < returnValue.size(); i++) {
		std::cout<<returnValue[i]<<std::endl;
	}
}
void hitAndRun(){
	socket.bind ("tcp://*:9999");

    while (true) {
      zmq::message_t request;

      // Wait for next request from client
      socket.recv (&request);
      //getting the data from IPC
      std::string received_data = std::string(static_cast<char*>(request.data()), request.size());

      //process it with received_data
      
      sleep(1);
      //wait until getting the signal from hit and run with measured data

      // Send the string to python, outmessage is a string
      std::string to_IPC = "recieved"; 
      zmq::message_t reply (to_IPC.size());
      const void * a = to_IPC.c_str();
      memcpy (reply.data(), a, to_IPC.size());
      socket.send(reply);
      
    }
}
void printout() {
//getting data from IPC and 

	while(true) {
		if(test.wasDataReceived()) {
			//if IPC gets data from python
			//process it
			//have to increment the value so that we can check it
			//string to integer
			int element = std::stoi(test.testingData)+10;
			test.sendData(element);

		}


	}
}
void runServer() {
	test.startServer();
}

int main () {

//test.startServer();
  std::thread first (runServer);
  std::thread second (printout);  

  first.join();
  second.join();               // pauses until second finishes

  std::cout << "foo and bar completed.\n";


	return 0;
}