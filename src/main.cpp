#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include "Superhero.h"
#include "my_hash.h"

Superhero superheroBuilder(std::string &input);
void writeFile(int &collision1, int &collision2, int &collision3);
void writeDistribution(std::vector<int> data, std::string filename);
int main(int argc, char** argv){
  std::ifstream in{"marvel-wikia-data.csv"};

  //Stop the program if there is a file error. 
  if(not in){
    std::perror("File Error");
    return 0;
  }
  //Three my_hash instances to store the superheros.
  //One for each hash function created. 
  my_hash<Superhero> hashmap1;
  my_hash<Superhero> hashmap2;
  my_hash<Superhero> hashmap3;

  //Three int vars to track collisions for each
  //my_hash variable. 
  int collision1(0);
  int collision2(0);
  int collision3(0);

  //String to read the input from the file.
  std::string input;
  
  //Get rid of the first line 
  std::getline(in,input);
 
  //For every line in the file create a Superhero and add it to all
  //three my_hash variables while also checking for collisions.
  while(std::getline(in,input)){
    Superhero hero = superheroBuilder(input);

    if(hashmap1.insert(hero, hashmap1.hash1(hero.getName())))
      ++collision1;

    if(hashmap2.insert(hero, hashmap2.hash2(hero.getName())))
      ++collision2;
 
    if(hashmap3.insert(hero, hashmap3.hash3(hero.getName())))
      ++collision3;
  }
  
  writeFile(collision1,collision2,collision3);

  writeDistribution(hashmap1.vectorSizes(), "Hash1_Dist.csv");
  writeDistribution(hashmap2.vectorSizes(), "Hash2_Dist.csv");
  writeDistribution(hashmap3.vectorSizes(), "Hash3_Dist.csv"); 
  
  return 0;
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

void writeFile(int &collision1, int &collision2, int &collision3){
  std::ofstream outputFile("README.md");

  outputFile << "The number of collisions for hash1: " << collision1 << " Collisions" << std::endl;
  outputFile << std::endl << "The number of collisions for hash2: " << collision2 << " Collisions" << std::endl;
  outputFile << std::endl << "The number of collisions for hash3: " << collision3 << " Collisions" << std::endl;

 
  outputFile.close();
  return;
}

void writeDistribution(std::vector<int> data, std::string filename){
  std::ofstream outputFile(filename);

  for(unsigned int i{-1}; i < data.size();++i)
    outputFile << i << "," << data[i] << std::endl;

  outputFile.close();
  return;
}
