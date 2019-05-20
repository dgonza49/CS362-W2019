#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include "rngs.h"

int adventurerCard(int *drawntreasure, struct gameState *state, int *cardDrawn, int *currentPlayer, int *temphand, int *z);


int random_number(int lower, int upper, int count) 
{ 
    int i, num; 
    for (i = 0; i < count; i++) { 
        num = (rand() %(upper - lower + 1)) + lower; 
    } 
	return num;
}

int main(int argc, char const *argv[]){
	
	struct gameState game;
	int i, j;
	int k[10] = {village, smithy, gardens, mine, feast, adventurer, council_room, salvager, sea_hag, steward};
	int drawntreasure;
	int player;
	int temphand[MAX_HAND]; 
	int z;
	int cardDrawn;
	int myCard = 1;
	if(myCard)
		myCard = 0;
	int tempcoins;

	for (i = 0; i < random_number(0, 100, 1); i ++){ 
		initializeGame(random_number(2,4, 1), k, random_number(1, 9, 1), &game); 
		player = game.whoseTurn; 
		for (j = 0; j < random_number(0, 25, 1); j++){ 
			drawntreasure = random_number(0, 10, 1); //What happens if you start with drawntreasure
			//drawCard(player, &game); //What happens if you draw a card prematurely
			//z = random_number(0, 500); //If z is higher than 0, it produces a significant access error
			tempcoins = game.coins;

			myCard = adventurerCard(&drawntreasure, &game, &cardDrawn, &player, temphand, &z);
			if (tempcoins > game.coins)
				printf("Error: tempcoins [%d] game.coins[%d]\n", tempcoins, game.coins);
			else
				printf("Passed: tempcoins [%d] game.coins[%d]\n", tempcoins, game.coins);
		}
	}

	return 0;
}