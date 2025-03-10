/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:52:49 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 13:13:01 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Brain {
public:
  Brain();
  Brain(const Brain &src);
  ~Brain();

  Brain &operator=(Brain const &src);

  std::string ideas[100];
};
