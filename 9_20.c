#include <stdlib.h>
#include <stdio.h>


FILE *f, *g;


int count;

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

    for( int i = 1; i <= 101; ++i ) {

            seed *= seed;

            int seedCount = counter( seed );
            if( seedCount > 7 ) {

                seed /= 10;
            }

            seed = (seed / 100) % 10000;

            seedCount = counter( seed );
            if( seedCount < 4 ){

              seed = seed * 10 + 7;
            }

        if( i < 101 ) {

        fprintf(f ,"Number: %d\n", seed);
      } else {
        fprintf(g ,"Number: %d\n", seed);

      }
  }
}

int counter( long seedToCount ) {

  count = 0;

  while( seedToCount > 0 ) {               //Count number of the seed's digits

      seedToCount = seedToCount / 10;
      count++;
  }

  return count;
}
