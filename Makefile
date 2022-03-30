NAME		= des

INCS		= des.h

SRCS		= main.cpp \
			  des_algorithm.cpp \
			  key_generation.cpp \
			  plain_utils.cpp \
			  str_utils.cpp

OBJS		= $(SRCS:.cpp=.o)

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
