/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:23:46 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 12:23:47 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl 
{
	public:
		Harl();
		~Harl();

		void	complain(std::string level);

	private:
		void	debug() const;
		void	info() const;
		void	warning() const;
		void	error() const;
};

#endif