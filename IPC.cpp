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
      std::string str = std::string(static_cast<char*>(request.data()), request.size());
      
      //Parse data from python (getting number) and make it vector
      //so that Hit and Run can making data with that easily

      std::vector<int> data;
      for(std::string::iterator it = str.begin(); it != str.end(); ++it) {
          if(isdigit(*it)) {
              int element = *it - '0';
              data.push_back(element);
          }
      }
      //sending vector to hit and run





      //end of sending vector to hit and run

      //getting vector from hit and run

      //end of getting vector from hit and run


      //make string to send measued data from HIT and RUN 
      //make it string and send it to python and python can parse it easily
      std::stringstream ss;
      for(int i = 0; i < data.size(); i++) {
        if(i != data.size()-1){
            ss << data[i] << ",";
        }else{
            ss << data[i];
        }
      }
      // Do some 'work'
      std::string outMessage;
      ss >> outMessage;
      
      sleep(1);

      // Send the string to python
      zmq::message_t reply (outMessage.size());
      const void * a = outMessage.c_str();
      memcpy (reply.data(), a, outMessage.size());
      socket.send(reply);
      
    }

}

/**
  * isServerWorking
  * Return true if we are connected to the Python server then send
  * that answer to establishConnection in HitRun.
  */ 
bool IPC::isServerWorking(){

    //sending message
    std::string heartbeat = "heartbeat";
    zmq::message_t H_Message (heartbeat.size());
    const void * a = heartbeat.c_str();
    memcpy (H_Message.data(), a, heartbeat.size());
    socket.send(H_Message);


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
  //when HIT AND RUN send the data  
}