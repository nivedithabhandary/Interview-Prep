#include <iostream>
#include <time.h>

using std::cout;
using std::endl;


void print_array(int *arr, int len) {
  for(int i=0; i<len; i++){
    cout<<arr[i]<<"\t";
  }
  cout<<"\n";
}

void bubble_sort(int *arr, int len) {
  for(int i=0; i<len; i++) {
    for(int j=i+1; j<len; j++) {
      if(arr[i]>arr[j]){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  return;
}

void selection_sort(int *arr, int len) {
    for(int i=0; i<len; i++){
      int min_index = i;
      for(int j=i+1; j<len; j++){
        if(arr[min_index] > arr[j]) {
          min_index = j;
        }
      }
      int temp = arr[i];
      arr[i] = arr[min_index];
      arr[min_index] = temp;
    }
}

void insertion_sort(int *arr, int len) {
  int i,j,k, temp;
  for(i=1; i<len; i++){
    j = i-1;
    k = i;
    while(arr[k]<arr[j] && j>=0){
      temp = arr[k];
      arr[k] = arr[j];
      arr[j] = temp;
      j--;
      k--;
    }
  }
  return;
}

void insertion_sort_(int arr[], int n) {
    int i,j;
    for(i=1; i<n; i++) {
        j = i;
        while(j>0 && arr[j]<arr[j-1]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;

            j--;
        }
    }
}

void merge(int *arr, int left, int mid, int right) {
  int left_size = mid - left;
  int right_size = right - mid;

  int left_side [left_size], right_side [right_size];

  for(int i=0; i<left_size; i++) {
    left_side[i] = arr[left+i];
  }
  for(int j=0; j<right_size; j++) {
    right_side[j] = arr[mid+j+1];
  }
  int l = 0;
  int r = 0;
  int m = l;
  while(l<left_size && r<right_size){
    if(left_side[l] <= right_side[r]){
      arr[m] = left_side[l];
      l++;
    } else {
      arr[m] = right_side[r];
      r++;
    }
    m++;
  }
  while(l<left_size ) {
    arr[m] = left_side[l];
    m++;
    l++;
  }
  while(r<right_size) {
    arr[m] = right_side[r];
    m++;
    r++;
  }
}

void merge_sort(int *arr, int left, int right) {

  int mid = (left + right)/2;
  if(left<right) {
    merge_sort(arr, left, mid-1);
    merge_sort(arr, mid, right);
    merge(arr, left, mid, right);
  }
}


int binary_search(int arr[], int key, int low, int high) {
  int mid = (low + high)/2;
  if(low > high) {
    return -1;
  }
  if(arr[mid] == key) {
    return mid;
  } else if(arr[mid] > key) {
    return binary_search(arr, key, low, mid-1);
  } else {
    return binary_search(arr, key, mid+1, high);
  }
}

int get_left_boundary(int arr[], int key, int low, int high) {
  if(low<=high) {
    int mid = (low+high)/2;
    if(arr[mid]==key && (arr[mid-1]<key||mid==0)) {
      return mid;
    } else if (arr[mid]>key) {
      return get_left_boundary(arr, key, low, mid-1);
    } else {
      return get_left_boundary(arr, key, mid+1, high);
    }
  }
  return -1;
}

int get_right_boundary(int arr[], int key, int low, int high) {
  if(low<=high) {
    int mid = (low+high)/2;
    if(arr[mid]==key && (arr[mid+1]>key)) {
      return mid;
    } else if (arr[mid]>key) {
      return get_right_boundary(arr, key, low, mid-1);
    } else {
      return get_right_boundary(arr, key, mid+1, high);
    }
  }
  return -1;
}

int get_frequency(int arr[], int key, int low, int high) {
  if(binary_search(arr,key,low,high)==-1){
    return -1; // Key is not found even once.
  }
  int left_boundary = get_left_boundary(arr, key, low, high);
  int right_boundary = get_right_boundary(arr, key, left_boundary, high);
  return (right_boundary - left_boundary + 1);
}

int main() {
  clock_t bubble_sort_time, insertion_sort_time, selection_sort_time;

  int arr [] = {4,2,5,6,7,8,9,1,0,7,7,7,7,7};
  int len = sizeof(arr)/sizeof(arr[0]);
  cout<<"Inital array : "<<endl;
  print_array(arr,len);

  bubble_sort_time = clock();
/*
  cout<<"After Bubble Sort : "<<endl;
  bubble_sort(arr, len);
  print_array(arr,len);
  cout<<"Time taken for Bubble Sort : "<<(clock()-bubble_sort_time)<<endl;

  selection_sort_time = clock();
  cout<<"After Selection Sort : "<<endl;
  selection_sort(arr, len);
  print_array(arr,len);
  cout<<"Time taken for selection Sort : "<<(clock()-selection_sort_time)<<endl;


  insertion_sort_time = clock();
  cout<<"After Insertion Sort : "<<endl;
  insertion_sort(arr, len);
  print_array(arr,len);
  cout<<"Time taken for Insertion Sort : "<<(clock()-insertion_sort_time)<<endl;


  cout<<"After Merge Sort : "<<endl;
  cout<<"length : "<<len<<endl;
  merge_sort(arr, 0,len-1);
  print_array(arr,len);
*/
/*
  int key = 10;
  cout<<"Key "<<key<<" found at position : "<<binary_search(arr, key, 0, len-1)<<endl;

  cout<<"Frequency of Key "<<key<<": \t "<<get_frequency(arr, key, 0, len-1)<<endl;
*/
  insertion_sort_(arr,len);
  print_array(arr,len);
}
