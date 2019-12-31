#include "./pathfinder.h"

int mx_check_all(t_lines *line, t_graph *graph, int i, char ***names_ptr) {
    int tmp[2] = {0, 1};

    tmp[1] = mx_read_line(&line->start, 2, '-', line->fd);
    if(tmp[1] == -1 && mx_strcmp(line->start, "")  == 0)
        return tmp[1];
    if (!mx_check_alpha(line->start, tmp[1], i) || 
        !mx_check_the_name(graph, line->start, names_ptr))
        return -3;
    tmp[1] = mx_read_line(&line->end, 2, ',', line->fd);
    if (!mx_check_alpha(line->end, tmp[1], i) || 
        !mx_check_the_name(graph, line->end, names_ptr))
        return -3;
    tmp[1] = mx_read_line(&line->d, 2, '\n', line->fd);
    if (!mx_check_distance(line->d) || mx_atoi(line->d) < 1 || tmp[1] < -1) {
        mx_error_in_line(i);
        return -3;
    }
    tmp[0] = mx_atoi(line->d);
    mx_add_new_edges(graph, tmp[0], line->start, line->end);
    return tmp[1];   
}

t_lines *mx_create_new_line() {
    t_lines *line = (t_lines *)malloc(sizeof(t_lines));

    line->d = mx_strnew(1);
    line->end = mx_strnew(1);
    line->start = mx_strnew(1);
    return line;
}
