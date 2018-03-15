#ifndef __H_SUPERHERO_
#define __H_SUPERHERO_

#include <string>

class Superhero{

public:

  Superhero(int page_id, const std::string &name, const std::string &urlslug, const std::string &id,
              const std::string &alignment, char eye_color, char hair_color, char sex, const std::string &gsm,
              bool alive, int appearances, const std::string &first_apperance, int year);  

  std::string toString();

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
