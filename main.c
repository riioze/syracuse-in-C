#include "syracuse.h"
#include <stdio.h>
#include <time.h>
#define SIZE 50
#define MAX 1000000000


int main(){
    syra(1);
    form flist[SIZE];
    calcflist(SIZE,flist);
    afficheflist(flist,SIZE);
    form f;
    int max = MAX;
    clock_t start, end;
    double cpu_time_used;
    printf("max : ");
    //scanf("%d",&max);
    start = clock();
    for(int i = 2; i<max; i++){
        f = ftest(i,flist,SIZE);
        if (f.a == 1){
            printf("%d : %d\n",i,test_syra(i));
        }//  else {
        //     printf("%d : (form %dn+%d)\n",i,f.a,f.b);
        // }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%.2f\n",cpu_time_used);
    return 0;
}