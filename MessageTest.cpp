//
// Created by francesco caselli
//

#include <gtest/gtest.h>
#include "../Message.h"
#include "../User.h"



TEST (Message, TestMessage) {

    User tom("tom","1234","Firenze");
    User jerry("jerry","5678","Roma");




    Message mx(tom,jerry,"welcome.");
    Message ms(jerry,tom,"good moorning");




    ASSERT_EQ(ms.isRead(), false);
    ASSERT_EQ(mx.getMsgFrom().getName(), tom.getName());
    ASSERT_EQ(mx.getMsgTo().getName(), jerry.getName());
    ASSERT_EQ(mx.getText(), "welcome.");
    ASSERT_EQ(mx.isRead(), false);
    mx.setRead(true);
    ASSERT_EQ(mx.isRead(), true);

}
