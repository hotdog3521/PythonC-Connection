
import zmq

class test(object):
	context = zmq.Context()
	socket = context.socket(zmq.REQ)
	def __init__(self, socket):
		self.socket = socket
		self.socket.connect("tcp://localhost:5555")

	def sendMessage(self, message):
		socket.send(message)
	
context = zmq.Context()
socket = context.socket(zmq.REQ)

import json
row = [1,2,3,4,5,6]
row_json = json.dumps(row)
print row_json


hello = test(socket)
hello.sendMessage(row_json)
print "-------"

message = socket.recv()
print message

vector = []
index = 1;
for x in message:
	if index % 2 == 0:
		vector.append(x)
	index += 1

for y in vector:
	print y



"""

context = zmq.Context()

# Socket to talk to server
print ("Connecting to hello world server...")
socket = context.socket(zmq.REQ)
socket.connect("tcp://localhost:5555")

# Do 10 requests, waiting each time for a response
for request in range(10):
	print ("Sending request %s ..." % request)
	socket.send(b"Hello")

	# Get the reply
	message = socket.recv()
	print("Received reply %s [ %s ]" % (request, message))

socket.close()
"""