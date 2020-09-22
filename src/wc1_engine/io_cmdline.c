/*
 * © 2020 Aaron Taylor <ataylor at subgeniuskitty dot com>
 * See LICENSE file for copyright and license details.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wc1_config.h"

/*
 * This function assumes 'start' and 'end' can be smashed together to create a
 * valid path. It is only intended to be used for concatenating the
 * user-supplied path to a Wing Commander directory with the #defined files
 * within that directory. The parameter 'start' should be the user-supplied
 * path to a WC installation, guaranteed to have a trailing slash by
 * process_cmdline_args(), and 'end' should always be a #defined path relative
 * to that WC directory, hardcoded during compilation.
 *
 * This function returns a pointer to the heap that the caller must free().
 */
char *
path_concat(const char * start, const char * end) {
    size_t filename_length = strlen(start) + strlen(end) + 1;
    char * filename = calloc(1, filename_length);
    if (filename == NULL) {
        fprintf(stderr, "ERROR: Failed to allocate memory to concatenate %s and %s.\n", start, end);
        exit(EXIT_FAILURE);
    }
    strncat(filename, start, strlen(start));
    strncat(filename, end, strlen(end));
    return filename;
}

void
print_usage(char ** argv) {
    printf("Squadron v%d (www.subgeniuskitty.com)\n"
           "An open source re-implementation of the Wing Commander game engine.\n"
           "\n"
           "Usage: %s <path_to_original_wing_commander_directory>\n"
           "\n"
           "For example, if your original Wing Commander installation contains directories and files like\n"
           "    /usr/home/ataylor/wc_install/WC/GAMEDAT/\n"
           "and\n"
           "    /usr/home/ataylor/wc_install/WC/WC.EXE\n"
           "then you can launch this program with the invocation\n"
           "    %s /usr/home/ataylor/wc_install/\n"
           , VERSION, argv[0], argv[0]
    );
}

char *
process_cmdline_args(int argc, char ** argv) {
    /* See print_usage() for details of command line arguments. */
    if (argc == 1) {
        print_usage(argv);
        exit(EXIT_FAILURE);
    } else if (argc > 2) {
        print_usage(argv);
        exit(EXIT_FAILURE);
    }

    if (argv[1][strlen(argv[1])-1] != '/') {
        char * path_prefix;
        path_prefix = malloc(strlen(argv[1])+2);
        if (path_prefix == NULL) {
            fprintf(stderr, "ERROR: Failed to malloc() space for path_prefix.\n");
            exit(EXIT_FAILURE);
        }
        strncat(strncat(path_prefix, argv[1], strlen(argv[1])), "/", 1);
        return path_prefix;
    } else {
        return argv[1];
    }
}

