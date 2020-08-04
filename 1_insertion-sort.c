#include <stdio.h>
#include <stdlib.h>

/*
 * 待排序的数组作为程序参数，以空格隔开
 * 
 */
int main(int argc, char *argv[]){
    int length = argc-1;

    int array[length];
    for(int i=0; i<length; i++){
        array[i] = atoi(argv[i+1]);
    }

    for(int j=1; j<length; j++){
        int key = array[j];
        int i = j-1;
//递增排序
        while(i>=0 && array[i]>key){
            array[i+1] = array[i];
            i--;
        }
        array[i+1] = key;
    }


    for(int i=0; i<length; i++){
        printf("%d ", array[i]);
    }
    puts("");
}
