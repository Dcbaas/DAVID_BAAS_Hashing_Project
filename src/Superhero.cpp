#include <string>
#include "Superhero.h"


Superhero::Superhero(int page_id, const std::string &name, const std::string &urlslug, const std::string &id,
                     const std::string &alignment, char eye_color, char hair_color, char sex, const std::string &gsm,
                     bool alive, int appearances, const std::string &first_apperance, int year) :
        page_id(page_id), name(name),urlslug(urlslug), id(id), alignment(alignment), eye_color(eye_color),
        hair_color(hair_color), sex(sex), gsm(gsm), alive(alive), appearances(appearances), first_apperance(first_apperance),
        year(year) {}


//void Superhero::setPageID(int &page_id){
//  Superhero::page_id = page_id;
//}
//
//int Superhero::getPageID() const{
//  return page_id;
//}

//void Superhero::setName(std::string &name){
//  Superhero::name = name;
//}
//
//std::string Superhero::getName() const{
//  return name;
//}
//
//void Superhero::setUrlSlug(std::string &urlslug){
//  Superhero::urlslug = urlslug;
//}
//
//std::string Superhero::getUrlSlug() const{
//  return urlslug;
//}
//
//void Superhero::setID(std::string &id){
//  Superhero::id = id;
//}
//
//std::string Superhero::getID() const{
//  return id;
//}
//
//void Superhero::setAlighment(std::string &alignment){
//  Superhero::alignment = alignment;
//}
//
//std::string Superhero::getAlignment() const{
//  return alignment;
//}
//
//void Superhero::setEyeColor(char &eye_color){
//  Superhero::eye_color = eye_color;
//}
//
//char Superhero::getEyeColor() const{
//  return eye_color;
//}
//
//void Superhero::getHairColor(char &hair_color){
//  Superhero::hair_color = hair_color;
//}
//
//char Superhero::getHairColor() const{
//  return hair_color;
//}
//
//void Superhero::setSex(char &sex){
//  Superhero::sex = sex;
//}
//
//char Superhero::getSex() const{
//  return sex;
//}
//
//void Superhero::setGSM(std::string &gsm){
//  Superhero::gsm = gsm;
//}
