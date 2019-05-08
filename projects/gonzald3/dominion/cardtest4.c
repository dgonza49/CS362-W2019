#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main () {
	printf("TESTING council_room \n");
	struct gameState G;
	int k[10] = {7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

	initializeGame(2, k, 3, &G);
	G.handCount[0] = 3;
	G.hand[0][0] = 8; //council_room
	int preNumCards = G.handCount[0];
	int preNumBuys = G.numBuys;

	//Testing if council_room draws 3 and increments NumBuys for player, and draws 1 for remaining players
	playCard(0, 1, 0, 0, &G);
	assert(G.handCount[0] == preNumCards + 3);
	assert(G.numBuys == preNumBuys + 1);

	printf("Test PASSED\n");

}