.PHONY: all clean test

PROG=   totp
SRCS=   totp.c \
        hmac/hmac_sha1.c \
				sha/sha1.c

UNAME_SYS := $(shell uname -s)
ifeq ($(UNAME_SYS), Linux)
    RESTRICT_PROCESS ?= seccomp
else ifeq ($(UNAME_SYS), OpenBSD)
    CFLAGS ?= -DHAVE_STRTONUM
    RESTRICT_PROCESS ?= pledge
else ifeq ($(UNAME_SYS), FreeBSD)
    CFLAGS ?= -DHAVE_STRTONUM
    RESTRICT_PROCESS ?= capsicum
endif

RESTRICT_PROCESS ?= rlimit
TOTP_CFLAGS ?= -g -Wall -fwrapv -pedantic -pie -fPIE

CFLAGS += $(TOTP_CFLAGS) \
					-D_FORTIFY_SOURCE=2 -O2 -fstack-protector-strong \
          -Wformat -Werror=format-security \
          -fno-strict-aliasing \
					-DRESTRICT_PROCESS=\"$(RESTRICT_PROCESS)\" \
					-DRESTRICT_PROCESS_$(RESTRICT_PROCESS)

LDFLAGS ?= -Wl,-z,relro,-z,now -Wl,-z,noexecstack -I. $(TOTP_LDFLAGS)

all: $(PROG)

$(PROG):
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LDFLAGS)

clean:
	-@rm $(PROG)

test:
	@PATH=.:$(PATH) bats test
