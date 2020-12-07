#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

double xa, ya, xb, yb;

double f(double x){
    double AC = sqrt((xa-x)*(xa-x) + ya*ya);
    double BC = sqrt((xb-x)*(xb-x) + yb*yb);
    return AC+BC;
}

main(){
    scanf("%lf%lf%lf%lf", &xa, &ya, &xb, &yb);
    double rr=max(xa, xb);
    double ll=min(xa, xb);
    double ml=(ll+ll+rr)/3;
    double mr=(ll+rr+rr)/3;

    while (ll!=ml && ml!=mr && mr!=rr){
        if (f(ml) > f(mr)) ll=ml;
        else rr=mr;
        ml=(ll+ll+rr)/3;
        mr=(ll+rr+rr)/3;
    }

    printf("answer = %lf\n", (ll+rr)/2);
    printf("cost = %lf\n", f((ll+rr)/2));
}