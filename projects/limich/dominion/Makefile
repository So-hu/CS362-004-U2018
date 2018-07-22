CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g dominion.o rngs.o

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

unittestresults: dominion.o rngs.o
	gcc -o test1 -g unittest1.c dominion.o rngs.o $(CFLAGS)
	gcc -o test2 -g unittest2.c dominion.o rngs.o $(CFLAGS)	
	gcc -o test3 -g unittest3.c dominion.o rngs.o $(CFLAGS)
	gcc -o test4 -g unittest4.c dominion.o rngs.o $(CFLAGS)
	gcc -o test5 -g cardtest1.c dominion.o rngs.o $(CFLAGS)
	gcc -o test6 -g cardtest2.c dominion.o rngs.o $(CFLAGS)
	gcc -o test7 -g cardtest3.c dominion.o rngs.o $(CFLAGS)
	gcc -o test8 -g cardtest4.c dominion.o rngs.o $(CFLAGS)
	./test1 >> unittestresults.out
	./test2 >> unittestresults.out
	./test3 >> unittestresults.out
	./test4 >> unittestresults.out
	./test5 >> unittestresults.out
	./test6 >> unittestresults.out
	./test7 >> unittestresults.out
	./test8 >> unittestresults.out
	gcov -f -b dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe test1 test2 test3 test4 test5 test6 test7 test8
