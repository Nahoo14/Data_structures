#include <iostream>

using namespace std;

// priority queue implemented using linked lists

class Node{
    public:
    int data;
    int priority;
    Node * next;
    Node(int data, int priority){
        this->data = data;
        this->priority = priority;
        this->next = nullptr;
    }
};

class Priority_Queue{
    Node * root;
    int length;
    public:
    Priority_Queue(){
        this->length = 0;
        this->root = nullptr;
    }
    void add_node(int data, int priority){
        Node * temp = new Node(data,priority);
        Node * iter = this->root;
        Node * prev = this->root;
        if (iter == nullptr){
            this->root = temp;
        }
        else{
            while(iter!=nullptr){
                if((temp->priority)<=(iter->priority)){
                    prev = iter;
                    iter = iter->next;
                }
                else{
                    if(prev!=this->root){
                        prev->next = temp;
                    }
                    temp->next = iter;
                    // iter = this->tail;
                    // cout << "Tail = " << this->tail->data << endl;
                    if(iter==this->root){
                        this->root = temp;
                    }
                    break;
                }
            }
        }
    }
    void delete_node(int data, int priority){
        Node * iter = this->root;
        Node * prev = this->root;
        bool found = false;
        while(iter!=nullptr){
            if((iter->data == data)&&(iter->priority==priority)){
                if(iter == this->root){
                    this->root = iter->next;
                    iter = nullptr;
                    found = true;
                    break;
                }
                prev->next = iter->next;
                iter = nullptr;
                found = true;
                break;
            }
            prev = iter;
            iter = iter->next;
        }
        if (!found)
            cout << "Specified node not found" << endl;
    }
    void display(){
        Node *iter = this->root;
        if(iter==nullptr){
            cout << "Nothing to display" << endl;
        }
        else{
            while(iter!=nullptr){
                cout << "Data: " << iter->data << " Priority: " << iter->priority << endl;
                iter = iter->next;
            }
        }
    }
};

int main(){

    Priority_Queue q;
    q.add_node(1,1);
    q.add_node(8,10);
    q.add_node(2,100);
    q.add_node(1,2000);
    q.add_node(4,3);
    //q.delete_node(8,10);
    q.delete_node(1,2000);
    q.display();

}