#ifndef DirDirGraphProc_H
#define DirDirGraphProc_H

#include <deque>
#include <stack>
class DirGraph;
/*!
 * \brief The DirectedDFS class
 */
class DirectedDFS{
	public:
        /*!
         * \brief DirectedDFS
         * \param G
         * \param s
         */
		DirectedDFS(DirGraph& G, int s);
        /*!
         * \brief DirectedDFS
         * \param G
         * \param s
         * \param elements
         */
		DirectedDFS(DirGraph& G, int *s, int elements);
        /*!
         * \brief Reachable
         * \param v
         * \return
         */
        bool Reachable(int v){return marked[v];}
		~DirectedDFS();
	private:
        bool *marked;/*!<*/
        /*!
         * \brief dfs
         * \param G
         * \param s
         */
		void dfs(DirGraph &G, int s);
};
/*!
 * \brief The DirectedCycle class
 */
class DirectedCycle{
	public:
    /*!
         * \brief DirectedCycle
         * \param G
         */
		DirectedCycle(DirGraph& G);
        /*!
         * \brief hasCycle
         * \return
         */
		bool hasCycle();
        /*!
         * \brief GetCycle
         * \return
         */
        std::deque<int> *GetCycle();
		~DirectedCycle();
	private:
        std::deque<int> cycle;/*!< */
        bool *marked;/*!< */
        int *edgeTo;/*!< */
        bool *onStack;/*!< */
        /*!
         * \brief dfs
         * \param G
         * \param v
         */
		void dfs(DirGraph &G, int v);
};
/*!
 * \brief The DepthFirstOrder class
 */
class DepthFirstOrder{
	public:
    /*!
         * \brief DepthFirstOrder
         * \param G
         */
		DepthFirstOrder(DirGraph& G);
        /*!
         * \brief Getpre
         * \return
         */
        std::deque<int> *Getpre(){return &pre;}
        /*!
         * \brief Getpost
         * \return
         */
        std::deque<int> *Getpost(){return &post;}
        /*!
         * \brief GetreversePost
         * \return
         */
        std::deque<int> *GetreversePost(){return &reversePost;}
		~DepthFirstOrder();
	private:
        bool *marked;/*!< */
        std::deque<int> pre;/*!< */
        std::deque<int> post;/*!< */
        std::deque<int> reversePost;/*!< */
        /*!
         * \brief dfs
         * \param G
         * \param v
         */
		void dfs(DirGraph &G, int v);	
};
/*!
 * \brief The Topological class
 */
class Topological{
	public:
    /*!
         * \brief Topological
         * \param G
         */
		Topological(DirGraph &G);
        /*!
         * \brief GetOrder
         * \return
         */
        std::deque<int> *GetOrder();
        /*!
         * \brief isDAG
         * \return
         */
        bool isDAG();
	private:
        std::deque<int> *order;/*!< */
};

#endif
