#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h>

using namespace std;

int main() {
    
    // Create Json::StyledWriter object to write a JSON file
    Json::StyledWriter styled;

    // JSON content Holder
    Json::Value countriesPopulation;  

    // Add china to countriesPopulation
    countriesPopulation["countries"]["China"]["population"] = 1415045928;
    countriesPopulation["countries"]["China"]["population_percentage_growth_rate"] = 0.39;
    countriesPopulation["countries"]["China"]["country_area_km_square"] = 9706961;

    // Add india to countriesPopulation
    countriesPopulation["countries"]["India"]["population"] = 1354051854;
    countriesPopulation["countries"]["India"]["population_percentage_growth_rate"] = 1.11;
    countriesPopulation["countries"]["India"]["country_area_km_square"] = 3287590;

    // Add france to countriesPopulation
    countriesPopulation["countries"]["France"]["population"] = 65233271;
    countriesPopulation["countries"]["France"]["population_percentage_growth_rate"] = 0.39;
    countriesPopulation["countries"]["France"]["country_area_km_square"] = 551695;

    // Add algeria to countriesPopulation
    countriesPopulation["countries"]["Algeria"]["population"] = 42008054;
    countriesPopulation["countries"]["Algeria"]["population_percentage_growth_rate"] = 1.67;
    countriesPopulation["countries"]["Algeria"]["country_area_km_square"] = 2381741;

    // Create a formatted JSON string
    string sStyled = styled.write(countriesPopulation);

    // Write JSON string into a file
    ofstream out("world_population.json", ofstream::out); 
    out << sStyled;
    out.close();    
 
    return 0;
}
