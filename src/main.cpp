#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include "Superhero.h"
#include "my_hash.h"

 /**********************************************************************
 * The main.cpp file uses imperitive programming to declare three
 * my_hash structures and use them individually to test all three hash
 * functions individually of each other. The program starts by loading
 * the database file for each line of the database file the elements 
 * of the line are parsed and then used to construct a Superhero object
 * from there the object is then passed into all three my_hash data
 * structrues where for each structure, a different hash function is
 * used to insert the object. Collisions for each my_hash is tracked 
 * everytime an item is inserted. When all of the items have been 
 * successfully inserted into the my_hash structures, a report on the 
 * total number of collisons is written to a file and the program ends.
 *
 * Author: David Baas
 * Version: 1.0
 **********************************************************************/ 
Superhero superheroBuilder(std::string &input);
void writeFile(int &collision1, int &collision2, int &collision3, int &collision4);


int main(int argc, char** argv){
  std::ifstream in{"marvel-wikia-data.csv"};

  //Stop the program if there is a file error. 
  if(not in){
    std::perror("File Error");
    return 0;
  }
  //Four my_hash instances to store the superheros.
  //One for each hash function created. 
  my_hash<Superhero> hashmap1;
  my_hash<Superhero> hashmap2;
  my_hash<Superhero> hashmap3;
  my_hash<Superhero> hashmap4;

  //Four int vars to track collisions for each
  //my_hash variable. 
  int collision1(0);
  int collision2(0);
  int collision3(0);
  int collision4(0);

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
    
    if(hashmap4.insert(hero, hashmap4.hash4(hero.getName())))
      ++collision4;
  }
  
  writeFile(collision1,collision2,collision3,collision4); 
  
  return 0;
}

 /***********************************************************************
 * The superheroBuilder function takes a string that represents one line
 * of the file and parses it into an array of strings. From there, each
 * string is parsed to each variable that creates a Superhero and in 
 * turn, those are passed into a Superhero consructor which is returned
 * to the main method. The data coming from the database file isn't 
 * uniform therefore certian variables have checks performed on them 
 * to ensure all of the data is created correctly.
 *
 * param: input a string that is a line of the database file
 * return: A Superhero Object. 
 **********************************************************************/ 
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

/***********************************************************************
 * The writeFile function takes all of the collison values as input
 * parameters and writes them to a file with formatting which talks 
 * about how many collisons a given hash created.
 *
 * param: collision1 int that is the number of collisions for hash1
 * param: collision2 int that is the number of collisions for hash2
 * param: collision3 int that is the number of collisions for hash3
 * param: collision4 int that is the number of collisions for hash4
***********************************************************************/ 
void writeFile(int &collision1, int &collision2, int &collision3, int &collision4){
  std::ofstream outputFile("README.md");

  outputFile << "The number of collisions for hash1: " << collision1 << " Collisions" << std::endl;
  outputFile << std::endl << "The number of collisions for hash2: " << collision2 << " Collisions" << std::endl;
  outputFile << std::endl << "The number of collisions for hash3: " << collision3 << " Collisions" << std::endl;
  outputFile << std::endl << "The number of collisions for hash4: " << collision4 << " Collisions" << std::endl;
 
  outputFile.close();
  return;
}
