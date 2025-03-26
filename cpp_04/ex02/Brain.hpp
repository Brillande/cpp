/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:09:10 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/26 18:09:11 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Brain {
public:
  Brain();
  Brain(const Brain &src);
  ~Brain();

  Brain &operator=(Brain const &src);

  std::string ideas[100];
};
