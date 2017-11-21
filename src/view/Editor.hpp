/*
 * editor.hpp
 *
 *  Created on: 3 nov. 2017
 *      Author: lordofkawaiii
 */

#pragma once
#include <wx/wx.h>
#include "zones.hpp"
class Edit;
class Methodes;

/**
 * classe principale de l'editeur qui contient une zone d'edition, de methodes, de retour et 3 boutons
 */
class Editor : public wxFrame
{
private:
  //========================>Attributes<========================
  /**
   *
   */
  wxTextCtrl *m_edit;
  /**
   *
   */
  wxTextCtrl *m_res;
  /**
   *
   */
  Methodes *m_methode;
public:
  //=======================>Constructors<=======================
  Editor(wxString const & title);

  //=========================>Methods<==========================
  void OnQuit(wxCommandEvent & event);
  void OnAbort(wxCommandEvent & WXUNUSED(event));
  void OnAdd(wxCommandEvent & WXUNUSED(event));

  void writeMet(std::string methode, wxColour const* color = wxBLACK);
  void writeRes(std::string methode, wxColour const* color = wxBLACK);

  void ajouterMethode(std::map<std::string, std::vector<std::string> > liste);
  void supprimerMethodes();
  //=====================>Getters&Setters<======================
  wxTextCtrl* getEdit() const;
  wxTextCtrl* getRes() const;
  Methodes* getMethodes() const;
};

