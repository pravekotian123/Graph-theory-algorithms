#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<list>

using namespace std;
class DFSgraph
{
int v;
list<int> *adjlist;
void DFS_traversal(int V,bool visited[]);

public:
DFSgraph(int V)
{
  this->v=V;
  adjlist= new list<int> [v];
}
void addedge(int V, int w);

void DFS(int V);

};

void DFSgraph::addedge(int V,int w)
{  
  adjlist[V].push_back(w);
  adjlist[w].push_back(V);
}

void DFSgraph::DFS(int V)
{
bool *visited =new bool[v];
for(int i=0;i<v;i++)
visited[i]=false;

DFS_traversal(V,visited); 
}

void DFSgraph::DFS_traversal(int V,bool visited[])
{
visited[V]=true;
cout<<V<<" ";
list<int>::iterator i;

for(i=adjlist[V].begin();i!=adjlist[V].end();i++)
{      
       if(!visited[*i])
       DFS_traversal(*i,visited);
}
}


int main()
{ 
  DFSgraph g(5);
  g.addedge(0,1);
  g.addedge(0,2);
  g.addedge(2,3);
  g.addedge(2,4);
  
  int starting_vertex;
  cin>>starting_vertex;
  g.DFS(starting_vertex);
    
}