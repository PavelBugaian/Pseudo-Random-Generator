#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int randPasha(mod, a, c, count){
    time_t seed;
    seed = time(NULL);

    for(int i = 1; i < count; i++){
        seed = (a * seed * c) % mod;
        printf("%d\n", seed);
    }
}

int main() {

  randPasha(4, 15, 4, 10);

  return 0;
}
