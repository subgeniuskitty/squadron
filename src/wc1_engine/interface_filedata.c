/*
 * © 2020 Aaron Taylor <ataylor at subgeniuskitty dot com>
 * See LICENSE file for copyright and license details.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "interface_filedata.h"
#include "filetype_comm.h"

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

struct file_data *
load_file_data(char * file_data_path_prefix) {
    struct file_data * file_data = malloc(sizeof(struct file_data *));

    char * filename = path_concat(file_data_path_prefix, FT_COMM_FILENAME_WC1);
    file_data->comm_msgs_wc1 = load_comm_data(filename);
    free(filename);
    filename = path_concat(file_data_path_prefix, FT_COMM_FILENAME_SM2);
    file_data->comm_msgs_sm2 = load_comm_data(filename);
    free(filename);
    /* TODO: Load all the other file formats here. */

    return file_data;
}
