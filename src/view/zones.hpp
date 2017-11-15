#ifndef SRC_VIEW_ZONE_HPP_
#define SRC_VIEW_ZONE_HPP_
#include <wx/wx.h>
#include <string>
#include <vector>
#include <map>
#include <wx/treectrl.h>
/**
 * la zone d'edition
 */
class Edit : public wxPanel
{
public:
  Edit(wxFrame *parent);

  //----------------------------------
  //les elements
  //----------------------------------
  void OnSetText(wxCommandEvent & event);
  wxTextCtrl *getText();

  wxTextCtrl *text;

};
/**
 * zone qui contient les methodes
 */
class Methodes : public wxTreeCtrl
{
public:

  Methodes(wxFrame *parent, std::map<std::string, std::vector<std::string> > methodesListe);


  //----------------------------------
  //les events
  //----------------------------------
//  void OnMethode1(wxCommandEvent & event);
//  void OnMethode2(wxCommandEvent & event);
  void OnTreeClick(wxTreeEvent & event);

  //----------------------------------
  //les elements
  //----------------------------------
  std::map<std::string, std::vector<std::string> > methodesListe;
};

class MyTreeItemData : public wxTreeItemData
{
public:
  MyTreeItemData(wxString const & desc) :
      m_desc(desc)
  {
  }

  void ShowInfo(wxTreeCtrl *tree);
  wxString const& GetDesc() const
  {
    return m_desc;
  }

private:
  wxString m_desc;
};
#endif
