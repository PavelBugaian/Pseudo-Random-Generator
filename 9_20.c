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

    for( int i = 1; i <= 1000; ++i ) {

            seed *= seed;

            if( seed > 10000000 ) {

                seed /= 10;
            }

            seed = (seed / 100) % 10000;


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
