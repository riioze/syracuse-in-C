

typedef struct _form {
    int a,b;
} form;

int syra(int n);
int test_syra(int n);
form ftest(int n, form flist[], int size);
int eq(form f1,form f2);
form reduce(form f);
int outflist(form f, form flist[], int size);
void calcflist(int size, form flist[]);
form fsyra(form f);
int test_fsyra(form f);
void afficheflist(form flist[], int size);