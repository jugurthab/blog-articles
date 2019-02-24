import zmq

# Creating zmq context
context = zmq.Context()

# Creating subX interface 
subX = context.socket(zmq.SUB)
subX.bind("tcp://*:5580")

subX.setsockopt_string(zmq.SUBSCRIBE, "")

# Creating the pubX interface
pubX = context.socket(zmq.PUB)
pubX.bind("tcp://*:5581")

print("Proxy is active!")
# connect subX and pubX (creating the proxy)
zmq.device(zmq.FORWARDER, subX, pubX)


# close and free resources
subX.close()
pubX.close()
context.term()
