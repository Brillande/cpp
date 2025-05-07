/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:58:12 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/30 16:02:24 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
	Base *ellande = generate();
	std::cout << "pointer identifer : ";
	identify(ellande);
	std::cout << "ref identifer : ";
	identify(*ellande);
	delete ellande;
}
