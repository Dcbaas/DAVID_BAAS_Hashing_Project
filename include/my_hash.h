#include <vector>
#include <string>
#include "Superhero.h"
#include "md5.h" 


 /*********************************************************************
 * The my_hash class is a generic hashmap class that stores a genric
 * type ADT. The underlying structure is a vector of vectors. This 
 * enables for colliding elements to be stacked on the same index.
 * The my_hash function has three seperate hashing functions that
 * converts a key into a useable index. They are intended to only be
 * used in isolation and not in combination with each other. 
 *
 * author: David Baas
 * version: 1.0
 *********************************************************************/
template <typename T>
class my_hash{
public:
 /********************************************************************
 * The contructor initializes all of the variables and reserves a size
 * for the vector of vectors to a predetermined structure size. 
 ********************************************************************/  
  my_hash(){ 
    data.reserve(SIZE);
  }

 /*********************************************************************
 * The destructor destroys the data structure if it was declared
 * dynamically.
 *********************************************************************/ 
  ~my_hash(){}

 /*********************************************************************
 * The insert function take a generic element and insterts it at the
 * index specified.The element is always inserted at the fron of the 
 * vector that is contained at that index. If the vector at that element
 * has more than one element at the vector where the data is being
 * inserted, then the boolean returns true.
 *
 * param: element the object of type T being inserted into the hashmap
 * param: index the index where the element is being inserted.
 * return: true if the vector @ the index has more than 1 item and 
 * false otherwise.
 *********************************************************************/
  bool insert(const T &element, int index){
    data[index].insert(data[index].begin(),element);
    return 1 < data[index].size();
  }

 /*********************************************************************
 * The first hash function takes all of the chars of the key and sums
 * up thier value. This all modded by the size of the list. 
 *
 * param: key string being used to assign a hash value. 
 * return: int result which will be the hash value. 
 *********************************************************************/
  int hash1(const std::string key){
   unsigned int hash{0};

    for(char c: key)
      hash += c;
   
    return hash % SIZE;
  }

 /**********************************************************************
 * The second hash function takes the first five chars of the string
 * and multipies each by a the numbers in order 17, 19, 23, 29, 31 while 
 * summing them althogether. This is all divided by the size of the
 * structure.
 *
 * param: key string being used to assign a hash value.
 * return: int result which will be the hash value.
 **********************************************************************/
  int hash2(const std::string key){
    return (key[0] * 17 + key[1] * 19 + key[2] * 23 + key[3] * 29 +
    key[4] * 31) % SIZE;
  }

 /**********************************************************************
 * The third hash function takes an unsigned int starting at 7 and for
 * every char the hash is multiplied by itself * 47 and the value of the
 * char is added to the hash. This is a modified version of a hash 
 * function found in the Hashing PowerPoint.
 *
 * param: key string being used to assign a hash value.
 * return: int result which will be the hash value.
 **********************************************************************/
  unsigned int hash3(const std::string key){
    unsigned int hash{7};

    for(char c: key)
      hash = 47 * hash + c;

    return hash % SIZE; 
  }
 /**********************************************************************
 * This extra hash function takes the string and encodes it using 
 * the md5 standard. The enoding is done from a third party library 
 * which only returns a hex value. This hex value is converted to a 
 * decimal value and is stored in a long which is modded by the 
 * table size. The md5 library was found at:
 * http://www.zedwood.com/article/cpp-md5-function
 *
 * param: key string being used to assign a hash value.
 * return: int result which will be the hash value.
 **********************************************************************/
 unsigned long hash4(const std::string key){
    std::string md5Str = md5(key);
    std::stringstream ss;
    unsigned long hash;
    ss << std::dec << md5Str;
    ss >> hash;
    return hash % SIZE; 
}

  Superhero & get(const std::string name, int hashMode){

    std::vector<Superhero> elements;
    switch(hashMode){
      case 1:
        elements = data[hash1(name)];
        break;
      case 2:
        elements = data[hash2(name)];
        break;
      case 3:
        elements = data[hash3(name)];
        break;
    }

    for(Superhero h: elements){
      if(h.getName() == name)
        return h;
    }
    return -1;
  }

private:
  //A vector of Vectors to hold collisions. 
  std::vector<std::vector<T>> data;  

  //The size of the data array. A constant number that must always be prime.
  const int SIZE{17011};
};
