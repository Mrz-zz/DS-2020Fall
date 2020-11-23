//
// Created by MarkL on 2020/11/22.
//

#include "Graph.h"
#include <iostream>
#include <queue>

using namespace std;


void AdjMatrixDirGraph::destroyHelp()
{
    delete[] elements;
    delete[] tag;

    for (int ipos = 0; ipos < vexNum; ++ipos)
    {
        delete[] Matrix[ipos];
    }
    delete[] Matrix;
}

void AdjMatrixDirGraph::initPara(int vertexNum)
{
    this->vexNum = vertexNum;
    this->edgeNum = 0;
    // initialize the elements array
    this->elements = new int[vexNum];
    for (int i = 0; i < vexNum; ++i)
    {
        this->elements[i] = 0;
    }

    // initialize the tag array
    this->tag = new bool[vexNum];
    for (int i = 0; i < vexNum; ++i)
    {
        this->tag[i] = false;
    }

    // initialize the matrix
    this->Matrix = new int *[vexNum];
    for (int i = 0; i < vexNum; ++i)
    {
        this->Matrix[i] = new int[vexNum];
    }

    for (int i = 0; i < vexNum; ++i)
    {
        for (int j = 0; j < vexNum; ++j)
        {
            this->Matrix[i][j] = 0;
        }
    }

}


AdjMatrixDirGraph::AdjMatrixDirGraph(const int *os, int vertexNum)
{


    this->initPara(vertexNum);
    // copy the values from os[] to elements
    for (int i = 0; i < vexNum; ++i)
    {
        elements[i] = os[i];
    }


}

AdjMatrixDirGraph::AdjMatrixDirGraph(int vertexNum)
{
    initPara(vertexNum);
}


AdjMatrixDirGraph::AdjMatrixDirGraph(const AdjMatrixDirGraph &copy)
{
    this->edgeNum = copy.edgeNum;
    this->vexNum = copy.vexNum;
    this->elements = copy.elements;
    this->Matrix = copy.Matrix;
    this->tag = copy.tag;
}

AdjMatrixDirGraph &AdjMatrixDirGraph::operator=(const AdjMatrixDirGraph &copy)
{
    if (&copy != this)
    {
        this->vexNum = copy.vexNum;
        this->elements = copy.elements;
        this->Matrix = copy.Matrix;
        this->tag = copy.tag;
        this->edgeNum = copy.edgeNum;
    }

    return *this;
}

AdjMatrixDirGraph::~AdjMatrixDirGraph()
{
    destroyHelp();
}

bool AdjMatrixDirGraph::GetElem(int v, int &e) const
{
    if (v >= 0 && v < this->vexNum)
    {
        e = elements[v];
        return true;
    }
    else
        return false;
}

bool AdjMatrixDirGraph::setElem(int v, const int &e)
{
    if (v >= 0 && v < this->vexNum)
    {
        elements[v] = e;
        return true;
    }
    else
    {
        return false;
    }

}

int AdjMatrixDirGraph::getVexNum() const
{
    return this->vexNum;
}


void AdjMatrixDirGraph::InsertEdge(int v1, int v2)
{
    if ((v1 >= 0 && v1 < vexNum) && (v2 >= 0 && v2 < vexNum))
    {
        if (v1 != v2)
        {
            Matrix[v1][v2] = 1;
        }
    }
    else
    {
        cout << "V1 0r V2 doesn't exist!" << endl;
    }
}

void AdjMatrixDirGraph::DeleteEdge(int v1, int v2)
{
    if ((v1 >= 0 && v1 < vexNum) && (v2 >= 0 && v2 < vexNum))
    {
        if (v1 != v2)
        {
            Matrix[v1][v2] = 0;
        }
    }
    else
    {
        cout << "V1 0r V2 doesn't exist!" << endl;
    }
}

bool AdjMatrixDirGraph::getTag(int v) const
{
    if (v >= 0 && v < this->vexNum)
        return tag[v];
    else
        cout << "V doesn't exist!" << endl;

}

void AdjMatrixDirGraph::setTag(int v, bool newTag)
{
    if (v >= 0 && v < this->vexNum)
        tag[v] = tag;
    else
        cout << "V doesn't exist!" << endl;
}

int AdjMatrixDirGraph::getEdgeNum() const
{
    return this->edgeNum;
}

void AdjMatrixDirGraph::displayGraph(AdjMatrixDirGraph &graph)
{
    int vertexNum = graph.vexNum;
    int *ele = graph.elements;
    int **matrix = graph.Matrix;
    cout << "  ";
    for (int i = 0; i < vertexNum; ++i)
    {
        cout << ele[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < vertexNum; ++i)
    {
        cout << ele[i] << " ";
        for (int j = 0; j < vertexNum; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void AdjMatrixDirGraph::insertVertex(int vexValue)
{
    int *newElem = new int[vexNum + 1];
    for (int i = 0; i < vexNum + 1; ++i)
    {
        if (i < vexNum)
            newElem[i] = this->elements[i];
        else
            newElem[i] = vexValue;
    }

    this->elements = newElem;

    int **newMatrix = new int *[vexNum + 1];
    for (int i = 0; i < vexNum + 1; ++i)
    {
        newMatrix[i] = new int[vexNum + 1];
    }

    for (int i = 0; i < vexNum + 1; ++i)
    {
        for (int j = 0; j < vexNum + 1; ++j)
        {
            newMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < vexNum; ++i)
    {
        for (int j = 0; j < vexNum; ++j)
        {
            newMatrix[i][j] = this->Matrix[i][j];
        }
    }
    this->Matrix = newMatrix;

    bool *newTag = new bool[vexNum + 1];
    for (int i = 0; i < vexNum; ++i)
    {
        newTag[i] = tag[i];
    }

    this->tag = newTag;
    this->vexNum += 1;

}

void AdjMatrixDirGraph::deleteVertex(int vexPos)
{


    int *newElem = new int[vexNum - 1];


    for (int i = 0; i < vexNum - 1; ++i)
    {
        if (i < vexPos) newElem[i] = this->elements[i];
        else if (i >= vexPos) newElem[i] = this->elements[i + 1];
    }


    this->elements = newElem;

    int **newMatrix = new int *[vexNum - 1];
    for (int i = 0; i < vexNum - 1; ++i)
    {
        newMatrix[i] = new int[vexNum - 1];
    }

    for (int i = 0; i < vexNum - 1; ++i)
    {
        for (int j = 0; j < vexNum - 1; ++j)
        {
            newMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < vexNum - 1; ++i)
    {
        for (int j = 0; j < vexNum - 1; ++j)
        {
            if (i < vexPos && j < vexPos)
                newMatrix[i][j] = Matrix[i][j];
            else if (i < vexPos && j >= vexPos)
                newMatrix[i][j] = Matrix[i][j + 1];
            else if (i >= vexPos && j < vexPos)
                newMatrix[i][j] = Matrix[i + 1][j];
            else if (i >= vexPos && j >= vexPos)
                newMatrix[i][j] = Matrix[i + 1][j + 1];
        }
    }
    this->Matrix = newMatrix;

    bool *newTag = new bool[vexNum - 1];
    for (int i = 0; i < vexNum - 1; ++i)
    {
        if (i < vexPos) newTag[i] = tag[i];
        else if (i >= vexPos) newTag[i] = tag[i + 1];
    }

    this->tag = newTag;
    this->vexNum -= 1;
}

void AdjMatrixDirGraph::DFSTraverse(int v)
{
    cout << this->elements[v] << "\t";
    this->setTag(v, true);
    for (int i = 0; i < this->vexNum; ++i)
    {
        if (this->Matrix[v][i] && !this->getTag(i))
        {
            DFSTraverse(i);
        }
    }

}

void AdjMatrixDirGraph::BFSTraverse(int v)
{
    queue<int> Q;
    cout << this->elements[v] << "\t";
    this->setTag(v, true);
    Q.push(v);

    while (!Q.empty())
    {
        int u;
        u = Q.front();
        Q.pop();
        for (int w = 0; w < this->vexNum; ++w)
        {
            if (this->Matrix[u][w] && !this->getTag(w))
            {
                Q.push(w);
                cout << w << "\t";
                this->setTag(w, true);
            }
        }
    }


}

