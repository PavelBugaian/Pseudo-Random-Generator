#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


FILE *f, *g;


int count;
int listN[6];

int main() {

    f = fopen("random1.txt", "w");
    g = fopen("secret.txt", "w");

    int x;

    printf("Write initial 4-digit number: ");
    scanf("%d", &x);

    generator( x );

    fclose(f);
    fclose(g);

    return 0;
  }

int generator( long seed ) {

    for( int i = 1; i <= 1000; ++i ) {

            seed *= seed;

            if( seed > 10000000 ) {

                seed /= 10;
            }

            seed = (seed / 100) % 10000;

            Memorate (seed);                    //Write seed into listN
            if (CheckNumber (seed))             //Checking if the seed doesn't repeat
              seed = seed + 7;

            if( i < 101 ) {

                fprintf(f ,"%d\n", seed);
              }

              else {

                fprintf(g ,"%d\n", seed);
              }

            if( seed < 1000 ){

                seed = seed * 10 + 7;
            }
  }
}

void Memorate (int n) {
  for (int j = 5; j > 0; j--) {
    listN[j] = listN[j-1];
  }
  listN[0] = n;
}

int CheckNumber (int n) {
  for (int i = 5; i >= 0; i--)
    if (n == listN[i])
      return true;

  return false;
}
