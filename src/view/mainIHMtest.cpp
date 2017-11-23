#include "mainIHMtest.hpp"

#include "../controler/CMethods.hpp"
#include "../model/MParameters.hpp"
#include "../tools/utils.hpp"

#include <bits/exception.h>
#include <wx/app.h>
#include <string>

IMPLEMENT_APP(MyApp)


bool MyApp::OnInit()
{
  using namespace std;
  wstring wStr(argv[0]);
  string str(wStr.begin(), wStr.end());
  MParameters::load(str);

  try
  {
    new CMethods();
  }
  catch (exception& e)
  {
    printLog(e.what(), LogType::ERROR);
  }
  return true;
}
