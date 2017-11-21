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
#include "../view/zones.hpp"
#include "../tools/observerPattern/Observed.hpp"

#include <wx/chartype.h>
#include <map>
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
  addAction<Event, string>(Event::METHOD_INPUT, [&](string content, Observed const&)->void
  {
    ihmEditor->writeMet(methodsLoader.getMethod(content));
  });
}
//------------------------------------------------------------
//=====================>Getters&Setters<======================
//------------------------------------------------------------

