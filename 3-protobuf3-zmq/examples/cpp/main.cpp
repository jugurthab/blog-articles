/* 
   ------------------------ main.cpp -----------------------
   Google Protocol Buffer Serializer and Deserializer Example
*/

#include <iostream>
#include <string>
#include "petIdentity.pb.h"
using namespace std;


int main(){
    GOOGLE_PROTOBUF_VERIFY_VERSION; // it's recommanded by Google to make sure that the correct protobuf library is loaded
    
    /* ------------------------------------------------------
       ------------ Protobuf serialization process ----------
       ------------------------------------------------------
    */
    com_company_pet::PetIdentity petIdentity; // Create an instance of PetIndentity

    petIdentity.set_pet_name("Oscar"); // Set pet name to Oscar
    petIdentity.set_pet_age(2); // Set pet age to 2 years
    petIdentity.set_pet_gender(false); // Set gender to female

    string petIdentitySerialized;

    petIdentity.SerializeToString(&petIdentitySerialized);    

    cout << "Serialized protobuf data : " << petIdentitySerialized << endl;
 

    /* ------------------------------------------------------
       ----------- Protobuf deserialization process ---------
       ------------------------------------------------------
    */

    com_company_pet::PetIdentity petIdentityDeserialized;
    
    petIdentityDeserialized.ParseFromString(petIdentitySerialized);
    cout << "\nDeserializing the data" << endl;
    cout << "Cat-Name : " << petIdentityDeserialized.pet_name() << " <===> Cat-age : " << petIdentityDeserialized.pet_age() << " <===> Cat-gender : " << (petIdentityDeserialized.pet_gender()?"male":"female") << endl; 




    google::protobuf::ShutdownProtobufLibrary(); // free all resources
    return 0;    
}
