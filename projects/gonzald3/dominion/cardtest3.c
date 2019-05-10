#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "assert.h"
#include <string.h>
#include <time.h>



// Unit Test for Feast

int main () {
	
	printf("TESTING feast \n");
	   
	struct gameState gTest;   
	struct gameState G;
	int player1 = 0;
	int initHandCount;
	//time_t end  = time(NULL) + 7; //7s
	int effect = 1;
	if(effect == 1)
		effect = 0;


	int n;
	int k[10] = {village, smithy, gardens, mine, feast, adventurer, council_room, salvager, sea_hag, steward}; //7 is adventurer

	initializeGame(2, k, 4, &G);

	// copy over to test gameState
	memcpy(&gTest, &G, sizeof(struct gameState));

	// load hand
	gTest.hand[player1][0] = feast;
	for(n = 1; n < 5; n++){
		gTest.hand[player1][n] = k[n+3];
	}

	initHandCount = 6;
	playCard(feast, 1, 0, 0, &gTest);
		
	// Testing that current player has drawn 1 card 
	if (gTest.handCount[player1] == initHandCount) {
		printf("TEST PASSED\n");
	}
	else {
		printf("TEST Failed\n");
		printf("Expected hand count of %d, actual hand count is %d\n", initHandCount, gTest.handCount[player1]);
	}


}

