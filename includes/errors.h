/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 16:24:16 by yarroubi          #+#    #+#             */
/*   Updated: 2021/01/22 18:48:01 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define EMAF								72	//MEMORY_ALLOCATION_FAILURE

# define EUED								63	//UNIDENTIFIED ENTITY DECLARATION

/*
**=============			multiple declaration error defines		  =============
*/
# define EMRD								40	//resolution
# define EMAD								41	//ambient light
# define EMSKD								42	//skybox
# define EMSED								43	//sepia
# define EMAAD								44	//anti-aliasing

/*
**=============				critical entities error defines		  =============
*/
# define EERP								50	//resolution
# define EEAP								51	//ambient light
# define EECP								52	//camera

/*
**=============					map fils error defines		 	  =============
*/
# define EMFME								100	//MAP FILE MISSING EXTENSION
# define EMFWE								101 //MAP FILE WRONG EXTENSION
# define EMPEF								102	//MAP FILE EXTRACTON FAILURE
# define EMPICF								103	//MAP FILE IMAGE CREATION FAILURE

/*
**=============					input file error defines		   =============
*/
# define EIFOF								110	//INPUT_FILE_OPENING_FAILURE
# define EIFRE								111	//INPUT_FILE_READING_ERROR
# define EIFCF								112	//INPUT_FILE_CLOSING_FAILURE

/*
**=============					bmp file error defines			   =============
*/
# define EBFOF								120	//BMP FILE OPENING FAILURE
# define EBFCF								121	//BMP FILE CLOSING FAILURE
# define EBFWF								122	//WRITING BMP FILE FAILURE


/*
**=============					MLX error defines				  =============
*/
# define EMCF								130	//MLX_CONNECTION_FAILURE
# define EWCF								131	//WINDOW_CREATION_FAILURE
# define EICF								132	//IMAGE_CREATION_FAILURE
# define EIEF								133	//IMAGE_EXTRACTION_FAILURE


/*
**=============					threads error defines			  =============
*/
# define ETCF								140	//THREAD CREATION FAILURE
# define ETJF								141	//THREAD JOIN FAILURE

/*
**=============				program arguments error defines		  =============
*/
# define EMIFE								200	//missing input file extension
# define EWIFE								201	//wrong input file extension
# define EMIF								202	//missing input file
# define ETCPA								203	//truncated characters after program arguments
# define EIA								204	//invalid argument


void	manage_config_error(int fd, char *line, \
		void **entities, int er_nb);
void	manage_exec_error(void **entities, int error_number);
void	display_error_message(int error_number);
void	display_configuration_error_message(int error_number);
void	display_execution_error_message(int error_number);

#endif
