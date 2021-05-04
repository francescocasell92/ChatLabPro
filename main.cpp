//
// Created by francesco caselli
//


#include <iostream>
#include <memory>
#include "User.h"
#include "MessageNotify.h"
#include "Chat.h"

using namespace std;

int main() {

    //--USER--//
    User tom("Tom","1234","Firenze");
    User jerry("Jerry","5678","Roma");
    User bugs("Bugs","9123","Milano");
    User duffy("Duffy","4567","Torino");


    //--MESSAGES--//
    Message a("Tom","Jerry","Ciao Jerry come è andata ieri?");
    Message b("Jerry","Tom","Ciao Tom, è andato tutto bene te?.");
    Message c("Tom","Jerry","Tutto bene anche io.");
    Message d("Bugs","Duffy","Che succede amico??");

    //--CHAT--//
    Chat foo(tom,jerry);

    //--SMART_POINTER--//
    shared_ptr<Chat> fooptr = make_shared<Chat>(foo);

    //--NOTIFIER--//
    MessageNotify notifier((fooptr), true);
    notifier.attach();

    //--EXE--//
    foo.newMessage(a);
    foo.newMessage(b);
    foo.newMessage(c);
    foo.readMessage(0);
    foo.readMessage(1);
    foo.readMessage(2);

    //--ERROR--//

    try {
        foo.newMessage(d);
    }
    catch (invalid_argument &e){
        cerr << "Error: " << e.what() << endl;
    }
        foo.readMessage(3);




    return 0;
}
