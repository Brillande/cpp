/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:19:10 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 19:07:08 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

using namespace std;

int main() {
	{
		const Animal *animal = new Animal();
		const Animal *dog = new Dog();
		const Animal *cat = new Cat();
		cout << dog->getType() << " " << endl;
		cout << cat->getType() << " " << endl;
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
		cout << cat->getType() << " " << endl;
		cat->makeSound();
		animal->makeSound();
		delete animal;
		delete cat;
	}
}
