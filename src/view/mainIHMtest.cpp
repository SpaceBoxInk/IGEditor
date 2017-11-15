#include "mainIHMtest.hpp"

#include <wx/app.h>
#include <wx/chartype.h>

#include "Editor.hpp"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
  Editor *editore = new Editor(wxT("editor"));
  editore->Show(true);

  return true;
}

