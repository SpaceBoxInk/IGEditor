#include "mainIHMtest.hpp"
#include "editor.hpp"
#include <wx/app.h>
#include <wx/chartype.h>

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
  editor *editore = new editor(wxT("editor"));
  editore->Show(true);

  return true;
}

