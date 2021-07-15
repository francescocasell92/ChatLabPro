//
// Created by francesco caselli
//

#include <gtest/gtest.h>
#include "../Chat.h"
#include "../MessageNotify.h"
#include "../User.h"

User tom("tom","1234","Firenze");
User jerry("jerry","5678","Roma");

Chat bar(tom,jerry);



Message mx = Message(tom, jerry, "Hello world.");
Message ms = Message(jerry,tom,"good moorning.");
Message mn = Message(tom,jerry,"Have a nice day.");
Message mm = Message(jerry,tom,"good evening.");
Message mp = Message(tom,jerry,"Say hello.");
Message mi = Message(jerry,tom,"your are welcome.");


shared_ptr<Chat>barptr = make_shared<Chat>(bar);


 MessageNotify notifier((barptr),true);





TEST(Chat, TestChatGetters) {



    ASSERT_EQ(bar.getFirstUser().getName(), "tom");
    ASSERT_EQ(bar.getSecondUser().getName(), "jerry");

}
TEST(Chat, TestMethods){

    notifier.attach();

    bar.newMessage(mx);
    bar.newMessage(ms);
    bar.newMessage(mn);
    bar.newMessage(mm);
    bar.newMessage(mp);
    bar.newMessage(mi);

    ASSERT_EQ(bar.getCountUnreadMessages(),6);

   ASSERT_EQ( bar.readMessage(0),"tom : Hello world.");
   ASSERT_EQ(bar.readMessage(1),"jerry : good moorning.");

    ASSERT_EQ(bar.getCountUnreadMessages(),4);

}
