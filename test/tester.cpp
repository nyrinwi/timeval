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

    // Note that usec can exceed 1e+6
    EXPECT_EQ(2.0, TimeVal(0,2000000).seconds());
    EXPECT_EQ(20.0, TimeVal(0,20000000).seconds());
}

TEST(TimeVal,int)
{
    EXPECT_EQ(1.6,TimeVal(1,600000).seconds());
}

TEST(TimeSpec,double)
{
    EXPECT_EQ(1.0,TimeSpec(1.0).seconds());
    EXPECT_EQ(1.1,TimeSpec(1.1).seconds());
    EXPECT_EQ(1.6,TimeSpec(1.6).seconds());
    EXPECT_EQ(600000000,TimeSpec(1.6).tv_nsec);

    // Note that nsec can exceed 1e+9
    EXPECT_EQ(2.0, TimeSpec(0,2000000000).seconds());
}

TEST(TimeSpec,int)
{
    EXPECT_EQ(1.6,TimeSpec(1,600000000).seconds());
}

TEST(Timval,default)
{
    TimeVal tvd;
    EXPECT_EQ(0, tvd.tv_sec);
    TimeVal tsd;
    EXPECT_EQ(0, tsd.tv_sec);
}

TEST(API,TimeVal)
{
    TimeVal tv(0,1);
    EXPECT_EQ(0, select(0, 0, 0, 0, &tv) );

    TimeVal tvf(.25);
    EXPECT_EQ(0, select(0, 0, 0, 0, &tvf) );
}

TEST(API,TimeSpec)
{
    TimeSpec ts(0,1);
    EXPECT_EQ(0, nanosleep(&ts, NULL) );


    TimeSpec tsf(.25);
    EXPECT_EQ(0, nanosleep(&tsf, NULL) );

    time_t tref = time(NULL);
    TimeVal tvd;
    EXPECT_EQ(0,gettimeofday(&tvd,NULL));
    EXPECT_GE(tref,tvd.tv_sec);
    EXPECT_GE(tvd.tv_usec,0);
    EXPECT_LT(tvd.tv_usec,1000000);
}
