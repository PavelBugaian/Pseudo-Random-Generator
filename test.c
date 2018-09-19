/*#include <stdlib.h>
#include <stdio.h>

long int seed = 23468;

int generator() {

   int n;

   for( int i = 1; i <= 101; i++ ) {

     seed *= seed;
     //n = div(seed, 100);
     //seed = n.rem;

     seed = abs(( seed / 10 ) %  10000);

     printf( "%d ", seed );

   }
}

int main() {

  generator();

  return 0;
} */

#include <stdlib.h>
#include <stdio.h>

long seed = 234;

int generator() {

    int seedArray[6];
    int count = 1;
    int seedVar;
    int tmp1 = 10000;
    int mod = 1;

    seed *= seed;
    seedVar = seed;

    while( seedVar != 0 ) {               //Count number of the seed's digits

        printf("%d \n", seedVar);

        seedVar = seedVar / 10;
        count++;
    }

    for( int j = 1; j <= 10; j++ ) {

        for( int i = 1; i <= count; i++ ) {

            seedVar = seed / tmp1;

            if( seedVar % mod != 0 ) {       //If seed has 1 digit modulo is equal to 0
                                             //If function is declared to prevent this case
                seedVar = seedVar % 10;
            }

            else {

                mod *= 10;
            }

            seedArray[i] = seedVar;          //Setting seeds to the array
            tmp1 /= 10;

            printf("\n%d", seedArray[i]);
        }

        seed = seedArray[1] * 100 + seedArray[2] * 10 + seedArray[3];
        seed *= seed;

        printf("%d \n", seed);
    }
}

int main( ) {

  generator();

  //int x = (54756 / 1) % 10;
  //printf("\n%d", x);

  return 0;
}
 
