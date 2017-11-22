#include "mainIHMtest.hpp"

#include <wx/app.h>
#include <wx/chartype.h>

#include "Editor.hpp"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
  Editor *editor = new Editor(wxT("editor"));
  editor->Show(true);
  // FIXME : exemple
//  std::map<std::string, std::vector<std::string> > liste;
//  std::vector<std::string> meth1;
//  std::vector<std::string> meth2;
//  std::vector<std::string> meth3;
//  meth1.push_back("for");
//  meth1.push_back("while");
//  meth1.push_back("dowhile");
//  meth2.push_back("toto");
//  meth2.push_back("titi");
//  liste.insert(std::make_pair("boucles", meth1));
//  liste.insert(std::make_pair("autre_methodes", meth2));
//  editor->ajouterMethode(liste);

  return true;
}

