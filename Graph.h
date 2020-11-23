//
// Created by MarkL on 2020/11/22.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H


class AdjMatrixDirGraph
{
protected:
    int vexNum, edgeNum; // vexNum: num of Vertex edgeNum: num of edges
    int **Matrix;  // an adjacent matrix -> matrix[i][j]
    int *elements; // save the value of vertexes
    mutable bool *tag; // an array save the vertex's status

    void initPara(int vexNum);

    void destroyHelp();


public:


    // construct a graph whose vertex values saved in an array called os
    // and the number of vertex in this Graph is vertexNum.
    // the Graph has no edge.
    AdjMatrixDirGraph(const int os[], int vertexNum);

    // construct a graph whose vertex values is one(default)
    //  and the number of vertex in this Graph is vertexNum.
    explicit AdjMatrixDirGraph(int vertexNum);

    //de-constructor
    ~AdjMatrixDirGraph();

    // return the v-th vertex's value and save it to e
    bool GetElem(int v, int &e) const;

    // change the v-th vertex's value into e
    bool setElem(int v, const int &e);

    // get the number of vertex
    int getVexNum() const;

    // get the number of existing edges
    int getEdgeNum() const;

    // insert an edge from v1 to v2
    void InsertEdge(int v1, int v2);

    // delete an existing edge from v1 to v2
    void DeleteEdge(int v1, int v2);

    // insert a vertex whose value equals to vexValue
    void insertVertex(int vexValue);

    // delete an existing vertex and its relating edges
    void deleteVertex(int vexPos);

    // get the vertex v's status
    bool getTag(int v) const;

    // change the vertex v's status to newTag
    void setTag(int v, bool newTag);

    AdjMatrixDirGraph(const AdjMatrixDirGraph &copy);

    AdjMatrixDirGraph &operator=(const AdjMatrixDirGraph &copy);

    static void displayGraph(AdjMatrixDirGraph &graph);

    void DFSTraverse(int v);

    void BFSTraverse(int v);

};


#endif //GRAPH_GRAPH_H
