//
// Created by francesco caselli
//

#ifndef CHATLABPRO_MESSAGE_H
#define CHATLABPRO_MESSAGE_H

#include "string"
#include "User.h"

using namespace std;

class Message {

public:
    //--METHODS---//
    Message(User &msgFrom, User &msgTo, std::string text, bool read = false) :
            firstUser(msgFrom), secondUser(msgTo), text(text), read(read) {}

    const User &getMsgFrom() const {
        return firstUser;
    }

    const User &getMsgTo() const {
        return secondUser;
    }

    const std::string &getText() const {
        return text;
    }

    bool isRead() const {
        return read;
    }

    bool setRead(bool read) {
        Message::read = read;
    }

private:
    //--ATTRIBUTES--//
    User firstUser , secondUser ;
    std::string text;
    bool read;

};

#endif //CHATLABPRO_MESSAGE_H
