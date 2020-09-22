/*
 * © 2020 Aaron Taylor <ataylor at subgeniuskitty dot com>
 * See LICENSE file for copyright and license details.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "filetype_comm.h"

/*
 * Parses a COMM file like WC/GAMEDAT/COMMUNIC.DAT or WC/GAMEDAT/COMMSM2.DAT,
 * generating a 2D array of (char *) to the actual message with format
 * array[pilot_id][msg_id]. These COMM files are comprised of 14 blocks of 880
 * bytes, one block per pilot. Each block contains 11 messages of 80
 * characters/bytes each. Shorter messages are padded to 80 characters with
 * zeroed bytes.
 */
char ***
load_comm_data(char * comm_filename) {
    FILE * comm_file;
    char *** pilot_messages;
    int pilot_id, msg_id;

    if ((comm_file = fopen(comm_filename, "r")) == NULL) {
        fprintf(stderr, "ERROR: %s: %s\n", comm_filename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    /* Allocate a 2D array to hold all the comm messages. */
    pilot_messages = malloc(sizeof(char **) * FT_COMM_NUM_PILOTS);
    if (pilot_messages == NULL) {
        fprintf(stderr, "ERROR: Failed to allocate memory for outer comm message array.\n");
        exit(EXIT_FAILURE);
    }
    for (pilot_id = 0; pilot_id < FT_COMM_NUM_PILOTS; pilot_id++) {
        pilot_messages[pilot_id] = malloc(sizeof(char *) * FT_COMM_NUM_MSGS_PER_PILOT);
        if (pilot_messages == NULL) {
            fprintf(stderr, "ERROR: Failed to allocate memory for inner comm message array.\n");
            exit(EXIT_FAILURE);
        }
        for (msg_id = 0; msg_id < FT_COMM_NUM_MSGS_PER_PILOT; msg_id++) {
            pilot_messages[pilot_id][msg_id] = malloc(FT_COMM_MAX_MSG_CHARS+1); /* +1 for null-term */
            if (pilot_messages == NULL) {
                fprintf(stderr, "ERROR: Failed to allocate memory for comm message.\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    /* Populate the 2D comm message array with data from the COMM file. */
    for (pilot_id = 0; pilot_id < FT_COMM_NUM_PILOTS; pilot_id++) {
        for (msg_id = 0; msg_id < FT_COMM_NUM_MSGS_PER_PILOT; msg_id++) {
            char buf[FT_COMM_MAX_MSG_CHARS];
            int i;
            for (i = 0; i < FT_COMM_MAX_MSG_CHARS; i++) {
                char c = fgetc(comm_file);
                if (c != EOF) {
                    buf[i] = c;
                } else {
                    fprintf(stderr, "ERROR: COMM file %s ended prematurely.\n", comm_filename);
                    exit(EXIT_FAILURE);
                }
            }
            strncat(pilot_messages[pilot_id][msg_id], (char *)&buf, FT_COMM_MAX_MSG_CHARS);
        }
    }

    return pilot_messages;
}
