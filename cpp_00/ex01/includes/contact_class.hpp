/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact_class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:34:57 by emedina-          #+#    #+#             */
/*   Updated: 2024/09/19 11:24:55 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <iostream>
# include <stdlib.h>
# include <iomanip>
# include <string>
# include <ctype.h>
class Contact
{
	private:
		std::string first_name;
		std::string lastname;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	public:
		Contact();
		~Contact();
		
		Contact(std::string first_name, std::string lastname, std::string nickname, std::string phone_number, std::string darkest_secret);
		
		Contact 	add(Contact contact);
		int         null(Contact contact);
		void        print_contacts(Contact contact);
		void        print_info(Contact contact, int i);
};
#endif