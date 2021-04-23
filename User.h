//
// Created by francesco caselli on 22/04/21.
//

#ifndef CHATLABPRO_USER_H
#define CHATLABPRO_USER_H



#include "string"


class User{

public:

     //--costruttore----//
     User(std::string name , std::string number , std::string city):
     name(name), number(number), city(city) {}

     //--metodi---------//
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

    //--attributi-------//
    std::string name , number , city ;



};

#endif //CHATLABPRO_USER_H
