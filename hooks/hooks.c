/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:59:21 by anadege           #+#    #+#             */
/*   Updated: 2022/01/13 21:00:51 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int close_win_hook(t_data *data)
{
    free_everything(data);
    return (0);
}

int key_press_hook(int keycode, t_data *data)
{
    if (keycode == ESC)
        free_everything(data);
    else if (keycode == MOVE_FOWARD || keycode == MOVE_BACKWARD
        || keycode == MOVE_LEFT || keycode == MOVE_RIGHT)
        move(keycode, data);
    else if (keycode == ROTATE_RIGHT || keycode == ROTATE_LEFT)
        rotate(keycode, data);
    return (0);
}

void    set_hooks(t_data *data)
{
    mlx_hook(data->win, KeyPress, KeyPressMask, key_press_hook, data);
    mlx_hook(data->win, DestroyNotify, StructureNotifyMask, close_win_hook, data);
}