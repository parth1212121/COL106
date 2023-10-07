#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;


class Graph{

    private:
        unordered_map<int,unordered_set<int>>adjList;
    public:

        void addVertex(int vertex){
            if(adjList.find(vertex)==adjList.end()){
                adjList[vertex]= unordered_set<int>();
            }
        }

        void addEdge(int vertex1,int vertex2){
            addVertex(vertex1);
            addVertex(vertex2);
            adjList[vertex1].insert(vertex2);
            adjList[vertex2].insert(vertex1);
        }

        void removeedge(int vertex1,int vertex2){

                if(adjList[vertex2].find(vertex1)!=adjList[vertex2].end()   && adjList[vertex1].find(vertex2)!=adjList[vertex1].end()){
                        adjList[vertex1].erase(vertex2);
                        adjList[vertex2].erase(vertex1);
                }

        }

        void DFSUtil(int vertex,unordered_set<int>&visited){

            cout<<vertex<<" ";
            visited.insert(vertex);

            for(auto neighbour : adjList[vertex]){

                    if(visited.find(neighbour)==visited.end()){
                        DFSUtil(neighbour,visited);
                    }
            }
        }

        void DFS(int start_vertex){

            unordered_set<int>visited;
            DFSUtil(start_vertex,visited);

        }
};



int main(){

  Graph g;
  g.addVertex(1);
  g.addVertex(2);
  g.addVertex(3);
  g.addVertex(4);
  g.addVertex(5);
  
  g.addEdge(1,2);
  g.addEdge(1,3);
  g.addEdge(1,4);
  g.addEdge(2,5);
  g.addEdge(3,4);
  g.addEdge(3,5);

  g.DFS(1);

















    return 0;
}