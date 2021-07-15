//
// Created by francesco caselli
//

#ifndef PROGETTOCHATLAB_MESSAGE_H
#define PROGETTOCHATLAB_MESSAGE_H


#include <string>

using namespace std;

class Message {


public:

    Message(std::string from, std::string to, std::string text, bool read = false):
    from(from), to(to) , text(text), read(read) {}


    const std::string &getFrom() const {
        return from;
    }

    const std::string &getTo() const {
        return to;
    }

    const std::string &getText() const {
        return text;
    }

    bool isRead() const {
        return read;
    }

    void setRead(bool read) {
        Message::read = read;

    }
        bool operator==(const Message &right) const {
            return this->getTo() == right.getTo() && this->getFrom() == right.getFrom() &&
                   this->getText() == right.getText() && this->isRead() == right.isRead();
        }

        private:

        std::string from, to, text;

        bool read;



};


#endif //PROGETTOCHATLAB_MESSAGE_H
