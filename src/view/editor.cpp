/*
 * editor.cpp
 *
 *  Created on: 3 nov. 2017
 *      Author: lordofkawaiii
 */

#include "editor.hpp"

editor::editor(wxString const & title) :
    wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(290, 150))
{

  m_methode = new methodes(this);
  m_edit = new edit(this);

  wxButton *button = new wxButton(this, wxID_EXIT, wxT("fermer"), wxPoint(200, 120));
  Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(editor::OnQuit));
  button->SetFocus();
  SetIcon(wxIcon("src/pictures/icon.png")); //on met le logo sympa, PATH sepuis racine projet
  Centre();
}

void editor::OnQuit(wxCommandEvent & WXUNUSED(event))
{
  Close(true);
}
