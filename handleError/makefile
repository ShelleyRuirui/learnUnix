all:badptr testmacs error boom exitfcn logit

badptr: badptr.o

testmacs: testmacs.o filefcn.o filefcn.h

errno : error.c
	gcc error.c -o error -lm

boom: boom.o

exitfcn: exitfcn.o

logit: logit.o