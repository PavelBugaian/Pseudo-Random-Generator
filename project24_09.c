/*#include <stdlib.h>
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
*/

#include <stdio.h>
#include <time.h>

int seed, i, n = 1000;
int a = 163, b = 1987;
int input;

int main () {
  time_t t = time(NULL);

  printf("Write input number");
  scanf("%d", &input);

  int h = (t / 3600) % 24;
  int m = (t / 60) % 60;
  int s = t % 60;

  seed = 1;
  seed = (h + m + s);

  while(i != 101) {
    seed = (a * seed + b) % n;
    if(seed <= input){
      printf("%3d\n", seed);
      i++;
    }
  }
  return 0;
  }
