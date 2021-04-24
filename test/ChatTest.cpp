//
// Created by francesco caselli
//

#include <gtest/gtest.h>
#include "../Chat.h"
#include "../User.h"
#include "../Message.h"


User Luca("Luca","1234","Milano");
User Paolo("Paolo","5678","Roma");


TEST( Chat , TestChat){
    Chat foo(Luca,Paolo);
    ASSERT_EQ(foo.getFirstUser(),"luca");
    ASSERT_EQ(foo.setSecondUser(),"paolo");
    Message a = (Message("luca","paolo","ciao."));
    ASSERT_EQ(foo.getUnreadMessages(),"ciao");


}

