/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook_class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:35:43 by emedina-          #+#    #+#             */
/*   Updated: 2024/09/19 16:38:05 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "contact_class.hpp"

class Phonebook 
{
	private:
		Contact contacts[8];
	public:
		Phonebook();
		~Phonebook();
		int 		check_first_name(std::string first_name);	
		int			check_last_name(std::string last_name);
		int 		check_nickname(std::string nickname);
		int         check_phonebook(Phonebook phonebook);
		int			check_darkest_secret(std::string darkest_secret);
		int			check_phonenumber(std::string phonenumber);
		Phonebook   del_one(Phonebook phonebook);
		void        display(Phonebook phonebook);
		Phonebook   add_iterator(Phonebook phonebook, int i);
};
#endif