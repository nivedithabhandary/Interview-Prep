#include<iostream>
#include<vector>
using namespace std;


vector<int> sumSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    int count = 0, sum = 0;

    for(int i=0, j=0; i<nums.size(); i++) {
        sum = sum + nums[i];
        count++;
        if(count == k) {
            result.push_back(sum);
            sum = sum - nums[j];
            j = j+1;
            count--;
        }
    }
    return result;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    vector<int> temp;
    int count = 0, sum = 0;

    for(int i=0, j=0; i<nums.size(); i++) {
        temp.push_back(nums[i]);
        count++;
        if(count == k) {
            result.push_back(*max_element(temp.begin(), temp.end()));
            temp.erase(temp.begin());
            count--;
        }
    }
    return result;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> dq;

    for (int i=0; i<nums.size(); i++) {
        if (!dq.empty() && dq.front() == i-k) dq.pop_front();
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();
        dq.push_back(i);
        if (i>=k-1) ans.push_back(nums[dq.front()]);
    }
    return ans;

}

void printVector(const vector<int> nums) {
  cout<<"\n\n Resulting vector is : ";
  for(auto it=nums.begin(); it!=nums.end(); it++) {
    cout<<*it<<"\t";
  }
  cout<<"\n\n";
}

int main() {
    static const int arr[] = {1,2,3,4,5,6};
    vector<int> nums (arr, arr + sizeof(arr) / sizeof(arr[0]) );
    int k = 3;
    vector<int> result = maxSlidingWindow(nums, k);
    printVector(result);

}
