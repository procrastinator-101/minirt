/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 16:24:16 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/22 11:55:15 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define EMAF								72	//MEMORY_ALLOCATION_FAILURE

# define EUED								63	//UNIDENTIFIED ENTITY DECLARATION

/*
**=============				program arguments error defines		  =============
*/
# define EMIFE								40	//missing input file extension
# define EWIFE								41	//wrong input file extension
# define EMIF								42	//missing input file
# define ETCPA								43	//truncated characters after program arguments
# define EIA								44	//invalid argument

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
**=============					map fils error defines		 	  =============
*/
# define EMFME								70	//MAP FILE MISSING EXTENSION
# define EMFWE								71 //MAP FILE WRONG EXTENSION
# define EMPEF								72	//MAP FILE EXTRACTON FAILURE
# define EMPICF								73	//MAP FILE IMAGE CREATION FAILURE

/*
**=============				execution error defines				  =============
*/
# define EIFRF								80	//INPUT_FILE_READING_FAILURE
# define EIFRE								81	//INPUT_FILE_READING_ERROR
# define EIFCF								82	//INPUT_FILE_CLOSING_FAILURE

/*
**=============				execution error defines				  =============
*/
# define EBFOF								90	//BMP FILE OPENING FAILURE
# define EBFCF								91	//BMP FILE CLOSING FAILURE
# define EBFWF								92	//WRITING BMP FILE FAILURE



/*
**=============					MLX error defines				  =============
*/
# define EMCF								100	//MLX_CONNECTION_FAILURE
# define EWCF								101	//WINDOW_CREATION_FAILURE
# define EICF								102	//IMAGE_CREATION_FAILURE


/*
**=============					threads error defines			  =============
*/
# define ETCF								110	//THREAD CREATION FAILURE
# define ETJF								111	//THREAD JOIN FAILURE


void					manage_config_error(int fd, char *line, \
						void **entities, int er_nb);
void					manage_exec_error(void **entities, int error_number);
void					display_error_message(int error_number);
void					display_error_message_utils(int error_number);

#endif
