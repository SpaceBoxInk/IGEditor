/*
 * editor.hpp
 *
 *  Created on: 3 nov. 2017
 *      Author: lordofkawaiii
 */

#include "zones.hpp"
#include <wx/wxprec.h>


class editor : public wxFrame
{
public:
  editor(wxString const & title);

  edit *m_edit;
  methodes *m_methode;

  void OnQuit(wxCommandEvent & event);
};

