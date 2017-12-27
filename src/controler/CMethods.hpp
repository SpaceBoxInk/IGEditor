/**
 * CMethods.hpp
 *
 * Early optimization is the root of all evil
 *
 *  Created on: 5 nov. 2017
 *      Author: nihil
 */

#pragma once

#include "../model/MLuaInterpreter.hpp"
#include "../model/MMethodsLoader.hpp"
#include "../model/MSave.hpp"
#include "../tools/observerPattern/Observer.hpp"

#include <wx/textctrl.h>
#include <string>
#include <set>

class Editor;

enum class Event
{
  METHOD_INPUT,
  SAVE_AND_CLOSE_EDITOR,
  EXECUTE_EDITOR,
  SYNTAX,
};

class CMethods : public Observer
{
//========================>Attributes<========================
private:
  static wxColour keywordColor;

  MMethodsLoader methodsLoader;
  std::set<std::string> listeKey;
  MSave save;
  MLuaInterpreter luaInterpreter;
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

  void writeColoredMet(std::string const& method);
  void writeColoredMot(std::string const& mot);
  wxTextCoord formatMethod(std::string& method, std::vector<wxTextCoord> & wordRepCoord);
//=====================>Getters&Setters<======================
public:

private:

};
