#include "mainIHMtest.hpp"

#include "../controler/CMethods.hpp"
#include "../model/MParameters.hpp"

#include <wx/app.h>
#include <wx/chartype.h>
#include <sstream>
#include <string>

IMPLEMENT_APP(MyApp)


bool MyApp::OnInit()
{
  using namespace std;
  wstring wStr(argv[0]);
  string str(wStr.begin(), wStr.end());
  MParameters::load(str);

  CMethods();
  return true;
}
