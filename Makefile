# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 12:20:40 by sersanch          #+#    #+#              #
#    Updated: 2023/02/22 15:01:25 by sersanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#### FORMAT #####
RESET		:= \033[0m
BOLD		:= \033[1m
GREEN		:= \033[32m
YELLOW		:= \033[33m
CYAN		:= \033[36m
LMAGENTA	:= \033[95m

##### STANDARD VARIABLES #####
NORM	= norminette -R CheckForbiddenSourceHeader
RM		= rm -f
RMALL	= rm -rf
AR		= ar -rcs
MKDIR	= mkdir -p
MV		= mv -f

##### COMPILATION VARIABLES #####
CFLAGS	= -Wall -Wextra -Werror -MMD
MLX_LIB = -framework OpenGL -framework AppKit

##### NAMES #####
NAME			= so_long
LIBFT_NAME		= libft.a
FT_PRINTF_NAME	= ft_printf.a
GNL_NAME 		= get_next_line.a
#MLX_NAME		= ???

SRC_DIR			= src
INC_DIR			= include
UTILS_DIR		= utils
LIBFT_DIR		= $(UTILS_DIR)/libft
FT_PRINTF_DIR	= $(UTILS_DIR)/ft_printf
GNL_DIR			= $(UTILS_DIR)/get_next_line
MLX_DIR			= $(UTILS_DIR)/minilibx_opengl_20191021


TST_DIR = test

##### HEADERS #####
HEADERS	= $(wildcard ./$(INC_DIR)/*.h)

##### SRC FILES #####
SRC_FILES	= $(wildcard ./$(SRC_DIR)/*.c)
SRC_OBJ		= $(SRC_FILES:%.c=%.o)
SRC_DEP		= $(SRC_FILES:%.c=%.d)


%o: %.c
	$(CC) $(CFLAGS) -L  -c $< -o $@

all: $(NAME) #make_libft make_ft_printf make_gnl make_mlx 

$(NAME): #$(SRC_OBJ) $(INC_DIR)/$(HEADERS)
	@$(CC) $(SRC_FILES) $(MLX_LIB) -o $(NAME)


make_libft:
	@make -C $(LBF_DIR)

make_ft_printf:
	@make -C $(FT_PRINTF_DIR)

make_gnl:
	@make -C $(GNL_DIR)

make_mlx:
	@make -C $(MLX_DIR)

clean:
	@make clean -C $(LBF_DIR)
	@make clean -C $(FT_PRINTF_DIR)
	@make clean -C $(GNL_DIR)
	@make clean -C $(MLX_DIR)
	@$(RMALL) $(SRC_DIR)/$(OBJ_DIR) $(SRC_DIR)/$(DEP_DIR)
	@echo "$(CYAN)$(NAME)$(YELLOW) objects and dependencies deleted.$(RESET)"

fclean: clean
	@make fclean -C $(LBF_DIR)
	@make fclean -C $(FT_PRINTF_DIR)
	@make fclean -C $(GNL_DIR)
#	@make fclean -C $(MLX_DIR)
	@$(RM) $(NAME)
	@echo "$(CYAN)$(NAME)$(YELLOW) deleted.$(RESET)"

re: fclean all

push:
	git add *.c Makefile *.h && git commit -m "Functions updated" && git push

-include $(SRC_DEP)

.PHONY: all clean fclean re make_libft make_gnl make_mlx test
