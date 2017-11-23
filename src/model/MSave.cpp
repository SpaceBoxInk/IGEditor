/**
 * @file MSave.cpp
 *
 * Early optimization is the root of all evil
 *
 *  @date 22 nov. 2017
 *  @author FederAndInk
 *  @brief TODO complete
 */

#include "MSave.hpp"
#include "MParameters.hpp"

#include "../tools/utils.hpp"

#include <sstream>
#include <stdexcept>


//------------------------------------------------------------
//========================>Constants<=========================
//------------------------------------------------------------

//------------------------------------------------------------
//=======================>Constructors<=======================
//------------------------------------------------------------

MSave::MSave(std::string const& fileName)
{
  setFileName(fileName);
}

MSave::~MSave()
{
}

//------------------------------------------------------------
//=========================>Methods<==========================
//------------------------------------------------------------
void MSave::save(std::string const& content)
{
  file.open(getFilePath(), std::ios::out);
  file << content;
  if (!file.fail())
  {
    printLog("Program Saved", LogType::OK);
  }
  else
  {
    printLog("Fail to save Program !!", LogType::ERROR);
  }
  file.close();
}

void MSave::load(std::string& content)
{
  file.open(getFilePath(), std::ios::in);

  file.seekg(0, file.end);
  uint length = file.tellg();
  file.seekg(0, file.beg);

  char* buf = new char[length + 1];

  file.read(buf, length);
  file.close();
  buf[length] = 0;

  content = buf;
  if (length == content.size())
  {
    printLog("load successful", LogType::OK);
  }
  else
  {
    printLog("load fail ! not read good number of chars", LogType::ERROR);
  }

  delete[] buf;
  buf = nullptr;

}


//------------------------------------------------------------
//=====================>Getters&Setters<======================
//------------------------------------------------------------
void MSave::setFileName(std::string const& fileName)
{
  if (std::fstream(MParameters::getProgramsPath() + fileName, std::ios::app).good())
  {
    this->fileName = fileName;
    printLog("Program File : " + getFilePath(), LogType::OK);
  }
  else
  {
    throw
  std::invalid_argument(
        "Can not acces to file" + getFilePath());
  }
}

std::string MSave::getFilePath()
{
  return MParameters::getProgramsPath() + fileName;
}
