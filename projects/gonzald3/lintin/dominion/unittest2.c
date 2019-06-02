/* villageCardEffect()*/


#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>



// Tests shuffle() 
int main()
{
	printf("TESTING shuffle() of Kingdom Cards\n");

	srand(time(NULL));
	int seed = 1000;
	int numplayers = rand() % (MAX_PLAYERS - 1) + 1;
	int player = rand() % numplayers;
	struct gameState g;
	int k[10] = {village, smithy, gardens, mine, feast, adventurer, council_room, salvager, sea_hag, steward};
	initializeGame(numplayers, k, seed, &g);

	 // Copy gamestate for later comparison
	struct gameState prevDeck;
	memcpy(&prevDeck, &g, sizeof(struct gameState));


	int numtests = 100;
	int unshuffledNum = 0;
	for(int i = 0; i < numtests; i++){
		shuffle(player, &g);
		if(memcmp(&prevDeck.deck[player], &g.deck[player], sizeof(int)* MAX_DECK) != 0) 
			unshuffledNum++;
	}

	int shuffleSuccess = numtests - unshuffledNum;
	printf("Shuffle Percentage: %d/%d \n", shuffleSuccess, numtests);

	if(unshuffledNum < numtests )
			printf("TEST PASSED \n");
	else
		printf("TEST FAILED \n");
	
	printf("--------------Test Complete-----------------------\n");

}

