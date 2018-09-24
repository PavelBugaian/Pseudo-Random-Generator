#include<stdio.h>
#include<stdlib.h>
int a,i,seed,seed_1,counter;
FILE *random, *secret;
int randomer (seed) {
for(i=0;i<=101;i++) {
seed*=seed;

seed=seed / 100 %10000;
printf(" %d \n",seed);
counter++;
if (counter<=100){
fprintf(random,"%d \n",seed);
}
if(counter==101){
fprintf(secret,"%d", seed);
}
seed=seed+139;
}
}
int main() {
random=fopen("numbers.txt","w");
secret=fopen("secret.txt","w");
printf(" Enter 4-digit number: ");
scanf("%d",&seed);
randomer (seed);
fclose(random);
fclose(secret);
return 0;
}
