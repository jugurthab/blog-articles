import sys
import zmq

portPublisher = "5580"

# Create an zmq context
context = zmq.Context()
# create a subscriber socket 
socket = context.socket(zmq.SUB)

print("Waiting to connect to remote publisher...")

# subscriber must connect to publisher
socket.connect("tcp://localhost:%s" % portPublisher)


# Choose a topic 
topicFilter = "/test"
socket.setsockopt_string(zmq.SUBSCRIBE, topicFilter)

while True:
    # get received data
    dataReceived = socket.recv_string()
    # parse received data using comma separator
    topic, msgContent = dataReceived.split(",")
    # display topic name and message content 
    print("Topic : " + topic + " ==> Message content : " + msgContent)
