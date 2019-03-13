#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>

int initializeFeld(char feld [8][8]);
int spiel(char feld [8][8]);
int voll = 0;

//main Funktion
int main(){
  char feld[8][8];

  initializeFeld(feld);
  /*char feld[8][8] = { {' ',' ',' ',' ',' ',' ',' ',' '},
          {' ',' ',' ',' ',' ',' ',' ',' '},
          {' ',' ',' ',' ',' ',' ',' ',' '},
          {' ',' ',' ',' ',' ',' ',' ',' '},
          {' ',' ',' ',' ',' ',' ',' ',' '},
          {' ',' ',' ',' ',' ',' ',' ',' '},
          {' ',' ',' ',' ',' ',' ',' ',' '},
          {'x',' ',' ',' ',' ',' ',' ',' '} };*/

  while(!voll) {
    spiel(feld);
  }
}

void print(char feld [8][8]){
  int m,n;

  for (m=0;m<8;m++)
  {
   printf ("\n+--+--+--+--+--+--+--+--+\n");
   printf("|");
               for (n=0;n<8;n++)
               {
                printf("%c", feld[m][n]);
                printf(" |");
               }
  }
  printf ("\n+--+--+--+--+--+--+--+--+\n");
}

int spiel(char feld [8][8]){
  int eingabe,i,j,k;

  print(feld);

  //Eingabeaufforderung
  printf("Bitte eine Zahl zwischen 1 und 8 eingeben\n");
  scanf("%1i", &eingabe);
  printf("Sie haben die Zahl %i eingegeben\n", eingabe);

  if (eingabe>=1 && eingabe<=8) {
    //Freie Zeile aussuchen und einen Block mit der Eingabegröße einfügen

    for(i=7; i>=0; i--) {
      for(j=0; j<8; j++) {
        if(feld[i][j] == ' ' && j+eingabe<=8) {
          for(k=0; k<eingabe; k++) {
            printf("k: %d; i: %d; j: %d; eingabe: %d",k,i,j,eingabe);
            feld[i][j+k] = 'X';
          }
          print(feld);
          return 0;
        }
      }
    }
    print(feld);
  }
  voll = 1;
  return 1;
}

int  initializeFeld(char feld [8][8]){
  int i,j;
  for(i=0; i<8; i++){
    for(j=0; j<8; j++){
      feld[i][j]=' ';
    }
  }
  return 0;
}
