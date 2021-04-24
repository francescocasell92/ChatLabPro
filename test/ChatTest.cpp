//
// Created by francesco caselli
//

#include <gtest/gtest.h>
#include "../Chat.h"
#include "../User.h"
#include "../Message.h"

User tom("tom","1234","Firenze");
User jerry("jerry","5678","Roma");

TEST(Chat, TestChatGetters){
    Chat tj(tom,jerry);
    ASSERT_EQ(tj.getFirstUser().getName(), "tom");
    ASSERT_EQ(tj.getSecondUser().getName(),"jerry");
}
