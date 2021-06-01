#include<iostream>
using namespace std;

class Queue{
    public:
    int a[1000];
    int maxSize=1000;
    int front=0;
    int size=0;
    int rear=maxSize-1;


    void enqueue(int e){
        if(size==maxSize){
            cout<<"Queue is full"<<endl;
            return;
        }
        rear=(rear+1)%maxSize;
        a[rear]=e;
        size++;
        cout<<e<<" added to queue"<<endl;

    }

    int dequeue(){
        if(size==0){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int e=a[front];
        front=(front+1)%maxSize;
        size--;
        return e;
    }

    int getFront(){
        if(size==0){
            cout<<"Queue is empty";
            return -1;
        }

        return a[front];


    }
    int getRear(){
        if(size==0){
            cout<<"Queue is empty";
            return -1;
        }

        return a[rear];
    }

    bool isEmpty(){
        if(size==0){
            return true;
        }else{
            return false;
        }
    }

    bool isFull(){
        if(size==maxSize){
            return true;
        }else{
            return false;
        }
    }


};

int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout<<"dequeued item: "<< q.dequeue()<<endl;
    cout<<"dequeued item: "<< q.dequeue()<<endl;
    cout<<"dequeued item: "<< q.dequeue()<<endl;
    cout<<"dequeued item: "<< q.dequeue()<<endl;
    cout<<q.isEmpty()<<endl;
    cout<<q.getFront()<<endl;
    return 0;
}
