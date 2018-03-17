#include <vector>
#include <cstdlib> 
#include <string> 
#include <iostream>

template <typename T>

class my_hash{


public:

  my_hash(){ 
    data.reserve(SIZE);
  }

  ~my_hash(){}

  bool insert(const T &element, int index){
    data[index].insert(data[index].begin(),element);
    return 1 < data[index].size();
  }
 /*********************************************************************
 * The first hash function takes all of the chars of the key and sums
 * up thier value. This is followed by at sum being muliplied by a 
 * number between 1-5. This all modded by the size of the list. 
 *
 * param: key string being used to assign a hash value. 
 * return: int result which will be the hash value. 
 *********************************************************************/
  int hash1(const std::string key){
    int hash{0};

    for(char c: key)
      hash += c;

    int randNum{rand() % 5};
  
    return (hash * randNum) % SIZE;

  }
 /**********************************************************************
 * The second hash function takes the first five chars of the string
 * and multipies each by a the numbers in order 17, 19, 23, 29, 31 while 
 * summing them althogether. This is all divided by the size of the
 * structure. 
 **********************************************************************/
  int hash2(const std::string key){
    return (key[0] * 17 + key[1] * 19 + key[2] * 23 + key[3] * 29 +
    key[4] * 31) % SIZE;
  }
 /**********************************************************************
 * The third hash function takes 10 random chars from the key and 
 * sums them up together modding it by the size of the structure.
 * 
 *
 **********************************************************************/
  int hash3(const std::string key){
   int hash{0};

   for(int i{-1}; i < 10; ++i)
     hash += rand() % key.size();

   return hash % SIZE;
  }

  std::vector<int> vectorSizes() const{
    std::vector<int> sizes;

    for(std::vector<T> element:data){
      sizes.push_back(element.size());
    }
    return sizes;
  }
private:
  //A vector of Vectors to hold collisions. 
  std::vector<std::vector<T>> data;  

  //The size of the data array. A constant number that must always be prime.
  const int SIZE{17011};
};
