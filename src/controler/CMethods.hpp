/**
 * CMethods.hpp
 *
 * Early optimization is the root of all evil
 *
 *  Created on: 5 nov. 2017
 *      Author: nihil
 */

#pragma once
#include "../model/MMethodsLoader.hpp"

class Editor;

class CMethods
{
//========================>Attributes<========================
private:
  MMethodsLoader methodsLoader;
  Editor* ihmEditor;
//=======================>Constructors<=======================
public:
  CMethods();
  // TODO: rule of five ? copyandswap
  virtual ~CMethods();

private:

//=========================>Methods<==========================
public:

private:

//=====================>Getters&Setters<======================
public:

private:

};
