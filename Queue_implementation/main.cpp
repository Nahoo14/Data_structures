#include <iostream>

using namespace std;

class Node{
    public:
    string Data;
    Node * next;
    Node(string Data){
        this->Data = Data;
        this->next = nullptr;
    }
};

class Queue{
    Node * First_in_line;
    Node * Last_in_line;
    int length;
    public:
    Queue(){
        this->First_in_line = nullptr;
        this->Last_in_line = nullptr;
        this->length = 0;
    }
    void Enqueue(string Data){
        Node * newNode = new Node(Data);
        if(this->length==0){
            this->First_in_line = newNode;
            this->Last_in_line = newNode;
            this->length++;
        }
        else{
            Node * temp = this->Last_in_line;
            temp->next = newNode;
            this->Last_in_line = newNode;
            newNode->next = nullptr;
            this->length++;
        }
    }
    void Dequeue(){
        if(this->length<=0){
            cout << "Queue is empty" << endl;
        }
        else{
            Node * curr = this->First_in_line;
            Node * temp = curr->next;
            curr = nullptr;
            this->First_in_line = temp;
            this->length--;
        }
    }
    void peek(){
        if(this->length==0){
            cout << "Queue is empty" << endl;
        }
        else{
            cout << this->First_in_line->Data << endl;
        }
    }
    void display(){
        cout << "Display-------------------------------" << endl;
        Node * iter = this->First_in_line;
        while (iter!=nullptr){
            cout << iter->Data << endl;
            iter = iter->next;
        }
        cout << "-------------------------------------" << endl; 
    }

};

int main(){
    Queue q;
    q.Enqueue("Joy");
    q.Enqueue("Matt");
    q.Enqueue("Pavel");
    q.Enqueue("Samir");

    q.peek();
    //q.display();
    q.Dequeue();
    q.peek();
    //q.display();
    q.Dequeue();
    q.peek();
    q.Dequeue();
    q.peek();
    q.Dequeue();
    q.peek();
    q.Dequeue();
}