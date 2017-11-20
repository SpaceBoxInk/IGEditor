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
    wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(-1, -1))
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

  wxBoxSizer* hbox = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* hbox2 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* hbox3 = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* hbox4 = new wxBoxSizer(wxHORIZONTAL);
  wxGridSizer *sizerg = new wxGridSizer(2, 1, 0, 0);
  wxGridSizer *sizerhaut = new wxGridSizer(1, 2, 0, 0);
  wxGridSizer *sizerbas = new wxGridSizer(1, 2, 0, 0);
  wxGridSizer *sizerbouton = new wxGridSizer(3, 1, 0, 0);

  wxPanel *haut = new wxPanel(this);
  wxPanel *bas = new wxPanel(this);
  wxPanel *bouttons = new wxPanel(bas);
  m_methode = new Methodes(haut, liste);
//  m_edit = new Edit(haut);

  m_edit = new wxTextCtrl(haut, -1, wxEmptyString, wxPoint(-1, -1), wxSize(-1, -1),
                          wxTE_MULTILINE, wxDefaultValidator, wxTextCtrlNameStr);
  m_res = new wxTextCtrl(bas, -1, wxEmptyString, wxPoint(-1, -1), wxSize(-1, -1),
  wxTE_MULTILINE,
                         wxDefaultValidator, wxTextCtrlNameStr);

//  wxButton *buttonexe = new wxButton(bouttons, wxID_EXIT, wxT("executer"), wxPoint(0, 0));
//  wxButton *buttonarr = new wxButton(bouttons, wxID_EXIT, wxT("arreter"), wxPoint(0, 40));
//  wxButton *buttonc = new wxButton(bouttons, wxID_EXIT, wxT("fermer"), wxPoint(0, 80));
  //buttonexe->SetFocus();
  SetIcon(wxIcon("src/pictures/icon.png")); //on met le logo sympa, PATH sepuis racine projet

  //les boutons
  hbox3->Add(new wxButton(bouttons, wxID_ADD, wxT("executer"), wxPoint(-1, -1)), 0,
                   wxEXPAND);
  hbox3->Add(new wxButton(bouttons, wxID_ANY, wxT("arreter"), wxPoint(-1, -1)), 0,
                   wxEXPAND);
  hbox3->Add(new wxButton(bouttons, wxID_EXIT, wxT("fermer"), wxPoint(-1, -1)), 0,
                   wxEXPAND);

  Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Editor::OnQuit));

  //la zone du bas
  hbox2->Add(m_res, 3, wxEXPAND);
  hbox2->Add(bouttons, 1, wxEXPAND);

//  sizerbas->AddGrowableCol(0, 1);
//  sizerbas->AddGrowableRow(0, 1);

  //la zone du haut
  hbox4->Add(m_methode, 1, wxEXPAND);
  hbox4->Add(m_edit, 3, wxEXPAND);

  //la zone generale
  hbox->Add(haut, 3, wxEXPAND);
  hbox->Add(bas, 1, wxEXPAND);


//  sizerg->AddGrowableRow(1, 0);
//  sizerg->AddGrowableCol(1, 0);


//  hbox4->Add(sizerhaut, 1, wxEXPAND);
//  hbox3->Add(sizerbouton, 1, wxEXPAND);
//  hbox2->Add(sizerbas, 1, wxEXPAND);
//  hbox->Add(sizerg, 1, wxEXPAND);

  bouttons->SetSizer(hbox3);
  haut->SetSizer(hbox4);
  bas->SetSizer(hbox2);
  this->SetSizer(hbox);

  Centre();

}

void Editor::OnQuit(wxCommandEvent & WXUNUSED(event))
{
  Close(true);
}

wxTextCtrl* Editor::getRes()
{
  return m_res;
}
wxTextCtrl* Editor::getEdit()
{
  return m_edit;
}

Methodes* Editor::getMethodes()
{
  return m_methode;
}
void Editor::writeMet(std::string methode)
{
  wxTextCtrl* text = getEdit(); //on recupere l'editeur
  *text << methode << "\n"; //on ajoute la methode à l'editeur
}
void Editor::writeRes(std::string methode)
{
  wxTextCtrl* text = getRes(); //on recupere l'editeur
  *text << methode << "\n"; //on ajoute la methode à l'editeur
}

