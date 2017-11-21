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
#include "../tools/observerPattern/Observer.hpp"

class Editor;

enum class Event
{
  METHOD_INPUT,
};

class CMethods : public Observer
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
  void addEvents();

//=====================>Getters&Setters<======================
public:

private:

};
