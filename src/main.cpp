#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include "Superhero.h"
#include "my_hash.h"

Superhero superheroBuilder(std::string &input);

int main(int argc, char** argv){
  std::ifstream in{"marvel-wikia-data.csv"};

  std::vector<Superhero>* heroDB = new std::vector<Superhero>;

  if(not in){
    std::perror("File Error");
    return 0;
  }

  std::string input;
  
  //Get rid of the first line 
  std::getline(in,input);
 
  while(std::getline(in,input)){
          Superhero hero = superheroBuilder(input);

        heroDB->push_back(hero);
    }

    for(auto hero_it(heroDB->begin()); hero_it < heroDB->end(); hero_it++){
        Superhero output(*hero_it);
        std::cout << output.toString() << std::endl;
    }


}


Superhero superheroBuilder(std::string &input){
    std::string params[13];

    std::stringstream data(input);

    for(int i(0); i < 13; i++) {
        std::getline(data, params[i], ',');
        if(params[i].front() == '"'){
            while(params[i].back() != '"') {
                std::string temp;
                std::getline(data,temp,',');
                params[i] +=temp;
            }
        }}

    int page_id = std::stoi(params[0]);
    const std::string name(params[1]);
    const std::string urlslug(params[2]);
    const std::string id(params[3]);
    const std::string alignment(params[4]);

    char eye_color('V');
    if(!params[5].empty())
        eye_color = params[5].at(0);

    char hair_color('V');
    if(!params[6].empty())
        hair_color = params[6].at(0);

    char sex('U');
    if(!params[7].empty())
        sex = params[7].at(0);

    const std::string gsm(params[8]);

    int appearances(1);
    if(!params[10].empty())
        appearances = std::stoi(params[10]);

    const std::string first_apperance(params[11]);

    int year(0);
    if(!params[12].empty())
        year = std::stoi(params[12]);

    bool alive(true);
    if( !params[9].empty() && params[9].at(0) == 'D')
        alive = false;

    Superhero hero(page_id, name, urlslug, id, alignment, eye_color,
                   hair_color, sex, gsm, alive, appearances, first_apperance, year);

    return hero;
}

