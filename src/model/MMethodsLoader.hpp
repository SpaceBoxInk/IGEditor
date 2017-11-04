/**
 * MMethodsLoader.hpp
 *
 * Early optimization is the root of all evil
 *
 *  Created on: 31 oct. 2017
 *      Author: nihil
 */

#ifndef SRC_MODEL_MMETHODSLOADER_HPP_
#define SRC_MODEL_MMETHODSLOADER_HPP_

#include <iostream>
#include <string>
#include <fstream>

class MMethodsLoader
{
//========================>Attributes<========================
private:
  std::string methodsFileName;
  std::fstream methodsFile;
//=======================>Constructors<=======================
public:
  MMethodsLoader();
  // TODO: rule of five ? copyandswap
  virtual ~MMethodsLoader();

private:

//=========================>Methods<==========================
public:

private:

//=====================>Getters&Setters<======================
public:

private:

};

#endif /* SRC_MODEL_MMETHODSLOADER_HPP_ */
