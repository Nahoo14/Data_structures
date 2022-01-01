#include <iostream>
#define array_size 100

using namespace std;

class Node{
    int Data;
    Node(int Data){
        this->Data = Data;
    }
};

class stack{
    public:
    int array [array_size];
    int top_index;
    int push(int Data){
        if(top_index<=array_size){
            this->top_index++;
            this->array[top_index]=Data;
            return 0;
        }
        else{
            cout << "Base array is full" << endl;
            return -1;
        }
    }
    int pop(){
        if(top_index<0){
            cout << "Nothing to pop" << endl;
            return -1;
        }
        this->array[top_index] = NAN;
        this->top_index--;
        return 0;
    }
    int peek(){
        if(top_index<0){
            cout << "Nothing to peek" << endl;
            return -1;
        }
        cout << this->array[top_index] << endl;
        return 0;
    }
    stack(){
        this->top_index = -1;
    }  
};

class MyQueue{
    public:
    stack * one;
    int low_index;
    //Node * first_element;
    //stack two
    MyQueue(){
        this->one = new stack();
        this->low_index = 0;
    }
    void push(int num){
        this->one->push(num);
    }
    void peek(){
        cout << this->one->array[low_index] << endl;
    }
    void pop(){
        
    }

};

int main(){
//     Input
//  ["MyQueue", "push", "push", "peek", "pop", "empty"]
// [[], [1], [2], [], [], []]
// Output
// [null, null, null, 1, 1, false]

// Explanation
// MyQueue myQueue = new MyQueue();
// myQueue.push(1); // queue is: [1]
// myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
// myQueue.peek(); // return 1
// myQueue.pop(); // return 1, queue is [2]
// myQueue.empty(); // return false

}