//
// Created by francesco caselli
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
#include "string"


class Chat {


public:

    //--METHODS--//
    Chat(User &ux, User &uy) : firstUser(ux), secondUser(uy) {}

    ~Chat() = default;


    const User &getFirstUser() const {
        return firstUser;
    }

    void setFirstUser(const User &firstUser) {
        Chat::firstUser = firstUser;
    }

    const User &getSecondUser() const {
        return secondUser;
    }

    void setSecondUser(const User &secondUser) {
        Chat::secondUser = secondUser;
    }

    virtual void subscribe(std::shared_ptr<Observer> observer) {
        observers.push_back(observer);
    }

    virtual void unsubscribe(std::shared_ptr<Observer> observer) {
        observers.remove(observer);
    }

    virtual void notify() {
        for (auto observer:observers)
            observer->update();
    }

    void newMessage(const Message &addMsg) {
        if (   firstUser.getName() == addMsg.getMsgFrom().getName() ||
               firstUser.getName() == addMsg.getMsgTo().getName() ||
              secondUser.getName() == addMsg.getMsgFrom().getName() ||
              secondUser.getName() == addMsg.getMsgTo().getName()) {
              messages.push_back(addMsg);
            if (firstUser.getName() == addMsg.getMsgFrom().getName())
                this->notify();
        } else
            throw std::invalid_argument("La Chat tra questi utenti non esiste.");
    }

    string readMessage(int i ) {
        if (i < messages.size() && i >= 0) {
            messages[i].setRead(true);
            this->notify();
            if (messages[i].getMsgFrom().getName() == firstUser.getName() ||
                messages[i].getMsgTo().getName() == secondUser.getName()) {
                 return  firstUser.getName()+" : "+ messages[i].getText();
            } else {
                return secondUser.getName() +" : "+ messages[i].getText();
            }
        } else
            throw std::invalid_argument("Messaggio fuori da una Chat.") ;
    }

    int getCountUnreadMessages() const {
        int i = 0;
        for (const auto &message:messages)
            if (!message.isRead())
                i++;
        return i;
    }

private:

    //--ATTRIBUTES--//
    User firstUser, secondUser;
    std::list<std::shared_ptr<Observer>> observers;
    std::vector<Message> messages;


};


#endif //USER_H_CHAT_H
