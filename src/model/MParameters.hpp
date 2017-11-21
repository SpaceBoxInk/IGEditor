/**
 * MParameters.hpp
 *
 * Early optimization is the root of all evil
 *
 *  Created on: 5 nov. 2017
 *      Author: nihil
 */

#pragma once

#include <string>
#include <map>
#include <fstream>

/**
 * Enum for languages
 */
enum class Lang
{
  EN, //!< EN
  FR, //!< FR
};

/**
 * List of parameters for editor
 */
class MParameters
{
//========================>Constant<========================
public:
  static std::string rootPath;
  static auto constexpr configFile = "SbiEditor.conf";
  static std::string methodsListFile;

//========================>Methods<========================
private:
  static bool checkConfFile(std::string path);

  static void setRootPath();

public:
  static std::string getMethodsPath();

  static std::string getConfPath();

  static void load(std::string exePath);
};
