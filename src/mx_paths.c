#include "./pathfinder.h"

t_paths *mx_create_new_path(int *a, int  indx) {
    t_paths *new_node = (t_paths *)malloc(sizeof(t_paths));

    if (a) {
        new_node->arr = (int *)malloc(sizeof(int) * indx);
        for (int i = 0; i < indx; i++)
            new_node->arr[i] = a[i];
    }
    else
        new_node->arr = NULL;
    new_node->last_index = indx;
    new_node->next = NULL;
    new_node->flag = true;
    return new_node;
}

void mx_add_path(t_paths **head, int *a, int indx) {
    t_paths *new_one = NULL;

    if (head == NULL || *head == NULL)
        *head = mx_create_new_path(a, indx);
    else {
        new_one = mx_create_new_path(a, indx);
        new_one->next = *head;
        *head = new_one;
    }
}

int mx_get_distance(int *path, int last_el, t_graph *graph) {
    int dist = 0;
    t_adjListNode *ptr = NULL;
    
    for (int i = 0; i < last_el; i++) {
        ptr = graph->arr[path[i]].head;
        if (i < last_el - 1) {
            while(ptr->dest != path[i + 1])
                ptr = ptr->next;
            if (last_el <= 2)
                return ptr->distance;
        }
        if (last_el > 2) {
            if (i == last_el - 1) {
                return(dist);
            }
            else if (i < last_el - 1)
                dist += ptr->distance;
        }
    }
    return dist;
}

void mx_print_all_paths_until(t_visit v_arr, int *path_index, t_graph *graph, t_paths **head) {
    v_arr.visited[v_arr.s] = true;
    v_arr.path[(*path_index)] = v_arr.s;
    (*path_index)++;

    if(v_arr.s == v_arr.d) {
        mx_add_path(head, v_arr.path, *path_index);
    }
    else {
        t_adjListNode *curr = graph->arr[v_arr.s].head; 
        while(curr) {
            if (!v_arr.visited[curr->dest]) {
                v_arr.s = curr->dest;
                mx_print_all_paths_until(v_arr, path_index, graph, head);
            }
            curr = curr->next;
        }
    }
    (*path_index)--;
    v_arr.visited[v_arr.s] = false;
}

void mx_display_results(t_graph *graph, t_paths *great) {
    while(great->next) {
        if (great->next->flag) {
            mx_format_output(great->next->arr, great->next->last_index, graph);
        }
        great = great->next;
    }
}
