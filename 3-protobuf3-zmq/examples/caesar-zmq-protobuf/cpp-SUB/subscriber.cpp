#include <iostream>
#include <zmq.hpp>
#include <string>
#include "caesarCipher.pb.h"

using namespace std;

void DecryptCipherDisplay(std::string cipherText, int cipherKey);

int main(){
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    /* -------------------------- */
    /* Create a subscriber socket */
    /* -------------------------- */
    zmq::context_t context(1);
    zmq::socket_t subSocket(context, ZMQ_SUB);
    // Connect to pyton's publisher binding port
    subSocket.connect("tcp://localhost:5580"); 
  
    cout << "------ Subscriber running ------\n" << endl;
    // Listen for all topics
    subSocket.setsockopt(ZMQ_SUBSCRIBE, "" , strlen(""));
    // Instantiate a CaesarCipher to be filled with received data
    com_company_caesar::CaesarCipher caesarCipher; 
    while(true) {
        
        zmq::message_t zmqMessageReceived; // used to hold zmq received data
        subSocket.recv(&zmqMessageReceived); // Blocks until data reception
        // Map zmq data holder to string
        std::string messageReceived(static_cast<char*>(zmqMessageReceived.data()), zmqMessageReceived.size());
        // Deserialize protobuf data and store them into caesarCipher
        caesarCipher.ParseFromString(messageReceived);
         
        // Descrypt caesar cipher and display received string
        DecryptCipherDisplay(caesarCipher.caesar_cipher_text(), caesarCipher.shift_key());
           
        cout << "-------------------------------------" << endl;
    }        

    google::protobuf::ShutdownProtobufLibrary();

    return 0;
}


void DecryptCipherDisplay(std::string cipherText, int cipherKey){
    string::iterator it;
    string PlainTextRecovered;
    for (it = cipherText.begin(); it < cipherText.end(); it++) 
        PlainTextRecovered += static_cast<char>(*it - cipherKey); // reverse caesar cipher
    cout <<  "Reversing caesar cipher : "<< PlainTextRecovered << endl;
}
