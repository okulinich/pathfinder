#include "./pathfinder.h"

static void init_graph(t_graph **graph, int v) {
    (*graph) = mx_create_graph(v);
    (*graph)->v = v;
    (*graph)->names = (char **)malloc(sizeof(char **) * v);
    for (int i = 0; i < v; i++)
        (*graph)->names[i] = mx_strnew(1);
}

static void iter_paths(t_graph *graph, t_paths **head, t_paths **great_copy, t_paths **great) {
    for (int i = 0; i < graph->v; i++)
            for (int j = 0; j < graph->v; j++)
                if (j != i) {
                    (*head) = mx_print_all_paths(i, j, graph->v, graph);
                    while((*great_copy)->next)
                        (*great_copy) = (*great_copy)->next;
                    (*great_copy)->next = *head;
                }
    (*great_copy) = (*great)->next;
    while (*great_copy) {
        mx_find_occurences(*great_copy, graph);
        (*great_copy) = (*great_copy)->next;
    }
}

static void mem_free(t_paths *great) {
    t_paths *prev;

    while(great) {
        prev = great;
        great = great->next;
        free(prev->arr);
        free(prev);
    }
}

static void mem_freee(t_graph *graph) {
    t_adjListNode *cur = NULL;
    t_adjListNode *prev = NULL;

    for (int i = 0; i < graph->v; i++)
        free(graph->names[i]);
    free(graph->names);
    for (int i = 0; i < 2 * graph->v; i++) {
        cur = graph->arr[i].head;
        while(cur) {
            prev = cur;
            cur = cur->next;
            free(prev);
        }
    }
    free(graph->arr);
    free(graph);
}

void mx_find_my_way(int fd, char *num_of_nodes) {
    int v = mx_atoi(num_of_nodes);
    t_graph *graph = NULL;
    t_paths *great = mx_create_new_path(NULL, 0);
    t_paths *great_copy = great;
    t_paths *head = NULL;

    if (!mx_check_num_of_islands(num_of_nodes, v)) {
        free(great);
        return ;
    }
    init_graph(&graph, v);
    if (mx_fill_graph(fd, graph)) {
        iter_paths(graph, &head, &great_copy, &great);
        mx_display_results(graph, great);
    }
    mem_free(great);
    mem_freee(graph);
}
