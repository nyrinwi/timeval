
#ifndef Timeval_INCL
#define Timeval_INCL
#include <sys/time.h>

/*
** Use with nanosleep, clock_gettime
*/
struct TimeSpec: public timespec
{
    TimeSpec( unsigned long sec, unsigned long nsec );
    TimeSpec( double sec );
    double seconds(void) const;
};

/*
** Use with select
*/
struct TimeVal: public timeval
{
    TimeVal( unsigned long sec, unsigned long usec );
    TimeVal( double sec=0 );
    double seconds(void) const;
};
#endif

