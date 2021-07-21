#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>

int main(void) {
    // Get the HOME directory from the environment variables.
    char *home = getenv("HOME");
    if (home == NULL) {
        printf("$HOME is missing\n");
        return 1;
    }

    // PATH_MAX is the biggest possible path on Linux.
    char path[PATH_MAX + 1];
    // snprintf copies the formatted text on the right to the
    // string on the left.
    snprintf(path, PATH_MAX + 1, "%s/.diary", home);
    printf("%s\n", path);

    // Open a file for reading.
    char line[4096];
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        // perror() prints the error message and code.
        perror("file could not be opened");
        return 1;
    }

    // Print each line of the file.
    while (fgets(line, 4096, file) != NULL) {
        // We're too lazy to take out the \n, so
        // just print without an extra \n.
        printf("%s", line);
    }

    // I'm done with the file.
    fclose(file);

    return 0;
}
