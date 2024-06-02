NAME = push_swap
LIBFTNAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFTDIR = ./libtft

SRCS = src/dll_swap.c \
       src/main.c \
       src/utilities.c \
       src/error_handling.c \
       src/dll_bubble_sort.c \
	   src/stack_operations.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

all: $(NAME)

$(NAME): $(OBJS) libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFTDIR) -lft

libft:
	@$(MAKE) -C $(LIBFTDIR)
	@echo "Library libft.a built successfully."

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFTDIR) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re libft

#tester
TESTER_GET  =   https://raw.githubusercontent.com/lorenuars19/push_swap_tester/main/push_swap_tester.pl
TESTER      =   ./ps_tester.pl

$(TESTER):
	curl $(TESTER_GET) -o $(TESTER)
3: $(NAME) $(TESTER)
	perl $(TESTER) 3 100
5: $(NAME) $(TESTER)
	perl $(TESTER) 5 100
100: $(NAME) $(TESTER)
	perl $(TESTER) 100 100
500: $(NAME) $(TESTER)
	perl $(TESTER) 500 100