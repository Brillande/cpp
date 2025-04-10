/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2025/04/10 13:58:52 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/10 13:58:53 by emedina-         ###   ########.fr       */
=======
/*   Created: 2025/03/26 18:09:10 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/26 18:09:11 by emedina-         ###   ########.fr       */
>>>>>>> 205bf8f307193d68bde3af2bbce6653b49249667
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
