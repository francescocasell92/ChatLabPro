//
// Created by francesco caselli
//

#include <gtest/gtest.h>
#include "../Message.h"


TEST (Message, TestMessage) {
    Message mx = Message("tom", "jerry", "welcome.");
    ASSERT_EQ(mx.getMsgFrom(), "tom");
    ASSERT_EQ(mx.getMsgTo(), "jerry");
    ASSERT_EQ(mx.getText(), "welcome.");
    ASSERT_EQ(mx.isRead(), false);
    mx.setRead(true);
    ASSERT_EQ(mx.isRead(), true);

}
