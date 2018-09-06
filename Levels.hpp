/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Levels.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 11/30/15 by mafernan          #+#    #+#             */
/*   Updated: 2018/09/05 13:23:50 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		LEVELS_HPP
# define	LEVELS_HPP

# include <iostream>
# include <fstream>
# include <vector>
//# include <boost/archive/text_oarchive.hpp>
//# include <boost/archive/text_iarchive.hpp>
# include "Map.hpp"

// block numbers
// 0 : grass
// 1 : iron
// 2 : bricks
// 3 : player 
// 4 : enemy 1
// 5 : enemy 2
// 6 : power brick
// 7 : health brick

class Levels {
	public:
		Levels();
		Levels(Levels const & src);
		~Levels();
		Levels & operator=(Levels const & src);

		std::vector<std::vector<char> >		makeMap( int seed );
		std::vector<std::vector<char> >		load( void );
		void								save(std::vector<std::vector<char> > map);

		std::string		getDir( void );
		void			dimension(int width, int height);
		void			difficulty( int lvl );
		void			changeDir( std::string dir);
		void			debug( void );
		char			populate( void );
		int				getHeight( void );
		int				getWidth( void );

	private:
		int				_debug = 0;
		int				_width = 33;
		int				_height = 15;
		int				_enemyTotal = 5;
		int				_bricks = 0;
		int				_health = 0;
		int				_power = 0;
		int				_lvl = 1;
		std::string		_dir = ".";
};

#endif
