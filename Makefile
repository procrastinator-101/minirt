# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 10:09:04 by yarroubi          #+#    #+#              #
#    Updated: 2020/03/03 11:21:22 by yarroubi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AUTHOR = youness

NAME = minirt.a

FLAGS = -Wall -Wextra -Werror

CC = gcc

CONFIGURATION_READER_SRC = choose_entity_type.c \
							configuration_reader.c \
							display_error_message.c \
							fetch_point_3d.c \
							fetch_rgb.c \
							fetch_vector_3d.c \
							find_next_arg.c \
							ft_atod_length.c \
							ft_atoi_length.c \
							ft_lst_delete.c \
							ft_lst_destroy.c \
							ft_lstadd_head.c \
							get_ambient_light.c \
							get_camera.c \
							get_cylinder.c \
							get_entity_info.c \
							get_light.c \
							get_plane.c \
							get_resolution.c \
							get_sphere.c \
							get_square.c \
							get_triangle.c \
							manage_config_error.c \
							print_ambient_light.c \
							print_camera.c \
							print_cylinder.c \
							print_entity.c \
							print_light.c \
							print_plane.c \
							print_point_3d.c \
							print_resolution.c \
							print_rgb.c \
							print_sphere.c \
							print_square.c \
							print_triangle.c \
							print_vector_3d.c \
							update_start.c

LIBFT_SRC = libft/ft_atoi.c \
			libft/ft_bzero.c \
			libft/ft_calloc.c \
			libft/ft_isalnum.c \
			libft/ft_isalpha.c \
			libft/ft_isascii.c \
			libft/ft_isdigit.c \
			libft/ft_isprint.c \
			libft/ft_itoa.c \
			libft/ft_lstadd_back_bonus.c \
			libft/ft_lstadd_front_bonus.c \
			libft/ft_lstclear_bonus.c \
			libft/ft_lstdelone_bonus.c \
			libft/ft_lstiter_bonus.c \
			libft/ft_lstlast_bonus.c \
			libft/ft_lstmap_bonus.c \
			libft/ft_lstnew_bonus.c \
			libft/ft_lstsize_bonus.c \
			libft/ft_memccpy.c \
			libft/ft_memchr.c \
			libft/ft_memcmp.c \
			libft/ft_memcpy.c \
			libft/ft_memmove.c \
			libft/ft_memset.c \
			libft/ft_putchar_fd.c \
			libft/ft_putendl_fd.c \
			libft/ft_putnbr_fd.c \
			libft/ft_putstr_fd.c \
			libft/ft_split.c \
			libft/ft_strchr.c \
			libft/ft_strdup.c \
			libft/ft_strjoin.c \
			libft/ft_strlcat.c \
			libft/ft_strlcpy.c \
			libft/ft_strlen.c \
			libft/ft_strmapi.c \
			libft/ft_strncmp.c \
			libft/ft_strnstr.c \
			libft/ft_strrchr.c \
			libft/ft_strtrim.c \
			libft/ft_substr.c \
			libft/ft_tolower.c \
			libft/ft_toupper.c

GET_NEXT_LINE_SRC = get_next_line.c \
					get_next_line_utils.c



SRC = $(CONFIGURATION_READER_SRC) $(LIBFT_SRC) $(GET_NEXT_LINE_SRC)

OBJ = $(SRC:.c=.o)


.PHNONY : clean fclean re

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $@ $^
	@ranlib $@

%.o : %.c
	@$(CC) -o $@ -c $(FLAGS) $<

clean :
		@rm -rf $(OBJ)

fclean : clean
		@rm -rf $(NAME)

re : fclean all
