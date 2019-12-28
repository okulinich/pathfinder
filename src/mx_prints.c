#include "./pathfinder.h"

static void print_line() {
    for (int i = 0; i < 40; i++)
        mx_printstr("=");
    mx_printstr("\n");
}

static void func(t_adjListNode **ptr, int *path, int i) {
    char *dist = NULL;

    while((*ptr)->dest != path[i + 1])
        (*ptr) = (*ptr)->next;
    dist = mx_itoa((*ptr)->distance);
    mx_printstr(dist);
    free(dist);
}

static void print_distance(int *path, int last_el, t_graph *graph) {
    int dist = 0;
    t_adjListNode *ptr = NULL;
    char *str = NULL;

    for (int i = 0; i < last_el; i++) {
        ptr = graph->arr[path[i]].head;
        if (i < last_el - 1)
            func(&ptr, path, i);
        if (last_el > 2) {
            if (i == last_el - 1) {
                mx_printstr(" = ");
                str = mx_itoa(dist);
                mx_printstr(str);
                free(str);
            }
            else if (i < last_el - 1)
                dist += ptr->distance;
            if (i < last_el - 2)
                mx_printstr(" + ");
        }
    }
}

void mx_format_output(int *arr, int last_el, t_graph *graph) {
    if (arr != NULL && last_el >= 0) {
        print_line();
        mx_printstr("Path: ");
        mx_printstr(graph->names[arr[0]]);
        mx_printstr(" -> ");
        mx_printstr(graph->names[arr[last_el - 1]]);
        mx_printstr("\nRoute: ");
        for (int i = 0; i < last_el; i++) {
            mx_printstr(graph->names[arr[i]]);
            if (i < last_el - 1)
                mx_printstr(" -> ");
            else
                mx_printstr("\n");
        }
        mx_printstr("Distance: ");
        print_distance(arr, last_el, graph);
        mx_printstr("\n");
        print_line();
    }
}

t_paths *mx_print_all_paths(int ss, int dd, int v, t_graph *graph) {
    bool visited[v];
    int path[v];
    int path_index = 0;
    t_paths *head = NULL;
    t_visit v_arr;

    v_arr.d = dd;
    v_arr.s = ss;
    v_arr.path = path;
    v_arr.visited = visited;
    for (int i = 0; i < v; i++)
        visited[i] = false;
    mx_print_all_paths_until(v_arr, &path_index, graph, &head);
    return head;
}
