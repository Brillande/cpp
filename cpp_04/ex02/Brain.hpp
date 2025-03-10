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
