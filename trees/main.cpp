#include <iostream>
#include <stack>

using namespace std;

class Node{
    public:
    Node * left;
    Node * right;
    int value;
    Node(int value){
        this->left = nullptr;
        this->right = nullptr;
        this->value = value;
    }
};
class Tree{
    public:
    Node * root;
    Tree(){
        this->root = nullptr;
    }
    void insert(int value){
        Node * newNode = new Node(value);
        if(root==nullptr){
            root = newNode;
        }
        else{
            Node *iter = this->root;
            while(iter!=nullptr){
                if((newNode->value < iter->value)){
                    if(iter->left==nullptr){
                        iter->left = newNode;
                        break;
                    }
                    else{
                        iter = iter->left;
                    }
                    
                }
                else{
                    if(iter->right == nullptr){
                        iter->right = newNode;
                        break;
                    }
                    else{
                        iter = iter->right;
                    }
                }
            }
        }
    }
    bool lookup(int num){
        Node * iter = this->root;
        while(iter!=nullptr){
            if(iter->value==num){
                return true;
            }
            else if(num < iter->value){
                iter = iter->left;
            }
            else{
                iter = iter->right;
            }
        }
        return false;
    }
    void display_helper(Node * curr){
        if (curr->left!=nullptr)
            cout << curr->left->value << endl;
        else if(curr->right!=nullptr)
            cout << curr->right->value << endl;
    }
    void inode_display(){
        stack <Node *> s;
        Node *iter = this->root;
        while((iter!=nullptr)||!s.empty()){
            //cout << "new left Iter value = " << iter->value << endl;  
            while(iter!=nullptr){
                s.push(iter);
                iter = iter->left;
            }
            iter = s.top();
            cout << iter->value << endl;
            s.pop();
            iter = iter -> right;
    }
    } 

};

int main(){

    Tree * t = new Tree;
    t->insert(9);
    t->insert(4);
    t->insert(20);
    t->insert(1);
    t->insert(6);
    t->insert(15);
    t->insert(170);
    t->inode_display();

    // cout << t->root->value << endl;
    // cout << t->root->left->value << endl;
    // cout << t->root->left->left->value << endl;
    // cout << t->root->left->right->value << endl;
    // cout << t->root->right->value << endl;
    // cout << t->root->right->left->value << endl;
    // cout << t->root->right->right->value << endl;
    // cout << t->lookup(9) << endl;
    // cout << t->lookup(123) << endl;
    // cout << t->lookup(170) << endl;
    // cout << t->lookup(20) << endl;
    // cout << t->lookup(200) << endl;

    return 0;

}