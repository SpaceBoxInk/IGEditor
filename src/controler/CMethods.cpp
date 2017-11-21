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
  ihmEditor = new Editor(wxT("Editeur"));
  ihmEditor->ajouterMethode(methodsLoader.getListCatMeth());
  ihmEditor->Show();
}

CMethods::~CMethods()
{
}

//------------------------------------------------------------
//=====================>Getters&Setters<======================
//------------------------------------------------------------

