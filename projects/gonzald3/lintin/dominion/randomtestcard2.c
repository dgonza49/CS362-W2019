#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>


int random_number(int lower, int upper, int count) 
{ 
    int i, num; 
    for (i = 0; i < count; i++) { 
        num = (rand() %(upper - lower + 1)) + lower; 
    } 
	return num;
}



int main() 
{
	srand(time(NULL));
	int i;
	int player = 0;
	struct gameState state, test;
	int k[10] = {village, smithy, gardens, mine, feast, adventurer, council_room, salvager, sea_hag, steward};

	for(i=0; i < random_number(0, 100, 1); i++ ){
		int numPlayers = (rand() % 50);
		int seed = (rand() % 5000);

		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &state);		

		printf("---------Smithy Test #%d----------\n", i+1);

		// copy the game state to a test case
		memcpy(&test, &state, sizeof(struct gameState));

		cardEffect(smithy, 0, 0, 0, &state, 0, NULL);

		player = whoseTurn(&test);
		
		//Check if player played smithy
		if(test.playedCardCount + 1 == state.playedCardCount)
			printf("Passed where player discarded smithy\n");
		else
			printf("Failed where player did not discard smithy\n");
			
		
		if(test.handCount[player] + 2 == state.handCount[player])
			printf("Passed where 3 extra cards were drawn\n");
		else
			printf("Failed where 3 extra cards were not drawn\n");
		}
	printf("---------------------------------------------\n");
}