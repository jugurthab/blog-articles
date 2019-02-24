#include <iostream>
#include <tinyxml2.h>

using namespace std;
int main(){

    // create main level XML document container
    tinyxml2::XMLDocument xmlDoc;
        
    // load xml file
    if(xmlDoc.LoadFile("geeks.xml") != tinyxml2::XML_SUCCESS)
    {
        cerr << "loading XML failed" << "\n";
        return false;
    }

    // Get reference to root element "geeks"
    tinyxml2::XMLNode* pRoot = xmlDoc.RootElement();
    // Check if pRoot is non empty
    if (pRoot == NULL) return tinyxml2::XML_ERROR_FILE_READ_ERROR;    
    // Display root node    
    cout << "Root Element : " << pRoot->Value() << endl;
    


    // Traverse root element to get it's children    (geek tags in our example) 
    for(tinyxml2::XMLElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
    {      
        cout << "TAG : " << e->Value() << endl;

        // Traverse each geek tag and read it's content
        for(tinyxml2::XMLElement* subEl = e->FirstChildElement(); subEl != NULL; subEl = subEl->NextSiblingElement()){
       
                if(subEl->Value() == string("name"))
                    cout << "Name : " << subEl->GetText() << endl;
                else if(subEl->Value() == string("year_of_birth"))
                    cout << "Year of birth : " << subEl->GetText() << endl;
                else if(subEl->Value() == string("country_of_birth"))
                    cout << "Country of birth : " << subEl->GetText() << endl;
                else if(subEl->Value() == string("works")){
                    cout << subEl->Value() << " : ";                    
                    for(tinyxml2::XMLElement* works = subEl->FirstChildElement(); works != NULL; works = works->NextSiblingElement()){
                            cout << works->GetText() << " \t";                    
                    }
                    cout << endl;
                }
        }
        cout << "------------------------------------" << endl;    
    }

    return 0;
}

