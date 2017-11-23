/**
 * @file LuaInterpreter.cpp
 *
 * Early optimization is the root of all evil
 *
 *  @date 22 nov. 2017
 *  @author FederAndInk
 *  @brief TODO complete
 */

#include "MLuaInterpreter.hpp"

#include <iostream>

extern "C"
{
#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>
}

//------------------------------------------------------------
//========================>Constants<=========================
//------------------------------------------------------------
std::stringstream MLuaInterpreter::output;

int MLuaInterpreter::avancer(lua_State* l)
{
  output << "Avance d'une case" << '\n';
  return 0;
}

int MLuaInterpreter::tournerDe(lua_State* l)
{
  int direction = lua_tonumber(l, 1);
  output << "Tourne de " << direction << " degre" << '\n';
  return 0;
}

int MLuaInterpreter::print(lua_State* l)
{
  for (int i = 1; i <= lua_gettop(l); ++i)
  {
    output << lua_tostring(l, i);
  }
  output << "\n";
  return 0;
}


//------------------------------------------------------------
//=======================>Constructors<=======================
//------------------------------------------------------------

MLuaInterpreter::MLuaInterpreter()
{
  lua = luaL_newstate();
  luaL_openlibs(lua);
  registerFonctions();
}

MLuaInterpreter::~MLuaInterpreter()
{
  lua_close(lua);
}

//------------------------------------------------------------
//=========================>Methods<==========================
//------------------------------------------------------------
void MLuaInterpreter::execute(std::string const& exePath)
{
  luaL_dofile(lua, exePath.c_str());
}

void MLuaInterpreter::registerFonctions()
{
  lua_register(lua, "avancer", MLuaInterpreter::avancer);
  lua_register(lua, "print", MLuaInterpreter::print);
  lua_register(lua, "tournerDe", MLuaInterpreter::tournerDe);
}

//------------------------------------------------------------
//=====================>Getters&Setters<======================
//------------------------------------------------------------
void MLuaInterpreter::clearOutput()
{
  output.str(std::string());
}

std::stringstream const & MLuaInterpreter::getOutput() const
{
  return output;
}
