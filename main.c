/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:20:45 by vlaroque          #+#    #+#             */
/*   Updated: 2018/12/19 21:26:13 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

typedef struct s_vars t_vars;

struct	s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
};

int		deal_key(int key, void *params)
{
	printf("%d\n", key);
	return (0);
}

int		main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		i;
	t_vars	vars;

	i = 0;
	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, 512, 512, "Hello World");
	vars.x = 100;
	vars.y = 100;
	mlx_key_hook(vars.win_ptr, deal_key, (void *)0);
	mlx_loop(vars.mlx_ptr);
	return(0);
}