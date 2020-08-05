#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void merge(int *a, int p, int q, int r);
void merge_sort(int *a, int p, int r);

int main(int argc, char *argv[]){
    int length = argc-1;

    int array[length];
    for(int i=0; i<length; i++){
        array[i] = atoi(argv[i+1]);
    }

    merge_sort(array, 0, length-1);


    for(int i=0; i<length; i++){
        printf("%d ", array[i]);
    }
    puts("");
}


void merge(int *a, int p, int q, int r){
    //复制2个字数组加哨兵
    int n1 = q-p+1;
    int n2 = r-q;
    int left[n1+1], right[n2+1];
    for(int i=0; i<n1; i++){
        left[i] = a[p+i];
    }
    for(int i=0; i<n2; i++){
        right[i] = a[q+i+1];
    }
    left[n1] = INT_MAX;
    right[n2] = INT_MAX;

    int i = 0, j = 0;
    for(int k=p; k<=r; k++){
        if(left[i] < right[j]){
            a[k] = left[i];
            i++;
        } else {
            a[k] = right[j];
            j++;
        }
    }
}

void merge_sort(int *a, int p, int r){
    if(r>p){
        int q = (p+r)/2;
        merge_sort(a, p, q);
        merge_sort(a, q+1, r);
        merge(a, p, q, r);
    }
}
