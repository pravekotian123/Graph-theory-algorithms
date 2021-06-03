/* This is BFS traversal for directed graph with adjacent list representation*/
#include<iostream>
#include<list>
using namespace std;
class Graph
{
  int V;
  list<int> *adjacent;
  

  public:
  Graph(int v);
  void addedge(int v,int w);
  void BFS_traversal(int v);
};

 Graph::Graph(int v)
 {
     this->V=v;
     adjacent= new list<int> [V];
    
 }

 void Graph::addedge(int v,int w)
 {
     adjacent[v].push_back(w);
 }

 void Graph::BFS_traversal(int v)
 {   bool *visited= new bool[V];
     for(int i=0;i<V;i++)
     {
         visited[i]=false;
     }  
    
     visited[v]=true;
     list <int>::iterator i;
     list <int>queue;
     queue.push_back(v);
     while(!queue.empty())
     { 
        v=queue.front();
       cout<<v<<" ";
       queue.pop_front();
       for(i=adjacent[v].begin();i!=adjacent[v].end();i++)
       {   if(!visited[*i])
           {
               visited[*i]=true;
               queue.push_back(*i);
           }  
       }
     }
 }


 int main()
 {

  Graph g(4);
  g.addedge(0,1);
  g.addedge(0,2);
  g.addedge(1,2);
  g.addedge(2,0);
  g.addedge(2,3);
  g.addedge(3,3);

  g.BFS_traversal(1);




 }
