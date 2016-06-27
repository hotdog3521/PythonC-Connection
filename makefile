all: zmqC

zmqC: zmqC.cpp
		g++ -g -std=c++0x zmqC.cpp IPC.cpp HIT.cpp -o server -lzmq -pthread
clean:
		rm -rf *o zmqC