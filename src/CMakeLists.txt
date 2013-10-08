include_directories(${GraphLib_SOURCE_DIR}/include)

add_library(GraphLib SHARED DirGraphProc.cpp DirWeightGraph.cpp EagerPrimMST.cpp edge.cpp Graph.cpp kruskalMST.cpp LazyPrimMST.cpp Mybag.cpp ShortestPath.cpp undirGraph.cpp undirGraphProc.cpp unionFinder.cpp weightedGraph.cpp)
