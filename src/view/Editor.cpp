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

/**
 *
 * @param title
 */
Editor::Editor(wxString const & title) :
    wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(500, 300))
{
  this->SetMinSize(wxSize(500, 300)); //la taille minimum

  //----------------------------------------------------------

  wxBoxSizer* hbox = new wxBoxSizer(wxVERTICAL); //le sizer generale
  wxBoxSizer* hbox2 = new wxBoxSizer(wxHORIZONTAL); //le sizer "du bas", contient la zone de retour et les boutons
  wxBoxSizer* hbox3 = new wxBoxSizer(wxVERTICAL); //le sizer des boutons
  wxBoxSizer* hbox4 = new wxBoxSizer(wxHORIZONTAL); //le sizer "du haut", contient les methodes et le zone d'edition

  wxPanel *haut = new wxPanel(this); //le panel "du haut", contient les methodes et le zone d'edition
  wxPanel *bas = new wxPanel(this); //le panel "du bas", contient la zone de retour et les boutons
  wxPanel *bouttons = new wxPanel(bas); //le panel des boutons

  m_methode = new Methodes(haut);
  m_edit = new wxTextCtrl(haut, -1, wxEmptyString, wxPoint(-1, -1), wxSize(-1, -1),
  wxTE_MULTILINE,
                          wxDefaultValidator, wxTextCtrlNameStr);
  m_res = new wxTextCtrl(bas, -1, wxEmptyString, wxPoint(-1, -1), wxSize(-1, -1),
  wxTE_MULTILINE,
                         wxDefaultValidator, wxTextCtrlNameStr);

  SetIcon(wxIcon("src/pictures/icon.png")); //on met le logo sympa

  //les boutons
  hbox3->Add(new wxButton(bouttons, wxID_ADD, wxT("executer"), wxPoint(-1, -1)), 0, wxEXPAND);
  hbox3->Add(new wxButton(bouttons, wxID_ABORT, wxT("arreter"), wxPoint(-1, -1)), 0, wxEXPAND);
  hbox3->Add(new wxButton(bouttons, wxID_EXIT, wxT("fermer"), wxPoint(-1, -1)), 0, wxEXPAND);

  Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Editor::OnQuit));
  Connect(wxID_ABORT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Editor::OnAbort));
  Connect(wxID_ADD, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Editor::OnAdd));

  //la zone du bas
  hbox2->Add(m_res, 3, wxEXPAND);
  hbox2->Add(bouttons, 1, wxEXPAND);

  //la zone du haut
  hbox4->Add(m_methode, 1, wxEXPAND);
  hbox4->Add(m_edit, 3, wxEXPAND);

  //la zone generale
  hbox->Add(haut, 5, wxEXPAND);
  hbox->Add(bas, 1, wxEXPAND);

  bouttons->SetSizer(hbox3);
  haut->SetSizer(hbox4);
  bas->SetSizer(hbox2);
  this->SetSizer(hbox);

  Centre();

}

/**
 *
 * @param
 */
void Editor::OnAbort(wxCommandEvent & WXUNUSED(event))
{
  //TODO
  printf("%s", "j'arrete\n");

}

/**
 *
 * @param
 */
void Editor::OnAdd(wxCommandEvent & WXUNUSED(event))
{
  //TODO
  printf("%s", "j'execute\n");
}

/**
 *
 * @param
 */
void Editor::OnQuit(wxCommandEvent & WXUNUSED(event))
{
  Close(true);
}

/**
 *
 * @return
 */
wxTextCtrl* Editor::getRes() const
{
  return m_res;
}

/**
 *
 * @return
 */
wxTextCtrl* Editor::getEdit() const
{
  return m_edit;
}

/**
 *
 * @return
 */
Methodes* Editor::getMethodes() const
{
  return m_methode;
}

/**
 *
 * @param methode
 */
void Editor::writeMet(std::string methode)
{
  wxTextCtrl* text = getEdit(); //on recupere la zone d'edition
  *text << methode << "\n"; //on ajoute la methode à l'editeur
}

/**
 *
 * @param retur
 */
void Editor::writeRes(std::string retur)
{
  wxTextCtrl* text = getRes(); //on recupere la zone de retour
  *text << retur << "\n"; //on ajoute le retour à l'editeur
}
void Editor::ajouterMethode(std::map<std::string, std::vector<std::string> > liste)
{
  supprimerMethodes();
  wxTreeItemId categor = m_methode->GetRootItem();
  for (auto categorie : liste)
  {
    wxTreeItemId catego = m_methode->AppendItem(categor, categorie.first, -1, -1, nullptr);
    for (std::string methode : categorie.second)
    {
      wxTreeItemId truc = m_methode->AppendItem(catego, methode, -1, -1,
                                                new MyTreeItemData(methode));
      Connect(wxID_ANY, wxID_ANY, wxEVT_TREE_ITEM_ACTIVATED,
              wxTreeEventHandler(Methodes::OnTreeClick));
    }
  }
  m_methode->Expand(categor);
}
void Editor::supprimerMethodes()
{
  m_methode->CollapseAndReset(m_methode->GetRootItem());
}
