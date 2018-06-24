#include <cstdio>
#include <cstring>
#include <iostream>
#include "Timeval.h"

#include <gtest/gtest.h>

TEST(TimeVal,double)
{
    EXPECT_EQ(1.0,TimeVal(1.0).seconds());
    EXPECT_EQ(1.1,TimeVal(1.1).seconds());
    EXPECT_EQ(1.6,TimeVal(1.6).seconds());
    EXPECT_EQ(600000,TimeVal(1.6).tv_usec);
}

TEST(TimeVal,int)
{
    EXPECT_EQ(1.5,TimeVal(1,600000).seconds());
}

TEST(TimeSpec,double)
{
    EXPECT_EQ(1.0,TimeSpec(1.0).seconds());
    EXPECT_EQ(1.1,TimeSpec(1.1).seconds());
    EXPECT_EQ(1.6,TimeSpec(1.6).seconds());
    EXPECT_EQ(600000000,TimeSpec(1.6).tv_nsec);
}

TEST(TimeSpec,int)
{
    EXPECT_EQ(1.5,TimeSpec(1,600000000).seconds());
}
