#include <iostream>
#include <tinyxml2.h>

using namespace std;
int main(){
    // Create Main level XML container
    tinyxml2::XMLDocument xmlDoc;
    // Add XML prolog	
    xmlDoc.InsertFirstChild(xmlDoc.NewDeclaration());
    

    // Create XML root node called animals 
    tinyxml2::XMLNode* pRoot = xmlDoc.NewElement("animals");
    // Add pRoot to xmlDoc after prolog    
    xmlDoc.InsertEndChild(pRoot);

    // ************* Add first animal to root node *******
    // create an animal tag
    tinyxml2::XMLNode* animalTag_cat = xmlDoc.NewElement("animal");
    pRoot->InsertFirstChild(animalTag_cat);
    
    // add cat's name and age to animal tag
    tinyxml2::XMLElement* animalName_cat = xmlDoc.NewElement("name");
    // Set animal kind and name
    animalName_cat->SetAttribute("type", "cat");
    animalName_cat->SetText("Oscar"); 
    // Insert cat's name as first child of animal    
    animalTag_cat->InsertFirstChild(animalName_cat);
    // Set cat's age    
    tinyxml2::XMLElement* animalAge_cat = xmlDoc.NewElement("age");
    animalAge_cat->SetText(3); 
    // Insert cat's age as last child of animal    
    animalTag_cat->InsertEndChild(animalAge_cat);   

    // ************* Add second animal to root node *******
    tinyxml2::XMLNode* animalTag_Dog = xmlDoc.NewElement("animal");
    pRoot->InsertEndChild(animalTag_Dog);
    tinyxml2::XMLElement* animalName_dog = xmlDoc.NewElement("name");
    animalName_dog->SetAttribute("type", "dog");
    animalName_dog->SetText("Ace"); 
    animalTag_Dog->InsertFirstChild(animalName_dog);
    tinyxml2::XMLElement* animalAge_dog = xmlDoc.NewElement("age");
    animalAge_dog->SetText(5); 
    animalTag_Dog->InsertEndChild(animalAge_dog);


    // Write xmlDoc into a file
    xmlDoc.SaveFile("animals.xml");
  
    return 0;
}

