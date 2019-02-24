import zmq
import time

portSubscriberX = "5580"

# create an zmq context
context = zmq.Context()
# create a publisher socket
socket = context.socket(zmq.PUB)
# COnnect the socket to SUBX (broker interface)  
socket.connect("tcp://localhost:%s" % portSubscriberX)

while True:
    # Set the topic on which to publish
    topicFilter = "/test"
    # create some data to send
    msgToPublish = "Hello world Zmq!"

    # print topic and data
    print("%s %s" % (topicFilter, msgToPublish))
    # send topic and message separated by comma 
    # (in order to parse them easily on subscriber side)    
    socket.send_string("%s,%s" % (topicFilter, msgToPublish))
    # slow down sending rate
    time.sleep(1)
