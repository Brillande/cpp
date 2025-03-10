/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:53:07 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 19:08:08 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

using namespace std;

Brain::Brain() {
	cout << "Brain constructor empty" << endl;
}

Brain::Brain(const Brain &src) {
	cout << "Brain constructor copy" << endl;
	*this = src;
}

Brain::~Brain() {
	cout << "Brain destructor empty" << endl;
}

Brain &Brain::operator=(Brain const &src) {
    if (this == &src)
		return *this;
	for (size_t i = 0; i < 100; ++i) {
		this->ideas[i] = src.ideas[i];
	}
    return *this;
}
