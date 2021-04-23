#include <iostream>
#include "User.h"
#include "iostream"
#include "MessageNotify.h"
#include "Chat.h"

using namespace std;

int main() {
    User tom("tom","1234","firenze");
    User jerry("jerry","5678","roma");

    std::cout << "Hello my name is "+ tom.getName()+" and my number is:"+ tom.getNumber()+", i am from "+ tom.getCity()<<std::endl;

    Message a("tom","jerry","ciao jerry oggi ti catturerò..");
    Message b("jerry","tom","ciao tom, non sarà oggi.");


    Chat foo(tom,jerry);

    shared_ptr<Chat> fooptr = make_shared<Chat>(foo);

    MessageNotify notifier((fooptr), true);
    notifier.attach();

    foo.newMessage(a);
    foo.newMessage(b);
    foo.readMessage(0);
    foo.readMessage(1);



    return 0;
}
