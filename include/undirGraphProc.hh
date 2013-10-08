#include"undirGraph.hh"
using namespace std;

//----------------------------

#ifndef DFSCLASS
#define DFSCLASS

  /*!
   * \brief The Depth-First Search Class
   *
   * This Graph client uses a recursive method for travesing or searching graph data structure. It is a fundamental recursive method that follows the graph’s edges to find the vertices connected to the vertex provided as argument(or source vertex)
   */

class DepthFirstSearch{
private:
  bool* marked; /*!< marked vertices */
  int count; /*< vertices connected to the source */
  /*!
   * \brief dfs recursive method that visit and mark all adjacent vertices 
   * \param G undirected graph
   * \param v start vertex
   */
  void dfs(Graph&, int v);
public:
  /*!
   * \brief DepthFirstSearch
   * \param G undirected graph
   * \param s source vertex
   */
  DepthFirstSearch(Graph& G, int s);
  /*!
   * \brief Destructor
   */
  ~DepthFirstSearch();
  /*!
   * \brief Marked
   *
   * mark all of the vertices that are connected to the source vertex
   * \param w any vertex of graph G
   * \return true value if w is connected to s
   */
  bool Marked(int w){return marked[w];};
  /*!
   * \brief Count
   * \return the number of the vertices connected to s
   */
  int Count(void){return count;};

};

#endif

//----------------------------

#ifndef DFSFINDPATHCLASS
#define DFSFINDPATHCLASS

 /*!
   * \brief The Depth-First Search to Find Paths Class
   *
   * This Graph client uses depth-first search to find paths to all the vertices in a graph that are connected to a given start vertex s
   */

class DFSfindPaths{
private:
  bool* marked; /*!< marked vertices */
  int* edgeTo; /*!< last vertex on known path to this vertex */
  MyStack* path; /*!< path iterator */
  int s; /*!< source vertex */
  /*!
   * \brief dfs recursive method
   * \param G undirected Graph
   * \param v start vertex
   */
  void dfs(Graph&, int v);
public:
  /*!
   * \brief DFSfindPath
   * \param G undirected graph
   * \param s source vertex
   */
  DFSfindPaths(Graph& G, int s);
  /*!
   * \brief Destructor
   */
  ~DFSfindPaths();
  /*!
   * \brief hasPathTo
   *
   * mark all of the vertices that are connected to the source vertex
   * \param v any vertex of graph G
   * \return true value if there is path from s to v
   */
  bool hasPathTo(int v){return marked[v];};
  /*!
   *\brief pathTo
   *
   * Create a pointer to iterate through the vertices on a path from s to any vertex connected to s
   * \param v any vertex connected to s 
   * \return iterator for path from s to v, or null if no such path
   */
  MyStack* pathTo(int v);
};

#endif

//-----------------------

#ifndef BFPCLASS
#define BFPCLASS

 /*!
   * \brief The Bredht-First Search to Find Paths Class
   *
   * This Graph client uses depth-first search to find paths to all the vertices in a graph that are connected to a given start vertex s
   */

class BreadthFirstPaths{
private:
  bool* marked; /*!< marked vertices */
  int* edgeTo; /*!< last vertex on known path to this vertex */
  MyStack* path; /*!< path iterator */
  MyQueue* queue; /*!< maintains all vertices that have been marked but whose adjacency lists have not been checked.*/
  int s; /*!< source vertex */
  /*!
   * \brief bfs marks all vertices connected to s
   * \param G undirected Graph
   * \param s start vertex
   */
  void bfs(Graph& G, int s);
public:
  /*!
   * \brief BreadthFirstPaths
   * \param G undirected graph
   * \param s source vertex
   */
  BreadthFirstPaths(Graph& G, int s );
  /*!
   * \brief Destructor
   */
  ~BreadthFirstPaths();
  /*!
   * \brief hasPathTo
   *
   * mark all of the vertices that are connected to the source vertex
   * \param v any vertex of graph G
   * \return true value if there is path from s to v
   */
  bool hasPathTo(int v){return marked[v];};
  /*!
   *\brief pathTo
   *
   * Create a pointer to iterate through the vertices on a path from s to any vertex connected to s
   * \param v any vertex connected to s 
   * \return iterator for path from s to v, or null if no such path
   */
  MyStack* pathTo(int v);
};

#endif

//-----------------------

#ifndef CC_CLASS
#define CC_CLASS

  /*!
   * \brief The Depth-First Search Class
   *
   * This Graph client provides its clients with the ability to independently process a graph’s connected components
   */

class CC{
private:
  bool* marked; /*!< marked vertices */
  int* id; /*!< marked vertices */
  int count; /*< vertices connected to the source */
  /*!
   * \brief dfs recursive method that mark and identify all the vertices connected to v
   * \param G undirected graph
   * \param v start vertex
   */
  void dfs(Graph& G, int v);
public:
  /*!
   * \brief CC
   * \param G undirected graph
   */
  CC(Graph& G);
  /*!
   * \brief Destructor
   */
  ~CC();
  /*!
   * \brief connected
   * \param v graph vertex
   * \param w graph vertex
   */
  bool connected(int v, int w){return id[v]==id[w];};
  /*!
   * \brief Id
   * \param v graph vertex
   * \return component identifier (between 0 and count()-1)
   */
  int Id(int v){return id[v];};
  /*!
   * \brief Count
   * \return number of connected components
   */
  int Count(void){return count;};
};

#endif
