CFLAGS = -g
LDFLAGS = Llib
LIBS = -llibs
SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)
NAME = prog

all: clean $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $(NAME) $(LIBS)

lib: 
	make -C lib

$(OBJECTS):
	$(CC) -c $(CFLAGS) $(SOURCES)


clean: 
	rm -f $(OBJECTS)
	rm -f $(NAME)
	