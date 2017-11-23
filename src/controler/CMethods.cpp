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
    methodsLoader("allEn"), save("defaultProgram.lua")
{
  addEvents();

  // IHM init
  ihmEditor = new Editor(wxT("Editeur"));
  ihmEditor->getMethodes()->addObserver(this);
  ihmEditor->addObserver(this);
  ihmEditor->Show();
  ihmEditor->ajouterMethode(methodsLoader.getListCatMeth());

  string loaded;
  save.load(loaded);
  ihmEditor->writeMet(loaded);
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
    vector<wxTextCoord> wordRepList;
    formatMethod(method, wordRepList);
    ihmEditor->writeMet(method);
  });

  addAction<Event, string>(Event::SAVE_AND_CLOSE_EDITOR, [&](string content, Observed const&)
  {
    printLog("Save and quit : Bye", LogType::INFO);
    save.save(content);
  });

  addAction<Event, string>(Event::EXECUTE_EDITOR, [&](string content, Observed const&)
  {
    printLog("Save and execute : yeah", LogType::INFO);
    save.save(content);
    luaInterpreter.execute(save.getFilePath());

    ihmEditor->clearRes();
    ihmEditor->writeRes(luaInterpreter.getOutput().str());
    luaInterpreter.clearOutput();
  });

}

/**
 *
 * @param method
 * @return the position of the cursor
 */
wxTextCoord CMethods::formatMethod(std::string& method, vector<wxTextCoord> & wordRepCoord)
{
  printLog("Parsing : " + method);
  regex reNli("\\$\\[nli\\]");
  regex reNl("\\$\\[nl\\]");
  regex reTab("\\$\\[tab\\]");
  regex reCursor("\\$\\[cursor\\]");
  regex reOthers("\\$\\[(\\w|\\d)+\\]");
  method = regex_replace(method, reNli, "\n" + ihmEditor->getIndentation());
  method = regex_replace(method, reNl, "\n");
  method = regex_replace(method, reTab, "\t");
  method = regex_replace(method, reCursor, "");
  method = regex_replace(method, reOthers, "_"); //TODO complete for tab ;)

  printLog("Transformation : " + method);
}
//------------------------------------------------------------
//=====================>Getters&Setters<======================
//------------------------------------------------------------

