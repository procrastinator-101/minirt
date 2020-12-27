/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 16:24:16 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/27 16:38:20 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

/*
**=============					error defines					  =============
*/
# define EFR								15	//FILE_READING_ERROR
# define EMA								16	//MEMORY_ALLOCATION_FAILURE
# define EMRD								17	//MULTIPLE_R_DECLARATION
# define EMAD								18	//MULTIPLE_A_DECLARATION
# define EERP								19	//EMPTY_RESOLUTION
# define EEAP								20	//EMPTY_AMBIENT
# define EECP								21	//EMPTY_CAMERA
# define EMC								22	//MLX_CONNECTION_ERROR
# define EWC								23	//WINDOW_CREATION_ERROR
# define EIC								24	//IMAGE_CREATION_ERROR
# define EMFE								25	//MISSING FILE EXTENSION
# define EWFE								26	//WRONG FILE EXTENSION
# define EMIF								27	//MISSING INPUT FILE
# define EUPA								28	//UNDESIRED PROGRAM ARGUMENTS
# define EIA								29	//INVALID ARGUMENT

void					manage_config_error(int fd, char *line, \
						void **entities, int er_nb);
void					manage_exec_error(void **entities, int error_number);
void					display_error_message(int error_number);

#endif
