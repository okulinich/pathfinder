#include "./pathfinder.h"

t_adjListNode* mx_add_node(int dest, int dist) { 
    t_adjListNode* new_node = (t_adjListNode*)malloc(sizeof(t_adjListNode));

    new_node->dest = dest;
    new_node->distance = dist;
    new_node->next = NULL; 
    return new_node;
}

t_graph* mx_create_graph(int v) { 
    t_graph* graph =  (t_graph *)malloc(sizeof(t_graph));

    graph->v = v;
    graph->arr =  (t_adjList*) malloc(2 * v * sizeof(t_adjList)); 
    for (int i = 0; i < 2 * v; ++i) 
        graph->arr[i].head = NULL; 
    return graph; 
}

void mx_add_edge(t_graph *graph, int src, int dest, int dist) {
    t_adjListNode *new_node = mx_add_node(dest, dist);

    new_node->next = graph->arr[src].head;
    graph->arr[src].head = new_node;
}

void mx_add_new_edges(t_graph *graph, int tmp, char *start, char *end) {
    mx_add_edge(graph, mx_check_name(graph->names, graph->v, start), 
             mx_check_name(graph->names, graph->v, end), tmp);
    mx_add_edge(graph, mx_check_name(graph->names, graph->v, end), 
             mx_check_name(graph->names, graph->v, start), tmp);
}
