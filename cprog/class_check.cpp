#include <iostream>
using namespace std;

#define Pi 3.14

struct box {
 int size;
public:
  box() {
    this->size = 100;
  }
  box(int x){
    this->size = x;
  }
   int get_size()  {
    return size;
  }
  void set_size(int x)  {
    this->size = x;
  }
};

int main() {
  box *b = new box;

  box *b2 = (box *)malloc(sizeof(box));

  //b2->set_size(4);
  cout<<b->get_size()<<endl;

  float area = Pi * 10 * 10;
  cout<<area<<endl;
}
