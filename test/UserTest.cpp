//
// Created by francesco caselli on 24/04/21.
//


#include <gtest/gtest.h>
#include "../User.h"
TEST(User,TestUser){
    User tom("tom","1234","Firenze");
    ASSERT_EQ(tom.getName(),"tom");
    ASSERT_EQ(tom.getNumber(),"1234");
    ASSERT_EQ(tom.getCity(),"Firenze");
}