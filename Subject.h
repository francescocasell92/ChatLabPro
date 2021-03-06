//
// Created by francesco caselli
//

#ifndef CHATLABPRO_SUBJECT_H
#define CHATLABPRO_SUBJECT_H


#include "memory"
#include "Observer.h"

class Subjcet{

public:
    virtual ~Subjcet() = default;

    virtual void subscribe(std::shared_ptr<Observer> observer) = 0;

    virtual void unsubscribe(std::shared_ptr<Observer> observer) = 0;

    virtual void notify() = 0;
};
#endif //CHATLABPRO_SUBJECT_H
