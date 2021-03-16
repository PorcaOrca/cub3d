# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 10:47:43 by lodovico          #+#    #+#              #
#    Updated: 2021/03/16 09:23:34 by lodovico         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	$(MAIN)\
			$(DB)\
			$(EM)\
			$(IM)\
			$(TM)\
			$(MAP)\
			$(UT)


MLX_F	=	-lmlx -lXext -lX11 -lm -lbsd

# MLX_F	=	-lmlx -framework OpenGL -framework AppKit

TM		=	img_manage/textures/ft_get_txtcolor.c\
			img_manage/textures/ft_txt_init.c

IM		=	img_manage/color_manage/ft_color.c\
			img_manage/ft_img_fill.c\
			img_manage/ft_img_init.c\
			img_manage/ft_img_pixel_put.c\
			img_manage/ft_img_wall.c\
			img_manage/ft_sprite_sort.c\
			img_manage/ft_sprite.c\

EM		=	event_manage/ft_close.c\
			event_manage/ft_new_frame.c\
			event_manage/ft_movement.c\
			event_manage/ft_key_press.c\
			event_manage/ft_key_release.c

MAIN	=	main/ft_akira2021.c\
			main/ft_init.c\
			main/ft_cub_init.c

MAP		=	maps/ft_element_select.c\
			maps/ft_map.c
			
UT		=	utils/ft_get_next_line.c\
			
DB		= 	debuggin/debug.c\
			debuggin/debugstr.c\
			debuggin/debugint.c

NAME	=	cub3d

CFLAGS	=	-Wall -Werror -Wextra -g

CC		=	gcc

OBJCS	=	$(SRCS:.c=.o)

$(NAME):	$(OBJCS)
			rm -rf $(NAME)
			@$(MAKE) bonus -C ./libft
			$(CC) $(OBJCS) $(CFLAGS) $(MLX_F) ./libft/libft.a -o $(NAME)

lib:		$(OBJCS)
			ar -rc akira2021.a $(OBJCS)
			ranlib akira2021.a
			
run:		$(NAME)
			./cub3d "./maps/map_files/map_trip.cub"

all:		$(NAME)

clean:
			@$(MAKE) clean -C ./libft
			rm -f $(OBJCS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re run
