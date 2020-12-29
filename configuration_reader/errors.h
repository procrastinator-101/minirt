/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 16:24:16 by yarroubi          #+#    #+#             */
/*   Updated: 2020/12/29 12:23:06 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define EMA 		71//

/*
**=============			multiple declaration error defines		  =============
*/
# define EMRD								50	//resolution
# define EMAD								51	//ambient light
# define EMSKD								52	//skybox
# define EMSED								53	//sepia
# define EMAAD								54	//anti-aliasing

/*
**=============				critical entities error defines		  =============
*/
# define EERP								60	//resolution
# define EEAP								61	//ambient light
# define EECP								62	//camera

/*
**=============				execution error defines				  =============
*/
# define EFR								70	//FILE_READING_ERROR
# define EMAF								71	//MEMORY_ALLOCATION_FAILURE
# define EMC								72	//MLX_CONNECTION_ERROR
# define EWC								73	//WINDOW_CREATION_ERROR
# define EIC								74	//IMAGE_CREATION_ERROR

/*
**=============				program arguments error defines		  =============
*/
# define EMFE								80	//missing file extension
# define EWFE								81	//wrong file extension
# define EMIF								82	//missing input file
# define EUPA								83	//truncated characters
# define EIA								84	//invalid argument

void					manage_config_error(int fd, char *line, \
						void **entities, int er_nb);
void					manage_exec_error(void **entities, int error_number);
void					display_error_message(int error_number);
void					display_error_message_utils(int error_number);

#endif
