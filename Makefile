# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 10:09:04 by yarroubi          #+#    #+#              #
#    Updated: 2020/03/03 11:32:47 by yarroubi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AUTHOR = youness

NAME = minirt.a

FLAGS = -Wall -Wextra -Werror

CC = gcc

CONFIGURATION_READER_SRC = configuration_reader/choose_entity_type.c \
						   configuration_reader/configuration_reader.c \
						   configuration_reader/display_error_message.c \
						   configuration_reader/fetch_point_3d.c \
						   configuration_reader/fetch_rgb.c \
						   configuration_reader/fetch_vector_3d.c \
						   configuration_reader/find_next_arg.c \
						   configuration_reader/ft_atod_length.c \
						   configuration_reader/ft_atoi_length.c \
						   configuration_reader/ft_lst_delete.c \
						   configuration_reader/ft_lst_destroy.c \
						   configuration_reader/ft_lstadd_head.c \
						   configuration_reader/get_ambient_light.c \
						   configuration_reader/get_camera.c \
						   configuration_reader/get_cylinder.c \
						   configuration_reader/get_entity_info.c \
						   configuration_reader/get_light.c \
						   configuration_reader/get_plane.c \
						   configuration_reader/get_resolution.c \
						   configuration_reader/get_sphere.c \
						   configuration_reader/get_square.c \
						   configuration_reader/get_triangle.c \
						   configuration_reader/manage_config_error.c \
						   configuration_reader/print_ambient_light.c \
						   configuration_reader/print_camera.c \
						   configuration_reader/print_cylinder.c \
						   configuration_reader/print_entity.c \
						   configuration_reader/print_light.c \
						   configuration_reader/print_plane.c \
						   configuration_reader/print_point_3d.c \
						   configuration_reader/print_resolution.c \
						   configuration_reader/print_rgb.c \
						   configuration_reader/print_sphere.c \
						   configuration_reader/print_square.c \
						   configuration_reader/print_triangle.c \
						   configuration_reader/print_vector_3d.c \
						   configuration_reader/update_start.c

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

GET_NEXT_LINE_SRC = get_next_line/get_next_line.c \
					get_next_line/get_next_line_utils.c



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