//
// Created by francesco caselli
//

#ifndef PROGETTOCHATLAB_CHAT_H
#define PROGETTOCHATLAB_CHAT_H


#include "User.h"
#include "Message.h"
#include "Subject.h"
#include "iostream"
#include "memory"
#include "list"
#include "vector"

using namespace std;

class Chat {

public:
    Chat(User &u1, User &u2) : myUser(u1), otherUser(u2) {}

    ~Chat() {};


    const User &getMyUser() const {
        return myUser;
    }

    void setMyUser(const User &myUser) {
        Chat::myUser = myUser;
    }

    const User &getOtherUser() const {
        return otherUser;
    }

    void setOtherUser(const User &otherUser) {
        Chat::otherUser = otherUser;
    }

    void newMessage(const Message& newMsg) {
        if (myUser.getName() == newMsg.getFrom() || myUser.getName() == newMsg.getTo()||
            otherUser.getName() == newMsg.getTo() ||
            otherUser.getName() == newMsg.getFrom()) {
            messages.push_back(newMsg);
            if (myUser.getName() == newMsg.getFrom())
                this->notify();
        } else
            throw std::invalid_argument("invalid argument");

    }


    void readMessage(int i) {

        if (i >= 0 && i < messages.size()) {
            if (messages[i].getFrom() == myUser.getName() || messages[i].getTo() == otherUser.getName()) {
                std::cout << myUser.getName() + ":" << std::endl;
                std::cout << messages[i].getText() << std::endl;
                messages[i].setRead(true);
                this->notify();
            } else {
                std::cout << otherUser.getName()+ ":" << std::endl;
                std::cout << messages[i].getText() << std::endl;
            }
        }
        else
            throw std::out_of_range("out of range");
    }


    int getUnredMessages() const {
        int i = 0;
        for (const auto &message:messages)
            if (message.getTo() == myUser.getNumber())
                if (!message.isRead())
                    i++;
        return i;

    }
    const Message& lastMessage() const{
        return messages.back();
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

private:

    User myUser , otherUser;
    std::list<std::shared_ptr<Observer>>observers;
    std::vector<Message> messages;
};


#endif //PROGETTOCHATLAB_CHAT_H
