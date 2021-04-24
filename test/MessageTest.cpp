//
// Created by francesco caselli
//

#include <gtest/gtest.h>
#include "../Message.h"

TEST ( Message , TestMessage){

    Message mx= Message("Luca","Paolo","welcome.");
    ASSERT_EQ(mx.getMsgFrom(),"Luca");
    ASSERT_EQ(mx.getMsgTo(),"Paolo");
    ASSERT_EQ(mx.getText(),"welcome");
    ASSERT_EQ(mx.isRead(),false);
}