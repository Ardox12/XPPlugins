SRC	= $(wildcard *.c)
CC	= clang
OS	= $(shell uname)

ifeq "$(OS)" "Linux"
	NAME    = lin.xpl
	CFLAGS  = -DLIN -fPIC -O2
	LDFLAGS = ../Util/util.a -fvisibility=hidden -shared -rdynamic -nodefaultlibs -undefined_warning
else ifeq "$(OS)" "Darwin"
	NAME    = mac.xpl
	CFLAGS  = -DAPL -O2
	LDFLAGS = ../XP/Libs/XPLM ../Util/util.a -dynamiclib -fvisibility=hidden -framework ApplicationServices
endif

all: $(NAME)

$(NAME): $(SRC)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

clean:
	rm -f *.o $(NAME)
