/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact_class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:34:57 by emedina-          #+#    #+#             */
/*   Updated: 2024/09/09 17:34:03 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <iostream>
# include <stdlib.h>
# include <iomanip>
# include <string>
class Contact
{
	private:
		std::string name;
		std::string lastname;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	public:
		Contact();
		~Contact();
		
		Contact(std::string name, std::string lastname, std::string nickname, std::string phone_number, std::string darkest_secret);
		
		Contact add(Contact add_contact);
};
#endif