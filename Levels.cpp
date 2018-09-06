/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Levels.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 11/30/15 by mafernan          #+#    #+#             */
/*   Updated: 2018/09/05 13:26:17 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Levels.hpp"

Levels::Levels() {}

Levels::Levels(Levels const & src)
{
	*this = src;	
}

Levels::~Levels() {}

Levels & Levels::operator=(Levels const & src)
{
	if (this != &src)
		*this = src;
	return (*this);
}

// ========================================================================== //

// randomly place a type
char	Levels::populate( void )
{
	int random = static_cast<int>(rand() % 100);

	if (random >= 80)
	{
		if (rand() % 100 < 5)
		{
			this->_health += 1;
			return ('7');
		}
		else if (rand() % 100 < 7)
		{
			this->_power += 1;
			return ('6');
		}
		this->_bricks += 1;
		return ('2');
	}
	if (random > 20 && random <= 25 && this->_enemyTotal > 0)
	{
		this->_enemyTotal -= 1;
		if (this->_lvl == 1)
			return ('4');
		else if (this->_lvl == 2)
			return (rand() % 10 <= 5 ? '4' : '5' );
		else if (this->_lvl == 3)
			return ('5');
	}
	return ('0');
}

std::vector<std::vector<char> >	 Levels::makeMap( int seed )
{
	char			type = '0';
	int				enemyTotal = this->_enemyTotal;
	std::vector<std::vector<char> >	result;

	if (seed > 0 && seed <= 5)
		srand(seed);
	else
		srand(time(NULL));
	result.resize(this->_height + 1);
	if (this->_debug == 1)
		std::cout << "creating map" << std::endl;
	// open file for writing
	for (int row = 1; row <= this->_height; row++)
	{
		result[row].resize(this->_width);
		for (int col = 1; col <= this->_width; col++)
		{
			if (col == 3 && row == 3)
				type = '3';
			else if ((col == 4 && row == 3) || (col == 3 && row == 4))
				type = '0';
			else if ((col == 5 && row == 3) || (col == 3 && row == 5))
				type = '0';
			else if (col == 1 || col == this->_width || row == 1 || row == this->_height)
				type = '0';
			else if (row % 2 == 0 && col % 2 == 0)
				type = '1';
			else if ((col >= 2 && col <= this->_width -1) && (row == 2 || row == this->_height - 1))
				type = '1';
			else if ((row >= 2 && row <= this->_height - 1) && (col == 2 || col == this->_width - 1))
				type = '1';
			else if (row > 2 && row < this->_height && col > 2 && col < this->_width)
				type = populate();
			else
				type = '0';
			if (this->_debug == 1)
				std::cout << type << " ";
			result[row].push_back(type);
		}
		type = '0';
		if (this->_debug == 1)
			std::cout << " | " << row << std::endl;
	}
	// print out to see amount of blocks spawned
	if (this->_debug == 1)
	{
		std::cout << "Total enemies not spawned : " << this->_enemyTotal << std::endl;
		std::cout << "Total bricks spawned : " << this->_bricks << std::endl;
		std::cout << "Total health spawned : " << this->_health << std::endl;
		std::cout << "Total powers spawned : " << this->_power << std::endl;
	}
	// reset enemy total
	this->_enemyTotal = enemyTotal;
	// close file when done
	result.erase(result.begin());
	return (result);
}

//void			Levels::save(std::vector<std::vector<VisibleGameObject *> > visObj)
void			Levels::save(std::vector<std::vector<char>> map)
{
	const Map		temp(map);
	// open file stream
	std::ofstream ofs("save.data");
	// create output archive object with stream
	boost::archive::text_oarchive oa(ofs);
	// write instance to archive
	oa << temp;
}

std::vector<std::vector<char> >			Levels::load( void )
{
	Map		temp;
	// open a read stream
	std::ifstream ifs("save.data");
	// create the read archive class with the stream
	boost::archive::text_iarchive		ia(ifs);
	// load the read archive to map
	ia >> temp;

	return (temp.getMap());
}



// toggle Debug
void			Levels::debug( void )
{
	if (this->_debug == 0)
		this->_debug = 1;
	else
		this->_debug = 0;
}

// set difficulty
void			Levels::difficulty( int lvl)
{
	if (lvl >= 1 && lvl <= 3)
		this->_lvl = lvl;
	else
		std::cout << "Throw error : Invalid lvl type" << std::endl;
}

// get director
std::string		Levels::getDir( void )
{
	return (this->_dir);
}

// change directory
void	Levels::changeDir( std::string dir)
{
	this->_dir = dir;
}

// get height of map
int		Levels::getHeight( void )
{
	return (this->_height);
}

// get width of map
int		Levels::getWidth( void )
{
	return (this->_width);
}

// set a width and height
void	Levels::dimension(int width, int height)
{
	this->_width = width;
	this->_height = height;
}