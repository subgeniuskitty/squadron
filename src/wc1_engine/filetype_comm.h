/*
 * © 2020 Aaron Taylor <ataylor at subgeniuskitty dot com>
 * See LICENSE file for copyright and license details.
 */

#ifndef WC1_FILETYPE_COMM_H
#define WC1_FILETYPE_COMM_H

#define FT_COMM_NUM_PILOTS         14
#define FT_COMM_NUM_MSGS_PER_PILOT 11
#define FT_COMM_MAX_MSG_CHARS      80
#define FT_COMM_FILENAME_WC1       "WC/GAMEDAT/COMMUNIC.DAT"
#define FT_COMM_FILENAME_SM2       "WC/GAMEDAT/COMMSM2.DAT"

char *** load_comm_data(char * path);

#endif
