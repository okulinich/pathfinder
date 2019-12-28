#include "./pathfinder.h"

int mx_check_name(char **names, int size, char *cur_name) {
    for (int i = 0; i < size; i++) {
        if (mx_strcmp(cur_name, names[i]) == 0) {
            return i;
        }
    }
    return -1;
}

bool mx_check_vertex(t_graph *graph) {
    char **ptr = graph->names;
    int i = 0;

    while(ptr) {
        if (mx_strcmp(*ptr, "") != 0) {
            i++;
        }
        ptr++;
    }
    if (i == graph->v) {
        return true;
    }
    return false;
}
