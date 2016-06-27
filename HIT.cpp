#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

#include "HIT.h"
#include "zmq.hpp"
#include <string>
#include <iostream>
#ifndef _WIN32
#include <unistd.h>
#else
#include <windows.h>
#include <vector>

#define sleep(n)  Sleep(n)
#endif

/**
  * isServerWorking
  * Return true if we are connected to the Python server then send
  * that answer to establishConnection in HitRun.
  */ 
void HIT::startHIT(){

}

/**
  * wasDataReceived
  * Return true if we have received our data from the Python server.
  */
std::vector<int> HIT::work(){

}
