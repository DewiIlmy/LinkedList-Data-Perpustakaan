#include "header.h"

void createGraph(Graph &G)
{
    G = NULL;
}

adrNode createNode(InfotypeNode newInfo)
{
    adrNode p;

    p = new Node;
    info(p) = newInfo;
    nextNode(p) = NULL;
    firstNeighbour(p) = NULL;

    return p;
}

adrNeighbour createNeighbour(InfotypeNode newInfo)
{
    adrNeighbour p;

    p = new Neighbour;
    info(p) = newInfo;
    nextNeighbour(p) = NULL;

    return p;
}

void insertLastNeighbour(adrNeighbour p, adrNode pNode) //insertFirstNeighbour
{
    adrNeighbour q;

    if (firstNeighbour(pNode) == NULL) {
        firstNeighbour(pNode) = p;
    }else {
        q = firstNeighbour(pNode);
        while (nextNeighbour(q) != NULL) {
            q = nextNeighbour(q);
        }
        nextNeighbour(q) = p;
    }
}



void deleteFirstNeighbour(adrNode pNode, adrNeighbour &p)
{
    p = firstNeighbour(pNode);
    if(p != NULL){ //tambahan
        firstNeighbour(pNode) = nextNeighbour(p);
        nextNeighbour(p) = NULL;
    }
}

void deleteAfterNeighbour(adrNeighbour prec, adrNeighbour &p)
{
   // p = nextNeighbour(p);
    p = nextNeighbour(prec); //tambahan
    nextNeighbour(prec) = nextNeighbour(p);
    nextNeighbour(p) = NULL;
}

void insertFirstNode(InfotypeNode newInfo, Graph &G)
{
    adrNode p;

    p = createNode(newInfo);

    //nextNode(p) = G;
    //G = p;
    //tambahan
    if(G == NULL){
        G = p;
    } else {
        nextNode(p) = G;
        G = p;
    }
}

adrNode searchNode(InfotypeNode infoCari, Graph G)
{
    adrNode p;

    if (G == NULL) {
        return NULL;
    }else {
        p = G;
        //while (info(p) == infoCari && nextNode(p) != NULL) {
        while (info(p) != infoCari && nextNode(p) != NULL) { //tambahan
            p = nextNode(p);
        }
        if (info(p) == infoCari) {
            return p;
        }else {
            return NULL;
        }
    }
}

void connect(InfotypeNode node1, InfotypeNode node2, Graph G)
{
    adrNeighbour N1, N2, q;
    adrNode p1, p2;

    if (G!=NULL){ //tambahan
        p1 = searchNode(node1, G);
        p2 = searchNode(node2, G);

        if (p1 != NULL && p2 != NULL) {
            //N1 = createNeighbour(node2);
            //N2 = createNeighbour(node1);
            N1 = createNeighbour(node1); //tambahan
            N2 = createNeighbour(node2); //tambahan
            insertLastNeighbour(N1, p2);
            insertLastNeighbour(N2, p1);
        } else {
            cout<<"Node tidak ditemukan";
        }
    }
}

adrNeighbour searchNeighbour(InfotypeNode infoCari, adrNode pN)
{
    adrNeighbour p;

    p = firstNeighbour(pN);
    if(p!=NULL) { //tambahan
        while (info(p) != infoCari && nextNeighbour(p) != NULL) {
            p = nextNeighbour(p);
        }
        if (info(p) == infoCari) {
            return p;
        }else {
            return NULL;
        }
    }
    return p; //tambahan
}

void disconnect(InfotypeNode node1, InfotypeNode node2, Graph G)
{
    adrNeighbour n1, n2, p, prec;
    adrNode p1, p2;

    p1 = searchNode(node1, G);
    p2 = searchNode(node2, G);
    if (p1 != NULL && p2 != NULL) {
        n1 = searchNeighbour(node1, p2); //n1 - p2
        n2 = searchNeighbour(node2, p1); //n2 - p1
        if (n2 != NULL && n1 != NULL){
            //if (n1 == firstNeighbour(p1) && n2 == firstNeighbour(p2)){
            if (n1 == firstNeighbour(p2) && n2 == firstNeighbour(p1)){ //tambahan
                deleteFirstNeighbour(p1, p);
                deleteFirstNeighbour(p2, p);
            //}else if (n1 != firstNeighbour(p1) && n2 == firstNeighbour(p2)) {
            }else if (n2 != firstNeighbour(p1) && n1 == firstNeighbour(p2)) { //tambahan
                deleteFirstNeighbour(p2, p);

                prec = firstNeighbour(p1);
                //while (nextNeighbour(prec) != n1) {
                while (nextNeighbour(prec) != n2) { //tambahan
                    prec = nextNeighbour(prec);
                }
                deleteAfterNeighbour(prec, p);
            //}else if (n1 == firstNeighbour(p1) && n2 != firstNeighbour(p2)) {
            }else if (n2 == firstNeighbour(p1) && n1 != firstNeighbour(p2)) { //tambahan
                deleteFirstNeighbour(p1, p);

                prec = firstNeighbour(p2);
                //while (nextNeighbour(prec) != n2) {
                while (nextNeighbour(prec) != n1) { //tambahan
                    prec = nextNeighbour(prec);
                }
                deleteAfterNeighbour(prec, p);
            }else {
                prec = firstNeighbour(p1);
                //while (nextNeighbour(prec) != n1) {
                while (nextNeighbour(prec) != n2) { //tambahan
                    prec = nextNeighbour(prec);
                }
                deleteAfterNeighbour(prec, p);

                prec = firstNeighbour(p2);
                //while (nextNeighbour(prec) != n2) {
                while (nextNeighbour(prec) != n1) { //tambahan
                    prec = nextNeighbour(prec);
                }
                deleteAfterNeighbour(prec, p);
            }
        }
    }
}

void printGraph(Graph G)
{
    adrNode p;
    adrNeighbour n;
    if (G != NULL) {
        p = G;
        while (p != NULL) {
            n = firstNeighbour(p);
            cout<<"Node "<<info(p)<<": ";
            if(n == NULL) { //tambahan
                cout<<"null; ";
            }
            while (n != NULL) {
                cout<<info(n)<<", ";
                n = nextNeighbour(n);
            }
            p = nextNode(p);
        }
    }else {
        cout<<"Graf kosong";
    }
    cout<<endl;
}
