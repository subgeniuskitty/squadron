/*
 * © 2020 Aaron Taylor <ataylor at subgeniuskitty dot com>
 * See LICENSE file for copyright and license details.
 */

#include <stdlib.h>

#include "filetype_comm.h"
#include "interface_filedata.h"
#include "io_cmdline.h"

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
