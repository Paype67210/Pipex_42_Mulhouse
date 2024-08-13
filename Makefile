# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 17:11:36 by pdeson            #+#    #+#              #
#    Updated: 2024/02/26 11:14:52 by pdeson           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NC			:= \033[0m
B_RED		:= \033[1;31m
RED 		:= \033[0;31m
B_GREEN		:= \033[1;32m
GREEN 		:= \033[0;32m
B_BLUE 		:= \033[1;34m
BLUE 		:= \033[0;34m
PURPLE		:= \033[0;35m
B_PURPLE	:= \033[1;35m

NAME = pipex
BONUS = pipex_bonus
CC = @cc
CFLAGS = -Werror -Wall -Wextra -g3
LIBFT_LIB = libft/libft.a
SRCES_PATH = sources/
SRCES_BONUS_PATH = sources_bonus/
OBJS_PATH = .obj/
OBJS_BONUS_PATH = .bonus/

SRC =	pipex.c ft_parsing.c ft_program.c pipex_utils.c
SRCS = $(addprefix $(SRCES_PATH), $(SRC))
SRC_BONUS = pipex_bonus.c ft_parsing_bonus.c ft_program_bonus.c pipex_utils_bonus.c
SRCS_BONUS = $(addprefix $(SRCES_BONUS_PATH), $(SRC_BONUS))
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
OBJS = $(addprefix $(OBJS_PATH), $(OBJ))
OBJS_BONUS = $(addprefix $(OBJS_BONUS_PATH), $(OBJ_BONUS))

all: $(NAME)

$(OBJS_PATH)%.o: $(SRCES_PATH)%.c
	@mkdir -p $(OBJS_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_BONUS_PATH)%.o: $(SRCES_BONUS_PATH)%.c
	@mkdir -p $(OBJS_BONUS_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS)

$(NAME): $(OBJS)
	@echo "${PURPLE}======== Pipex ========${NC}"
	@make -C libft/ all --no-print-directory
	@echo "${B_BLUE}Library libft created${NC}"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)
	@echo "${B_GREEN}Compilation Pipex made${NC}"

$(BONUS): $(OBJS_BONUS)
	@echo "${PURPLE}======== Pipex Bonus ========${NC}"
	@make -C libft/ all --no-print-directory
	@echo "${B_BLUE}Library libft created${NC}"
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT_LIB) -o $(BONUS)
	@echo "${B_GREEN}Compilation Pipex_Bonus made${NC}"

clean:
	@make -C libft/ clean --no-print-directory
	@rm -rf $(OBJS)
	@rm -rf $(OBJS_BONUS)

fclean: clean
	@make -C libft/ clean --no-print-directory
	@rm -rf $(NAME) $(OBJS_PATH)
	@rm -rf $(BONUS) $(OBJS_BONUS_PATH)

re: fclean all

.PHONY: all clean fclean re bonus
