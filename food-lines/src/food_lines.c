#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100       // maximum number of lines

int get_shortest_line_index(int lines[MAX_LINES], int n_lines);

int main(void) {
    int i = 0, lines[MAX_LINES], n_lines, n_new_people, shortest_line_index;

    // get two whitespace separated integers from stdin.
    // number of lines and the number of new people.
    scanf("%d %d\n", &n_lines, &n_new_people);

    for (i = 0; i < n_lines; i++) {
        scanf("%d", &lines[i]);
    }

    for (i = 0; i < n_new_people; i++) {
        // if there's only one line, then there's no need to search for the shortest line.
        if (n_lines == 1) {
            shortest_line_index = 0;
        } else {
            shortest_line_index = get_shortest_line_index(lines, n_lines);
        }
        printf("%d\n", lines[shortest_line_index]);
        lines[shortest_line_index]++;
    }

    return 0;
}

// linear search for the shortest line
int get_shortest_line_index(int lines[MAX_LINES], int n_lines) {
    int shortest_line_index = 0;
    for (int i = 1; i < n_lines; i++) {
        if (lines[shortest_line_index] > lines[i]) {
            shortest_line_index = i;
        }
    }
    return shortest_line_index;
}

