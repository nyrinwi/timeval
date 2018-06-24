# vim:noet

CC=g++
LDLIBS+=-L ~/src/googletest -lgtest -lpthread
CXXFLAGS+=-I ~/src/googletest -I..

vpath %.cpp $(CURDIR)/..

all:: tester
	./tester

tester: tester.o timeval.o

clean::
	$(RM) *.o tester
