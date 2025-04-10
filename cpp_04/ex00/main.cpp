/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:19:10 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/10 13:56:01 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	{
		const Animal *animal = new Animal();
		const Animal *dog = new Dog();
		const Animal *cat = new Cat();
		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		cat->makeSound(); 
		dog->makeSound();
		animal->makeSound();
		delete animal;
		delete cat;
		delete dog;
	}

	{
		const WrongAnimal *animal = new WrongAnimal();
		const WrongAnimal *cat = new WrongCat();
		std::cout << cat->getType() << " " << std::endl;
		cat->makeSound();
		animal->makeSound();
		delete animal;
		delete cat;
	}
}
