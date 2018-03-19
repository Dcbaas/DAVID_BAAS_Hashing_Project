#include <string>
#include "Superhero.h"
//For information on the Superhero Class, please refer to the header file
//Superhero.h.
  Superhero::Superhero(int page_id, const std::string &name, const std::string &urlslug, const std::string &id,
                       const std::string &alignment, char eye_color, char hair_color, char sex, const std::string &gsm,
                       bool alive, int appearances, const std::string &first_apperance, int year) :
          page_id(page_id), name(name),urlslug(urlslug), id(id), alignment(alignment), eye_color(eye_color),
          hair_color(hair_color), sex(sex), gsm(gsm), alive(alive), appearances(appearances), first_apperance(first_apperance),
          year(year) {}

  std::string Superhero::toString(){
    return "" +  page_id + name;
  }

  std::string Superhero::getName() const{
    return name;
  }
