/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:58:12 by emedina-          #+#    #+#             */
/*   Updated: 2025/05/16 15:30:08 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data ellande;

	ellande.raw = 123456789;
	std::cout << "ellande (" << &ellande << ") raw = " << ellande.raw << std::endl;

	unsigned long maialen = Serializer::serialize(&ellande);
	std::cout << "after serialize (0x" << maialen << std::hex << ") before serialize (0x" << maialen << ")" << std::dec << std::endl;

	Data *ugo = Serializer::deserialize(maialen);
	std::cout << "after desserialize ugo (" << ugo << ") raw = " << ugo->raw << std::endl;
}
