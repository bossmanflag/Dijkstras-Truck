/*
Program to show the implementation of dijkratas algorithm

The program will use linked lists to implement a graph
Point - Item in the graph i.e a city
Node - stores the weight of all the connected Point (linked list)

Each Point(city ) stores a linked list of nodes(cites) it is connected to
The graph can be made in this sense, refer main()
The graph can be passed to dijkstras() to compute shortest distance from one point
to every other point in the graph


Todo -
1. Adding functionality to the menu - ask if you want to calculate more 
2. Documentation and report
3. Custom distance and place entry instead of hardcoding the values
*/

#include <stdio.h>
#include <stdlib.h>
#include "utils.c"

#define MAX_WEIGHT 9999999
#define null NULL

void dijkstra(Vertex *vertices[], int size, int from)
{
    Vertex *toVisit[size], *current;
    int top = -1;
    toVisit[++top] = vertices[from];
    vertices[from]->smallestWeight = 0;
    while (current = toVisit[top--])
    {
        Edge *edge = current->edges->head;
        while (edge != null)
        {
            int _wgt = current->smallestWeight + edge->weight;
            if (_wgt < edge->to->smallestWeight)
            {
                edge->to->smallestWeight = _wgt;
                toVisit[++top] = edge->to;
            }
            edge = edge->next;
        }
        if (top == -1)
            break;
    }
}
// void printList(LinkedList *n)
// {
//     Edge *nn = n->head;
//     while (nn != NULL)
//     {
//         printf("%d \t", nn->weight);
//         printf("%c \n", nn->to->value);
//         nn = nn->next;
//     }
// }

const char cites[][50] = {"Bangalore", "Mumbai", "Delhi", "Chennai", "Kolkata", "Patna", "Jaipur"};

int main(int argc, char *argv[])
{
    int len = sizeof(cites) / sizeof(cites[0]), i;
    Vertex *vertices[len];
    for (i = 0; i < len; i++)
    {
        vertices[i] = makeVertex(cites[i][50]);
        //printf("%c : %d \n", vertices[i]->value, vertices[i]->smallestWeight);
    }

    for (i = 0; i < len; i++)
    {
        LinkedList *list = createLinkedList();
        switch (i)
        {
        case 0: //bangalore
            insert(list, makeEdge(840, vertices[1]));
            insert(list, makeEdge(260, vertices[3]));
            insert(list, makeEdge(1540, vertices[4]));
            insert(list, makeEdge(1580, vertices[5]));
            break;
        case 1: //mumbai
            insert(list, makeEdge(840, vertices[0]));
            insert(list, makeEdge(1163, vertices[2]));
            insert(list, makeEdge(1040, vertices[3]));
            break;
        case 2: //delhi
            insert(list, makeEdge(1760, vertices[1]));
            break;
        case 3: //chennai
            insert(list, makeEdge(260, vertices[0]));
            insert(list, makeEdge(1040, vertices[1]));
            break;
        case 4: //kolkata
            insert(list, makeEdge(1540, vertices[0]));
            insert(list, makeEdge(480, vertices[5]));
            insert(list, makeEdge(1512, vertices[6]));
            break;
        case 5: //patna
            insert(list, makeEdge(1580, vertices[0]));
            insert(list, makeEdge(480, vertices[4]));
            insert(list, makeEdge(1117, vertices[6]));
            break;
        case 6: //jaipur
            insert(list, makeEdge(1360, vertices[4]));
            insert(list, makeEdge(1117, vertices[5]));
            break;
        default:
            break;
        }
        //printf("-------- \n");
        //printList(list);
        vertices[i]->edges = list;
    }

    printf("Choose a city as starting point\n1.Bangalore\n2.Mumbai\n3.Delhi\n4.Chennai\n5.Kolkata\n6.Patna\n7.Jaipur\n");
    int place;
    scanf("%d", &place);
    int from = place - 1;
    dijkstra(vertices, len, from);
    for (i = 0; i < len; i++)
    {
        if (i == from)
            continue;
        printf("The shortest distance from %s to %s is %d kilometers\n", cites[from], cites[i], vertices[i]->smallestWeight);
    }
    return 0;
}