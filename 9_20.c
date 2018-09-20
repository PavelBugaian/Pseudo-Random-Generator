  #include <stdlib.h>
  #include <time.h>
  #include <stdio.h>

  int count;

  int main() {

      int x;

      printf("Write initial 4-digit number: ");
      scanf("%d", &x);

      generator( x );

      return 0;
    }

  int generator( long seed ) {

      for( int i = 1; i <= 101; ++i ) {

          seed *= seed;

          int seedCount = counter( seed );
          if( count > 8 ) {

              seed /= 10;
          }

          seed = (seed / 100) % 10000;
          long a = seed;

          seedCount = counter( seed );
          if( count < 4 ){

              seed = seed * 10 + 7;
          }

          seed = a;

          printf("Number: %d\n", seed);
      }
  }

  int counter( long seedToCount ) {

    count = 0;

    while( seedToCount > 10 ) {               //Count number of the seed's digits

        seedToCount = seedToCount / 10;
        count++;
    }

    return count;
  }
