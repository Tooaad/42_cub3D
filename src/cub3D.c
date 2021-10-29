/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:46:35 by gpernas-          #+#    #+#             */
/*   Updated: 2021/10/29 16:35:21 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3D.h" 

void init_params(t_params *params)
{
	int i;

	i = 3;
	params->player.posX = -1;
	params->player.posY = -1;
	params->map.height = 0;
	params->map.width = 0;
	params->map.direction = '\0';
	params->n_path = NULL;
	params->w_path = NULL;
	params->s_path = NULL;
	params->n_path = NULL;
	while (i-- > 0)
	{
		params->floor[i] = -1;
		params->ceiling[i] = -1;
	}
}


void cleaks()
{
	system("leaks cub3D");
}

void	exit_error(char *str)
{
	printf("Error\n%s", str);
	exit(1);
}

int main(int argc, char **argv)
{
	//char        *relative_path = "../img/img.xpm";
	t_params    params;

// atexit(cleaks);
	if (argc != 2 || ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])) == NULL)
		exit_error("Lo archivo no valido");
	if (ft_strlen(ft_strnstr(argv[1], ".cub", ft_strlen(argv[1]))) > 4)
		exit_error("Lo archivo no valido");
	init_params(&params);
	parse_data(argv[1], &params);
	build_mlx(&params);

	return (0);

}
