#include<iostream>
using namespace std;

class Stack{
    public:
    int maxSize=1000;
    int size=0;
    int top=-1;
    int a[1000];

    void push(int e){

        if(size==maxSize){
            cout<<"Overflow"<<endl;
            return;
        }
        top++;
        a[top]=e;
        size++;
        cout<<e << " is pushed to stack"<<endl;

    }

    int pop(){

        if(size==0){
            cout<<"Underflow"<<endl;
            return -1;
        }

        int e=a[top];
        top--;
        size--;
        return e;
    }

    void peek(){
        if(size==0){
            cout<<"Stack is empty"<<endl;
            return;
        }
        cout<<"Top element is:"<<a[top]<<endl;

    }

    bool isEmpty(){
        if(size==0){
            return true;
        }else{
            return false;
        }
    }

};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.peek();
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.isEmpty();
    return 0;
}

