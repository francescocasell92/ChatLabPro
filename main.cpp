#include <iostream>
#include "User.h"
#include "Message.h"
#include "string"
#include "Chat.h"
#include "MessageNotify.h"
using namespace std;


int main() {

    //---Users----------------------//

    User tom("tom","1234");
    User jerry("jerry","5678");
    User bugs("bugs","2345");

    //---Messages------------------//

    Message p("tom","jerry","ciao come va?");
    Message a("jerry","tom","tutto bene,te?.");
    Message b("tom","jerry","bene grazie.");
    Message c("bugs","duffy","che succede amico?");


    //---newChat-------------------//

    Chat foo(tom,jerry);

    //---SmartPointerChat----------//

    shared_ptr<Chat> fptr = make_shared<Chat>(foo);

    //---Notifier------------------//

    MessageNotify notifier(true,(fptr));
    notifier.attach();

    //---example-------------------//

    foo.newMessage(p);
    foo.newMessage(a);
    foo.newMessage(b);
    foo.readMessage(0);
    foo.readMessage(1);
    foo.readMessage(2);

    //---error--------------------//

    try{
        foo.newMessage(c);
    }
    catch (invalid_argument &e){
        cerr << "Error: " << e.what() <<endl;
    }
    return 0;



}