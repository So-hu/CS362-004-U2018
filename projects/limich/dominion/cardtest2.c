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
	int numPlayer = 2;
	int seed = 1000;
	int kc[10] = {adventurer, smithy, council_room, outpost, feast, gardens, mine, village, baron, great_hall};
	int handpos = 0; 
	int choice1 = 0; 
	int choice2 = 0; 
	int choice3 = 0;
	int bonus = 0;
	struct gameState G;
	struct gameState testG;
	
	memset(&G, 23, sizeof(struct gameState));
	initializeGame(numPlayer, kc, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
	for (i = 0; i < numPlayer; i++)
    {
      testG.deckCount[i] = 0;
      for (j = 0; j < 3; j++){
	  	testG.deck[i][j] = estate;
	 	testG.deckCount[i]++;
	  }
      for (j = 3; j < 5; j++)
	  {
	  	testG.deck[i][j] = copper;
	  	testG.deckCount[i]++;		
	  }
    }
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	printf("Handsize is %d, expected 6\n", testG.handCount[testG.whoseTurn]);
	assertTrue(testG.handCount[testG.whoseTurn], 7);

	printf("<2 treasure in deck test\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	for (i = 0; i < numPlayer; i++)
    {
      testG.deckCount[i] = 0;
      for (j = 0; j < 4; j++){
	  	testG.deck[i][j] = estate;
	 	testG.deckCount[i]++;
	  }
      for (j = 4; j < 5; j++)
	  {
	  	testG.deck[i][j] = copper;
	  	testG.deckCount[i]++;		
	  }
    }
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
	printf("Handsize is %d, expected 5\n", testG.handCount[testG.whoseTurn]);
	assertTrue(testG.handCount[testG.whoseTurn], 7);

	return 0;	
}
