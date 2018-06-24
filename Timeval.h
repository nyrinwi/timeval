
#ifndef Timeval_INCL
#define Timeval_INCL
#include <sys/time.h>

struct TimeSpec: public timespec
{
    TimeSpec( unsigned long sec, unsigned long nsec );
    TimeSpec( double sec );
    double seconds(void) const;
};

struct TimeVal: public timeval
{
    TimeVal( unsigned long sec, unsigned long usec );
    TimeVal( double sec );
    double seconds(void) const;
};
#endif

