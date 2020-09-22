/*
 * © 2020 Aaron Taylor <ataylor at subgeniuskitty dot com>
 * See LICENSE file for copyright and license details.
 */

#ifndef WC1_IO_CMDLINE_H
#define WC1_IO_CMDLINE_H

char * path_concat(const char * start, const char * end);

char * process_cmdline_args(int argc, char ** argv);

#endif
