// A+B for Polynomials

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<float.h>

#define maxn 1001

typedef struct ans_pair{
    int exp;
    double coe;
}ANS_PAIR;

int main(void){
    int k;
    double polynomial[maxn];

    ANS_PAIR ans[21];
    int index_ans = 0;

    for(int i=0; i<maxn; i++){
        polynomial[i] = 0;
    }

    scanf("%d", &k);
    for(int i=0; i<k; i++){
        int polynomial_exp;
        double polynomial_coe;
        scanf("%d%lf",&polynomial_exp, &polynomial_coe);
        polynomial[polynomial_exp] += polynomial_coe;
    }

    scanf("%d", &k);
    for(int i=0; i<k; i++){
        int polynomial_exp;
        double polynomial_coe;
        scanf("%d%lf",&polynomial_exp, &polynomial_coe);
        polynomial[polynomial_exp] += polynomial_coe;
    }
    
    for(int i=maxn-1; i>=0; i--){
        if(polynomial[i] < - DBL_EPSILON || polynomial[i] > DBL_EPSILON){
            ans[index_ans].exp = i;
            ans[index_ans].coe = polynomial[i];
            index_ans++;
        }
    }

    if(index_ans == 0)
        printf("0");
    else
        printf("%d ", index_ans);
    for(int i=0; i<index_ans-1; i++){
        printf("%d %.1lf ", ans[i].exp, ans[i].coe);
    }
    if(index_ans!=0)
        printf("%d %.1lf", ans[index_ans-1].exp, ans[index_ans-1].coe);

    return 0;
}