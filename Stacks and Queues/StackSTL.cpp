#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<s.empty()<<endl;
    cout<<s.top()<<endl;
    s.pop();
    s.pop();
    s.pop();
    cout<<s.size();
    stack<int> s1;
    s1.push(7);
    s1.push(9);
    s1.push(10);
    s.swap(s1);
    cout<<s.top()<<endl;

    return 0;


}
