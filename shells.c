#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define X 3.0
#define Y 1.77
#define Z 1.0

#define LOOPS 1000000000


double gameround() {
    int num = rand()%27;

    //< lose    [8/27]
    if (num > 18)
        return 0;

    //< win     [1/27]
    if (!num)
        return X;

    //< cb 1    [6/27]
    if (num <= 6)
        return Y;

    //< cb 2    [12/27]
    return Z;
}


int main() {
    printf("LOOPS: \t%d\n", LOOPS);
    printf("X: \t%lf\n", X);
    printf("Y: \t%lf\n", Y);
    printf("Z: \t%lf\n", Z);
    printf("-----------\n");

    srand(time(NULL));
    int i;
    double balance = LOOPS;

    for (i = 0; i < LOOPS; i++)
        balance -= gameround();

    printf("house edge: %lf\n", 1-(balance/LOOPS));

    return 0;
}

