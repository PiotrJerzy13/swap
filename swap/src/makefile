NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra


SRCS = src/stack_operations.c \
	   src/stack_operations2.c \
	   src/stack_operations3.c \
	   src/stack_operations4.c \
	   src/stack_operations5.c \
	   src/stack_operations6.c \
	   src/push_swap.c \
       src/main.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(FTPRINTDIR)/$(FTPRINTNAME)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(FTPRINTDIR) -lftprintf

$(FTPRINTDIR)/$(FTPRINTNAME):
	@$(MAKE) -C $(FTPRINTDIR)
	@echo "Library libftprintf.a built successfully."

%.o: %.c
	$(CC) $(CFLAGS) -I$(FTPRINTDIR)/libft -I$(FTPRINTDIR)/src -c $< -o $@

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(FTPRINTDIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(FTPRINTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
