#include <iostream>
#include <map>
#include <string>
using namespace std;

char get_matching_character(const char c) {
    map<char, char> char_map;
    char_map['}'] = '{';
    char_map[']'] = '[';
    char_map[')'] = '(';

    if (char_map.find(c) == char_map.end()){
        cout<<"character not found!!";
        return 'E'; //For error
    } else {
        return char_map.find(c)->second;
    }
}

int main()
{
    cout<<"matching char for } : "<<get_matching_character('}')<<endl;
}

/*
#include <iostream>
#include <map>

int main ()
{
  std::map<char,int> mymap;

  mymap['b'] = 100;
  mymap['a'] = 200;
  mymap['c'] = 300;

  // show content:
  for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}
*/