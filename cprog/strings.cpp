#include<iostream>
#include<string>
using namespace std;

bool isUnique(string s) {
	int temp = 0;
	for(int i=0; i<s.length(); i++) {
		int index = s[i]-'a';
		if((temp & 1<<index) > 0) {
			return false;
		}
		temp = temp | (1<<index);
	}
	return true;
}

bool isPermutation(string s) {
	int temp = 0;
	for(int i=0; i<s.length(); i++) {
		if(isspace(s[i])){
			continue;
		}
		int index = s[i]-'a';
		temp = temp ^ (1<<index);
	}
	return (temp==0 || (temp & (temp-1)) == 0);
}

string compress(string s) {
	string result = "";
	int len = s.length();
	int count = 0;
	for(int j=0; j<len; j++) {
		count++;
		if(j+1 >= len || s[j]!=s[j+1]) {
			result = result + s[j] + to_string(count);
			count = 0;
		}
	}
	return len < result.length() ? s:result;

}

int main()
{
	string s1 = "abcbcbb";
	string s2 = "abcdefgh";
	cout<<s1<<"  "<<isUnique(s1)<<endl;
	cout<<s2<<"  "<<isUnique(s2)<<endl;


	string s3 = "taco cat";
	cout<<s3<<"  "<<isPermutation(s3)<<endl;

	string s4 = "aaabbccccd";
	cout<<"Compress "<<s4<<" "<<compress(s4)<<endl;
}
