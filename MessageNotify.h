//
// Created by francesco caselli
//

#ifndef CHAT_H_MESSAGENOTIFY_H
#define CHAT_H_MESSAGENOTIFY_H



#include "Observer.h"
#include "Chat.h"
#include <memory>

class MessageNotify: public Observer {
public:
    MessageNotify(bool act, std::shared_ptr<Chat> sub) : active(act), subject(sub){}

    virtual ~MessageNotify(){}

    virtual void attach() override{
        std::shared_ptr<MessageNotify> ths = std::make_shared<MessageNotify>(*this);
        subject->subscribe(ths);
    }
    virtual void detach() override{
        std::shared_ptr<MessageNotify> ths = std::make_shared<MessageNotify>(*this);
        subject->unsubscribe(ths);
    }
    virtual void update() override{
        if (active)
            this->draw(subject->getUnredMessages());
    }
    void activate(){
        active = true;
    }
    void turnOff(){
        active = false;
    }
    void draw(int m){
        std::cout << "Hai " << m <<" messaggi non letti" << std::endl;
        std::cout << "ultimo messaggio da parte di " << subject->lastMessage().getFrom() << ": " << subject->lastMessage().getText() << "." << std::endl;
    }


    std::shared_ptr<Chat> getSubject(){
        return subject;
    }
private:
    bool active;
    std::shared_ptr<Chat> subject;
};


#endif //CHAT_H_MESSAGENOTIFY_H
