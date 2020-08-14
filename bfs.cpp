// BFS algorithm in C++

#include <iostream>
#include <list>

using namespace std;


class Graph{
    int numVertices;
    list<int> *adjlist;
    bool *visited;
    public:

    Graph(int vertices){
        numVertices=vertices;
        adjlist= new list<int>[vertices];
    }
    void addEdge(int src, int dest){
        adjlist[src].push_back(dest);
        adjlist[dest].push_back(src);
    }

    void BFS(int startVertex){
        visited=new bool[numVertices];
        for(int i=0;i<numVertices;i++){
            visited[i]=false;
        }

        list<int> q;

        visited[startVertex]=true;
        q.push_back(startVertex);
        list<int>::iterator i;
        while(!q.empty()){
            int currVertex=q.front();
            cout<<currVertex<<" ";
            q.pop_front();

            for(i=adjlist[currVertex].begin();i!=adjlist[currVertex].end();++i){
                int adjVertex=*i;
                if(!visited[adjVertex]){
                    visited[adjVertex]=true;
                    q.push_back(adjVertex);
                }
            }
        }
    }
};



int main() {

    Graph g(4);

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  g.BFS(2);

  return 0;
}
