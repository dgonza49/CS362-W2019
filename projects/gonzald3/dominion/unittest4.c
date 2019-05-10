#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#

int main () {

	printf("TESTING updateCoins() \n");
	struct gameState g;
	int seed = 1000;
	
	int k[10] = {village, smithy, gardens, mine, feast, adventurer, council_room, salvager, sea_hag, steward};
	initializeGame(2, k, seed, &g);
	//initialize Hand with one gold
	g.handCount[0] = 1;
	g.hand[0][0] = gold;
	int r = 0;
	if(r == 0)
		r = updateCoins(0, &g, 2);
	
	//check if update coins with bonus works by testing coins
	int Coins = g.coins;
	assert(Coins == 5);
	printf("TEST PASSED\n");


}