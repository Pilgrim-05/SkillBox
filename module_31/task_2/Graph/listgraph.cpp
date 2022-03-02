#include "listgraph.h"

ListGraph::ListGraph(){}

ListGraph::ListGraph(IGraph *_oth)
{
    if(_oth->getType() == "Matrix")
    {
        std::cout << "Matrix in List" <<std::endl;
    }else if(_oth->getType() == "List")
    {
        std::cout << "List in List" <<std::endl;
    }
}

ListGraph::~ListGraph(){}

std::string ListGraph::getType() {return type;}

void ListGraph::AddEdge(int from, int to)
{
    grph[to];
    grph[from].push_back(to);
}

int ListGraph::VerticesCount() const {return grph.size();}

void ListGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const
{
    if(grph.find(vertex) != grph.end())
        vertices = grph.at(vertex);
}

void ListGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const
{

}
