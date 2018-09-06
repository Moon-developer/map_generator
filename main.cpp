/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 11:11:01 by mafernan          #+#    #+#             */
/*   Updated: 2018/09/05 15:26:12 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Levels.hpp"
#include <iostream>

int		main(int ac, char **av)
{
	Levels	lvl;
	(void)ac;
	std::vector<std::vector<char> >  res;
	std::vector<std::vector<char> >  load;

	// turn difficulty
	lvl.difficulty(std::atoi(av[2]));
	// turn debug on
	//lvl.debug();
	// generate level
	res = lvl.makeMap(std::atoi(av[1]));
	std::cout << "size og : " << res[0].size() << std::endl;
	for (size_t i = 0; i < res.size(); i++)
	{
		for (size_t n = 0; n < res[i].size(); n++)
			std::cout << res[i][n] << "-";
		std::cout << std::endl;
	}
	std::cout << "============= saving ============ " << std::endl;
	lvl.save(res);
	std::cout << "============= saved ============ " << std::endl;
	std::cout << "============= load ============ " << std::endl;
	load = lvl.load();
	std::cout << "size load : " << load[0].size() << std::endl;
	for (size_t i = 0; i < load.size(); i++)
	{
		for (size_t n = 0; n < load[i].size(); n++)
			std::cout << load[i][n] << "-";
		std::cout << std::endl;
	}
	std::cout << " =========== done ==============" << std::endl;
	return (0);
}
