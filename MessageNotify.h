//
// Created by francesco caselli on 22/04/21.
//

#ifndef USER_H_MESSAGENOTIFY_H
#define USER_H_MESSAGENOTIFY_H

#include "Observer.h"
#include "Chat.h"
#include "memory"

class MessageNotify: public Observer{

public:

      //--costruttore--------//
      MessageNotify(std::shared_ptr<Chat> sub, bool act): subject(sub), active(act){}

      //--metodi-------------//
      virtual ~MessageNotify(){}


private:

      //--attributi--------//

      std::shared_ptr<Chat> subject;

      bool active;
};


#endif //USER_H_MESSAGENOTIFY_H
