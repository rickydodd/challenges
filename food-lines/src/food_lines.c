#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100       // maximum number of lines
#define MAX_CHARS 10100     // the maximum number of characters to read during input (null char inclusive)

int get_shortest_line_index(int lines[MAX_LINES], int n_lines);

int main(void) {
    int i = 0, lines[MAX_LINES], n_lines, n_new_people, shortest_line_index;
    char line[MAX_CHARS], *end;
    long int li;

    // get two whitespace separated integers from stdin.
    // number of lines and the number of new people.
    scanf("%d %d\n", &n_lines, &n_new_people);

    // get n whitespace separated integers from stdin.
    fgets(line, sizeof(line), stdin);
    end = line;
    while((li = strtol(end, &end, 10))) {
        lines[i] = (int)li;
        i++;
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
        if (n[shortest_line_index] > n[i]) {
            shortest_line_index = i;
        }
    }
    return shortest_line_index;
}

