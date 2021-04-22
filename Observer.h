//
// Created by francesco caselli on 22/04/21.
//

#ifndef CHATLABPRO_OBSERVER_H
#define CHATLABPRO_OBSERVER_H

#include "memory"

class Observer {
public:

    virtual ~Observer(){}

    virtual void attach() = 0;

    virtual void detach() = 0;

    virtual void update() = 0;

};

#endif //CHATLABPRO_OBSERVER_H
