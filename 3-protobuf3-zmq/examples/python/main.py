# main.py
# import petIdentity_pb2 module
import petIdentity_pb2
import sys


print("-------- Serializing data -------")
# Create an instance of PetIdentity
petIdentity = petIdentity_pb2.PetIdentity()


# Fill PetIdentity instance
petIdentity.pet_name = "Oscar";
petIdentity.pet_age = 2;
petIdentity.pet_gender = True;

# Serialize PetIdentity instance using protobuf
petIdentitySerialized = petIdentity.SerializeToString()

# display serialized data
print("Serialized Data : " + petIdentitySerialized) 

print("") # add empty line

print("-------- Deserializing data -------")
# Create an instance of PetIdentity for deserialization
petIdentityDeserialized = petIdentity_pb2.PetIdentity()

# Deserialize Serialized data
petIdentityDeserialized.ParseFromString(petIdentitySerialized)

# Display deserialized data
print("Cat-Name : " + petIdentityDeserialized.pet_name + " <===> Cat-age : " + str(petIdentityDeserialized.pet_age) + " <===> Cat-gender : " + ("male" if petIdentityDeserialized.pet_gender  else "female"))
