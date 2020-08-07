#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int low;
    int high;
    int sum;
} Sub_array; 

Sub_array 
find_maximum_subarray(int *a, int low, int high);

Sub_array 
find_max_crossing_subarray(int *a, int low, int mid, int high);

/*
 * 输入一串带有负数的整数
 * 计算使和最大的连续子数组
 */
int main(int argc, char *argv[]){
    int length = argc-1;
    if(length < 1){
        return 0;
    }

    int array[length];
    for(int i=0; i<length; i++){
        array[i] = atoi(argv[i+1]);
    }

    Sub_array result = 
        find_maximum_subarray(array, 0, length-1);

    printf("left index: %d, right index: %d\nsum: %d\n",
            result.low, result.high, result.sum);
}

Sub_array 
find_max_crossing_subarray(int *a, int low, int mid, int high)
{
    int sum = 0,
        left_sum = INT_MIN,
        right_sum = INT_MIN,
        left_index = mid,
        right_index = mid;

    for(int i=mid; i>=low; i--){
        sum += a[i];
        if(sum > left_sum){
            left_sum = sum;
            left_index = i;
        }
    }

    sum = 0;
    for(int i=mid+1; i<=high; i++){
        sum += a[i];
        if(sum > right_sum){
            right_sum = sum;
            right_index = i;
        }
    }

    sum = left_sum + right_sum;
    Sub_array result = {left_index, right_index, sum};
    return result;
}

Sub_array 
find_maximum_subarray(int *a, int low, int high)
{
    if(low == high){
        Sub_array base_result = {low, high, a[low]};
        return base_result;
    } else {
        int mid = (low + high)/2;
        Sub_array left_result, right_result, mid_result;

        left_result = find_maximum_subarray(a, low, mid);
        right_result = find_maximum_subarray(a, mid+1, high);
        mid_result = find_max_crossing_subarray(a, low, mid, high);

        if(left_result.sum >= right_result.sum &&
           left_result.sum >= mid_result.sum){
            return left_result;
        } else if(right_result.sum >= left_result.sum &&
                  right_result.sum >= mid_result.sum){
            return right_result;
        } else {
            return mid_result;
        }
    }
}

