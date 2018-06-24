# vim: noet
CXXFLAGS=-Wall -I.

all: timeval.o
	$(MAKE) -C test $@

clean:
	$(RM) *.o
	$(MAKE) -C test $@
