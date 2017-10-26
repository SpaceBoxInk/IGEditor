/**
 * MethodsLoader.cpp
 *
 * Early optimization is the root of all evil
 *
 *  Created on: 25 oct. 2017
 *      Author: nihil
 */

#include "MethodsLoader.hpp"

//------------------------------------------------------------
//========================>Constants<=========================
//------------------------------------------------------------

//------------------------------------------------------------
//=======================>Constructors<=======================
//------------------------------------------------------------

MethodsLoader::MethodsLoader()
{
}

MethodsLoader::~MethodsLoader()
{
}

//------------------------------------------------------------
//=========================>Methods<==========================
//------------------------------------------------------------

//------------------------------------------------------------
//=====================>Getters&Setters<======================
//------------------------------------------------------------

/*
 * //#include <SFML/Graphics.hpp>
 //#include <SFML/Main.hpp>
 //#include <SFML/Graphics/RenderWindow.hpp>
 //#include <SFML/Window/VideoMode.hpp>

 #include <fstream>
 #include <iostream>
 #include <vector>
 #include <map>
 #include <string>
 #include <utility>

 typedef std::pair<std::string, std::string> elemTest;
 typedef std::pair<std::string, std::vector<std::string>> elemTestVec;

 std::ostream& operator<<(std::ostream& output,
 std::map<std::string, std::string> const& var) {
 using namespace std;
 for (elemTest i : var) {
 output << get<0>(i) << " : " << get<1>(i) << endl;
 }
 return output;
 }

 std::ostream& operator<<(std::ostream& output,
 std::map<std::string, std::vector<std::string>> const& var) {
 using namespace std;
 for (elemTestVec i : var) {
 for (string val : get<1>(i)) {
 output << get<0>(i) << " : " << val << endl;
 }
 }
 return output;
 }

 std::istream& operator>>(std::istream& input,
 std::map<std::string, std::vector<std::string>>& var) {
 using namespace std;
 string key;
 string value;
 while (!input.eof()) {
 // on prend la clé mais aussi les " :"
 input >> key >> value;
 // on prend le reste pour la valeur (on ecrase les " : " aussi)
 getline(input, value);
 value = &value[1];
 if (key.size() > 1 && value.size() > 1) {
 try {
 var.at(key).push_back(value);
 } catch (out_of_range& e) {
 vector<string> vect;
 vect.push_back(value);
 var.insert(elemTestVec(key, vect));
 }
 }
 value = key = "";
 }
 return input;
 }

 int main() {
 using namespace std;
 fstream f;
 std::map<string, string> test;
 std::map<string, vector<string>> test2;
 test.insert(elemTest("Controle", "si (${condition}) alors${n}${n}fin"));
 test.insert(elemTest("Mouvement", "tournerAGauche()"));
 test.insert(elemTest("Operateur", "${Op1} < ${Op2}"));
 test.insert(elemTest("Variable", "${nom} = ${valeur}"));

 f.open("test.txt", ios::in);
 f >> test2;
 f.close();
 cout << test2;
 return 0;
 }

 *
 */
