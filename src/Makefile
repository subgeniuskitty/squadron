# © 2020 Aaron Taylor <ataylor at subgeniuskitty dot com>
# See LICENSE file for copyright and license details.

MODULES = wc1_engine

all:
	@for dir in $(MODULES); do \
		(cd $$dir; ${MAKE} all); \
	done

install:
	@for dir in $(MODULES); do \
		(cd $$dir; ${MAKE} install); \
	done

uninstall:
	@for dir in $(MODULES); do \
		(cd $$dir; ${MAKE} uninstall); \
	done

clean:
	@for dir in $(MODULES); do \
		(cd $$dir; ${MAKE} clean); \
	done
