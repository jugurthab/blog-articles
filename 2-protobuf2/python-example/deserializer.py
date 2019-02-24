import humainIdentity_pb2 # import generated class (required to deserialize)
import sys


def getGender(humainGender):
    if humainGender:
        return "Male"
    else:
        return "Female"


def parseDeserializedData(hId):
    print("Full Name : " + hId.humain_first_name + " " + hId.humain_last_name)
    print("Gender : " + getGender(hId.humain_gender))
    print("Age : " + str(hId.humain_age))
    print("Profession : "+ hId.humain_profession)

humainId = humainIdentity_pb2.HumainIdentityDescription() # Create object Instance 

fileInputStream = open("humain_id", "rb")
humainIdSerialized = fileInputStream.read() # Read data from file
humainId.ParseFromString(humainIdSerialized) # deserialize data read from file using ParseFromString method
fileInputStream.close()

parseDeserializedData(humainId) # display deserialized data


