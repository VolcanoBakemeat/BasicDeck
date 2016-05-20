#include <stdio.h>
#include <string.h>
#include <stdlib.h>//rand
#include <time.h>  //time based seeds
#define MAXLEN 80
#define LINEGAP 5
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
int drawcard(void)
{
    return rand()/1000 % 18; 	//Chooses only in the range of 0-51. with this in a centralized place, I can change it on the fly
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
	do
	{
	scanf("%d",&winner);
	}while(winner<0 || winner > 3);
	return tableau[winner];		//returns the card, not the player number
}

int main (void)
{

  struct card deckmaster[52];
  
  int i;      //gen deck counter
  
  int x=0; 	//player
  int y=0;	//hand positions
  int r=0; // round counter

  char winner[MAXLEN];
  short unsigned int curplay=0;
  short unsigned int handnum;
  short unsigned int rounds = 0;
  srand(time(NULL));	//initializes rand
 
 // printf("How many players?\n"); 
 // scanf("%d",&handnum);
//  getchar();

  do
  {
 	 printf("How many rounds do you wish to play?");
  	 scanf("%d",&rounds);
  }while (rounds>10 || rounds <1);
  
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
  
  strcpy(deckmaster[0].name,"Harry Potter");
  strcpy(deckmaster[1].name,"Hermione Granger");
  strcpy(deckmaster[2].name,"Ron Weasley");
  strcpy(deckmaster[3].name,"Neville Longbottom");
  strcpy(deckmaster[4].name,"Dumbledore");
  strcpy(deckmaster[5].name,"Snape");
  strcpy(deckmaster[6].name,"Voldemort");
  strcpy(deckmaster[7].name,"Sirus Black");
  strcpy(deckmaster[8].name,"Remus Lupin");
  strcpy(deckmaster[9].name,"Draco Malfoy");
  strcpy(deckmaster[10].name,"Dudley Dursley");

  
  strcpy(deckmaster[11].name,"DanIsNotOnFire");
  strcpy(deckmaster[12].name,"AmazingPhil");
  strcpy(deckmaster[13].name,"Dil Howelter");
  strcpy(deckmaster[14].name,"Susan2");
 
  strcpy(deckmaster[15].name,"Percy Jackson");
  strcpy(deckmaster[16].name,"Sally Jackson");
  strcpy(deckmaster[17].name,"Annabeth Chase");
  strcpy(deckmaster[18].name,"Rachel Elizabeth Dare");
/*	printf("Our noble combatants:\n");		//For some reason this cuts off the first letter of the name.
	for(i=0; i<handnum; ++i)
	{
		printf("Player %d: %s\n",i+1,handles[i]);
	}
*/

	//fills player hands. May spin into own function.
	for(x=0;x<handnum;++x)
	{
		for(y=0;y<7;++y)
		{
			play[x][y]=drawcard();
		}
	}

 for(r=0; r<rounds; ++r)
 {
	
	//I'm trying to rewite this so it does the actual gameplay
  printf("Players, %s needs a companion this round!\n",deckmaster[drawcard()].name);
  
  for(curplay=0; curplay<4; ++curplay)     //Now prints, does not fill
  {
	printf("Player %d:\n",curplay+1);
   	for(y=0; y<7; ++y)
  	{
  	 	printf("%d %s ",y+1, deckmaster[play[curplay][y]].name);	//After I make cards, I'll have this print the name.
   
   	}
    printf("\n");
    table[curplay] = playball(curplay, play);
  }
  
 // for (i=0;i<4;++i)
 // {
//  table[i]=playball(i,play);
 // }
  
  printf("Judge, choose from among these!\n");
  for (i=0;i<handnum;++i)
  {
  	printf("%d. %s\n",i, deckmaster[table[i]].name);
  }
  strcpy(winner, deckmaster[judgement(table)].name);	//doozy of a line.
  printf("Winning card is %s\n",winner);
  
}
  return 0;

}
