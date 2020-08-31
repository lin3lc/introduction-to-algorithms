#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
 * max_heapify O(lg(n)) build_max_heap O(n) 
 * heap_sort O(n*lg(n))
 */

void swap(int *a, int *b);
//int parent(int i);
int left(int i);
int right(int i);

void max_heapify(int *a, int i);
void build_max_heap(int *a);
void heap_sort(int *a);

int array_length = 0, heap_size = 0;

int main(int argc, char *argv[]){
    int length = argc-1;

    int array[length];
    for(int i=0; i<length; i++){
        array[i] = atoi(argv[i+1]);
    }

    array_length = length;
    heap_sort(array);


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

/*
int parent(int i){
    int parent = i/2;
    return parent;
}
*/

int left(int i){
    int left = i*2;
    return left;
}

int right(int i){
    int right = i*2 + 1;
    return right;
}

void max_heapify(int *a, int i){
    int l = left(i);
    int r = right(i);
    int largest = i;

    if(l < heap_size && a[l] > a[i]){
        largest = l;
    }
    if(r < heap_size && a[r] > a[largest]){
        largest = r;
    }
    if(largest != i){
        swap(&a[i], &a[largest]);
        max_heapify(a, largest);
    }
}


void build_max_heap(int *a){
    heap_size = array_length;
    for(int i = array_length/2; i >= 0; i--){
        max_heapify(a, i);
    }
}

void heap_sort(int *a){
    build_max_heap(a);
    for(int i = array_length-1; i >= 1; i--){
        swap(&a[0], &a[i]);
        heap_size--;
        max_heapify(a, 0);
    }
}
