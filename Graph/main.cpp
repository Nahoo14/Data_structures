#include <iostream>
#include <vector>

#define list_size 30

// graph implemented using an int vertex assigned to an adjacency list matrix
// graph data is pushed into a list and accessed at run time as needed

using namespace std;

class Node{
    public:
    int vertex;
    vector <int> connected_list;
    Node(int num){
        this->vertex = num;
        this->connected_list = {};
    }
};


class graph{
    public:
    Node * node_list[list_size];
    graph(){
        for(int i = 0; i<list_size; i++){
            node_list[i] = nullptr;
        }
    }
    void add_vertex(int num){
        Node * newNode = new Node(num);
        node_list[num] = newNode;
    }
    void add_edge(int vertex1, int vertex2){
        if((node_list[vertex1]!=nullptr)&&(node_list[vertex2]!=nullptr)){
            node_list[vertex1]->connected_list.push_back(vertex2);
            node_list[vertex2]->connected_list.push_back(vertex1);
        }
        else if(node_list[vertex1]==nullptr){
            cout << "First vertex argument hasn't been added to the vertex list" << endl;
        }
        else{
            cout << "Second vertex argument hasn't been added to the vertex list" << endl;
        }
    }
    void display_adjucency_list(){
        for(int i = 0; i < list_size ; i++){
            if(node_list[i]!=nullptr){
                cout << i << " : [";
                for(int j = 0; j < node_list[i]->connected_list.size(); j++){
                    cout << node_list[i]->connected_list[j];
                    if(j != node_list[i]->connected_list.size()-1){
                        cout << ",";
                    } 
                }
                cout << "]" << endl;
            }
        }
    }
};

int main(){
    graph g;
    g.add_vertex(0);
    g.add_vertex(2);
    g.add_vertex(3);
    g.add_vertex(1);
    g.add_edge(1,4);
    g.add_edge(1,2);
    g.add_edge(1,3);
    g.add_edge(2,0);
    g.add_edge(2,3);
    g.display_adjucency_list();
}