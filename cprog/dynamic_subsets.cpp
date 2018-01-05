#include <iostream>
#include <vector>
using namespace std;

vector<int> convertIntToSubset(int x, vector<int> v) {
  vector<int> subset;
  int index = 0;
  for(int k=x; k>0; k>>=1) {
    if((k & 1) == 1) {
      subset.push_back(v[index]);
    }
    index++;
  }
  return subset;
}

vector<vector<int>> getSubsets(vector<int> x) {

  int len = 1<<x.size();
  vector<int> subset;
  vector<vector<int>> result;
  for(int i=0; i<len; i++) {
    subset = convertIntToSubset(i, x);
    result.push_back(subset);
  }
  return result;

}

int main() {

  vector <int> x = {1,2,3};
  vector<vector<int>> result = getSubsets(x);

  for (int i = 0; i < result.size(); i++)
  {
      for (int j = 0; j < result[i].size(); j++)
      {
          cout << result[i][j];
      }
      cout<<"\n";
  }

}
