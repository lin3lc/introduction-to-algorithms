#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
int partition(int *a, int p, int r);
void quicksort(int *a, int p, int r);

int main(int argc, char *argv[]){
    int length = argc-1;

    int array[length];
    for(int i=0; i<length; i++){
        array[i] = atoi(argv[i+1]);
    }

    quicksort(array, 0, length-1);


    for(int i=0; i<length; i++){
        printf("%d ", array[i]);
    }
    puts("");
}

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *a, int p, int r){
    int x = a[r];
    int i = p-1;
    for(int j=p; j < r; j++){
        if(a[j] <= x){
            i++;
            swap(a+i, a+j);
        }
    }
    swap(a+i+1, a+r);
    return i+1;
}

void quicksort(int *a, int p, int r){
    if(r>p){
        int q = partition(a, p, r);
        quicksort(a, p, q-1);
        quicksort(a, q+1, r);
    }
}
