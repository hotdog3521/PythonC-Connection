all: zmqC

zmqC: zmqC.cpp
		g++ -g zmqC.cpp IPC.cpp -o server -lzmq
clean:
		rm -rf *o zmqC
