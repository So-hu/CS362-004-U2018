#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "outpost"

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
	int numPlayer = 2;
	int seed = 1000;
	int kc[10] = {adventurer, smithy, council_room, outpost, feast, gardens, mine, village, baron, great_hall};
	int handpos = 0; 
	int choice1 = 0; 
	int choice2 = 0; 
	int choice3 = 0;
	int bonus = 0;
	struct gameState G;
	
	memset(&G, 23, sizeof(struct gameState));
	initializeGame(numPlayer, kc, seed, &G);


	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
	cardEffect(outpost, choice1, choice2, choice3, &G, handpos, &bonus);
	printf("Handsize is %d, expected 4\n", G.handCount[G.whoseTurn]);
	assertTrue(G.handCount[G.whoseTurn], 4);
	printf("Check outpost flag\n");
	assertTrue(G.outpostPlayed, 1);

	return 0;	
}
