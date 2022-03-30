NAME		= des

INCS		= des.h

SRCS		= main.c \
			  des_algorithm.c \
			  key_generation.c \
			  plain_algorihtm.c

OBJS		= $(SRCS:.c=.o)

CC			= g++
CFLAGS		= -std=c++17


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS)


all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
