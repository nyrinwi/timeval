# vim:noet

CC=g++
GTESTHOME=~/src/googletest
LDLIBS+=-L $(GTESTHOME) -lgtest -lpthread
CXXFLAGS+=-I $(GTESTHOME) -I $(CURDIR)/..

vpath %.cpp $(CURDIR)/..

all:: tester
	./tester

tester: tester.o timeval.o

clean::
	$(RM) *.o tester
