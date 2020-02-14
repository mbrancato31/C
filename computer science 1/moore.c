#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float findNum(int k, float h, int i, float bestRes);

int main(){

    int nTimes;
    
    scanf("%d", &nTimes);
    int k[100], kTemp;
    float h[100], hTemp;

    for(int j = 0; j < nTimes; j++){

        scanf("%d", &kTemp);
        scanf("%f", &hTemp);
        k[j] = kTemp;
        h[j] = hTemp;
    }
   
    for(int j = 0; j < nTimes; j++){

        float res = findNum(k[j], h[j], 0, 1000);

        printf("%.6f \n", res);
    }

    return 0;
}

float findNum(int k, float h, int i, float bestRes){
   
    float n =i * pow(10, -2);
    float res = n + (k/ pow(h, sqrt(n)));

    if(res < bestRes){
        bestRes = res;
    }

    if(n >= 100){
        return bestRes;
    }

    return findNum(k, h, i + 1, bestRes);
}


