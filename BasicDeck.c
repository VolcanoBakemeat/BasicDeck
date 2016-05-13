#include <stdio.h>
#include <string.h>
#include <stdlib.h>//rand
#include <time.h>  //time based seeds
#define MAXLEN 80

//Here's an idea, put player handles in a seperate array. Location in handle array correspond to hands in play array. This works like a dreamfairy
//Also, make player number changeable. Scrapped for now.
struct card
{
	char name[MAXLEN];
	char description[MAXLEN];
	int id;			//Numerical id. 
	int taken;
};
/*
	randomly chooses card.
*/
int drawcard(void)		//why does this need to be its own function
{
    return rand()/1000 % 52; 	//Chooses only in the range of 0-51. with this in a centralized place, I can change it on the fly
}
/*
	This function (right now hardcoded so it only works with playnum =4) displays hands for each player and allows player to select card to put into table array
	you might need to make a different function for every permissible number of players, if you can't think of something clever.
*/
int playball (int player, int p[4][7])
{
	int k;
	int l;
	int chosen;

	printf("Player %d cards: ",player+1);
	for (l=1; l<=7; ++l)
	{
		printf("|%d. %d ",l, p[player][l-1]);
	}
	printf("\n Noble champion, what card do you wish to play?");
	scanf("%d",&chosen);
	return p[player][chosen-1];
	
}
/*
	This function takes array table[4] from funtion main and presents it to the judge.
	the judge can indicate selection, and in the final game this will increase that players points.
	this is why handles would be useful, so the judge can keep the players straight.
	will need to modify so that cards will display.
*/
int judgement(int tableau[4])
{
	int i;
	int winner;
	printf("Judge, which card wins this competition?\n");
	for(i=0;i<4;++i)
	{
		printf("%d. %d\n",i+1,tableau[i]);
	}
	scanf("%d",&winner);
	return winner;
}


int main (void)
{

  struct card deckmaster[52];
  
  int i;      //gen deck counter
  
  int x=0; 	//player
  int y=0;	//hand positions

  short unsigned int handnum;
  srand(time(NULL));	//initializes rand
 
 // printf("How many players?\n"); 
 // scanf("%d",&handnum);
//  getchar();
 
  handnum = 4;		//Every game automatically 4 players for now.
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

    deckmaster [i].id = i+1;
	deckmaster [i].taken = 0;
  }
  
  

/*	printf("Our noble combatants:\n");		//For some reason this cuts off the first letter of the name.
	for(i=0; i<handnum; ++i)
	{
		printf("Player %d: %s\n",i+1,handles[i]);
	}
*/

	//fills player hands.
  for(x=0; x<handnum; ++x)     //Now fills array play instead of simply printing.

  {
	printf("Player %d:\n",x+1);
   for(y=0; y<7; ++y)
   {
   	play[x][y]= drawcard();
   	printf("%d ",deckmaster[play[x][y]].id);	//After I make cards, I'll have this print the name.
   }

    printf("\n");
  }
  
  for (i=0;i<4;++i)
  {
  table[i]=playball(i,play);
  }
  
  
  judgement(table);
  return 0;

}
