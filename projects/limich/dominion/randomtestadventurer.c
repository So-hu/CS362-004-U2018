#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

int assertTrue(int input1, int input2){
	if(input1 == input2){
		printf("Test passed\n");
	}
	else{
		printf("Test failed\n");
	}
	return 0;
}

int main(){
	int i;
	int j;
	int testCount;
	int numPlayer = 2;
	int seed = 1000;
	int kc[10] = {adventurer, smithy, council_room, outpost, feast, gardens, mine, village, baron, great_hall};
	int handpos = 0; 
	int choice1 = 0; 
	int choice2 = 0; 
	int choice3 = 0;
	int bonus = 0;
	int randDeckSize;
	int treasureLoc;
	int temp;
	struct gameState G;

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
	for (testCount = 0; testCount < 500; testCount++){
		printf(">>>>>>>>>>iteration #: %d\n", testCount);
		memset(&G, 23, sizeof(struct gameState));
		initializeGame(numPlayer, kc, seed, &G);
		
		randDeckSize = rand() % MAX_DECK;
		temp = randDeckSize - 2;
		treasureLoc = rand() % temp;
		
		for (i = 0; i < numPlayer; i++)
    		{
      			G.deckCount[i] = randDeckSize;
      			for (j = 0; j < randDeckSize; j++){
		  		G.deck[i][j] = estate;
		 		G.deckCount[i]++;
		  	}
      			
		  	G.deck[i][treasureLoc] = copper;
			G.deck[i][treasureLoc + 1] = copper;
		  	G.deckCount[i]++;		
			G.deckCount[i]++;	  	
 		}
		
		cardEffect(adventurer, choice1, choice2, choice3, &G, handpos, &bonus);
		printf("Handsize is %d\n", G.handCount[G.whoseTurn]);
		printf("Deck size is %d\n", G.deckCount[G.whoseTurn]);
	}

	return 0;	
}
