# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 10:09:04 by yarroubi          #+#    #+#              #
#    Updated: 2021/01/02 09:55:21 by yarroubi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AUTHOR = youness

NAME = minirt.a

FLAGS = -Wall -Wextra -Werror

CC = gcc

LIB = -lX11 -lXext -lm


RAYTRACER_SRC = raytracer/check_prog_arg.c \
				raytracer/get_color.c \
				raytracer/get_left_corner.c \
				raytracer/get_rotation_matrix.c \
				raytracer/handle_filters.c \
				raytracer/handle_hidden_objects.c \
				raytracer/handle_object_mode.c \
				raytracer/image_to_bmp.c \
				raytracer/initialise_display.c \
				raytracer/initialise_filters.c \
				raytracer/manage_key.c \
				raytracer/manage_mouse_hits.c \
				raytracer/manage_mouse_moves.c \
				raytracer/manage_rotation.c \
				raytracer/manage_translation.c \
				raytracer/raytracer.c \
				raytracer/render.c \
				raytracer/render_block.c \
				raytracer/render_pixel.c \
				raytracer/save_image.c \
				raytracer/terminate_minirt.c \
				raytracer/update_pixel_data.c \
				raytracer/update_sphere_mode.c \
				raytracer/user_interract.c

OBJECTS_INTERACTIVITY = objects_interactivity/rotate_camera.c \
						objects_interactivity/rotate_cone.c \
						objects_interactivity/rotate_cube.c \
						objects_interactivity/rotate_cylinder.c \
						objects_interactivity/rotate_object.c \
						objects_interactivity/rotate_plane.c \
						objects_interactivity/rotate_pyramid.c \
						objects_interactivity/rotate_sphere.c \
						objects_interactivity/rotate_square.c \
						objects_interactivity/rotate_triangle.c \
						objects_interactivity/translate_camera.c \
						objects_interactivity/translate_cone.c \
						objects_interactivity/translate_cube.c \
						objects_interactivity/translate_cylinder.c \
						objects_interactivity/translate_light.c \
						objects_interactivity/translate_object.c \
						objects_interactivity/translate_plane.c \
						objects_interactivity/translate_pyramid.c \
						objects_interactivity/translate_skybox.c \
						objects_interactivity/translate_sphere.c \
						objects_interactivity/translate_square.c \
						objects_interactivity/translate_triangle.c

LIGHTING_SHADING_SRC = lighting_shading/ambient_term.c \
					   lighting_shading/cone_normal.c \
					   lighting_shading/cylinder_normal.c \
					   lighting_shading/diffuse_spec_terms.c \
					   lighting_shading/get_bump_normal.c \
					   lighting_shading/get_wave_length.c \
					   lighting_shading/get_wave_normal.c \
					   lighting_shading/illuminate.c \
					   lighting_shading/is_light_blocked.c \
					   lighting_shading/plane_normal.c \
					   lighting_shading/sphere_normal.c \
					   lighting_shading/square_normal.c \
					   lighting_shading/surface_normal.c \
					   lighting_shading/triangle_normal.c

OBJECTS_INTERSECTIONS_SRC = objects_intersections/get_closest_inter.c \
							objects_intersections/get_intersection.c \
							objects_intersections/get_right_solution.c \
							objects_intersections/intersect_cone.c \
							objects_intersections/intersect_cylinder.c \
							objects_intersections/intersect_object_class.c \
							objects_intersections/intersect_obstacle_class.c \
							objects_intersections/intersect_plane.c \
							objects_intersections/intersect_skybox.c \
							objects_intersections/intersect_sphere.c \
							objects_intersections/intersect_square.c \
							objects_intersections/intersect_triangle.c

RGB_SRC = rgb/adjust_rgb.c \
		  rgb/get_black_rgb.c \
		  rgb/get_map_pix_color.c \
		  rgb/get_object_rgb.c \
		  rgb/get_rgb_cone.c \
		  rgb/get_rgb_cylinder.c \
		  rgb/get_rgb_nb.c \
		  rgb/get_rgb_plane.c \
		  rgb/get_rgb_sphere.c \
		  rgb/get_rgb_square.c \
		  rgb/get_rgb_triangle.c \
		  rgb/uint_to_rgb.c \
		  rgb/rgb_cmp.c \
		  rgb/rgb_mul_double.c \
		  rgb/rgb_mul_rgb.c \
		  rgb/rgb_sum.c \
		  rgb/rgb_to_uint.c \
		  rgb/rgb_to_sepia.c

CONFIGURATION_READER_SRC = configuration_reader/build_cube.c \
						   configuration_reader/build_cube_faces.c \
						   configuration_reader/build_pyramid.c \
						   configuration_reader/build_pyramid_faces.c \
						   configuration_reader/check_critical_entities.c \
						   configuration_reader/check_end_entity_info.c \
						   configuration_reader/configuration_reader.c \
						   configuration_reader/construct_cubes.c \
						   configuration_reader/construct_pyramids.c \
						   configuration_reader/destroy_entities.c \
						   configuration_reader/display_error_message.c \
						   configuration_reader/display_error_message_utils.c \
						   configuration_reader/fetch_point_3d.c \
						   configuration_reader/fetch_rgb.c \
						   configuration_reader/fetch_vector_3d.c \
						   configuration_reader/find_next_arg.c \
						   configuration_reader/ft_dclst_add_head.c \
						   configuration_reader/ft_dclst_destroy.c \
						   configuration_reader/ft_lst_add_head.c \
						   configuration_reader/ft_lst_destroy.c \
						   configuration_reader/ft_print_object_position.c \
						   configuration_reader/ft_update_next.c \
						   configuration_reader/ft_update_previous.c \
						   configuration_reader/get_ambient_light.c \
						   configuration_reader/get_anti_aliasing.c \
						   configuration_reader/get_camera.c \
						   configuration_reader/get_cone.c \
						   configuration_reader/get_cube.c \
						   configuration_reader/get_cylinder.c \
						   configuration_reader/get_entity_info.c \
						   configuration_reader/get_light.c \
						   configuration_reader/get_next_lst_mem.c \
						   configuration_reader/get_plane.c \
						   configuration_reader/get_previous_lst_mem.c \
						   configuration_reader/get_pyramid.c \
						   configuration_reader/get_radius.c \
						   configuration_reader/get_resolution.c \
						   configuration_reader/get_screen_pixel.c \
						   configuration_reader/get_sepia.c \
						   configuration_reader/get_skybox.c \
						   configuration_reader/get_sphere.c \
						   configuration_reader/get_square.c \
						   configuration_reader/get_texture.c \
						   configuration_reader/get_texture_color.c \
						   configuration_reader/get_texture_map.c \
						   configuration_reader/get_texture_type.c \
						   configuration_reader/get_triangle.c \
						   configuration_reader/get_triangle_basis.c \
						   configuration_reader/get_triangle_texture_center.c \
						   configuration_reader/initialise_map_dimension.c \
						   configuration_reader/manage_config_error.c \
						   configuration_reader/manage_exec_error.c \
						   configuration_reader/parse_configuration.c \
						   configuration_reader/prepare_triangle_mapping.c \
						   configuration_reader/print_3d_basis.c \
						   configuration_reader/print_ambient_light.c \
						   configuration_reader/print_camera.c \
						   configuration_reader/print_cone.c \
						   configuration_reader/print_coord_3d.c \
						   configuration_reader/print_cylinder.c \
						   configuration_reader/print_entity.c \
						   configuration_reader/print_light.c \
						   configuration_reader/print_pixel.c \
						   configuration_reader/print_plane.c \
						   configuration_reader/print_resolution.c \
						   configuration_reader/print_rgb.c \
						   configuration_reader/print_smat_3d.c \
						   configuration_reader/print_sphere.c \
						   configuration_reader/print_square.c \
						   configuration_reader/print_texture.c \
						   configuration_reader/print_triangle.c \
						   configuration_reader/update_start.c

SUPPORT_FUNCTIONS_SRC = support_functions/convert_to_lit_end.c \
						support_functions/ft_atod_length.c \
						support_functions/ft_atoi_length.c \
						support_functions/ft_local_endian.c \
						support_functions/ft_max.c \
						support_functions/ft_min.c \
						support_functions/ft_issign.c

LIB_3D_MATH = lib_3d_math/check_linear_dependency.c \
			  lib_3d_math/coord_3d_antimetric_matrix.c \
			  lib_3d_math/coord_3d_cmp.c \
			  lib_3d_math/coord_3d_len.c \
			  lib_3d_math/coord_3d_minus.c \
			  lib_3d_math/coord_3d_plus.c \
			  lib_3d_math/cross_product.c \
			  lib_3d_math/dot_product.c \
			  lib_3d_math/get_base_3d.c \
			  lib_3d_math/get_coord_3d.c \
			  lib_3d_math/normalise_3d_vec.c \
			  lib_3d_math/null_3d_smat.c \
			  lib_3d_math/null_3d_vec.c \
			  lib_3d_math/outer_product.c \
			  lib_3d_math/scalar_product.c \
			  lib_3d_math/smat_3d_addition.c \
			  lib_3d_math/smat_3d_scalar_product.c \
			  lib_3d_math/smat_vec_3d_product.c

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
			libft/ft_strcmp.c \
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



SRC = $(RAYTRACER_SRC) $(OBJECTS_INTERACTIVITY) $(LIGHTING_SHADING_SRC) $(OBJECTS_INTERSECTIONS_SRC) \
	  $(RGB_SRC) $(CONFIGURATION_READER_SRC) $(SUPPORT_FUNCTIONS_SRC) \
	  $(LIB_3D_MATH) $(LIBFT_SRC) $(GET_NEXT_LINE_SRC)

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
