# **************************************************************************** #
#                                  PUSH_SWAP                                   #
# **************************************************************************** #

NAME       = push_swap
BONUS_NAME = checker

CC     = cc
CFLAGS = -Wall -Wextra -Werror
RM     = rm -f

# --------------------------- RUTAS ---------------------------
INC_DIR    = includes
SRC_DIR    = src
OBJ_DIR    = obj
BONUS_DIR  = bonus

PRINTF_DIR = printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

# includes: push_swap.h, ft_printf.h y libft.h
INCLUDES = -I$(INC_DIR) -I$(PRINTF_DIR) -I$(PRINTF_DIR)/libft

HEADERS  = $(INC_DIR)/push_swap.h

# --------------------------- FUENTES (OBLIGATORIA) ---------------------------
SRC = \
	main.c							\
	init.c 							\
	errors.c						\
	parse_nums.c					\
	parse_flags.c					\
	stack_utils.c					\
	moves/ft_p.c					\
	moves/ft_r.c					\
	moves/ft_rr.c					\
	moves/ft_s.c					\
	algorithms/algorithm_handler.c	\
	algorithms/simple.c				\
	algorithms/medium.c				\
	algorithms/complex.c			\
	bench.c

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

# --------------------------- FUENTES (BONUS) ---------------------------
BSRC = \
	checker_bonus.c			\
	checker_utils_bonus.c	\
	ck_ops1_bonus.c			\
	ck_ops2_bonus.c

BOBJ = $(BSRC:%.c=$(OBJ_DIR)/%.o)

BSHARED = \
		init.c			\
		errors.c		\
		parse_nums.c	\
		stack_utils.c
BSHOBJ = $(BSHARED:%.c=$(OBJ_DIR)/%.o)

# --------------------------- REGLAS ---------------------------
all: $(NAME)

# El submake de printf se consulta siempre (via FORCE) pero solo recompila
# si algo cambio -> no hay relink.
$(PRINTF_LIB): FORCE
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(PRINTF_LIB) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF_LIB) -o $(NAME)

# objetos de la parte obligatoria (src/ -> obj/)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# --------------------------- BONUS ---------------------------
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(PRINTF_LIB) $(BOBJ) $(BSHOBJ)
	$(CC) $(CFLAGS) $(BOBJ) $(BSHOBJ) $(PRINTF_LIB) -o $(BONUS_NAME)

# objetos del bonus (bonus/ -> obj/)
$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# --------------------------- LIMPIEZA ---------------------------
clean:
	$(MAKE) -C $(PRINTF_DIR) clean
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

FORCE:

.PHONY: all bonus clean fclean re FORCE