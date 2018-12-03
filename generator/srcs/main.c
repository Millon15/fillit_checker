/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:50:00 by glarivie          #+#    #+#             */
/*   Updated: 2015/12/04 11:02:53 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	ft_error(void)
{
		printf("[ERROR] Usage : ./tetri-gen {-v | -i} + {-f | -s} + nb\n");
		printf("Args :\n\t-v : Valid grid\n\t-i : Invalid grid (with errors)\n");
		printf("\n\t-f : Write grid in a file ./sample.fillit\n");
		printf("\t-s : Send the grid directly by the standard input (handle = 0)\n");
		printf("NB : Numbers of tetriminos per file, between 0 and 26 (may vary if invalid grid arg)\n");
}

int		main(int argc, char **argv)
{
	srand(time(NULL));

	if (argc != 4)
		ft_error();
	else
	{
		int		fd;
		int		index;
		char	tetri[12][21] = {
			"....\n.##.\n.#..\n.#..\n",
			"##..\n.#..\n.#..\n....\n",
			"....\n.##.\n.##.\n....\n",
			".#..\n.#..\n.#..\n.#..\n",
			"....\n.##.\n..##\n....\n",
			".##.\n##..\n....\n....\n",
			"..#.\n.###\n....\n....\n",
			"....\n....\n##.#\n..#.\n",
			"#.#.\n.#.#\n....\n..#.\n",
			"....\n.#.#\n#.#.\n....\n",
			"#...\n####\n....\n....\n",
			"....\n....\n....\n....\n",
		};
		if (ft_atoi(argv[3]) < 27 && ft_atoi(argv[3]) > 0)
		{
			index = ft_atoi(argv[3]);
			if (argv[2][0] == '-' && argv[2][1] == 's')
				fd = 0;
			if (argv[2][0] == '-' && argv[2][1] == 'f')
				fd = open("sample.fillit", O_CREAT | O_RDWR, 0666);
			while (--index >= 0)
			{
				if (argv[1][0] == '-' && argv[1][1] == 'v')
				{
					write(fd, ft_blk_rot(tetri[ft_rand(0, 6)], ft_rand(0, 3)), 20);
					if (index > 0)
						write(fd, "\n", 1);
				}
				if (argv[1][0] == '-' && argv[1][1] == 'i')
				{
					write(fd, ft_blk_rot(tetri[ft_rand(7, 11)], ft_rand(0, 3)), 20);
					if (ft_rand(0, 1) == 1)
						write(fd, "\n", 1);
				}
			}
			close(fd);
		}
		else
			ft_error();
	}
	return (0);

}
