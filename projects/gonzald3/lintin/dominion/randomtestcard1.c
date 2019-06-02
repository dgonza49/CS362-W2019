#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <time.h>


int random_number(int lower, int upper, int count) 
{ 
    int i, num; 
    for (i = 0; i < count; i++) { 
        num = (rand() %(upper - lower + 1)) + lower; 
    } 
	return num;
}

int main() {
	
	srand(time(NULL));
    int player = 0;
    int i, failures = 0;
	struct gameState state, test;
	int k[10] = {village, smithy, gardens, mine, feast, adventurer, council_room, salvager, sea_hag, steward};

	for(i=0, failures=0; i < random_number(0, 500, 1) ; i++ )
	{
		int numPlayers = random_number(0, 50, 1);
		int seed = random_number(1, 1000, 1);

		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &state);		

		printf("----------Village Test #%d---------------\n", i+1);

		state.deckCount[player] = random_number(0, MAX_DECK, 1);
        state.discardCount[player] = random_number(0, MAX_DECK, 1);
        state.handCount[player] = random_number(0, MAX_HAND, 1);		
       
	   
		// copy the game state to a test case
		memcpy(&test, &state, sizeof(struct gameState));

		
		
		cardEffect(village, 0, 0, 0, &state, 0, NULL);

		player = whoseTurn(&test);
	
		
       
		if(test.numActions+2 != state.numActions){
			printf("Failed where two extra action was added\n");
			failures++;
		}
    }

    printf("\n\n");
    printf("Status: %d failures\n", failures);
}