/*Cardtest4.c*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main(){
	int numPlayer = 2;
	int seed = 1000;
	int kc[10] = {adventurer, smithy, council_room, outpost, feast, gardens, mine, village, baron, great_hall};
	struct gameState G;
	
	int scoreCards[] = {curse, estate, duchy, province, great_hall, gardens};
	int score;
	int p;
	
	printf("Testing scorefor()\n");
	for(p = 0; p < numPlayer; p++){
		memset(&G, 23, sizeof(struct gameState));
		initializeGame(numPlayer, kc, seed, &G);
		G.discardCount[p] = 6;
		memcpy(G.discard[p], scoreCards, sizeof(int) * 6);
		G.handCount[p] = 6;
		memcpy(G.hand[p], scoreCards, sizeof(int) * 6);
		G.deckCount[p] = 6;
		memcpy(G.deck[p], scoreCards, sizeof(int) * 6);
		score = scoreFor(p, &G);		

		printf("Test score of player %d\n", p);
		printf("Score for player %d is %d, expected 33\n", p, score);
		if(score == 33){
			printf("Test passed for player %d\n", p);
		} 
		else{
			printf("Test failed for player %d\n", p);
		}
	}
	return 0;	
}
