/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:55:30 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 13:07:04 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class WrongAnimal {
public:
  WrongAnimal(const std::string &type);
  WrongAnimal(const WrongAnimal &src);
  WrongAnimal(void);
  virtual ~WrongAnimal(void);

  const std::string &getType(void) const;

  void makeSound(void) const;

  WrongAnimal &operator=(WrongAnimal const &src);

protected:
  std::string _type;
};
