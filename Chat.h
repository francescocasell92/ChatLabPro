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

    //--METHODS--//
    Chat(User &ux , User &uy ): firstUser(ux) , secondUser(uy){}

    ~Chat() {};


    const User &getFirstUser() const{return firstUser;}

    void setFirstUser(const User &firstUser){ Chat::firstUser = firstUser;}

    const User &getSecondUser() const {return secondUser;}

    void setSecondUser (const User &secondUser) { Chat::secondUser = secondUser;}

    virtual void subscribe(std::shared_ptr<Observer> observer){ observers.push_back(observer);}

    virtual void unsubscribe(std::shared_ptr<Observer> observer){ observers.remove(observer);}

    virtual void notify(){for(auto observer:observers)observer->update();}

    void newMessage(const Message & newMsg){
        if(firstUser.getName()==newMsg.getMsgFrom() || firstUser.getName()==newMsg.getMsgTo()||
        secondUser.getName()==newMsg.getMsgFrom()||secondUser.getName()==newMsg.getMsgTo()){
            messages.push_back(newMsg);
            if(firstUser.getName()==newMsg.getMsgFrom())
                this->notify();
        }
        else
            throw std::invalid_argument("messaggio non valido");
    }
    void readMessage(int i){
        if(i < messages.size() && i >= 0){
            if (messages[i].getMsgFrom()==firstUser.getName()||
            messages[i].getMsgTo()== secondUser.getName()){
                std::cout <<"\t"+firstUser.getName()+" : "+messages[i].getText()<< std::endl;

                messages[i].setRead(true);
                this->notify();
            }else
                {std::cout <<"\t"+secondUser.getName()+" : "+messages[i].getText()<<std::endl;}
        }
        else
            throw std::out_of_range("out of range");
    }

    int getUnreadMessages()const {
        int i=0;
        for(const auto &message:messages)
            if(message.getMsgTo()==firstUser.getName())
                if (!message.isRead())
                    i++;
                return i;
    }
private:

    //--ATTRIBUTES--//
    User   firstUser , secondUser ;
    std::list<std::shared_ptr<Observer>>observers;
    std::vector<Message> messages;



};



#endif //USER_H_CHAT_H
