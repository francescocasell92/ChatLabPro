#include <iostream>
#include "User.h"
#include "iostream"

int main() {
    User tom("tom","1234","firenze");

    std::cout << "Hello my name is "+ tom.getName()+" and my number is:"+ tom.getNumber()+", i am from "+ tom.getCity()<<std::endl;

    return 0;
}
