/**
 * CMethods.cpp
 *
 * Early optimization is the root of all evil
 *
 *  Created on: 5 nov. 2017
 *      Author: nihil
 */

#include "CMethods.hpp"

#include "../model/MParameters.hpp"
#include "../tools/utils.hpp"
#include "../view/Editor.hpp"
#include "../view/zones.hpp"

#include <wx/chartype.h>
#include <map>
#include <set>
#include <regex>
#include <sstream>
#include <vector>

using namespace std;

//------------------------------------------------------------
//========================>Constants<=========================
//------------------------------------------------------------

wxColour const CMethods::keywordColor = wxColour(0x8b0068);

//------------------------------------------------------------
//=======================>Constructors<=======================
//------------------------------------------------------------

CMethods::CMethods() :
    methodsLoader("all" + MParameters::getLang()), save("defaultProgram.lua")
{
  addEvents();

  listeKey.insert("if");
  listeKey.insert("then");
  listeKey.insert("else");
  listeKey.insert("elseif");
  listeKey.insert("si");
  listeKey.insert("end");
  listeKey.insert("for");
  listeKey.insert("do");
  listeKey.insert("sinon");
  listeKey.insert("finSi");
  listeKey.insert("wallah");

  // IHM init
  ihmEditor = new Editor(wxT("Editeur"));
  ihmEditor->getMethodes()->addObserver(this);
  ihmEditor->addObserver(this);
  ihmEditor->Show();
  ihmEditor->ajouterMethode(methodsLoader.getListCatMeth());

  string loaded;
  save.load(loaded);
  writeColoredMet(loaded);
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
    writeColoredMet(method);
    if (!wordRepList.empty())
    {
      ihmEditor->getEdit()->SetSelection(wordRepList[0], wordRepList[1]);
    }
  });

  addAction<Event>(
      Event::SYNTAX,
      [&](Observed const&)
      {
        std::string mot;

        wxTextCoord* coo = ihmEditor->getMot(mot);
        if (listeKey.find(mot) != listeKey.end())
        {
          printLog(string("coords : ") + to_string(coo[0]) + string(" ") + to_string(coo[1]) + " : colored", LogType::DEBUG);
          ihmEditor->getEdit()->SetStyle(coo[0],coo[1], (wxTextAttr)keywordColor);
        }
        else
        {
          printLog(string("coords : ") + to_string(coo[0]) + string(" ") + to_string(coo[1]) + " : not colored", LogType::DEBUG);
          ihmEditor->getEdit()->SetStyle(coo[0],coo[1], (wxTextAttr)*Editor::getDefaultColor());
        }
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

void CMethods::writeColoredMet(std::string const& method)
{
  string motCur = "";
  for (char c : method)
  {
    if (isalnum(c) || c < 0)
    {
      motCur += c;
    }
    else
    {
      writeColoredMot(motCur);
      ihmEditor->writeMet(string() + c);
      motCur = "";
    }
  }
  writeColoredMot(motCur);
}

void CMethods::writeColoredMot(std::string const& mot)
{
  // FIXME : coloration faite 2 fois :/
  if (listeKey.find(mot) != listeKey.end())
  {
    ihmEditor->writeMet(mot, &keywordColor);
  }
  else
  {
    ihmEditor->writeMet(mot);
  }
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

  regex reOthers("\\$\\[((\\w|\\d)+)\\]");

  method = regex_replace(method, reNli, "\n" + ihmEditor->getIndentation());
  method = regex_replace(method, reNl, "\n");
  method = regex_replace(method, reTab, "\t");
  method = regex_replace(method, reCursor, "");

  smatch mOthers;
  if (regex_search(method, mOthers, reOthers))
  {
    size_t pos = mOthers.prefix().str().size() + ihmEditor->getEdit()->GetInsertionPoint();
    printLog("Pos of first other word : " + to_string(pos), LogType::DEBUG);
    wordRepCoord.push_back(pos);
    // insert the position to end of first Other word (minus 3 for "$[]")
    wordRepCoord.push_back(mOthers[0].str().size() - 3 + pos);
  }

  method = regex_replace(method, reOthers, "$1"); //TODO complete for tab ;)

  printLog("Transformation : " + method);
}
//------------------------------------------------------------
//=====================>Getters&Setters<======================
//------------------------------------------------------------

