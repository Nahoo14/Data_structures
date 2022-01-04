#include <iostream>
#include <vector>
#include <map>

using namespace std;

// simple graph implemented using an int to vector map
class graph{
    private:
    map<int,vector<int>>graph_container;
    public:
    void add_vertex(int num){
        graph_container.insert(pair<int,vector<int>>(num,{}));
    }
    void add_edge(int vertex1, int vertex2){
        if((graph_container.find(vertex1)!=graph_container.end())&&
        (graph_container.find(vertex2)!=graph_container.end())){
            graph_container[vertex1].push_back(vertex2);
            graph_container[vertex2].push_back(vertex1);
        }
        else{
            cout << "One or two invalid arguments" << endl;
        }
    }
    void adjucency_list_display(){
        map<int,vector<int>>::iterator it;
        for(it = graph_container.begin(); it != graph_container.end(); it++){
            cout << it->first << " : [";
            for(int i = 0 ; i < it->second.size(); i++){
                cout << it->second[i];
                if(i!=it->second.size()-1){
                    cout << ",";
                }
            }
            cout << "]" << endl;
        }
    }
};




int main(){
    graph g;
    g.add_vertex(0);
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);
    g.add_edge(1,2);
    g.add_edge(1,3);
    g.add_edge(2,0);
    g.add_edge(2,3);
    //g.add_edge(1,4);
    g.adjucency_list_display();
}