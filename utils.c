#include <stdio.h>
#include <stdlib.h>
typedef enum
{
    false,
    true
} bool;

#define MAX_WEIGHT 9999999
#define null NULL
typedef struct _Edge Edge;
typedef struct _Vertex Vertex;
typedef struct _LinkedList LinkedList;

struct _Edge
{
    int weight;
    Vertex *to;
    Edge *next;
};

struct _Vertex
{
    char value;        // name of city
    LinkedList *edges; // [edge1 , edge2, edge3... ]
    // insert(edge3)
    bool visited;
    int smallestWeight;
};

struct _LinkedList
{
    Edge *head;
    Edge *tail;
};
// \     \
//[1,2,3,4]

Edge *makeEdge(int weight, Vertex *to)
{
    Edge *edge = (Edge *)malloc(sizeof(Edge));
    edge->weight = weight;
    edge->to = to;
    edge->next = null;
    return edge;
}

Vertex *makeVertex(char value)
{
    Vertex *vertex = (Vertex *)malloc(sizeof(Vertex));
    vertex->value = value;
    vertex->edges = null;
    vertex->visited = false;
    vertex->smallestWeight = MAX_WEIGHT;
    return vertex;
}

LinkedList *createLinkedList()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = null;
    list->tail = null;
    return list;
}
// []

void insert(LinkedList *list, Edge *edge)
{
    if (list->head == null)
    {
        list->head = edge;
        list->tail = edge;
    }
    else
    {
        list->tail->next = edge;
        list->tail = edge;
    }
}

void visit(Vertex *vertex)
{
    vertex->visited = true;
}

bool isVisited(Vertex *vertex)
{
    return vertex->visited;
}