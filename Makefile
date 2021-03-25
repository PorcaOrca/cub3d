# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 10:47:43 by lodovico          #+#    #+#              #
#    Updated: 2021/03/25 10:19:35 by lspazzin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	$(MAIN)\
			$(EM)\
			$(IM)\
			$(TM)\
			$(MAP)\
			$(UT)


# MLX_F	=	-lmlx -lXext -lX11 -lm -lbsd

MLX_F	=	-Lminilibx -lmlx -framework OpenGL -framework AppKit

TM		=	img_manage/textures/ft_get_txtcolor.c\
			img_manage/textures/ft_txt_init.c

IM		=	img_manage/color_manage/ft_color.c\
			img_manage/ft_img_fill.c\
			img_manage/ft_img_init.c\
			img_manage/ft_img_pixel_put.c\
			img_manage/ft_img_wall.c\
			img_manage/ft_sprite_sort.c\
			img_manage/ft_sprite.c\
			img_manage/ft_img_wall_2.c

EM		=	event_manage/ft_close.c\
			event_manage/ft_new_frame.c\
			event_manage/ft_movement.c\
			event_manage/ft_forward.c\
			event_manage/ft_backward.c\
			event_manage/ft_strafe_left.c\
			event_manage/ft_strafe_right.c\
			event_manage/ft_key_press.c\
			event_manage/ft_key_release.c\
			event_manage/ft_rotate.c

MAIN	=	main/ft_akira2021.c\
			main/ft_init.c\
			main/ft_init_2.c\
			main/ft_cub_init.c\
			main/ft_param_clean.c

MAP		=	maps/ft_element_select.c\
			maps/ft_map.c\
			maps/ft_map_2.c

UT		=	utils/ft_get_next_line.c\
			utils/ft_free_matrix.c\
			utils/ft_bmp.c

NAME	=	cub3d

CFLAGS	=	-Wall -Werror -Wextra

CC		=	gcc

OBJCS	=	$(SRCS:.c=.o)

	#		$(CC)  $(OBJCS) $(CFLAGS) $(MLX_F) -o -L libft libft/libft.a $(NAME)

all:		$(NAME)

$(NAME):	$(OBJCS)
			@echo "remove old executable..."
			@rm -rf $(NAME)
			@echo "compiling libft..."
			@make -s -C ./libft
			@echo "compiling minilibx..."
			@$(MAKE) -C ./minilibx
			@cp ./minilibx/libmlx.dylib ./
			@echo "compiling cub3d"
			@gcc $(CFLAGS) -o $(NAME) $(OBJCS) -Llibft -lft $(MLX_F)
			@echo "done :)"

run:		$(NAME)
			./cub3d "./maps/map_files/map_trip.cub"

save:		$(NAME)
			./cub3d "./maps/map_files/map_trip.cub" "--save"

clean:
			@$(MAKE) clean -C ./libft
			@$(MAKE) clean -C ./minilibx
			rm -f libmlx.dylib
			rm -f $(OBJCS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re run
