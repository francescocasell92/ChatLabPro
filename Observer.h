//
// Created by francesco caselli
//

#ifndef PROGETTOCHATLAB_OBSERVER_H
#define PROGETTOCHATLAB_OBSERVER_H

#include <memory>

class Observer {
public:
    virtual ~Observer(){}
    virtual void attach() = 0;
    virtual void detach() = 0;
    virtual void update() = 0;
};

#endif //PROGETTOCHATLAB_OBSERVER_H
