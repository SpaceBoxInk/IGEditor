/**
 * CMethods.cpp
 *
 * Early optimization is the root of all evil
 *
 *  Created on: 5 nov. 2017
 *      Author: nihil
 */

#include "CMethods.hpp"

#include "../tools/utils.hpp"
#include "../view/Editor.hpp"
#include "../view/zones.hpp"

#include <wx/chartype.h>
#include <map>
#include <regex>
#include <string>

using namespace std;

//------------------------------------------------------------
//========================>Constants<=========================
//------------------------------------------------------------

//------------------------------------------------------------
//=======================>Constructors<=======================
//------------------------------------------------------------

CMethods::CMethods() :
    methodsLoader("all")
{
  addEvents();

  // IHM init
  ihmEditor = new Editor(wxT("Editeur"));
  ihmEditor->getMethodes()->addObserver(this);
  ihmEditor->Show();
  ihmEditor->ajouterMethode(methodsLoader.getListCatMeth());
}

CMethods::~CMethods()
{
}


void CMethods::addEvents()
{
  // Action pour quand l'utilisateur clic sur une methode fournie
  // dans l'arbre
  addAction<Event, string>(Event::METHOD_INPUT, [&](string content, Observed const&) -> void
  {
    string method = methodsLoader.getMethod(content);
    formatMethod(method);
    ihmEditor->writeMet(method);
  });
}

void CMethods::formatMethod(std::string& method)
{
  printLog("Parsing : " + method);
  regex reNl("\\$\\[nl\\]");
  regex reTab("\\$\\[tab\\]");
  method = regex_replace(method, reNl, "\n");
  method = regex_replace(method, reTab, "\t");

  printLog("Transformation : " + method);
}
//------------------------------------------------------------
//=====================>Getters&Setters<======================
//------------------------------------------------------------

