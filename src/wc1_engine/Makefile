# © 2020 Aaron Taylor <ataylor at subgeniuskitty dot com>
# See LICENSE file for copyright and license details.

include ../common/mk.conf

SRC != ls *.c

all: wc1

wc1:
	@${CC} ${CFLAGS} ${SRC} -o $@

install: all
	@mkdir -p ${BINPREFIX}
	@cp -f wc1 ${BINPREFIX}
	@chmod 755 ${BINPREFIX}/wc1

uninstall:
	@rm -f ${BINPREFIX}/wc1

clean:
	@rm -f wc1 wc1.core
