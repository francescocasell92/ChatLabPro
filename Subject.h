//
// Created by francesco caselli
//

#ifndef PROGETTOCHATLAB_SUBJECT_H
#define PROGETTOCHATLAB_SUBJECT_H
#include <memory>
#include "Observer.h"

class Subject {
public:
    virtual ~Subject(){}
    virtual void subscribe(std::shared_ptr<Observer> observer) = 0;
    virtual void unsubscribe(std::shared_ptr<Observer> observer) = 0;
    virtual void notify() = 0;
};

#endif //PROGETTOCHATLAB_SUBJECT_H
