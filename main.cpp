/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 11:11:01 by mafernan          #+#    #+#             */
/*   Updated: 2018/09/06 14:41:19 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Levels.hpp"
#include <iostream>

int		main(int ac, char **av)
{
	Levels	lvl; // create Levels object
	std::vector<std::vector<char> >  res; // map will save to this
	std::vector<std::vector<char> >  load; // map will load to this
	if (ac >= 3)
	{
		try
		{
			// set difficulty to second arguments
			lvl.difficulty(std::atoi(av[2]));
			// save results of makeMap to res
			lvl.dimension(10, 10);
			res = lvl.makeMap(std::atoi(av[1]));
			std::cout << "height : " << res.size() << std::endl;
			std::cout << "width  : " << res[0].size() << std::endl;
			// print out the map
			std::cout << "===================== New map =====================" << std::endl;
			for (size_t i = 0; i < res.size(); i++)
			{
				for (size_t n = 0; n < res[i].size(); n++)
					std::cout << res[i][n] << " ";
				std::cout << std::endl;
			}
			// save the map to a file
			lvl.save(res);
			// load map from file and save results to load
			load = lvl.load();
			// print out loaded map
			std::cout << "===================== Loaded map ===================" << std::endl;
			for (size_t i = 0; i < load.size(); i++)
			{
				for (size_t n = 0; n < load[i].size(); n++)
					std::cout << load[i][n] << " ";
				std::cout << std::endl;
			}
			std::cout << "===================== Done =========================" << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	else
		std::cout << "not enough arguments. i.e: ./create <seed> <level>" << std::endl;
	return (0);
}
