#include <stdio.h>
#include <string.h>
#include <stdlib.h>//rand
#include <time.h>  //time based seeds
#define MAXLEN 80

//Here's an idea, put player handles in a seperate array. Location in handle array correspond to hands in play array. This works like a dreamfairy
//Also, make player number changeable. Scrapped for now.
/*
	randomly chooses card.
*/
int drawcard(void)
{
	int r;
    r= rand()/1000;
    return r;
}
/*
	This function (right now hardcoded so it only works with playnum =4) displays hands for each player and allows player to select card to put into table array
*/
int playball (int player, int p[4][7])
{
	int k;
	int l;
	for(k=0;k<4;++k)
	{
		printf("Player %d cards:",k+1);
	}
}


int main (void)
{

  int deckmaster[52];
  
  int i;      //gen deck counter

  int m=0;   //printdeck counter
  
  int x=0; 	//player
  int y=0;	//hand positions
  int r;
  short unsigned int handnum;
  srand(time(NULL));	//initializes rand
 
  printf("How many players?\n"); 
  scanf("%d",&handnum);
  getchar();
  int table[handnum]; //cards played on table
  int play[handnum][7];	//cards in play
 
 // char handles[handnum][MAXLEN];	Abandoning handles to work on something more productive
  
 
  
/*  for (i=0;i<4;++i)
  {
  	printf("Player %d, what is your handle?\n",i);
  	fgets(handles[i], MAXLEN, stdin);
  	getchar();
  }*/

  //strcpy(handles[0], "Mikazuki");		//In future, user will be able to assign player names
  //strcpy(handles[1], "Orga");
  //strcpy(handles[2], "Kudelia");
  //strcpy(handles[3], "Naze");



  for(i=0;i<52;++i)     //generates deck. The reason for even having a deck is because it won't always be just numbers. It won't always be 52 cards either

  {

    deckmaster [i] = i+1;

  }
  
  

/*	printf("Our noble combatants:\n");		//For some reason this cuts off the first letter of the name.
	for(i=0; i<handnum; ++i)
	{
		printf("Player %d: %s\n",i+1,handles[i]);
	}
*/

	//fills player hands. Ooh, ooh, create a drawcard function
  for(x=0; x<handnum; ++x)     //Now fills array play instead of simply printing.

  {
	printf("Player %d:\n",x+1);
   for(y=0; y<7; ++y)
   {
   	play[x][y]= deckmaster[drawcard()];
   	printf("%d ",play[x][y]);	//remember to change format char to reflect any new variables
   	++m;						//m is initalised at 0 at top of code
   }

    printf("\n");
  }

  return 0;

}
