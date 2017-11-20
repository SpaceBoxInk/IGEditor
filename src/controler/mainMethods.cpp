/**
 * mainMethods.cpp
 *
 * Early optimization is the root of all evil
 *
 *  Created on: 5 nov. 2017
 *      Author: nihil
 */

#include <iostream>
#include <string>
#include <algorithm>

#include "../model/MParameters.hpp"
#include "CMethods.hpp"


int main(int argc, char **argv)
{
  using namespace std;
  MParameters::load(argv[0]);

  CMethods();
  getchar();
}
