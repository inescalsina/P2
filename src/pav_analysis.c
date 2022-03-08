#include <math.h>
#include "pav_analysis.h"

float compute_power(const float *x, unsigned int N) {
    float sum = 1e-12;
    for(unsigned int i=0;i<N;i++){
        //No merece la pena utilizar la funcion pow puesto que requiere muchas mas operaciones
        sum=sum+x[i]*x[i];
    }
    return 10*log10(sum/N);
}

float compute_am(const float *x, unsigned int N) {
    float sum=0;
    for(unsigned int i =0;i<N;i++){
        sum=sum+fabs(x[i]);
    }
    return sum/N;
}

float compute_zcr(const float *x, unsigned int N, float fm) {
    float zcr,sum=0;
    for(unsigned int i=1;i<N;i++){
        if(x[i]*x[i-1]<0){
            sum=sum+1;
        }
    }
    return sum/(2*(N-1));
}
