#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "./libmx/inc/libmx.h"

typedef struct s_adjListNode {
    int dest;
    int distance;
    struct s_adjListNode *next;
} t_adjListNode;

typedef struct s_adjList {
    t_adjListNode *head;
} t_adjList;

typedef struct s_graph { 
    int v;
    t_adjList *arr;
    char **names;
} t_graph;

typedef struct s_path {
    int *arr;
    int last_index;
    bool flag;
    struct s_path *next;
} t_paths;

typedef struct s_info {
    int fd;
    int readed;
    char *num_of_nodes;
} t_info;

typedef struct s_lines {
    char *start;
    char *end;
    char *d;
    int fd;
} t_lines;

typedef struct s_visit {
    int s;
    int d;
    bool *visited;
    int *path;
} t_visit;

void mx_printerr(const char *str);
void mx_find_my_way(int fd, char *num_of_nodes);
void mx_error_in_line(int i);
void mx_error_in_file(char *arg);
void mx_error_in_file2(char *arg);
void mx_format_output(int *arr, int last_el, t_graph *graph);
t_paths *mx_print_all_paths(int s, int d, int v, t_graph *graph);
void mx_print_all_paths_until(t_visit v_arr, int *path_index, t_graph *graph, t_paths **head);
bool mx_check_distance(char *name);
int mx_check_name(char **names, int size, char *cur_name);
bool mx_isalpha(char *s);
t_paths *mx_create_new_path(int *a, int  indx);
int mx_get_distance(int *path, int last_el, t_graph *graph);
t_paths *mx_create_new_path(int *a, int  indx);
void mx_add_path(t_paths **head, int *a, int indx);
t_adjListNode* mx_add_node(int dest, int dist);
t_graph* mx_create_graph(int v);
void mx_add_edge(t_graph *graph, int src, int dest, int dist);
bool mx_fill_graph(int fd, t_graph *graph);
void mx_find_occurences(t_paths *first, t_graph *graph);
void mx_add_new_edges(t_graph *graph, int tmp, char *start, char *end);
int mx_atoi(char *str);
void mx_display_results(t_graph *graph, t_paths *great);
bool mx_isdigit(char c);
int mx_check_all(t_lines *line, t_graph *graph, int i, char ***names_ptr);
t_lines *mx_create_new_line();
bool mx_check_num_of_islands(char *num_of_nodes, int v);
bool mx_check_alpha(char *line, int tmp, int i);
bool mx_check_name_num(t_graph *graph);
bool mx_check_the_name(t_graph *graph, char *line, char ***names_ptr);

#endif
