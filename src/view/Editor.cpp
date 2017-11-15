/*
 * editor.cpp
 *
 *  Created on: 3 nov. 2017
 *      Author: lordofkawaiii
 */

#include <string>
#include <vector>
#include <map>
#include <wx/button.h>
#include <wx/wx.h>
#include "Editor.hpp"

Editor::Editor(wxString const & title) :
    wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(290, 150))
{

  std::map<std::string, std::vector<std::string> > liste;
  std::vector<std::string> meth1;
  std::vector<std::string> meth2;
  std::vector<std::string> meth3;
  meth1.push_back("for");
  meth1.push_back("while");
  meth1.push_back("dowhile");
  meth2.push_back("meh");
  meth2.push_back("wallah");
  liste.insert(std::make_pair("boucles", meth1));
  liste.insert(std::make_pair("wallah", meth2));


  m_methode = new Methodes(this, liste);
  m_edit = new Edit(this);

  wxButton *button = new wxButton(this, wxID_EXIT, wxT("fermer"), wxPoint(200, 120));
  Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Editor::OnQuit));
  button->SetFocus();
  SetIcon(wxIcon("src/pictures/icon.png")); //on met le logo sympa, PATH sepuis racine projet
  Centre();
}

void Editor::OnQuit(wxCommandEvent & WXUNUSED(event))
{
  Close(true);
}

Edit* Editor::getEdit()
{
  return m_edit;
}

Methodes* Editor::getMethodes()
{
  return m_methode;
}
