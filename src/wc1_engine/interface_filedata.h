/*
 * © 2020 Aaron Taylor <ataylor at subgeniuskitty dot com>
 * See LICENSE file for copyright and license details.
 */

#ifndef WC1_INTERFACE_FILEDATA_H
#define WC1_INTERFACE_FILEDATA_H

struct file_data {
    /*
     * These are 2D arrays of 'char *' with the form:
     *     comm_msgs_xxx[pilot_id][msg_id]
     * See filetype_comm.h for #defined limits.
     */
    char *** comm_msgs_wc1;
    char *** comm_msgs_sm2;
};

struct file_data * load_file_data(char * file_data_path_prefix);

#endif
