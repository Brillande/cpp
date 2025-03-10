/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:54:40 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 18:10:19 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

using namespace std;

int main() {
  {
    Animal *zoo[10];

    for (int i = 0; i < 5; i++) {
      zoo[i] = new Cat();
    }

    for (int i = 5; i < 10; i++) {
      zoo[i] = new Dog();
    }

    for (int i = 0; i < 10; i++) {
      delete zoo[i];
    }
  }
  {
    Cat *a = new Cat();
    for (int i = 0; i < 10; i++) {
      string idea = "idea_" + string(1, '0' + i);
      a->setBrainIdear(idea, i);
      cout << i << " " << a->getBrainIdear(i) << endl;
    }
    cout << endl;
    Cat b;
    b = *a;
    for (int i = 0; i < 10; i++)
      cout << i << " " << b.getBrainIdear(i) << endl;
    delete a;
  }
}
