#include "dominion.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>
#include "rngs.h"

int main () {
	printf("TESTING gardens \n");

	struct gameState G;
	int k[10] = {7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

	initializeGame(2, k, 3, &G);
	G.handCount[0] = 3;
	G.hand[0][0] = 10; //gardens

	//does gardens returns -1
	int r = playCard(0, 1, 0, 0, &G);
	assert(r ==  -1);

	printf("Test PASSED\n");

}
