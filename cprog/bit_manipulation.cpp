#include <iostream>
#include <vector>
using namespace std;

void repeatedArithmeticShift(int x, int count) {

  // Append sign bit at the beginning
  cout<<"Arithmetic Shift : ";
  for(int i=0; i<count; i++) {
    x >>= 1;
    cout<<x<<"\t";
  }
  for(int i=0; i<count; i++) {
    x = 1;
    cout<<x<<"\t";
  }
  cout<<"\n";

}

void repeatedLogicalShift(int x, int count) {

  // Append 0 at the beginning
  cout<<"Logical Shift : ";
  for(int i=0; i<count; i++) {
    //x >>>= 1;
    cout<<x<<"\t";
  }
  cout<<"\n";
}


//Get bit at location i
bool getBit(int num, int i) {
  return num & (1<<i);
}

//Set bit at location i
int setBit(int num, int i) {
    return num | (1<<i);
}

//Clear bit at location i
int clearBit(int num, int i) {
  return num & ~(1<<i);
}

//Clear all LSB bits from location i
int clearAllLSBBit(int num, int i) {
  return num & ~((1<<i) - 1);
}

//Clear all MSB bits after location i
int clearAllMSBBit(int num, int i) {
  return num & ((1<<(i+1)) - 1);
}

//Update ith bit with value sent
int update(int num, int i, bool value) {
  return (num & ~(1<<i)) | (value<<i);
}

//Insert number N into number M
int insert(int N, int M, int i, int j) {
  for(int k=i; k<=j; k++) {
    N = update(N, k, 0);
  }
  return N | (M<<i);
}

void countZeroOnes(int num, int &ones, int &zeros) {
  // int count = 0;
  while(num) {
    if(num & 1) {
      (ones)++;
    } else {
      (zeros)++;
    }
    num>>=1;
    // count++;
  }
}

bool hasAlternatingBits(int n) {
    cout<<n<<"\t"<<(n & 0x55)<<"\t"<<(n & 0xAA)<<endl;
    return (n == (n & 0x55) || n == (n & 0xAA));
}

/*
int flipBitToWin(int num) {
  vector<int> map;
  pair <int,int> p;
  int continuous_ones = 0;
  int onecount=0, zerocount=0;

  while(num) {
    if(num&1) {
      onecount++;
      prev = 1;
    } else {
      zerocount++;
      onecount = 0;
      prev = 0;
    }

    if(prev==0 && num&1) {

    }

  }
  return continuous_ones;
}
*/

int main() {
  repeatedArithmeticShift(8, 3);

  int num = 10;
  int i = 2;
  cout<<"Get Bit at location 2 : "<<getBit(num, i)<<endl;
  cout<<"Set bit at location 2 : "<<setBit(num, i)<<endl;
  cout<<"Clear bit at location 2 : "<<clearBit(num, i)<<endl;
  cout<<"Clear all LSB bit from location 2 : "<<clearAllLSBBit(num, i)<<endl;
  cout<<"Clear all MSB bit from location 2 : "<<clearAllMSBBit(num, i)<<endl;
  cout<<"Update bit at location 2 : "<<update(num, i, 0)<<endl;


  int N = 4096, M = 19;
  int j = 2, k = 6;
  cout<<"Insert M into N : "<<insert(N, M, j, k)<<endl;

  int ones=0, zeros=0;
  countZeroOnes(num, ones, zeros);
  cout<<"Number of zeros and ones : "<<zeros<<"\t"<<ones<<endl;

  cout<<"Has alternating bits : "<<hasAlternatingBits(11)<<endl;
}
