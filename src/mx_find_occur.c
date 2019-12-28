#include "./pathfinder.h"

static void mark_occur(t_paths *first, t_paths *cur, int d[2], int flag) {
    if  (flag == 1) {
        if (d[0] > d[1])
            first->flag = false;
        else if(d[1] > d[0])
            cur->flag = false;
    }
    else if (flag == 2) {
        if (d[0] <= d[1])
            cur->flag = false;
        else
            first->flag = false;
    }
}

void mx_find_occurences(t_paths *first, t_graph *graph) {
    t_paths *cur = first->next;
    int d[2] = {mx_get_distance(first->arr, first->last_index, graph), 0};

    if(!first->next)
        return ;
    while(cur) {
        d[1] = mx_get_distance(cur->arr, cur->last_index, graph);
        if (cur->arr[0] == first->arr[0] && cur->arr[cur->last_index - 1] == first->arr[first->last_index - 1])
            mark_occur(first, cur, d, 1);
        if (cur->arr[0] == first->arr[first->last_index - 1] && cur->arr[cur->last_index - 1] == first->arr[0])
            mark_occur(first, cur, d, 2);
        cur = cur->next;
    }
}
