#include <algorithm>
#include "listgraph.h"

ListGraph::ListGraph(){}

ListGraph::ListGraph(IGraph *oth)
{
    copyGraph(oth);
}

ListGraph::~ListGraph(){}

std::string ListGraph::getType() {return TYPE;}

void ListGraph::copyGraph(IGraph *oth)
{
    if(oth->getType() == "Matrix")
    {
        MatrixGraph *tmp;
        std::cout << "Matrix in List" <<std::endl;
        grph.clear();
        tmp = (MatrixGraph*)oth;


    }else if(oth->getType() == "List")
    {
        ListGraph *tmp;
        std::cout << "List in List" <<std::endl;
        grph.clear();
        tmp = (ListGraph*)oth;
        grph = tmp->grph;
    }
}


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
    if(grph.find(vertex) != grph.end())
    {
        for(auto it = grph.begin(); it != grph.end(); ++it)
        {
            auto itVector = std::find(grph.at(it->first).begin(), grph.at(it->first).end(), vertex);

            if(itVector != grph.at(it->first).end())

                vertices.push_back(it->first);
        }

    }

}
