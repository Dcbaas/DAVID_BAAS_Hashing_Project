#include <vector>
#include <cstdlib> 
#include <string> 

template <typename T>

class my_hash{


public:

  my_hash(){
    SIZE(17011); 
    data.reserve(SIZE);
  }

  ~my_hash(){}

  bool insert(const T &element, int index){
    data[index].insert(0,element);
    return 1 < data[index].size();
  }
 /*********************************************************************
 * The first hash function takes all of the chars of the key and sums
 * up thier value. This is followed by at sum being muliplied by a 
 * number between 1-5. This all modded by the size of the list. 
 * 
 * DO NOT USE THIS HASH FUNCTION IN CONJUNCTION WITH THE OTHER TWO
 * IT DEFEATS THE GOALS OF THE PROJECT.
 *
 * param: key string being used to assign a hash value. 
 * return: int result which will be the hash value. 
 *********************************************************************/
  int hash1(const std::string key){
    int hash(0);

    for(char c: key)
      hash += c;

    return (hash * rand() % 5 + 1) % SIZE;

  }
 /**********************************************************************
 * The second hash function 
 *
 * 
 **********************************************************************/
  int hash2(const std::string key){
    return 0;
  }

  int hash3(const std::string key){
    return 0;
  }
private:
  //A vector of Vectors to hold collisions. 
  std::vector<std::vector<T>> data;  

  //The size of the data array. A constant number that must always be prime.
  const int SIZE;
};
