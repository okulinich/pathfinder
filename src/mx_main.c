#include "./pathfinder.h"

int main(int argc, char *argv[]) {
    t_info cur_file;

    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(-1);
    }
    cur_file.fd = open(argv[1], O_RDONLY);
    if (cur_file.fd < 0) {
        mx_error_in_file(argv[1]);
        exit(-1);
    }
    cur_file.readed = mx_read_line(&cur_file.num_of_nodes, 1, '\n', cur_file.fd);
    if (cur_file.readed <= 0) {
        mx_error_in_file2(argv[1]);
        exit(-1);
    }
    mx_find_my_way(cur_file.fd, cur_file.num_of_nodes);
    free(cur_file.num_of_nodes);
    close(cur_file.fd);
    return 0;
}
