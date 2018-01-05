#include <iostream>

struct heap {
    int *arr;
    int count;
    int capacity;
    int heap_type; // MIN or MAX heap
};

int get_parent_index(heap *h, int child_index){
    if(child_index>h->count || child_index<=0) {
        return -1;
    }

    return (child_index-1)/2;
}

int get_left_child_index(heap *h, int parent_index){
    int left_child = 2*parent_index + 1;
    if(left_child > h->count) {
      return -1;
    }
    return left_child;
}

int get_right_child_index(heap *h, int parent_index){
  int right_child = 2*parent_index + 2;
  if(right_child > h->count) {
    return -1;
  }
  return right_child;
}

// Percolate down from particular index to satisfy Max heap property
void percolate_down(heap *h, int index) {
  int left_child = get_left_child_index(h, index);
  int right_child = get_right_child_index(h, index);
  if(left_child==-1 || right_child ==-1){
    return;
  }
  int max = h->arr[left_child] > h->arr[right_child] ? left_child : right_child;
  if(h->arr[index] != h->arr[max]){
    int temp = h->arr[index];
    h->arr[index] = h->arr[max];
    h->arr[max] = temp;
  }
  percolate_down(h, max);
}

void percolate_up(heap *h, int index) {
  int parent = get_parent_index(h, index);

  if(parent==-1){
    return;
  }

  if(h->arr[parent] < h->arr[index]){
    int temp = h->arr[parent];
    h->arr[parent] = h->arr[index];
    h->arr[index] = temp;
  }
  percolate_up(h, parent);
}

heap * create_heap(int *arr, int count, int capacity, int heap_type) {
    heap * new_heap = new heap;
    new_heap->count = count;
    new_heap->capacity = capacity;
    new_heap->arr = new int[capacity];
    for(int i=0; i<count; i++) {
        new_heap->arr[i] = arr[i];
        percolate_up(new_heap, i);
    }
    new_heap->heap_type = heap_type;
    return new_heap;
}

void print_heap(heap *h) {
  for(int i=0; i<h->count; i++) {
    std::cout<<h->arr[i]<<"\t";
  }
  std::cout<<std::endl;
}

void delete_node(heap *h, int index) {
  if(h->count == 0) {
    return;
  }
  h->arr[index] = h->arr[h->count-1];
  h->count--;
  percolate_down(h, index);
}

void resize_heap(heap *h) {
  h->capacity = h->capacity*2;
}

void insert_node(heap *h, int value) {
  if(h->count == h->capacity) {
    resize_heap(h);
  }
  h->count++;
  h->arr[(h->count)-1] = value;
  percolate_up(h,(h->count)-1);
}

int get_min_element(heap *h) {
  int min = INT_MAX;
  for(int i=(((h->count)+1)/2); i<h->count; i++){
    if(h->arr[i]<min) {
      min = h->arr[i];
    }
  }
  return min;
}

int main() {
    int arr[] = {31, 1, 3, 5, 10, 12,18,21};
    heap * h = create_heap(arr, sizeof(arr)/sizeof(arr[0]), 15, 0);
    print_heap(h);

    int child_index = 3;
    int parent_index = get_parent_index(h, child_index);
    std::cout<<"Parent of "<<h->arr[child_index]<<" is "<<h->arr[parent_index]<<std::endl;

    int parent_index_2 = 1;
    int left_child = get_left_child_index(h, parent_index_2);
    int right_child = get_right_child_index(h, parent_index_2);
    std::cout<<"Left child of "<<h->arr[parent_index_2]<<" is "<<h->arr[left_child]<<std::endl;
    std::cout<<"Right child of "<<h->arr[parent_index_2]<<" is "<<h->arr[right_child]<<std::endl;

/*
    std::cout<<"After percolate_down the heap looks like : "<<std::endl;
    percolate_down(h,1);
    print_heap(h);
*/
    std::cout<<"After delete_element the heap looks like : "<<std::endl;
    delete_node(h,2);
    print_heap(h);

    std::cout<<"After insert_node the heap looks like : "<<std::endl;
    insert_node(h, 41);
    print_heap(h);

    std::cout<<"Min element in heap : "<<get_min_element(h)<<std::endl;

}
