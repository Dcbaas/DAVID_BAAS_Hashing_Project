#include <vector> 
#include <string> 


template <typename T>

class my_hash{


public:

  my_hash(){
    data = new vector<T>[SIZE];
  }

  ~my_hash(){
    delete[] data;
  }
 /*********************************************************************
 * The first hash function takes the first 10 chars of the string and 
 * inserts them at the sumation of those 10 chars.
 * 
 * DO NOT USE THIS HASH FUNCTION IN CONJUNCTION WITH THE OTHER TWO
 * IT DEFEATS THE GOALS OF THE PROJECT.
 *
 * param: element T being inserted into the hash table.
 * param: key string being used to assign a hash value. 
 *********************************************************************/
  void function1(T element, const std::string key){

  }
 /**********************************************************************
 * The second hash function 
 *
 * 
 **********************************************************************/
  void function2(T element, const std::string key){

  }

  void functson3(T element, const std::string key){

  }

  int getCollisions() const{
    checkCollisions();
    return collisions;
  }

private:
  //An Array of Vectors to hold collisions. 
 std::vector<T>* data;  

  //The size of the data array. A constant number that must always be prime.
  const int SIZE(25243);

  //A integer to track the number of collisions. 
  int collisions(0);

  void checkCollisions(){
    //Maybe implement this in each fucntion
    for(std::vector<T> element: data){
      if(element.size() > 1)
        collisions += element.size();
    }
  }
};
