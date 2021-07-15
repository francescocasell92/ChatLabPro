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
    Message a(tom,jerry,"Ciao Jerry come è andata ieri?");
    Message b(jerry,tom,"Ciao Tom, è andato tutto bene te?.");
    Message c(tom,jerry,"Tutto bene anche io.");
    Message d(bugs,duffy,"Che succede amico??");

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
    cout<<foo.readMessage(0)<<endl;
    cout<<foo.readMessage(1)<<endl;
    cout<<foo.readMessage(2)<<endl;
    //--ERROR--//

    try {
        foo.newMessage(d);
    }
    catch (invalid_argument &e){

        cerr << "Error: " << e.what() << endl;
    }
     try {

         cout<<foo.readMessage(3)<<endl;

         }
     catch (invalid_argument &e){
         cerr<< "Error: " << e.what() << endl;
     }




    return 0;
}
