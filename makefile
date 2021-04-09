CFLAGS = -g
LDFLAGS = -Lsnake
LIBS = -lsnake
SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)
NAME = prog

all: libsnake $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $(NAME) $(LIBS)

libsnake: 
	make -C snake

$(OBJECTS):
	$(CC) -c $(CFLAGS) $(SOURCES)


clean: 
	make clean -C snake
	rm -f $(OBJECTS)
	rm -f $(NAME)
	