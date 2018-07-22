#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "council_room"

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
	int numPlayer = 2;
	int currentPlayer;
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
	cardEffect(council_room, choice1, choice2, choice3, &G, handpos, &bonus);
	printf("Handsize is %d, expected 8\n", G.handCount[G.whoseTurn]);
	assertTrue(G.handCount[G.whoseTurn], 8);
	printf("Buy count %d, expected 2\n", G.numBuys);
	assertTrue(G.numBuys, 2);
	currentPlayer = G.whoseTurn;
	for(i = 0; i< G.numPlayers; i++){
		if(i != currentPlayer){
			currentPlayer = i;
		}
	}
	printf("Check other player hand size: %d, expected 1\n", G.handCount[currentPlayer]);
	assertTrue(G.handCount[G.whoseTurn], 1);

	return 0;	
}
