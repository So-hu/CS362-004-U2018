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
	int j = 0;
	int numPlayer = 2;
	int seed = 1000;
	int kc[10] = {adventurer, smithy, council_room, outpost, feast, gardens, mine, village, baron, great_hall};
	struct gameState G;
	int flag;
	
	memset(&G, 23, sizeof(struct gameState));
	initializeGame(numPlayer, kc, seed, &G);
	G.supplyCount[province] = j;
	flag = isGameOver(&G);
	printf("Test endgame\n");
	printf("Endgame for empty province\n");
	if(flag == 1){
		printf("Test passed\n");
	}
	else{
		printf("Test failed\n");
	}
	memset(&G, 23, sizeof(struct gameState));
	initializeGame(numPlayer, kc, seed, &G);
	for(i = 0; i < 25; i++){
		G.supplyCount[i] = j;
	}
	flag = isGameOver(&G);
	printf("Endgame for empty Supply Piles\n");
		if(flag == 1){
		printf("Test passed\n");
	}
	else{
		printf("Test failed\n");
	}
	return 0;	
}
