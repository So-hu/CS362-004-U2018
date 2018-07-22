#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
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
	struct gameState G;
	int currentPlayer;
	int hand;
	
	printf("Test endturn\n");
	memset(&G, 23, sizeof(struct gameState));
	initializeGame(numPlayer, kc, seed, &G);
	endTurn(&G);
	currentPlayer = whoseTurn(&G);
	hand = G.handCount[G.whoseTurn];
	printf("Handsize is %d, expected 5\n", hand);
	assertTrue(hand, 5);
	printf("Current player is %d, expected 1\n", currentPlayer);
	assertTrue(currentPlayer, 1);
	printf("Checking State values");
	assertTrue(G.outpostPlayed, 0);
	assertTrue(G.phase, 0);
	assertTrue(G.numActions, 1);
	assertTrue(G.coins, 0);
	assertTrue(G.numBuys, 1);
	assertTrue(G.playedCardCount, 0);

	return 0;	
}
