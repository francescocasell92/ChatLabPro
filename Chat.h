//
// Created by francesco caselli on 22/04/21.
//

#ifndef USER_H_CHAT_H
#define USER_H_CHAT_H


#include "User.h"
#include "Message.h"
#include "Subject.h"
#include "list"
#include "memory"
#include "vector"
#include "iostream"


class Chat {


public:

    //--costruttore-----//
    Chat(User &ux , User &uy ): firstUser(ux) , secondUser(uy){}

    ~Chat() {};

    //--metodi---------//

    const User &getFirstUser() const{return firstUser;}

    void setFirstUser(const User &firstUser){ Chat::firstUser = firstUser;}

    const &getSecondUser() const {return secondUser;}

    void setSecondUser (const User &secondUser) { Chat::secondUser = secondUser;}

    void newMessage(const Message & newMsg){
        if(firstUser.getName()==newMsg.getMsgFrom() || firstUser.getName()==newMsg.getMsgTo()||
        secondUser.getName()==newMsg.getMsgFrom()||secondUser.getName()==newMsg.getMsgTo()){
            messages.push_back(newMsg)
            if(firstUser.getName()==newMsg.getMsgFrom())
                this->notify();
        }
        else
            throw std::invalid_argument("messaggio non valido");
    }









private:

    //--attributi-------//
    User   firstUser , secondUser ;
    std::list<std::shared_ptr<Observe>observers;
    std::vector<Message> messages;



};



#endif //USER_H_CHAT_H
