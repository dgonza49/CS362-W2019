#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "assert.h"
#include <string.h>


int main() {
	struct gameState g;          
	struct gameState gTest;          
	int seed = 1000;
	int k[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int player1 = 0;
	int players = 2;
	int numTests = 1; 
	int card = smithy;
	int effect = 1;
	int initHandCount;
	int position;


	if(effect == 1)
		effect = 0;

	printf("TESTING smithy \n");

	int i;
	int n;
	for (i = 0; i < numTests; i++) {

		// initialize the game
		initializeGame(players, k, seed, &g);

		// copy over to test gameState
		memcpy(&gTest, &g, sizeof(struct gameState));

		// load hand
		gTest.hand[player1][0] = smithy;
		int kingCards = 14;
		for(n = 1; n < 5; n++){
		gTest.hand[player1][n] = kingCards;
		kingCards++;
		}

		initHandCount = gTest.handCount[player1];
		position = gTest.hand[player1][0]; //smithy ready to play

		effect = cardEffect(card, 0, 0, 0, &gTest, position, 0);

		// Testing that current player has drawn 3 cards
		//The player has actually drawn 10 card!
		if (gTest.handCount[player1] == initHandCount + 2) {
			printf("TEST Failed\n");
			printf("Expected hand count of %d, actual hand count is %d\n\n", initHandCount+2, gTest.handCount[player1]);
		}
		else {
			printf("TEST PASSED\n");
		}
	}

	return 0;
}