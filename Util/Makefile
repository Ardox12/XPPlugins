NAME    = util.a
SRC	= $(wildcard *.c)
OBJ     = $(SRC:.c=.o)
CC	= clang
OS	= $(shell uname)

ifeq "$(OS)" "Linux"
	CFLAGS  = -DLIN -fPIC -O2 -Wno-unused-variable -Wno-return-type
else ifeq "$(OS)" "Darwin"
	CFLAGS  = -DAPL -O2 -Wno-unused-variable -Wno-return-type
endif

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f *.o *.a
