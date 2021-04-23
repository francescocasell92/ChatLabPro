//
// Created by francesco caselli on 22/04/21.
//

#ifndef CHATLABPRO_MESSAGE_H
#define CHATLABPRO_MESSAGE_H

#include "string"

using namespace std;

class Message{

public:
    //--METHODS--//
    Message(std::string msgFrom , std::string msgTo , std::string text, bool read = false ):
    msgFrom(msgFrom),msgTo(msgTo) , text(text) , read(read) {}

    const std::string &getMsgFrom() const{return msgFrom;}

    const std::string &getMsgTo() const{return msgTo;}

    const std::string &getText() const{return text;}

    bool isRead () const {return read;}

    bool setRead(bool read){Message::read=read;}

private:
    //--ATTRIBUTES--//
std::string msgFrom , msgTo , text;
bool read;

};

#endif //CHATLABPRO_MESSAGE_H
