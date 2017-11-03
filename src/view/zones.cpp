#include <wx/stattext.h>

#include "editor.hpp"

edit::edit(wxFrame *parent) :
    wxPanel(parent, -1, wxPoint(90, -1), wxSize(200, 100), wxBORDER_SUNKEN)
{
  text = new wxTextCtrl(parent, -1, wxEmptyString, wxPoint(90, -1), wxSize(200, 100), 0,
                        wxDefaultValidator, wxTextCtrlNameStr);
}

methodes::methodes(wxFrame *parent) :
    wxPanel(parent, -1, wxPoint(-1, -1), wxSize(90, 100), wxBORDER_SUNKEN)
{
  this->methode1 = new wxButton(this, 100, wxT("METHODE1"), wxPoint(0, 0));
  Connect(methode1->GetId(), wxEVT_COMMAND_BUTTON_CLICKED,
          wxCommandEventHandler(methodes::OnMethode1));
  this->methode2 = new wxButton(this, 101, wxT("METHODE2"), wxPoint(0, 50));
  Connect(methode2->GetId(), wxEVT_COMMAND_BUTTON_CLICKED,
          wxCommandEventHandler(methodes::OnMethode2));
}

void methodes::OnMethode1(wxCommandEvent & WXUNUSED(event))
{
  editor *comm = (editor *)this->GetParent();
  wxTextCtrl *texte = comm->m_edit->text;
  *texte << "meh" << "\n";
}
void methodes::OnMethode2(wxCommandEvent & WXUNUSED(event))
{
  editor *comm = (editor *)this->GetParent();
  wxTextCtrl *texte = comm->m_edit->text;
  *texte << "wallah" << "\n";
}
