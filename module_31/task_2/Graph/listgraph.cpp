#include <algorithm>
#include "listgraph.h"

ListGraph::ListGraph(){}

ListGraph::ListGraph(IGraph *oth)
{

    if(oth->getType() == "Matrix")
    {
        MatrixGraph *tmp = static_cast<MatrixGraph*>(oth);
        if(tmp->VerticesCount() != 0)
        {
            for(int i = 0; i < tmp->VerticesCount(); ++i)
            {
                std::vector<int> tmpVec;
                tmp->getLeaves(i, tmpVec);
                grph[i] = tmpVec;
            }
        }

    }else if(oth->getType() == "List")
    {
        ListGraph *tmp = static_cast<ListGraph*>(oth);
        grph = tmp->grph;
    }
}

ListGraph::~ListGraph(){}

std::string ListGraph::getType() {return TYPE;}

void ListGraph::getLeaves(int vertex, std::vector<int> &leaves)
{
    if(grph.find(vertex) != grph.end())
        leaves = grph.at(vertex);
}

ListGraph &ListGraph::operator=(IGraph &oth)
{
    if(oth.getType() == "Matrix")
    {
        MatrixGraph *tmp = static_cast<MatrixGraph*>(&oth);
        if(tmp->VerticesCount() != 0)
        {
            grph.clear();
            for(int i = 0; i < tmp->VerticesCount(); ++i)
            {
                std::vector<int> tmpVec;
                tmp->getLeaves(i, tmpVec);
                grph[i] = tmpVec;
            }
        }

    }else if(oth.getType() == "List")
    {
        ListGraph *tmp = static_cast<ListGraph*>(&oth);
        if((this != &oth))
        {
            grph.clear();
            grph = tmp->grph;
        }

    }

    return *this;
}

void ListGraph::AddEdge(int from, int to)
{
    int max = from > to ? from : to;
    for(int i = grph.size(); i <= max; ++i)
        grph[i];

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
