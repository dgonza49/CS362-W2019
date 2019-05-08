#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "assert.h"

//In the refactored smithyCard() 
//Test for whoseTurn()
/*
int whoseTurn(struct gameState *state) {
  return state->whoseTurn;
}

*/

int main(){
	
	printf("TESTING whoseTurn() \n");
	
	struct gameState g;
	
	int n = rand() % 20 + 1; //randomly generate a # of turns
	int curState = 0;
	
	//While there are still turns
	while(n != 0){
		//make sure that the whoseTurn() matches the gameState
		g.whoseTurn = n;
		curState = whoseTurn(&g);
		assert(curState == n);
		n--;
	}
	
	printf("TEST PASSED\n");
	
	
	return 0;
}