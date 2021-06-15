#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>

#define info(G) G->info
#define nextNode(G) G->nextNode
#define nextNeighbour(G) G->nextNeighbour
#define firstNeighbour(G) G->firstNeighbour

using namespace std;

typedef int InfotypeNode;
typedef struct Node *adrNode;
typedef struct Neighbour *adrNeighbour;
struct Node {
    InfotypeNode info;
    adrNeighbour firstNeighbour;
    adrNode nextNode;
};
struct Neighbour {
    InfotypeNode info;
    adrNeighbour nextNeighbour;
};
typedef adrNode Graph;

void createGraph(Graph &G);
adrNode createNode(InfotypeNode newInfo);
adrNeighbour createNeighbour(InfotypeNode newInfo);
void insertLastNeighbour(adrNeighbour p, adrNode pNode);
void deleteFirstNeighbour(adrNode pNode, adrNeighbour &p);
void deleteAfterNeighbour(adrNeighbour prec, adrNeighbour &P);
void insertFirstNode(InfotypeNode newInfo, Graph &G);
adrNode searchNode(InfotypeNode infoCari, Graph G);
void connect(InfotypeNode node1, InfotypeNode node2, Graph G);
adrNeighbour searchNeighbour(InfotypeNode infoCari, adrNode pN);
void disconnect(InfotypeNode node1, InfotypeNode node2, Graph G);
void printGraph(Graph G);


#endif // HEADER_H_INCLUDED
