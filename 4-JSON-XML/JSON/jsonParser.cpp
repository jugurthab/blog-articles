#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h>

using namespace std;

int main() {
    // Create an input file stream and load games.json's content
    ifstream ifs("game.json");

    // Create a JSON Reader
    Json::Reader reader;
    Json::Value jsonContentHolder;
    // Parse JSON and load result into obj
    reader.parse(ifs, jsonContentHolder);

    // Display Parser content
    cout << "Game : " << jsonContentHolder["game_name"].asString() << endl;
    cout << "Release Year : " << jsonContentHolder["release_year"].asUInt() << endl;
    cout << "Company : " << jsonContentHolder["company"].asString() << endl;
    
    // create Json::Value object to parse obj["developers"]
    const Json::Value& developers = jsonContentHolder["developers"];
    for (int i = 0; i < developers.size(); i++)
        cout << "----------------- developer : " << developers[i]["developer"].asString() << endl;

    return 0;
}
