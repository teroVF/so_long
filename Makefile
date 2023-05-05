#Standard

NAME = so_long
CHECKER = checker
LIBFT = libft/libft.a
CC = cc
SRC_PATH = src/
_PATH = obj/
CFLAGS = -Wall -Werror -Wextra
MLXFLAG = -lmlx -lXext -lX11
INCLUDES = push_swap.h
RM = rm -fr

#Sources
FILES        =     	main validate

BONUS_FILES	=		main_checker free_checker push_checker reverse_checker rotate_checker swap_checker get_checker \
					validate_checker

PS_SRC = $(addsuffix .c, $(FILES))
PS_OBJ = $(addsuffix .o, $(FILES))
# PS_SRC_BONUS = $(addsuffix .c, $(BONUS_FILES))
# PS_OBJ_BONUS = $(addsuffix .o, $(BONUS_FILES))
# SRC_BONUS = $(addprefix $(BONUS_PATH), $(PS_SRC_BONUS))
# OBJ_BONUS = $(addprefix $(BONUS_PATH), $(PS_OBJ_BONUS))
# OBJS =	$(addprefix $(OBJ_PATH), $(OBJ))
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

#MANDATORY
$(NAME):	$(LIBFT) $(PS_OBJ)
			@echo "$(YELLOW) Compiling: $@ $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(PS_OBJ) $(LIBFT) -o $@

%.o:		%.c
			@echo "$(YELLOW) Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) -c $< -o $@

bonus:		$(OBJ_BONUS) $(LIBFT)
			@echo "$(YELLOW) Compiling: $@ $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(CHECKER)
clean:
			@cd libft && $(MAKE) clean
			@$(RM) *.o
			@echo "$(BLUE)All objects files cleaned!$(DEF_COLOR)"

fclean: 	clean
			@cd libft && $(MAKE) fclean
			@$(RM) $(NAME) $(CHECKER)
			@echo "$(CYAN)All executable files cleaned!$(DEF_COLOR)"

re: 		fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything$(DEF_COLOR)"

.PHONY: 		fclean all re clean
