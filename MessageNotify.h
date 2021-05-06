//
// Created by francesco caselli
//

#ifndef USER_H_MESSAGENOTIFY_H
#define USER_H_MESSAGENOTIFY_H

#include "Observer.h"
#include "Chat.h"
#include "memory"

class MessageNotify: public Observer{

public:

      //--METHODS---//
      MessageNotify(std::shared_ptr<Chat> sub, bool act): subject(sub), active(act){}

      virtual ~MessageNotify() = default;

      virtual void attach() override{
          std::shared_ptr<MessageNotify> mhs = std::make_shared<MessageNotify>(*this);
          subject->subscribe(mhs);
      }

      virtual void detach() override {
          std::shared_ptr<MessageNotify> mhs= std::make_shared<MessageNotify>(*this);
          subject->unsubscribe(mhs);
      }

      virtual void update() override{
          if(active)
              this->draw(subject->getUnreadMessages());
      }

      void turnOn(){
          active = true;}

      void turnOff(){
          active = false;}

      void draw(int i){
          std::cout <<  i+ "messaggi non letti ." << std::endl;}

      std::shared_ptr<Chat> getSubject(){
          return subject;}


private:

      //--ATTRIBUTES--//
      std::shared_ptr<Chat> subject;
      bool active;
};


#endif //USER_H_MESSAGENOTIFY_H
