#include <stdio.h>
#include <time.h>

FILE *f;

int m = 16384, a = 17893, c, x, i;


int main()
{
  time_t now;
  struct tm *tm;

  f = fopen("random.txt", "w");

  now = time(0);
    tm = localtime (&now);


  x = c = tm-> tm_sec;

     for (i = 1; i <= 10; i++)
      {

    x = (a * x+ c) % m;
    fprintf (f,"%d ", x);}
    fclose(f);
    return 0;

}
