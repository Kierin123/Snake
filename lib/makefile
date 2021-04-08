CFLAGS = -g -fPIC
LDFLAGS = -shared
SOURCES = Snake.c
OBJECTS = $(SOURCES:.c=.o)
NAME = libsnake.so

all: clean $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $(NAME) $(LIBS)

$(OBJECTS):
	$(CC) -c $(CFLAGS) $(SOURCES)

clean: 
	rm -f $(OBJECTS)
	rm -f $(NAME)
	