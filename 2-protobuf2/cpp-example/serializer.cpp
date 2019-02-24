#include <iostream>
#include <fstream>
#include <string>
#include "bodyMassIndex.pb.h"
using namespace std;


int main(){
    GOOGLE_PROTOBUF_VERIFY_VERSION; // it's recommanded by Google to make sure that the correct protobuf library is loaded

    com_company_bodyMassIndex::BodyMassIndex bmi; // Create an instance of BodyMassIndex

    bmi.set_height(1.75); // Set the height
    bmi.set_weight(60); // Set the weight

    // Create a output file stream (in order to save BodyMassIndex instance)
    fstream outFileStream("bmi", ios::out | ios::trunc | ios::binary);

    if (outFileStream) {
      bmi.SerializeToOstream(&outFileStream); // Serialize bmi and save it
    } else
        cout << "file error"  << endl;
    google::protobuf::ShutdownProtobufLibrary(); // free all resources
    return 0;    
}
