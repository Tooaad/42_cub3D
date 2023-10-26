# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpernas- <gpernas-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/05 18:36:42 by gpernas-          #+#    #+#              #
#    Updated: 2021/11/21 19:32:42 by gpernas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project compilation files and directories
NAME            =	cub3D

LNAME           =	cub3D_bonus

C_CUB        =  	cub3D.c 		\
					parse_map.c		\
					parse_data.c	\
					parse_data2.c	\
					key_hook.c		\
					manage_window.c	\
					create_rays.c	\
					walls.c			\
					ray_utils.c		\
					texture_utils.c	\

C_CUB_BONUS     =  	cub3D_bonus.c 			\
					parse_map_bonus.c		\
					parse_data_bonus.c		\
					parse_data2_bonus.c		\
					key_hook_bonus.c		\
					manage_window_bonus.c	\
					create_rays_bonus.c		\
					walls_bonus.c			\
					ray_utils_bonus.c		\
					texture_utils_bonus.c	\
					minimap_bonus.c			\

BONUSFD			=	bonus/
SRCSFD          =   src/
OBJSFD          =   objs/
HDR_INC         =   -I./includes/cub3D.h
LIBFT_HDR 		= 	-I./libft/includes/
LIB_BINARY 		= 	-L./libft -lft
LIBFT 			= 	libft/libft.a

OBJS_CUB     =    $(addprefix $(OBJSFD), $(C_CUB:.c=.o))
OBJS_CUB_B    =    $(addprefix $(OBJSFD), $(C_CUB_BONUS:.c=.o))
# # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# Compilation
CFLAGS			=    -Wall -Wextra -Werror -fsanitize=address # FOR LEAKS
# # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# Colors
RED             = \033[0;31m
GREEN           = \033[0;32m
NONE            = \033[0m
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # 

all: check_libft project $(NAME)
	@echo "Project ready"

check_libft: $(LIBFT)

project:
	@echo "Checking project ..."

projectb:
	@echo "Checking project bonus ..."

$(LIBFT):
	@make -C libft bonus

$(OBJSFD):
	@mkdir $@
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ directory"

$(NAME): $(OBJSFD) $(OBJS_CUB)
	@gcc $(CFLAGS) $(OBJS_CUB) -lmlx -framework OpenGL -framework AppKit libft/libft.a -o $@
	@echo "\t[ $(GREEN)✔$(NONE) ] cub3D executable"

$(OBJSFD)%.o: $(SRCSFD)%.c
	@gcc $(CFLAGS) $(HDR_INC) -c $< -o $@
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ object"

#################################################################
bonus: check_libft projectb $(LNAME)
	@echo "... bonus project ready"

$(LNAME): $(OBJSFD) $(OBJS_CUB_B)
	@gcc $(CFLAGS) $(OBJS_CUB_B) -lmlx -framework OpenGL -framework AppKit libft/libft.a -o $(LNAME)
	@echo "\t[ $(GREEN)✔$(NONE) ] cub3D bonus executable"

$(OBJSFD)%.o: $(BONUSFD)%.c
	@gcc $(CFLAGS) -I./includes/cub3D_bonus.h -c $< -o $@
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ object"

########################################################
clean:
	@/bin/rm -rf $(OBJSFD)
	@echo "\t[ $(RED)✗$(NONE) ] objects directory"
	@make -C ./libft fclean
	@echo "\t[ $(RED)✗$(NONE) ] libft objects"

fclean: clean
	@/bin/rm -f cub3D
	@/bin/rm -f cub3D_bonus
	@echo "\t[ $(RED)✗$(NONE) ] cub3D executable"
	@make -C ./libft fclean

re: fclean all

.PHONY: project all clean fclean re bonus cub_bonus

