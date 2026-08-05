# --------------------------- VARIABLES ---------------------------
NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

# --- ARCHIVOS ---
SRCS	=	ft_printf.c		\
			ft_print_char.c	\
 			ft_print_nbr.c

OBJS	= $(SRCS:.c=.o)

# --------------------------- REGLAS ---------------------------
all: libft $(NAME)

libft:
	$(MAKE) -C libft

$(NAME): $(OBJS)
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft