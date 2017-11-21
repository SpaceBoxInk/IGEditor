/**
 * CMethods.cpp
 *
 * Early optimization is the root of all evil
 *
 *  Created on: 5 nov. 2017
 *      Author: nihil
 */

#include "CMethods.hpp"
#include "../view/Editor.hpp"
#include <wx/chartype.h>

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
  addAction<Event, string>(Event::METHOD_INPUT, [this](string const& content, Observed const&)
  {
    ihmEditor->writeMet(methodsLoader.getMethod(content));
  });
}
//------------------------------------------------------------
//=====================>Getters&Setters<======================
//------------------------------------------------------------

