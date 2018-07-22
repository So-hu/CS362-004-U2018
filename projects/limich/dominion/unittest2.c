/*Cardtest4.c*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main(){
	int i;
	int j;
	int numPlayer = 2;
	int seed = 1000;
	int kc[10] = {adventurer, smithy, council_room, outpost, feast, gardens, mine, village, baron, great_hall};
	struct gameState G;
	int MAX = 5;
	int coppers[MAX];

    for (i = 0; i < MAX; i++)
    {
        coppers[i] = copper;
    }
	int count;
	int p;
	
	printf("Testing scoreCount()\n");
	for(p = 0; p < numPlayer; p++){
		for(j = 0; j < MAX; j++){
			memset(&G, 23, sizeof(struct gameState));
			initializeGame(numPlayer, kc, seed, &G);
			G.discardCount[p] = j;
			memcpy(G.discard[p], coppers, sizeof(int) * j);
			G.handCount[p] = j;
			memcpy(G.hand[p], coppers, sizeof(int) * j);
			G.deckCount[p] = j;
			memcpy(G.deck[p], coppers, sizeof(int) * j);
			count = fullDeckCount(p, 0, &G);

			printf("Test count of player %d\n", p);
			printf("Count for player %d is %d, expected %d\n", p, count, i * 3);
			if(count == i * 3){
				printf("Test passed for player %d\n", p);
			} 
			else{
				printf("Test failed for player %d\n", p);
			}
		}
	}
	return 0;	
}
