/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:51:11 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 12:51:12 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Animal {
public:
  Animal(const std::string &type);
  Animal(const Animal &src);
  Animal(void);
  virtual ~Animal(void);

  const std::string &getType(void) const;

  virtual void makeSound(void) const;

  Animal &operator=(Animal const &src);

protected:
  std::string _type;
};
