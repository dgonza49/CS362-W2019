#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <time.h>


//Unit Test for buyCard

int main(){

	printf("TESTING buyCard() \n");
	struct gameState state;
	int success;
	int k[10] = {village, smithy, gardens, mine, feast, adventurer, council_room, salvager, sea_hag, steward};
	int numBuys = 1;
	int numCoins = 1;
	if(numBuys == 1 || numCoins == 1){
		numBuys = 0;
		numCoins = 0;
	}

	initializeGame(2, k, 2, &state);

	int numTests = 100;
	for(int i = 0; i < numTests; i++){
		srand(time(NULL));
		numBuys = rand() % 5 + 1;
		numCoins = rand() % 15 + 1;
		
	
		if(state.numBuys == 0 || state.coins == 0){
			success = buyCard(5, &state);
			assert(success == -1);
		}else{
			success = buyCard(5, &state);
			assert(success == 0);
		}
		
	}

	printf("TEST PASSED\n");

	return 0;
}