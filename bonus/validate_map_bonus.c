/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:07:23 by codespace         #+#    #+#             */
/*   Updated: 2025/04/08 16:21:03 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_area	*check_map_bonus(char *filename)
{
	t_area	*area;

	area = NULL;
	check_filename(filename);
	validate_map_walls(filename);
	validate_map_shape(filename);
	validate_map_elements(filename);
	validate_map_elements_bonus(filename);
	validate_invalid_elements_bonus(filename);
	validate_start_exit(filename);
	area = collect_info(filename);
	if (is_valid_map_bonus(area))
		return (area);
	return (NULL);
}
