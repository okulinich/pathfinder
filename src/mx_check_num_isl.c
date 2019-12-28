#include "./pathfinder.h"

bool mx_check_num_of_islands(char *num_of_nodes, int v) {
    if(!mx_check_distance(num_of_nodes)) {
        mx_error_in_line(1);
        return false;
    }
    else if(v < 2) {
        mx_printerr("error: invalid number of islands\n");
        return false;
    }
    return true;
}
