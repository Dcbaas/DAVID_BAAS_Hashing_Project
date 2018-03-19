#ifndef __H_SUPERHERO_
#define __H_SUPERHERO_

#include <string>
/**********************************************************************
 * The Superhero Class is an ADT that contians data about a Superhero
 * from the Marvel universe. It contains data that ranges from the
 * name of the superhero to knowing their first appearance to knowing 
 * thier hair color.
 *
 * Author: David Baas
 * Version: 3/5/2018
 *********************************************************************/
class Superhero{

public:
 /*********************************************************************
 * The contructor of the Superhero class initializes all of the 
 * variables. 
 *********************************************************************/
  Superhero(int page_id, const std::string &name, const std::string &urlslug, const std::string &id,
              const std::string &alignment, char eye_color, char hair_color, char sex, const std::string &gsm,
              bool alive, int appearances, const std::string &first_apperance, int year);  
 /*********************************************************************
 * The toString function prints a string literal of the superhero.
 *********************************************************************/ 
  std::string toString();

 /*********************************************************************
 * The getName method returns the name of the superhero. This is used
 * for creating a hash function for the rest of the program.
 *********************************************************************/
  std::string getName() const;

private:

  int page_id;

  std::string name;

  std::string urlslug;

  std::string id;

  std::string alignment;

  char eye_color;

  char hair_color;

  char sex;

  std::string gsm;

  bool alive;

  int appearances;

  std::string first_apperance;

  int year;
};

#endif
