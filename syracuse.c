#include "syracuse.h"
#include <stdio.h>

int syra(int n){
    if (n%2==0){
        return n/2;
    } return n*3+1;
}

int test_syra(int n){
    int k = syra(n);
    while (k>n){
        k = syra(k);
    }
    return (k!=n);
}

form ftest(int n, form flist[], int size){
    for (int i = 0; i<size;i++){
        if (n%flist[i].a == flist[i].b){
            return flist[i];
        }
    }
    return (form){1,0};
}


int eq(form f1, form f2){
    if (f1.a<f2.a){
        return eq(f2,f1);
    }
    if (f1.a == f2.a){
        return (f1.b==f2.b);
    }

    return eq(reduce(f1),f2);
}

form reduce(form f){
    return (form){f.a/2,f.b%(f.a/2)};
}

int outflist(form f, form flist[], int size){
    for (int i = 0; i<size; i++){
        if (eq(f,flist[i])){
            return 0;
        }
    }
    return 1;
}

form fsyra(form f){
    if (f.b%2 == 0){
        return (form){f.a/2,f.b/2};
    }
    return (form){3*f.a,3*f.b+1};
}

int test_fsyra(form f){
    if (f.b%2 == 0){
        return 1;
    }
    form k = fsyra(f);
    while (k.a%2==0){

        k = fsyra(k);
        if(k.a<f.a || (f.a==k.a && f.b<k.b)){
            return 1;
        }
    }
    return 0;

}

void calcflist(int size, form flist[]){
    flist[0] = (form){2,0};
    int i = 1;
    int a = 4;
    int b = 0;
    form f;
    while (i<size){
        if (b==a){
            a*=2;
            b = 0;
        }
        f = (form){a,b};
        if (outflist(f,flist,i)){
            if (test_fsyra(f)){
                flist[i] = f;
                i++;
            }
        }
        b++;
    }
}

void afficheflist(form flist[], int size){
    for (int i =0; i<size;i++){
        printf("%dn+%d\n",flist[i].a,flist[i].b);
    }
}