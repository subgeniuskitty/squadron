/*
 * © 2020 Aaron Taylor <ataylor at subgeniuskitty dot com>
 * See LICENSE file for copyright and license details.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wc1_config.h"

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
