#ifndef __H_SUPERHERO_
#define __H_SUPERHERO_

#include <string>

class Superhero{

public:

  Superhero(int page_id, const std::string &name, const std::string &urlslug, const std::string &id,
              const std::string &alignment, char eye_color, char hair_color, char sex, const std::string &gsm,
              bool alive, int appearances, const std::string &first_apperance, int year);  

  void setPageID(int &page_id);

  int getPageID() const;

  void setName(std::string &name);

  std::string getName() const;

  void setUrlSlug(std::string &urlslug);

  std::string getUrlslug() const;

  void setID(std::string &id);

  std::string getID() const;

  void setAlignment(std::string &alignment);

  std::string getAlignment() const;

  void setEyeColor(char &eye_color);

  char getEyeColor() const;

  void setHairColor(char &hair_color);

  char getHairColor() const;

  void setSex(char &sex);

  char getSex() const; //should this be changed to be less dirty?

  void setGSM(std::string &gsm);

  std::string getGSM() const;

  void setAlive(bool &alive);

  bool getAlive() const;

  void setApperances(int &appearances);

  int getApperances() const;

  void setFirstApperance(std::string &first_apperance);

  std::string getFristApperance() const;

  void setYear(int &year);

  int getYear() const;

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
