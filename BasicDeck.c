#include <stdio.h>

int main ()

{

  int deckmaster[52];

  int i;      //print deck counter

  int m =1;   //printdeck counter




  

  for(i=0;i<52;++i)     //generates deck

  {

    deckmaster [i] = i+1;

  }




  for(i=0; i<52;++i)     //prints entire deck

  {

    ++m;                //counter for newline

    if((m)%7 == 0)      //Generates newline every seven or so cards

    {

      printf("\n");

    }




    printf("%d ",deckmaster[i]);

  }

  return 0;

}
