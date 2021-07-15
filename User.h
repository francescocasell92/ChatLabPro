//
// Created by francesco caselli
//

#ifndef PROGETTOCHATLAB_USER_H
#define PROGETTOCHATLAB_USER_H


#include <string>


class User {

public:
    User(std::string name , std::string number): name(name), number(number){}



    std::string getName() const{
        return name;
    }

    std::string getNumber()const{
        return number;
    }


    bool operator==(const User &right) const {
        return this->getName()==right.getName() && this->getNumber()==right.getNumber();
    }


private:

    std::string number, name;
};


#endif //PROGETTOCHATLAB_USER_H
