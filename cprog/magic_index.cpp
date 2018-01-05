#include<iostream>
using namespace std;

// Program to find magic index in the array. ie if Arr[i] = i return i

int get_magic_index_bf(int arr[], int n) {
    for(int i=0; i<n; i++) {
        if(arr[i]==i) {
            return i;
        }
    }
}

int get_magic_index_helper(int arr[],int n, int start, int end) {
    
    if(end<start || end >= n || start<0) {
        return -1;
    }

    int mid = (start + end)/2;
    if(arr[mid] < mid) { // Magic index is on the right
        int right = mid+1 > arr[mid] ? mid+1:arr[mid];
        return get_magic_index_helper(arr, n, right, end);
    } else if(arr[mid] > mid) { //Magic index is on the left
        int left = mid-1 < arr[mid] ? mid-1:arr[mid];
        return get_magic_index_helper(arr,n,start,left);
    } else {
        return mid;
    }
}

int get_magic_index(int arr[], int n) {
    return get_magic_index_helper(arr, n, 0, n-1);
}

int main()
{   
    int arr[10] = {-20, -10, 2,2,2,4,7,8,9,10};

    cout<<"Magic index is at location : "<<get_magic_index(arr, sizeof(arr)/sizeof(arr[0]))<<endl;
}
