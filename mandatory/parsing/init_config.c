/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:46:04 by hiamedja          #+#    #+#             */
/*   Updated: 2023/11/29 23:06:37 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_config(t_cube *cube)
{
	cube->config.ea = NULL;
	cube->config.we = NULL;
	cube->config.no = NULL;
	cube->config.so = NULL;
}
