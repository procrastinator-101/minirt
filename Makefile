# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 10:09:04 by yarroubi          #+#    #+#              #
#    Updated: 2021/01/24 12:50:19 by yarroubi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AUTHOR = youness

NAME = minirt.a

FLAGS = -Wall -Wextra -Werror

CC = gcc

LIB = -lX11 -lXext -lm


RAYTRACER_SRC_PATH = srcs/raytracer
CONFIGURATION_READER_SRC_PATH = srcs/configuration_reader

OBJECTS_INTERACTIVITY_SRC_PATH = srcs/objects_interactivity
OBJECTS_INTERSECTIONS_SRC_PATH = srcs/objects_intersections

LIGHTING_SHADING_SRC_PATH = srcs/lighting_shading
SUPPORT_FUNCTIONS_SRC_PATH = srcs/support_functions
PRINTING_FUCNTIONS_SRC_PATH = srcs/printing_functions

RGB_SRC_PATH = srcs/rgb
LIB_3D_MATH_SRC_PATH = srcs/lib_3d_math

LIBFT_SRC_PATH = srcs/libft
GET_NEXT_LINE_SRC_PATH = srcs/get_next_line


RAYTRACER_SRC = $(RAYTRACER_SRC_PATH)/check_prog_arg.c \
				$(RAYTRACER_SRC_PATH)/get_color.c \
				$(RAYTRACER_SRC_PATH)/get_left_corner.c \
				$(RAYTRACER_SRC_PATH)/get_rotation_matrix.c \
				$(RAYTRACER_SRC_PATH)/handle_filters.c \
				$(RAYTRACER_SRC_PATH)/handle_hidden_objects.c \
				$(RAYTRACER_SRC_PATH)/handle_object_mode.c \
				$(RAYTRACER_SRC_PATH)/image_to_bmp.c \
				$(RAYTRACER_SRC_PATH)/initialise_display.c \
				$(RAYTRACER_SRC_PATH)/initialise_filters.c \
				$(RAYTRACER_SRC_PATH)/initialise_user_parameters.c \
				$(RAYTRACER_SRC_PATH)/manage_key.c \
				$(RAYTRACER_SRC_PATH)/manage_mouse_hits.c \
				$(RAYTRACER_SRC_PATH)/manage_mouse_moves.c \
				$(RAYTRACER_SRC_PATH)/manage_rotation.c \
				$(RAYTRACER_SRC_PATH)/manage_translation.c \
				$(RAYTRACER_SRC_PATH)/raytracer.c \
				$(RAYTRACER_SRC_PATH)/render.c \
				$(RAYTRACER_SRC_PATH)/render_block.c \
				$(RAYTRACER_SRC_PATH)/render_pixel.c \
				$(RAYTRACER_SRC_PATH)/save_image.c \
				$(RAYTRACER_SRC_PATH)/terminate_minirt.c \
				$(RAYTRACER_SRC_PATH)/update_pixel_data.c \
				$(RAYTRACER_SRC_PATH)/update_sphere_mode.c \
				$(RAYTRACER_SRC_PATH)/user_interract.c

OBJECTS_INTERACTIVITY_SRC = $(OBJECTS_INTERACTIVITY_SRC_PATH)/rotate_camera.c \
							$(OBJECTS_INTERACTIVITY_SRC_PATH)/rotate_cone.c \
							$(OBJECTS_INTERACTIVITY_SRC_PATH)/rotate_cube.c \
							$(OBJECTS_INTERACTIVITY_SRC_PATH)/rotate_cylinder.c \
							$(OBJECTS_INTERACTIVITY_SRC_PATH)/rotate_object.c \
							$(OBJECTS_INTERACTIVITY_SRC_PATH)/rotate_plane.c \
							$(OBJECTS_INTERACTIVITY_SRC_PATH)/rotate_pyramid.c \
							$(OBJECTS_INTERACTIVITY_SRC_PATH)/rotate_sphere.c \
							$(OBJECTS_INTERACTIVITY_SRC_PATH)/rotate_square.c \
							$(OBJECTS_INTERACTIVITY_SRC_PATH)/rotate_triangle.c \
							$(OBJECTS_INTERACTIVITY_SRC_PATH)/translate_camera.c \
							$(OBJECTS_INTERACTIVITY_SRC_PATH)/translate_cone.c \
							$(OBJECTS_INTERACTIVITY_SRC_PATH)/translate_cube.c \
							$(OBJECTS_INTERACTIVITY_SRC_PATH)/translate_cylinder.c \
							$(OBJECTS_INTERACTIVITY_SRC_PATH)/translate_light.c \
							$(OBJECTS_INTERACTIVITY_SRC_PATH)/translate_object.c \
							$(OBJECTS_INTERACTIVITY_SRC_PATH)/translate_plane.c \
							$(OBJECTS_INTERACTIVITY_SRC_PATH)/translate_pyramid.c \
							$(OBJECTS_INTERACTIVITY_SRC_PATH)/translate_skybox.c \
							$(OBJECTS_INTERACTIVITY_SRC_PATH)/translate_sphere.c \
							$(OBJECTS_INTERACTIVITY_SRC_PATH)/translate_square.c \
							$(OBJECTS_INTERACTIVITY_SRC_PATH)/translate_triangle.c

LIGHTING_SHADING_SRC = $(LIGHTING_SHADING_SRC_PATH)/ambient_term.c \
					   $(LIGHTING_SHADING_SRC_PATH)/cone_normal.c \
					   $(LIGHTING_SHADING_SRC_PATH)/cylinder_normal.c \
					   $(LIGHTING_SHADING_SRC_PATH)/diffuse_spec_terms.c \
					   $(LIGHTING_SHADING_SRC_PATH)/get_bump_normal.c \
					   $(LIGHTING_SHADING_SRC_PATH)/get_wave_length.c \
					   $(LIGHTING_SHADING_SRC_PATH)/get_wave_normal.c \
					   $(LIGHTING_SHADING_SRC_PATH)/illuminate.c \
					   $(LIGHTING_SHADING_SRC_PATH)/is_light_blocked.c \
					   $(LIGHTING_SHADING_SRC_PATH)/plane_normal.c \
					   $(LIGHTING_SHADING_SRC_PATH)/sphere_normal.c \
					   $(LIGHTING_SHADING_SRC_PATH)/square_normal.c \
					   $(LIGHTING_SHADING_SRC_PATH)/surface_normal.c \
					   $(LIGHTING_SHADING_SRC_PATH)/triangle_normal.c

OBJECTS_INTERSECTIONS_SRC = $(OBJECTS_INTERSECTIONS_SRC_PATH)/get_closest_inter.c \
							$(OBJECTS_INTERSECTIONS_SRC_PATH)/get_intersection.c \
							$(OBJECTS_INTERSECTIONS_SRC_PATH)/get_right_solution.c \
							$(OBJECTS_INTERSECTIONS_SRC_PATH)/intersect_cone.c \
							$(OBJECTS_INTERSECTIONS_SRC_PATH)/intersect_cylinder.c \
							$(OBJECTS_INTERSECTIONS_SRC_PATH)/intersect_object_class.c \
							$(OBJECTS_INTERSECTIONS_SRC_PATH)/intersect_obstacle_class.c \
							$(OBJECTS_INTERSECTIONS_SRC_PATH)/intersect_plane.c \
							$(OBJECTS_INTERSECTIONS_SRC_PATH)/intersect_skybox.c \
							$(OBJECTS_INTERSECTIONS_SRC_PATH)/intersect_sphere.c \
							$(OBJECTS_INTERSECTIONS_SRC_PATH)/intersect_square.c \
							$(OBJECTS_INTERSECTIONS_SRC_PATH)/intersect_triangle.c

RGB_SRC = $(RGB_SRC_PATH)/adjust_rgb.c \
		  $(RGB_SRC_PATH)/get_black_rgb.c \
		  $(RGB_SRC_PATH)/get_map_pix_color.c \
		  $(RGB_SRC_PATH)/get_object_rgb.c \
		  $(RGB_SRC_PATH)/get_rgb_cone.c \
		  $(RGB_SRC_PATH)/get_rgb_cylinder.c \
		  $(RGB_SRC_PATH)/get_rgb_nb.c \
		  $(RGB_SRC_PATH)/get_rgb_plane.c \
		  $(RGB_SRC_PATH)/get_rgb_sphere.c \
		  $(RGB_SRC_PATH)/get_rgb_square.c \
		  $(RGB_SRC_PATH)/get_rgb_triangle.c \
		  $(RGB_SRC_PATH)/uint_to_rgb.c \
		  $(RGB_SRC_PATH)/rgb_cmp.c \
		  $(RGB_SRC_PATH)/rgb_mul_double.c \
		  $(RGB_SRC_PATH)/rgb_mul_rgb.c \
		  $(RGB_SRC_PATH)/rgb_sum.c \
		  $(RGB_SRC_PATH)/rgb_to_uint.c \
		  $(RGB_SRC_PATH)/rgb_to_sepia.c

CONFIGURATION_READER_SRC = $(CONFIGURATION_READER_SRC_PATH)/build_cube.c \
						   $(CONFIGURATION_READER_SRC_PATH)/build_cube_faces.c \
						   $(CONFIGURATION_READER_SRC_PATH)/build_pyramid.c \
						   $(CONFIGURATION_READER_SRC_PATH)/build_pyramid_faces.c \
						   $(CONFIGURATION_READER_SRC_PATH)/check_critical_entities.c \
						   $(CONFIGURATION_READER_SRC_PATH)/check_end_entity_info.c \
						   $(CONFIGURATION_READER_SRC_PATH)/configuration_reader.c \
						   $(CONFIGURATION_READER_SRC_PATH)/construct_cubes.c \
						   $(CONFIGURATION_READER_SRC_PATH)/construct_pyramids.c \
						   $(CONFIGURATION_READER_SRC_PATH)/destroy_entities.c \
						   $(CONFIGURATION_READER_SRC_PATH)/display_configuration_error_message.c \
						   $(CONFIGURATION_READER_SRC_PATH)/display_error_message.c \
						   $(CONFIGURATION_READER_SRC_PATH)/display_execution_error_message.c \
						   $(CONFIGURATION_READER_SRC_PATH)/fetch_point_3d.c \
						   $(CONFIGURATION_READER_SRC_PATH)/fetch_rgb.c \
						   $(CONFIGURATION_READER_SRC_PATH)/fetch_vector_3d.c \
						   $(CONFIGURATION_READER_SRC_PATH)/find_next_arg.c \
						   $(CONFIGURATION_READER_SRC_PATH)/ft_dclst_add_head.c \
						   $(CONFIGURATION_READER_SRC_PATH)/ft_dclst_destroy.c \
						   $(CONFIGURATION_READER_SRC_PATH)/ft_destroy_lst_mem.c \
						   $(CONFIGURATION_READER_SRC_PATH)/ft_lst_add_head.c \
						   $(CONFIGURATION_READER_SRC_PATH)/ft_lst_destroy.c \
						   $(CONFIGURATION_READER_SRC_PATH)/ft_update_next.c \
						   $(CONFIGURATION_READER_SRC_PATH)/ft_update_previous.c \
						   $(CONFIGURATION_READER_SRC_PATH)/get_ambient_light.c \
						   $(CONFIGURATION_READER_SRC_PATH)/get_anti_aliasing.c \
						   $(CONFIGURATION_READER_SRC_PATH)/get_camera.c \
						   $(CONFIGURATION_READER_SRC_PATH)/get_cone.c \
						   $(CONFIGURATION_READER_SRC_PATH)/get_cube.c \
						   $(CONFIGURATION_READER_SRC_PATH)/get_cylinder.c \
						   $(CONFIGURATION_READER_SRC_PATH)/get_entity_info.c \
						   $(CONFIGURATION_READER_SRC_PATH)/get_light.c \
						   $(CONFIGURATION_READER_SRC_PATH)/get_lst_mem_texture.c \
						   $(CONFIGURATION_READER_SRC_PATH)/get_next_lst_mem.c \
						   $(CONFIGURATION_READER_SRC_PATH)/get_plane.c \
						   $(CONFIGURATION_READER_SRC_PATH)/get_previous_lst_mem.c \
						   $(CONFIGURATION_READER_SRC_PATH)/get_pyramid.c \
						   $(CONFIGURATION_READER_SRC_PATH)/get_radius.c \
						   $(CONFIGURATION_READER_SRC_PATH)/get_resolution.c \
						   $(CONFIGURATION_READER_SRC_PATH)/get_screen_pixel.c \
						   $(CONFIGURATION_READER_SRC_PATH)/get_sepia.c \
						   $(CONFIGURATION_READER_SRC_PATH)/get_skybox.c \
						   $(CONFIGURATION_READER_SRC_PATH)/get_sphere.c \
						   $(CONFIGURATION_READER_SRC_PATH)/get_square.c \
						   $(CONFIGURATION_READER_SRC_PATH)/get_texture.c \
						   $(CONFIGURATION_READER_SRC_PATH)/get_texture_color.c \
						   $(CONFIGURATION_READER_SRC_PATH)/get_texture_map.c \
						   $(CONFIGURATION_READER_SRC_PATH)/get_texture_type.c \
						   $(CONFIGURATION_READER_SRC_PATH)/get_triangle.c \
						   $(CONFIGURATION_READER_SRC_PATH)/get_triangle_basis.c \
						   $(CONFIGURATION_READER_SRC_PATH)/get_triangle_texture_center.c \
						   $(CONFIGURATION_READER_SRC_PATH)/initialise_map_dimension.c \
						   $(CONFIGURATION_READER_SRC_PATH)/manage_config_error.c \
						   $(CONFIGURATION_READER_SRC_PATH)/manage_exec_error.c \
						   $(CONFIGURATION_READER_SRC_PATH)/parse_configuration.c \
						   $(CONFIGURATION_READER_SRC_PATH)/prepare_triangle_mapping.c \
						   $(CONFIGURATION_READER_SRC_PATH)/update_start.c

PRINTING_FUCNTIONS_SRC = $(PRINTING_FUCNTIONS_SRC_PATH)/ft_print_object_position.c \
						 $(PRINTING_FUCNTIONS_SRC_PATH)/print_3d_basis.c \
						 $(PRINTING_FUCNTIONS_SRC_PATH)/print_ambient_light.c \
						 $(PRINTING_FUCNTIONS_SRC_PATH)/print_camera.c \
						 $(PRINTING_FUCNTIONS_SRC_PATH)/print_cone.c \
						 $(PRINTING_FUCNTIONS_SRC_PATH)/print_coord_3d.c \
						 $(PRINTING_FUCNTIONS_SRC_PATH)/print_cube.c \
						 $(PRINTING_FUCNTIONS_SRC_PATH)/print_cylinder.c \
						 $(PRINTING_FUCNTIONS_SRC_PATH)/print_entity.c \
						 $(PRINTING_FUCNTIONS_SRC_PATH)/print_light.c \
						 $(PRINTING_FUCNTIONS_SRC_PATH)/print_pixel.c \
						 $(PRINTING_FUCNTIONS_SRC_PATH)/print_plane.c \
						 $(PRINTING_FUCNTIONS_SRC_PATH)/print_pyramid.c \
						 $(PRINTING_FUCNTIONS_SRC_PATH)/print_resolution.c \
						 $(PRINTING_FUCNTIONS_SRC_PATH)/print_rgb.c \
						 $(PRINTING_FUCNTIONS_SRC_PATH)/print_smat_3d.c \
						 $(PRINTING_FUCNTIONS_SRC_PATH)/print_sphere.c \
						 $(PRINTING_FUCNTIONS_SRC_PATH)/print_square.c \
						 $(PRINTING_FUCNTIONS_SRC_PATH)/print_texture.c \
						 $(PRINTING_FUCNTIONS_SRC_PATH)/print_triangle.c

SUPPORT_FUNCTIONS_SRC = $(SUPPORT_FUNCTIONS_SRC_PATH)/convert_to_lit_end.c \
						$(SUPPORT_FUNCTIONS_SRC_PATH)/ft_atod_length.c \
						$(SUPPORT_FUNCTIONS_SRC_PATH)/ft_atoi_length.c \
						$(SUPPORT_FUNCTIONS_SRC_PATH)/ft_isnumber.c \
						$(SUPPORT_FUNCTIONS_SRC_PATH)/ft_issign.c \
						$(SUPPORT_FUNCTIONS_SRC_PATH)/ft_local_endian.c \
						$(SUPPORT_FUNCTIONS_SRC_PATH)/ft_max.c \
						$(SUPPORT_FUNCTIONS_SRC_PATH)/ft_min.c \
						$(SUPPORT_FUNCTIONS_SRC_PATH)/ft_strrstr.c

LIB_3D_MATH_SRC = $(LIB_3D_MATH_SRC_PATH)/check_linear_dependency.c \
				  $(LIB_3D_MATH_SRC_PATH)/coord_3d_add.c \
				  $(LIB_3D_MATH_SRC_PATH)/coord_3d_antimetric_matrix.c \
				  $(LIB_3D_MATH_SRC_PATH)/coord_3d_cmp.c \
				  $(LIB_3D_MATH_SRC_PATH)/coord_3d_len.c \
				  $(LIB_3D_MATH_SRC_PATH)/coord_3d_sub.c \
				  $(LIB_3D_MATH_SRC_PATH)/cross_product.c \
				  $(LIB_3D_MATH_SRC_PATH)/dot_product.c \
				  $(LIB_3D_MATH_SRC_PATH)/get_base_3d.c \
				  $(LIB_3D_MATH_SRC_PATH)/get_coord_3d.c \
				  $(LIB_3D_MATH_SRC_PATH)/normalise_3d_vec.c \
				  $(LIB_3D_MATH_SRC_PATH)/null_3d_smat.c \
				  $(LIB_3D_MATH_SRC_PATH)/null_3d_vec.c \
				  $(LIB_3D_MATH_SRC_PATH)/outer_product.c \
				  $(LIB_3D_MATH_SRC_PATH)/scalar_product.c \
				  $(LIB_3D_MATH_SRC_PATH)/smat_3d_addition.c \
				  $(LIB_3D_MATH_SRC_PATH)/smat_3d_scalar_product.c \
				  $(LIB_3D_MATH_SRC_PATH)/smat_vec_3d_product.c

LIBFT_SRC = $(LIBFT_SRC_PATH)/ft_atoi.c \
			$(LIBFT_SRC_PATH)/ft_bzero.c \
			$(LIBFT_SRC_PATH)/ft_calloc.c \
			$(LIBFT_SRC_PATH)/ft_isalnum.c \
			$(LIBFT_SRC_PATH)/ft_isalpha.c \
			$(LIBFT_SRC_PATH)/ft_isascii.c \
			$(LIBFT_SRC_PATH)/ft_isdigit.c \
			$(LIBFT_SRC_PATH)/ft_isprint.c \
			$(LIBFT_SRC_PATH)/ft_itoa.c \
			$(LIBFT_SRC_PATH)/ft_lstadd_back_bonus.c \
			$(LIBFT_SRC_PATH)/ft_lstadd_front_bonus.c \
			$(LIBFT_SRC_PATH)/ft_lstclear_bonus.c \
			$(LIBFT_SRC_PATH)/ft_lstdelone_bonus.c \
			$(LIBFT_SRC_PATH)/ft_lstiter_bonus.c \
			$(LIBFT_SRC_PATH)/ft_lstlast_bonus.c \
			$(LIBFT_SRC_PATH)/ft_lstmap_bonus.c \
			$(LIBFT_SRC_PATH)/ft_lstnew_bonus.c \
			$(LIBFT_SRC_PATH)/ft_lstsize_bonus.c \
			$(LIBFT_SRC_PATH)/ft_memccpy.c \
			$(LIBFT_SRC_PATH)/ft_memchr.c \
			$(LIBFT_SRC_PATH)/ft_memcmp.c \
			$(LIBFT_SRC_PATH)/ft_memcpy.c \
			$(LIBFT_SRC_PATH)/ft_memmove.c \
			$(LIBFT_SRC_PATH)/ft_memset.c \
			$(LIBFT_SRC_PATH)/ft_putchar_fd.c \
			$(LIBFT_SRC_PATH)/ft_putendl_fd.c \
			$(LIBFT_SRC_PATH)/ft_putnbr_fd.c \
			$(LIBFT_SRC_PATH)/ft_putstr_fd.c \
			$(LIBFT_SRC_PATH)/ft_split.c \
			$(LIBFT_SRC_PATH)/ft_strchr.c \
			$(LIBFT_SRC_PATH)/ft_strcmp.c \
			$(LIBFT_SRC_PATH)/ft_strdup.c \
			$(LIBFT_SRC_PATH)/ft_strjoin.c \
			$(LIBFT_SRC_PATH)/ft_strlcat.c \
			$(LIBFT_SRC_PATH)/ft_strlcpy.c \
			$(LIBFT_SRC_PATH)/ft_strlen.c \
			$(LIBFT_SRC_PATH)/ft_strmapi.c \
			$(LIBFT_SRC_PATH)/ft_strncmp.c \
			$(LIBFT_SRC_PATH)/ft_strnstr.c \
			$(LIBFT_SRC_PATH)/ft_strrchr.c \
			$(LIBFT_SRC_PATH)/ft_strtrim.c \
			$(LIBFT_SRC_PATH)/ft_substr.c \
			$(LIBFT_SRC_PATH)/ft_tolower.c \
			$(LIBFT_SRC_PATH)/ft_toupper.c

GET_NEXT_LINE_SRC = $(GET_NEXT_LINE_SRC_PATH)/get_next_line.c \
					$(GET_NEXT_LINE_SRC_PATH)/get_next_line_utils.c



SRC = $(RAYTRACER_SRC) $(OBJECTS_INTERACTIVITY_SRC) $(LIGHTING_SHADING_SRC) \
	  $(OBJECTS_INTERSECTIONS_SRC) $(RGB_SRC) $(CONFIGURATION_READER_SRC) \
	  $(PRINTING_FUCNTIONS_SRC) $(SUPPORT_FUNCTIONS_SRC) $(LIB_3D_MATH_SRC) \
	  $(LIBFT_SRC) $(GET_NEXT_LINE_SRC)

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
