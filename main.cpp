#include <iostream>
#include "User.h"
#include "iostream"
#include "MessageNotify.h"
#include "Chat.h"

using namespace std;

int main() {

    //--USER--//
    User tom("tom","1234","firenze");
    User jerry("jerry","5678","roma");


    //--MESSAGES--//
    Message a("tom","jerry","ciao jerry oggi ti catturerò..");
    Message b("jerry","tom","ciao tom, non sarà oggi.");

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
    foo.readMessage(0);
    foo.readMessage(1);



    return 0;
}
