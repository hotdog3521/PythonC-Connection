#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include <string>
#include <sstream>
//#include <json/json.h>

#include "IPC.h"
#include "zmq.hpp"
#include <string>
#include <iostream>
#ifndef _WIN32
#include <unistd.h>
#else

#define sleep(n)  Sleep(n)
#endif

void IPC::startServer(){
    socket.bind ("tcp://*:5555");

    while (true) {
      zmq::message_t request;

      // Wait for next request from client
      socket.recv (&request);


      //in case of getting string from the request
      //getting vector object from request
      std::string printout = std::string(static_cast<char*>(request.data()), request.size());
      std::cout<<printout<<std::endl;
      //send the vector to hit and run
      //get the measured data(vector) from it and run
      //
      std::istringstream ss(printout);
      std::string token;

      while(std::getline(ss, token, ',')) {
          std::cout << token << '\n';
      }

      // Do some 'work'
      sleep(1);

      // Send reply back to client
      zmq::message_t reply (19);
      const void * a = printout.c_str();
      memcpy (reply.data(), a, 19);
      socket.send(reply);
    }

}

/**
  * isServerWorking
  * Return true if we are connected to the Python server then send
  * that answer to establishConnection in HitRun.
  */ 
bool IPC::isServerWorking(){

}
/**
  * wasDataReceived
  * Return true if we have received our data from the Python server.
  */
bool IPC::wasDataReceived(){

}
/**
  * getData
  * Get the data from the Python server and store it as a vector.
  * Possibly return the vector.......???
  */
void IPC::getData(std::vector<int> msg){
  //when IPC get the message(data) from python,
  //IPC also process it and send it to HIT AND RUN


}

/**
  * sendData
  * Gets the data from sendVector in HitRun and sends it to the 
  * Python server. 
  */
void IPC::sendData(std::vector<int> msg){
  //when HIT AND RUN send the data from 
}