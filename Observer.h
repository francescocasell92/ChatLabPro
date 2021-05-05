//
// Created by francesco caselli
//

#ifndef CHATLABPRO_OBSERVER_H
#define CHATLABPRO_OBSERVER_H

#include "memory"

class Observer {
public:

    virtual ~Observer() = default;

    virtual void attach() = 0;

    virtual void detach() = 0;

    virtual void update() = 0;

};

#endif //CHATLABPRO_OBSERVER_H
