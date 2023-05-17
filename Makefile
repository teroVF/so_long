#Standard

NAME = so_long
LIBFT = libft/libft.a
CC = cc
BONUS_PATH = ./bonus/
CFLAGS = -Wall -Werror -Wextra -g
MLXFLAG = -lmlx -lXext -lX11 -lm
INCLUDES = push_swap.h
RM = rm -fr

#Sources
FILES	=	main validate read config render move error

BONUS_FILES	= main validate read config render move put_enemies enemies_move enemy_validate


PS_SRC = $(addsuffix .c, $(FILES))
PS_OBJ = $(addsuffix .o, $(FILES))
BONUS_SRC = $(addsuffix .c, $(BONUS_FILES))
BONUS_OBJ = $(addsuffix .o, $(BONUS_FILES))
SRC_BONUS = $(addprefix $(BONUS_PATH), $(BONUS_SRC))
OBJ_BONUS = $(addprefix $(BONUS_PATH), $(BONUS_OBJ))
INCS = -I.

#Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all: $(NAME)

$(LIBFT):
	@cd libft && $(MAKE) all

#MANDATORY -L./mlx na 42
$(NAME):	$(LIBFT) $(PS_OBJ)
			@echo "$(YELLOW) Compiling: $@ $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(PS_OBJ) $(LIBFT) $(MLXFLAG) -o $@

%.o:		%.c
			@echo "$(YELLOW) Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) -c $< -o $@

bonus:		$(OBJ_BONUS) $(LIBFT)
			@echo "$(YELLOW) Compiling: so_long_bonus $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) $(MLXFLAG) -o so_long_bonus
clean:
			@cd libft && $(MAKE) clean
			@find . -name "*.o" -type f -delete
			@echo "$(BLUE)All objects files cleaned!$(DEF_COLOR)"

fclean: 	clean
			@cd libft && $(MAKE) fclean
			@$(RM) $(NAME) so_long_bonus
			@echo "$(CYAN)All executable files cleaned!$(DEF_COLOR)"

re: 		fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything$(DEF_COLOR)"

.PHONY: 		fclean all re clean
