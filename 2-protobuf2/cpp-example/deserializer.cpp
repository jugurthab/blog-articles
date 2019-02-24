#include <iostream>
#include <fstream>
#include <string>
#include "bodyMassIndex.pb.h"
using namespace std;


int main(){
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    com_company_bodyMassIndex::BodyMassIndex bmi;
    
    // Create a input stream (to read serialized data from a file)
    fstream inFileStream("bmi", ios::in | ios::binary);

    if (inFileStream) {
      bmi.ParseFromIstream(&inFileStream); // Deserialize read data and load them into bmi
    } else
        cout << "file error"  << endl;

    cout << "Height : " << bmi.height() << " ==> Weight : " << bmi.weight() << endl; // display deserialized data

    cout << "BMI = " << bmi.weight() / (bmi.height() * bmi.height()) << endl; // bmi = (weight / (height * height))
    google::protobuf::ShutdownProtobufLibrary();
    return 0;    
}
