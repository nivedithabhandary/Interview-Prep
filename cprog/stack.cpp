#include "stack.h"

template <class Type>
stack<Type>::stack(int max_size){
    size = max_size;
    top = 0;
    arr = new Type[size];
}

template <class Type>
stack<Type>::~stack(){
    delete arr;
}

template <class Type>
void stack<Type>::push(Type val){
    if(is_stack_full()){
        cout<<"Stack full cant push! \n\n";
        return;
    } else {
        arr[top]=val;
        top = top+1;
    }
}

template <class Type>
void stack<Type>::pop(){
    if(is_stack_empty()){
        cout<<"Stack Empty cant pop! \n\n";
        return;
    } else {
        top = top - 1;
    }
}

template <class Type>
Type stack<Type>::return_top_element(){
    if(is_stack_empty()){
        cout<<"Stack Empty! \n\n";
    }
    return arr[top-1];
}

template <class Type>
bool stack<Type>::is_stack_empty(){
    if(top==0){
        return true;
    } else {
        return false;
    }
}

template <class Type>
bool stack<Type>::is_stack_full(){
    if(top==size){
        return true;
    } else {
        return false;
    }
}

template <class Type>
int stack<Type>::get_top() {
    return top;
}

template <class Type>
void stack<Type>::set_top(int x) {
    top = x;
}

template <class Type>
int stack<Type>::get_size(){
    return size;
}

template <class Type>
void stack<Type>::set_size(int s) {
    size = s;
}

template <class Type>
void stack<Type>::set_stack_elements(Type *elem) {
    arr = new Type[size];
    for(int i=0; i<size; i++) {
        arr[i] = elem[i];
    }
}

template <class Type>
Type * stack<Type>::get_stack_elements(){
    return arr;
}

template <class Type>
extended_stack<Type>::extended_stack(int max_size): stack<Type>(max_size){

}

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

template <class Type>
bool extended_stack<Type>::is_balanced(char *s) {
    for (int i=0; i<strlen(s); i++) {
        switch(s[i]) {
            case '(': 
            case '[': 
            case '{': stack<Type>::push(s[i]); break;
            case ')':
            case ']':
            case '}':

            if(stack<Type>::return_top_element()==get_matching_character(s[i])) 
            { stack<Type>::pop();
              continue;
              } else {
                return false;
                }
                break;

            }
    }
    if(stack<Type>::is_stack_empty()) {
        return true;
    }
    return false;
}

int main()
{
    
    cout<<"hello\n";
    stack<int> s1(40);
    s1.push(10);
    s1.push(20);
    s1.pop();
    cout<<s1.return_top_element()<<"\n\n";


    extended_stack<char> s2(30);
    cout<<"is it balanced : "<<s2.is_balanced("{[]()}")<<"\n\n";
}
