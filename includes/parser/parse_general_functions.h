/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_general_functions.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 12:42:48 by svassal           #+#    #+#             */
/*   Updated: 2017/04/19 17:10:28 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_GENERAL_FUNCTIONS_H
# define PARSE_GENERAL_FUNCTIONS_H
# include <core.h>

/*
** Should be called after every detail or object,
** Return ERROR if a coma is misplaced, or NO_ERROR elseway
*/

int				valide_coma(char *s);

/*
** Call subfunction braces if first character is {, brackets if it is [, or
** return NEUTRAL is it isn't any
*/

int				valide_braces_brackets(char *s);

/*
** Skip some characters that are not important
*/

void			character_skipper(char **s);

/*
** Return a parameter, or 0, if arguments are wrong
*/

char			*get_param_list(int type, int param_num);

/*
** Return ERROR if a parameter that doesn't exist is present,
** NO_ERROR elseway
*/

int				existing_parameters(int type, char *s);

/*
** Return ERROR if multiple occurence of the same parameter is present,
** NO_ERROR elseway
*/

int				count_parameters(int type, char *s);

/*
** Uses every error check functions, and return ERROR or NO_ERROR according
** to there results
*/

int				error_check(int type, char *s);

/*
** Calcul the length of a JSON parameter, using the brackets and braces
*/

int				get_param_length(char *s);

/*
** Skip the brackets/braces and their content
*/

void			skip_brackets_braces(char **string);

/*
** Return a scene parameter
*/

char			*get_scene_param(int param_num);

/*
** Return an object parameter (might be a light)
*/

char			*get_object_param(int param_num);

#endif
