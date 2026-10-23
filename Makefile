# drist – a simple hosts deployment tool
# See the LICENSE file for copyright and license details.
.POSIX:

BIN    := drist
PREFIX := /usr/local/bin

all:

install: 
	@echo installing executable to "${PREFIX}"
	@cp "${BIN}" "${PREFIX}/${BIN}"

uninstall:
	@echo removing executable file from "${PREFIX}"
	@rm -f "${PREFIX}/${BIN}"

.PHONY: all install uninstall
