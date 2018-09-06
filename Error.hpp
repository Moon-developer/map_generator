/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 14:26:47 by mafernan          #+#    #+#             */
/*   Updated: 2018/09/06 14:44:22 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HPP
# define ERROR_HPP

# include <exception>
# include <iostream>

class Error {
	public:
		Error( void );
		~Error( void );
		class InvalidSize : public std::exception {
			public:
				std::string		e_msg;
				InvalidSize(const std::string & line);
				virtual const char * what() const throw();
		};
		class InvalidDifficulty : public std::exception {
			public:
				std::string		e_msg;
				InvalidDifficulty(const std::string & line);
				virtual const char * what() const throw();
		};
};

#endif
