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

ListGraph &ListGraph::operator=(IGraph &oth)
{
    ListGraph *tmpList = dynamic_cast<ListGraph*>(&oth);
    if(tmpList && (this != tmpList))
    {
        grph.clear();
        grph = tmpList->grph;
    }

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

void ListGraph::getLeaves(int vertex, std::vector<int> &leaves)
{
    if(grph.find(vertex) != grph.end())
        leaves = grph.at(vertex);
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
    {
        int tmp = vertex;
        vertices.clear();
        for(auto v : grph.find(tmp)->second)
            if(std::find(vertices.begin(), vertices.end(), v) == vertices.end())
                    vertices.push_back(v);

        for(int i = 0; i < vertices.size(); ++i)
        {
            tmp = vertices[i];
            if(grph.find(tmp) != grph.end())
                for(auto v : grph.find(tmp)->second)
                    if(std::find(vertices.begin(), vertices.end(), v) == vertices.end())
                        vertices.push_back(v);
        }
    }
}

void ListGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const
{    
    if(grph.find(vertex) != grph.end())
    {
        int tmp = vertex;
        vertices.clear();
        for(auto it = grph.begin(); it != grph.end(); ++it)
        {
            if(std::find(grph.at(it->first).begin(), grph.at(it->first).end(), tmp) != grph.at(it->first).end())
                    vertices.push_back(it->first);
        }

        for(int i = 0; i < vertices.size(); ++i)
        {
            tmp = vertices[i];

            for(auto it = grph.begin(); it != grph.end(); ++it)
            {
                if(std::find(grph.at(it->first).begin(), grph.at(it->first).end(), tmp) != grph.at(it->first).end() &&
                        std::find(vertices.begin(), vertices.end(), it->first) == vertices.end())
                        vertices.push_back(it->first);
            }
        }
    }
}
