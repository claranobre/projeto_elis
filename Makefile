CC = g++
CFLAGS = -Wall -g -std=c++11
SRCDIR = src
DOCDIR = doc

SUBDIRS = $(SRCDIR) $(TESTDIR)

all:
	for i in $(SUBDIRS) ; do \
		( cd $$i ; make ) ; \
	done

clean:
	for i in $(SUBDIRS) ; do \
		( cd $$i ; make clean) ; \
	done