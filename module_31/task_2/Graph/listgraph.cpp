#include <algorithm>
#include "listgraph.h"

ListGraph::ListGraph(){}

ListGraph::ListGraph(IGraph *oth)
{
    MatrixGraph *tmpMatrix = dynamic_cast<MatrixGraph*>(oth);
    if(tmpMatrix)
    {
        if(tmpMatrix->VerticesCount() != 0)
        {
            for(int i = 0; i < tmpMatrix->VerticesCount(); ++i)
            {
                std::vector<int> tmpVec;
                tmpMatrix->getLeaves(i, tmpVec);
                grph[i] = tmpVec;
            }
        }
    }

    ListGraph *tmpList = dynamic_cast<ListGraph*>(oth);
    if(tmpList)
    {
        grph = tmpList->grph;
    }
}

ListGraph::~ListGraph(){}

void ListGraph::getLeaves(int vertex, std::vector<int> &leaves)
{
    if(grph.find(vertex) != grph.end())
        leaves = grph.at(vertex);
}

ListGraph &ListGraph::operator=(const ListGraph &oth)
{
    if((this != &oth))
    {
        grph.clear();
        grph = oth.grph;
    }

    return *this;
}

ListGraph &ListGraph::operator=(IGraph &oth)
{
    MatrixGraph *tmpMatrix = dynamic_cast<MatrixGraph*>(&oth);
    if(tmpMatrix)
    {
        if(tmpMatrix->VerticesCount() != 0)
        {
            grph.clear();
            for(int i = 0; i < tmpMatrix->VerticesCount(); ++i)
            {
                std::vector<int> tmpVec;
                tmpMatrix->getLeaves(i, tmpVec);
                grph[i] = tmpVec;
            }
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
