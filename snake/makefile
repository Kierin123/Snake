CFLAGS = -g -fPIC
LDFLAGS = -shared
SOURCES = Snake.c
OBJECTS = $(SOURCES:.c=.o)
NAME = libsnake.so

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $(NAME) 

$(OBJECTS):
	$(CC) -c $(CFLAGS) $(SOURCES)

clean: 
	rm -f $(OBJECTS)
	rm -f $(NAME)
	