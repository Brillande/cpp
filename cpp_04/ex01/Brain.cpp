/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:51:21 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/10 13:47:10 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor empty" << std::endl;
}

Brain::Brain(const Brain &src) {
	std::cout << "Brain constructor copy" << std::endl;
	*this = src;
}

Brain::~Brain() {
	std::cout << "Brain destructor empty" << std::endl;
}

Brain &Brain::operator=(Brain const &src) {
    if (this == &src)
		return *this;
	for (size_t i = 0; i < 100; ++i) {
		this->ideas[i] = src.ideas[i];
	}
    return *this;
}
