#include <wx/wx.h>
#include <string>

class edit : public wxPanel
{
public:
  edit(wxFrame *parent);

  //----------------------------------
  //les elements
  //----------------------------------
  void OnSetText(wxCommandEvent & event);

  wxTextCtrl *text;

};
class methodes : public wxPanel
{
public:
  methodes(wxFrame *parent);


  //----------------------------------
  //les events
  //----------------------------------
  void OnMethode1(wxCommandEvent & event);
  void OnMethode2(wxCommandEvent & event);

  //----------------------------------
  //les elements
  //----------------------------------
  wxButton *methode1;
  wxButton *methode2;
};
