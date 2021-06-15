#include "header.h"

int main()
{
    Graph G;

    createGraph(G);
    printGraph(G);
    insertFirstNode(17, G);
    insertFirstNode(18, G);

    insertFirstNode(19, G);
    insertFirstNode(20, G);
    printGraph(G);
    connect(17, 18, G);
    printGraph(G);

    connect(17, 19, G);
    connect(18, 19, G);
    connect(18, 20, G);
    printGraph(G);

    disconnect(18, 20, G);
    printGraph(G);

    disconnect(18, 19, G);
    printGraph(G);
    disconnect(18, 17, G);
    printGraph(G);
    disconnect(19, 17, G);
    printGraph(G);

    return 0;
}
