#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "assert.h"



// Unit Test for Adventurer

int main () {
	
	printf("TESTING adventurer \n");

	struct gameState G;
	int k[10] = {7, 8, 9, 10, 11, 12, 13, 14, 15, 16}; //7 is adventurer

	initializeGame(2, k, 4, &G);

	assert(cardEffect(adventurer, 0, 0, 0, &G, 0, NULL) == 0);
	printf("TEST PASSED\n");

}