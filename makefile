all: zmqC

zmqC: zmqC.cpp
		g++ -g zmqC.cpp IPC.cpp HIT.cpp -o server -lzmq
clean:
		rm -rf *o zmqC
