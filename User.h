
#ifndef CHATLABPRO_USER_H
#define CHATLABPRO_USER_H



#include "string"


class User{

public:

     //--METHODS---//
     User(std::string name , std::string number , std::string city):
     name(name), number(number), city(city) {}

     std::string getName() const{
         return name;
     }

     std::string getNumber() const{
         return number;
     }

     std::string getCity() const{
         return city;
     }

private:

    //--ATTRIBUTES--//
    std::string name , number , city ;



};

#endif //CHATLABPRO_USER_H
