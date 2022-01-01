#include <iostream>
#include <stack>

using namespace std;

class MyQueue{
    public:
    stack <int> push_stack,pop_stack;
    int fake_top;
    void push(int data){
        while(!pop_stack.empty()){
            push_stack.push(pop_stack.top());
            pop_stack.pop();
        }
        push_stack.push(data);
    }
    int peek(){
        while(!push_stack.empty()){
            pop_stack.push(push_stack.top());
            push_stack.pop();
        }
        return pop_stack.top();
    }
    int pop(){
        int temp = this->peek();
        pop_stack.pop();
        return temp;
    }
    bool empty(){
        return((pop_stack.empty())&&(push_stack.empty()));
    }
};

int main(){
    //     Input
    //  ["MyQueue", "push", "push", "peek", "pop", "empty"]
    // [[], [1], [2], [], [], []]
    // Output
    // [null, null, null, 1, 1, false]

    // Explanation
    MyQueue * myQueue = new MyQueue();
    myQueue->push(1); // queue is: [1]
    myQueue->push(2); // queue is: [1, 2] (leftmost is front of the queue)
    myQueue->push(3);
    cout << myQueue->peek() << endl; // return 1
    cout << myQueue->pop() << endl; // return 1, queue is [2]
    cout << myQueue->peek() << endl;
    cout << myQueue->pop() << endl;
    myQueue->push(4);
    cout << myQueue->pop() << endl;
    cout << myQueue->pop() << endl;
    cout << myQueue->empty() << endl; // return false
    
}