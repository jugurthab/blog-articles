import humainIdentity_pb2 # import generated class
import sys


humainId = humainIdentity_pb2.HumainIdentityDescription() # Create an objectHumainIdentityDescription
humainId.humain_first_name = "Jugurtha" # Set first name
humainId.humain_last_name = "BELKALEM" # Set last name
humainId.humain_age = 26 # Set age
humainId.humain_gender = True # Set age
humainId.humain_profession = "Embedded System Enginner" # Set profession (this optional, so can be left empty)


humainIdSerialized = humainId.SerializeToString() # Serialize data using SerializeToString method

print(humainIdSerialized) # display serialized data

fileOutputStream = open("humain_id", "wb")
fileOutputStream.write(humainIdSerialized) # save serialized data to a file
fileOutputStream.close()
