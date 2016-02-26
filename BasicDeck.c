#include <stdio.h>
#include <string.h>
#define MAXLEN 80

//Here's an idea, put player handles in a seperate array. Location in handle array correspond to hands in play array. This works like a dreamfairy
//Also, make player number changeable.
int main ()

{

  int deckmaster[52];

  int i;      //gen deck counter

  int m=0;   //printdeck counter
  
  int x=0; 	//player
  int y=0;	//hand positions
  short unsigned int handnum;
 
 
  printf("How many players?\n");
  scanf("%d",&handnum);
 // getchar();
  int play[handnum][7];	//cards in play
  char handles[handnum][80];
  
  for (i=0;i<handnum;++i)
  {
  	printf("Player %d, what is your handle?\t",i+1);
  	fgets(handles[i],MAXLEN,stdin);
  	getchar();
  }

  //strcpy(handles[0], "Mikazuki");		//In future, user will be able to assign player names
  //strcpy(handles[1], "Orga");
  //strcpy(handles[2], "Kudelia");
  //strcpy(handles[3], "Naze");


  

  for(i=0;i<52;++i)     //generates deck. The reason for even having a deck is because it won't always be just numbers

  {

    deckmaster [i] = i+1;

  }




  for(x=0; x<handnum; ++x)     //Now fills array play instead of simply printing. Plan to randomise in future.

  {

   for(y=0; y<7; ++y)
   {
   	play[x][y]= deckmaster[m];
   	printf("%d ",play[x][y]);	//remember to change special char to reflect any new variables
   	++m;						//m is initalised at 0 at top of code
   }

    printf("\n");

  }

  return 0;

}
