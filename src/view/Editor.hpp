/*
 * editor.hpp
 *
 *  Created on: 3 nov. 2017
 *      Author: lordofkawaiii
 */

#include <wx/event.h>
#include <wx/gtk/frame.h>
#include <wx/string.h>
#include "zones.hpp"
class Edit;
class Methodes;


class Editor : public wxFrame
{
public:
  Editor(wxString const & title);

  wxTextCtrl *m_edit;
  wxTextCtrl *m_res;
  Methodes *m_methode;

  void OnQuit(wxCommandEvent & event);
  wxTextCtrl* getEdit();
  wxTextCtrl* getRes();
  Methodes* getMethodes();
  void writeMet(std::string methode);
  void writeRes(std::string methode);
};

