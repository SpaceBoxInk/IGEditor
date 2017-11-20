#include "zones.hpp"

#include <wx/defs.h>
#include <wx/event.h>
#include <wx/gdicmn.h>
#include <wx/gtk/textctrl.h>
#include <wx/string.h>
#include <wx/stringimpl.h>
#include <wx/textctrl.h>
#include <wx/treebase.h>
#include <wx/validate.h>
#include <wx/window.h>
#include <utility>

#include "Editor.hpp"

/**
 *constructeur de la zone d'edition
 * @param parent
 */
#include <iostream>

Edit::Edit(wxFrame *parent) :
    wxPanel(parent, -1)
{
  text = new wxTextCtrl(parent, -1, wxEmptyString, wxPoint(parent->GetSize().x / 2, -1),
                        wxSize(-1, -1), wxTE_MULTILINE, wxDefaultValidator, wxTextCtrlNameStr);
}
Edit::Edit(wxPanel *parent) :
    wxPanel(parent, -1)
{
  text = new wxTextCtrl(parent, -1, wxEmptyString, wxPoint(parent->GetSize().x / 2, -1),
                        wxSize(-1, -1),
  wxTE_MULTILINE,
                        wxDefaultValidator, wxTextCtrlNameStr);
}

wxTextCtrl* Edit::getText()
{
  return text;
}

//-----------------------------------------------------------------------------------------
//----------------------------------zone methode-------------------------------------------
//-----------------------------------------------------------------------------------------

/**
 *constructeur de la zone des methodes
 * @param parent
 */
Methodes::Methodes(wxPanel *parent,
                   std::map<std::string, std::vector<std::string> > methodesListe) :
    wxTreeCtrl(parent, -1, wxPoint(-1, -1), wxSize(-1, -1),
    wxTR_HAS_BUTTONS),
    methodesListe(methodesListe)
{

  wxTreeItemId categor = this->AddRoot("Fonctions", -1, -1, nullptr);
  for (auto categorie : methodesListe)
  {
    wxTreeItemId catego = this->AppendItem(categor, categorie.first, -1, -1, nullptr);
    for (std::string methode : categorie.second)
    {
      wxTreeItemId truc = this->AppendItem(catego, methode, -1, -1,
                                           new MyTreeItemData(methode));
      Connect(wxID_ANY, wxID_ANY, wxEVT_TREE_ITEM_ACTIVATED,
              wxTreeEventHandler(Methodes::OnTreeClick));
//      Bind(wxEVT_TREE_ITEM_ACTIVATED, [methode, this](wxTreeEvent & event)
//      {
//        Editor *comm = (Editor *)this->GetParent();
//        wxTextCtrl *text = comm->getEdit()->getText();
//        *text << methode << "\n";
//      },
//           lastC.GetID(), wxID_ANY);
//      Connect(ID_PLUS, wxEVT_COMMAND_BUTTON_CLICKED,
//            wxCommandEventHandler(LeftPanel::OnPlus));
//        Connect(ID_MINUS, wxEVT_COMMAND_BUTTON_CLICKED,
//            wxCommandEventHandler(LeftPanel::OnMinus));
    }
  }
  this->Expand(categor);
}

/**
 *gere l'evenement : clique sur le bouton methode 1
 *met meh a la fin de la zone d'edition
 * @param
 */
void Methodes::OnTreeClick(wxTreeEvent & event)
{


  wxTreeItemId itemId = event.GetItem();
  if (GetItemData(itemId))
  {
    MyTreeItemData *item = dynamic_cast<MyTreeItemData *>(GetItemData(itemId)); //on recupere l'item(avec une description)
    Editor *comm = (Editor *)this->GetParent()->GetParent(); //on recupere l'editeur
    std::string meth = item->GetDesc().ToStdString();
    comm->writeMet(meth);
  }
  else
  {
    if (IsExpanded(itemId))
    {
      Collapse(itemId);
      std::cout << "wallah" << std::endl;
    }
    else
    {
      this->Expand(itemId);
    }
  }
}

//void Methodes::OnMethode1(wxCommandEvent & WXUNUSED(event))
//{
//  Editor *comm = (Editor *)this->GetParent();
//  wxTextCtrl *texte = comm->m_edit->text;
//  *texte << "meh" << "\n";
//}
///**
// *gere l'evenement : clique sur le bouton methode 2
// *met wallah a la fin de la zone d'edition
// * @param
// */
//void Methodes::OnMethode2(wxCommandEvent & WXUNUSED(event))
//{
//  Editor *comm = (Editor *)this->GetParent();
//  wxTextCtrl *texte = comm->m_edit->text;
//  *texte << "wallah" << "\n";
//}
