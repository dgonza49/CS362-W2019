#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int main () {
	
	printf("TESTING council_room \n");
	struct gameState G;          
	struct gameState gTest;          
	int seed = 1000;
	int k[10] = {village, smithy, gardens, mine, feast, adventurer, council_room, salvager, sea_hag, steward};
	int player1 = 0;
	int players = 2;
	int numTests = 1; 
	//int card = smithy;
	int effect = 1;
	//int initHandCount;
	int position;


	if(effect == 1)
		effect = 0;

	int i;
	int n;
	for (i = 0; i < numTests; i++) {

		// initialize the game
		initializeGame(players, k, seed, &G);

		// copy over to test gameState
		memcpy(&gTest, &G, sizeof(struct gameState));

		// load hand
		gTest.hand[player1][0] = council_room;
		int preNumCards = G.handCount[0];
		int preNumBuys = G.numBuys;
		//int kingCards = 14;
		for(n = 1; n < 5; n++){
			gTest.hand[player1][n] = k[n+3];
		//kingCards++;
		}

		//initHandCount = 6;
		position = gTest.hand[player1][0]; //smithy ready to play

		effect = cardEffect(council_room, 0, 0, 0, &gTest, position, 0);

		//Testing if council_room draws 4 and increments NumBuys for player, and draws 1 for remaining players
		cardEffect(council_room, 0, 0, 0, &gTest, position, 0);
		if(gTest.handCount[0] == preNumCards + 3)
			printf("HandCount TEST PASSED\n");
		else
			printf("HandCount TEST FAILED\n");
		
		//printf("%d", G.numBuys);
		//preNumBuys++;
		if(gTest.numBuys == preNumBuys + 1)
			printf("numBuys TEST PASSED\n");
		else 
			printf("numBuys TEST FAILED\n");
	}

	return 0;
}
/*	
	struct gameState G;
	int k[10] = {village, smithy, gardens, mine, feast, adventurer, council_room, salvager, sea_hag, steward};

	initializeGame(2, k, 3, &G);
	G.handCount[0] = 3;
	G.hand[0][0] = council_room; //council_room
	int preNumCards = G.handCount[0];
	int preNumBuys = G.numBuys;

	//Testing if council_room draws 4 and increments NumBuys for player, and draws 1 for remaining players
	cardEffect(council_room, 0, 0, 0, &gTest, position, 0);
	if(G.handCount[0] == preNumCards + 4)
		printf("TEST PASSED\n");
	else
		printf("TEST FAILED\n");
	
	printf("%d", G.numBuys);
	//preNumBuys++;
	if(G.numBuys == preNumBuys + 1)
		printf("TEST PASSED\n");


}*/