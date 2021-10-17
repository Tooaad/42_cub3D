/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:46:35 by gpernas-          #+#    #+#             */
/*   Updated: 2021/10/16 20:25:17 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3D.h" 

void cleaks()
{
	system("leaks cub3D");
}

void	exit_error(char *str)
{
	printf("Error: %s\n", str);
	exit(1);
}

int main(int argc, char **argv)
{
	//char        *relative_path = "../img/img.xpm";
	t_map       map;
	t_params    params;

// atexit(cleaks);
	if (argc != 2 || ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])) == NULL)
		exit_error("Lo archivo no valido");
	if (ft_strlen(ft_strnstr(argv[1], ".cub", ft_strlen(argv[1]))) > 4)
		exit_error("Lo archivo no valido");
	parse_map(argv[1], &map, &params);
	// params = (t_params *)malloc(sizeof(t_params));
	// map = (t_map *)malloc(sizeof(t_map));
	//parse_map(argv[1], map, params);
	
	return (0);

}
