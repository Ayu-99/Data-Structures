lude<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.pop();
    cout<<"Size : "<<q.size()<<endl;
    cout<<"Front : "<<q.front()<<endl;
    cout<<"Rear : "<< q.back()<<endl;
    cout<<"Is Empty: "<<q.empty()<<endl;
    return 0;
}
