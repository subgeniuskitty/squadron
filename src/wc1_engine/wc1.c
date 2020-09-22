/*
 * © 2020 Aaron Taylor <ataylor at subgeniuskitty dot com>
 * See LICENSE file for copyright and license details.
 */

#include <stdio.h>

#include "interface_filedata.h"
#include "io_cmdline.h"

int
main(int argc, char ** argv) {
    int pilot_id, msg_id; /* Temporary, for checking imported data. */
    struct file_data * file_data;
    char * path_prefix;

    path_prefix = process_cmdline_args(argc, argv);
    file_data = load_file_data(path_prefix);
    /* TODO: Init I/O. */

    /* Temporary check of imported data. */
    for (pilot_id = 0; pilot_id < 14; pilot_id++) {
        printf("Pilot %d:\n", pilot_id);
        for (msg_id = 0; msg_id < 11; msg_id++) {
            printf("\t%d: %s\n", msg_id, file_data->comm_msgs_wc1[pilot_id][msg_id]);
        }
    }
    for (pilot_id = 0; pilot_id < 14; pilot_id++) {
        printf("Pilot %d:\n", pilot_id);
        for (msg_id = 0; msg_id < 11; msg_id++) {
            printf("\t%d: %s\n", msg_id, file_data->comm_msgs_sm2[pilot_id][msg_id]);
        }
    }
}
