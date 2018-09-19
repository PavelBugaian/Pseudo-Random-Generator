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


long seed = 243;
int seedArray[6];
int j, count = 1;
long seedVar;
long tmp1 = 10000;
int mod = 1;

int disassembler( int count ) {

    int dis_count = count;

    for( int i = 1; i <= dis_count; i++ ) {

        seedVar = seed / tmp1;

        if( seedVar % mod != 0 ) {          //If seed has 1 digit modulo is equal to 0
                                            //If function is declared to prevent this case
            seedVar = seedVar % 10;

            if ( seedVar > 10 ) {

                seedVar /= 10;
            }

            seedArray[i] = seedVar;          //Setting seeds to the array
            tmp1 /= 10;
        }

        else {

            mod *= 10;
        }
    }
}

int generator() {

    seed *= seed;
    seedVar = seed;

    count = 0;

    while( seedVar != 0 ) {               //Count number of the seed's digits

        seedVar = seedVar / 10;
        count++;
    }

    for( j = 1; j <= 10; j++ ) {

        disassembler( count );

        seed = seedArray[2] * 100 + seedArray[3] * 10 + seedArray[4];
        printf("%d \n", seed);

        seed *= seed;
        tmp1 = 10000;
    }
}

int main() {

  generator();

  //int x = (54756 / 1) % 10;
  //printf("\n%d", x);

  return 0;
}
 
