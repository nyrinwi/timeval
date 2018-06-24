#include <cstdio>
#include <cstring>
#include <iostream>
#include <ctime>
#include <stdint.h>
#include <Timeval.h>

TimeSpec::TimeSpec( unsigned long sec, unsigned long nsec )
{
    tv_sec = sec;
    tv_nsec = nsec;
}

TimeSpec::TimeSpec( double sec )
{
    tv_sec = sec;
    tv_nsec = (sec - tv_sec)*1e+9;
}

double TimeSpec::seconds(void) const
{
    return tv_sec + tv_nsec *1e-9;
}

TimeVal::TimeVal( unsigned long sec, unsigned long usec )
{
    tv_sec = sec;
    tv_usec = usec;
}

TimeVal::TimeVal( double sec )
{
    tv_sec = sec;
    tv_usec = (sec - tv_sec)*1e+6;
}

double TimeVal::seconds(void) const
{
    return tv_sec + tv_usec *1e-6;
}


