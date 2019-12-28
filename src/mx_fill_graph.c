#include "./pathfinder.h"

bool mx_check_alpha(char *line, int tmp, int i) {
    if (!mx_isalpha(line) || tmp <= 0) {
        mx_error_in_line(i);
        return false;
    }
    else
        return true;
}

bool mx_check_name_num(t_graph *graph) {
    for(int i = 0; i < graph->v; i++)
        if(mx_strcmp(graph->names[i], "") == 0)
            return true;
    return false;
}

bool mx_check_the_name(t_graph *graph, char *line, char ***names_ptr) {
    if (mx_check_name(graph->names, graph->v, line) == -1) {
        if (mx_check_name_num(graph)) {
            free(**names_ptr);
            (**names_ptr) = mx_strdup(line);
            (*names_ptr)++;
        }
        else {
            mx_printerr("error: invalid number of islands\n");
            return false;
        }
    }
    return true;
}

static void w_free_mem(char **start, char **end, char **d, t_lines **line) {
    free(*start);
    free(*end);
    free(*d);
    free(*line);
}

bool mx_fill_graph(int fd, t_graph *graph) {
    t_lines *line = mx_create_new_line();
    char **names_ptr = graph->names;
    int a = 1;

    line->fd = fd;
    for (int i = 2; a > 0; i++) {
        a = mx_check_all(line, graph, i, &names_ptr);
        if (a == -3) {
            w_free_mem(&line->start, &line->end, &line->d, &line);
            return false;
        }
    }
    if (mx_check_name(graph->names, graph->v, "") != -1) {
        mx_printerr("error: invalid number of islands\n");
        w_free_mem(&line->start, &line->end, &line->d, &line);
        return false;
    }
    w_free_mem(&line->start, &line->end, &line->d, &line);
    return true;
}
