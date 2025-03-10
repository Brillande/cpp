/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:55:41 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 18:17:22 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal {
public:
  WrongCat();
  WrongCat(const WrongCat &src);
  ~WrongCat();

  WrongCat &operator=(WrongCat const &src);

private:
  void makeSound(void) const;
};
