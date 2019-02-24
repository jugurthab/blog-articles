import caesarCipher_pb2
import zmq
import time

def encryptCaesarCipher(plainText, shiftKey):
    cipherText = ""    
    for character in plainText:
        # shift every letter in message by 3
        cipherText += chr(ord(character) + shiftKey) 
    return cipherText

def serializeToProtobuf(msg, caesarCipherProto, shiftKey):
    # fill caesarCipherProto
    caesarCipherProto.caesar_cipher_text = encryptCaesarCipher(msg, shiftKey)
    caesarCipherProto.shift_key = shiftKey
    # return serialized protobuf caesarCipherProto
    return caesarCipherProto.SerializeToString()

# messages to send
messagesPlainText = ["hello world!", "programming is awesome", "computer science"]
caesarCipherProto = caesarCipher_pb2.CaesarCipher()


portPublisher = "5580"
# create an zmq context
context = zmq.Context()
# create a publisher socket
socket = context.socket(zmq.PUB)
# Bind the socket at a predefined port  
socket.bind("tcp://*:%s" % portPublisher)


while True:
    for msg in messagesPlainText:
        # serialize caesarCipherProto into protobuf format
        dataSerialized = serializeToProtobuf(msg, caesarCipherProto, 3)
        print("Plain Text : " + msg + " <===> Caesar cipher : " + caesarCipherProto.caesar_cipher_text)
        print("Protobuf message to send : " + str(dataSerialized)) # display caesarCipherProto data
        time.sleep(3)
        socket.send(b""+dataSerialized) # send binary serialized data
        print("---------------------------------")
        print("---------------------------------")
        print("---------------------------------")


