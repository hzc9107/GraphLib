#include "DirGraphProc.h"
#include "Graph.h"
/*
Iterable Class Description

Iterable::Iterable(int size){
	Data = new int(size);
	length = size;
	counter = 0;
}

bool Iterable::HasNext(){
	return counter < size;
}

int Iterable::Next(){
	return Data[
}

Iterable::~Iterable(){

}
*/
//***********************************
//Directed DFS procedure

DirectedDFS::DirectedDFS(DirGraph& G, int s){
	marked = new bool(G.V());
	for(int i=0; i < G.V(); i++)
		marked[i] = false;
	dfs(G, s);
}

DirectedDFS::DirectedDFS(DirGraph& G, int *s, int elements){
	marked = new bool(G.V());
	for(int a = 0; a< elements; ++a)
		if(!marked[s[a]])
			dfs(G,s[a]);
}

void DirectedDFS::dfs(DirGraph& G, int v){
	marked[v] = true;
	Bag *TempBag = G.Iterator(v);
	TempBag->BeginIter();
	int iter;
	while(TempBag->HasNext())
		if(!marked[(iter = TempBag->Next())])
			dfs(G,iter);
}

DirectedDFS::~DirectedDFS(){
	delete marked;
}

//**********************************

//Directed Cycle algorithm

DirectedCycle::DirectedCycle(DirGraph& G){
	onStack = new bool(G.V());
	edgeTo = new int(G.V());
	marked = new bool(G.V());
	for(int i=0; i < G.V(); i++){
		marked[i] = false;
		onStack[i] = false;
	}
	for(int v = 0; v<G.V(); ++v)
		if(!marked[v])
			dfs(G, v);	
}

void DirectedCycle::dfs(DirGraph& G, int v){
	onStack[v] = true;
	marked[v] = true;
	Bag *Temp = G.Iterator(v);
	Temp->BeginIter();
	int w;
	while(Temp->HasNext()){
		w = Temp->Next();
		if(hasCycle())
			return;
		else{
			if(!marked[w]){
				edgeTo[w] = v;
				dfs(G,w);
			} else if (onStack[w]){
				for(int x = v; x != w; x = edgeTo[x])
					cycle.push_front(x);
				cycle.push_front(w);
				cycle.push_front(v);
			}
		}			
	}
	onStack[v] = false;
}

bool DirectedCycle::hasCycle(){
	return !cycle.empty();
}

std::deque<int> *DirectedCycle::GetCycle(){
	return &cycle;
}

DirectedCycle::~DirectedCycle(){
	delete onStack;
	delete edgeTo;
	delete marked;
}
//**********************************

//DepthFirstOrder class description

DepthFirstOrder::DepthFirstOrder(DirGraph &G){
	marked = new bool(G.V());
	for(int i=0; i < G.V(); i++)
		marked[i] = false;
	for(int v = 0; v < G.V(); v++)
		if(!marked[v])
			dfs(G, v);
}

void DepthFirstOrder::dfs(DirGraph &G, int v){
	pre.push_back(v);
	marked[v] = true;
	Bag *Temp = G.Iterator(v);
	Temp->BeginIter();
	int nextVert;	
	while(Temp->HasNext()){
		nextVert = Temp->Next();
		if(!marked[nextVert])
			dfs(G,nextVert);
	}
	post.push_back(v);
	reversePost.push_front(v);	
}

DepthFirstOrder::~DepthFirstOrder(){
	delete marked;
}

//**********************************

//Topological Sort Class description

Topological::Topological(DirGraph &G){
	DirectedCycle *FindCycle = new DirectedCycle(G);
	if(!FindCycle->hasCycle()){
		delete FindCycle;
		DepthFirstOrder *dfs = new DepthFirstOrder(G);
		order = dfs->GetreversePost();
	}
}
std::deque<int> *Topological::GetOrder(){
	return order;
}

bool Topological::isDAG(){
	return order != 0;
}

//*********************************
/*
//Kosaraju Algorithm

Kosaraju::Kosaraju(DirGraph &G){
	marked = new bool(G.V());
	id = new int(G.V());
	DepthFirstOrder *order = new DepthFirstOrder(	
}

void Kosaraju::dfs(DirGraph &G, int v){

}*/
