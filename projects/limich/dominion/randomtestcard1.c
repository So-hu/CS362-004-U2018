#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"
#define TOTAL_TEST 500

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
	int initialHandSize;
	int i = 0;
	struct gameState G;
	
	printf("------------------- Testing Card: %s -----------------\n", TESTCARD);
	for (i = 0; i < 500; i++){
		memset(&G, 23, sizeof(struct gameState));
		initializeGame(numPlayer, kc, seed, &G);
		G.handCount[0] = rand() % MAX_HAND;
		G.handCount[1] = G.handCount[0];
		initialHandSize = G.handCount[0]; 
		
		printf(">>>>>>>iteration: %d\n", i + 1);
		cardEffect(smithy, choice1, choice2, choice3, &G, handpos, &bonus);
		printf("Handsize is %d, expected %d\n", G.handCount[G.whoseTurn], initialHandSize + 3);
		assertTrue(G.handCount[G.whoseTurn], initialHandSize + 3);	
	}
	
	return 0;
}
