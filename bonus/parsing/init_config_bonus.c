/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:46:04 by hiamedja          #+#    #+#             */
/*   Updated: 2023/11/30 00:16:17 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	init_config(t_cube *cube)
{
	cube->config.ea = NULL;
	cube->config.we = NULL;
	cube->config.no = NULL;
	cube->config.so = NULL;
}
