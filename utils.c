#include <stdio.h>
#include <stdlib.h>
typedef enum
{
    false,
    true
} bool;

#define MAX_WEIGHT 9999999
#define null NULL
typedef struct _Node Node;
typedef struct _Point Point;
typedef struct _LinkedList LinkedList;

struct _Node
{
    int weight;
    Point *to;
    Node *next;
};

struct _Point
{
    char value;
    LinkedList *edges;
    bool visited;
    int smallestWeight;
};

struct _LinkedList
{
    Node *head;
    Node *tail;
};

Node *makeNode(int weight, Point *to)
{
    Node *edge = (Node *)malloc(sizeof(Node));
    edge->weight = weight;
    edge->to = to;
    edge->next = null;
    return edge;
}

Point *makePoint(char value)
{
    Point *vertex = (Point *)malloc(sizeof(Point));
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

void insert(LinkedList *list, Node *edge)
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

void visit(Point *vertex)
{
    vertex->visited = true;
}

bool isVisited(Point *vertex)
{
    return vertex->visited;
}