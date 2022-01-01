#include <iostream>

// stack with a linked list base
// class node
// class stack should have top, buttom and length
// should support
// peek(top element)
// pop
// push google, push udemy, push discord and
// pop them
using namespace std;

class Node{
    public:
    Node * next;
    int Data;
    Node(int Data){
        this->Data = Data;
        this->next = nullptr;
    }
};

class stack{
    public:
    Node *top;
    Node *buttom;
    int length;
    stack(){
        this->top = nullptr;
        this->buttom = nullptr;
        this->length = 0;
    }
    void push(int data){
        Node * newNode = new Node(data);
        Node * temp = this->top;
        //cout << "Stack contains " << this->buttom->Data << " "<< this->buttom->next->Data << endl;
        if(this->length==0){
            this->top = newNode;
            this->buttom = newNode;
            newNode->next = nullptr;
            this->length++;
        }
        else{
            temp->next = newNode;
            newNode->next = nullptr;
            this->top = newNode;
            this->length++;
        }
    }
    int pop(){
        Node *iter = this->buttom;
        Node *prev;
        //cout << "Top = " << this->top->Data << endl;
        //cout << "Bottom = " << this->buttom->Data << endl;
        if(this->length==0){
            cout << "Nothing to pop" << endl;
            return -1;
        }
        while(iter!=this->top){
            prev = iter;
            iter = iter->next;
        }
        //cout << "Popped: " << iter->Data << endl;
        iter = nullptr;
        this->top = prev;
        this->length--;
        return 0;
    }
    int peek(){
        if(this->length == 0){
            cout << "Nothing to peek" << endl;
            return -1;
        }
        else
            cout << this->top->Data << endl;
            return 0;
    }

};

class Queue{

    public:
    stack * l;
    Queue(){
        this->l = new stack();
    }
    void push(int data){
        l->push(data);
    }
    int pop(){
        if(this->l->length==0){
            cout << "Nothing to pop" << endl;
            return NAN;
        }
        else{
            Node * temp1 = this->l->buttom;
            Node * temp2 = temp1->next;
            int val = temp1->Data;
            temp1 = nullptr;
            this->l->buttom = temp2;
            this->l->length--;
            return val;
        }
    }
    int peek(){
        if(this->l->length==0){
            cout << "Nothing to peek" << endl;
            return NAN;
        }
        else{
            return this->l->buttom->Data;
        }
    }
    bool empty(){
        if(l->length==0){
            return true;
        }
        return false;
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
    Queue * queue = new Queue();
    queue->push(1);
    queue->push(2);
    queue->peek();
    cout << queue->pop() << endl;
    queue->peek();
    cout << queue->empty() << endl;
    queue->pop();
    cout << queue->empty() << endl;
}