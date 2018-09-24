#include<stdio.h>
#include<stdlib.h>

int a, b = 10000, i, seed;
FILE *random, *secret;

void randomer (seed) {
    for (i = 0; i <= 101; i++) {
        seed*=seed;
        seed=seed / 100 % b;
        fprintf (random,"%d \n", seed);
        seed = seed + 139;
    }

    seed *= seed;
    seed = seed / 100 % 10000;
    fprintf (secret,"%d", seed);
}

void main() {
    random = fopen ("numbers.txt","w");
    secret = fopen ("secret.txt","w");

    printf ("Enter 4-digit number: ");
    scanf ("%d", &seed);

    randomer (seed);

    fclose (random);
    fclose (secret);
}
