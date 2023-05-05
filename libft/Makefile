# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 14:44:19 by anvieira          #+#    #+#              #
#    Updated: 2023/05/03 01:44:22 by anvieira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Standard

NAME		= libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDES = libft.h
RM = rm
AR = ar rcs

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

#Sources

FUNCTION	+=	ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint
FUNCTION	+=	ft_bzero ft_calloc ft_memchr ft_memcmp ft_memcpy ft_memmove ft_memset
FUNCTION	+=	ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd
FUNCTION	+=	ft_atoi ft_itoa ft_tolower ft_toupper
FUNCTION	+=	ft_split ft_strchr ft_strdup ft_striteri ft_strjoin \
			ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp \
			ft_strnstr ft_strrchr ft_strtrim ft_substr ft_printf \
			ft_putchar_ret ft_putnbrhminor ft_putnbrhplus ft_putnbr_ret ft_putnbru_ret \
			ft_putptr_ret ft_putstr_ret get_next_line \
			ft_error ft_pow



BONUS_FUNCTION	=	ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone \
				ft_lstiter ft_lstlast ft_lstmap ft_lstnew ft_lstsize

SRC = $(addsuffix .c, $(FUNCTION))
OBJ = $(addsuffix .o, $(FUNCTION))
BONUS = $(addsuffix .c, $(BONUS_FUNCTION))
BONUS_OBJ = $(addsuffix .o, $(BONUS_FUNCTION))

all:	$(NAME)

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(OBJ)
			@echo "$(GREEN)Libft compiled!$(DEF_COLOR)"

%.o:		%.c
			@echo "$(YELLOW) Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) -c $< -o $@


bonus:		$(OBJ) $(BONUS_OBJ)
			@$(AR) $(NAME) $(OBJ) $(BONUS_OBJ)
			@echo "$(GREEN)Libft with bonusccompiled!$(DEF_COLOR)"


clean:
			@$(RM) -f $(OBJ) $(BONUS_OBJ)
			@echo "$(BLUE)Libft objects files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -fr $(NAME)
			@echo "$(CYAN)Libft executable files cleaned!$(DEF_COLOR)"


re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for libft!$(DEF_COLOR)"


.PHONY:		all clean fclean re
