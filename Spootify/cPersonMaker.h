#pragma once

#include <vector>
#include <fstream>
#include "cPerson.h"









class cPersonMaker
{
public:
	bool LoadNameFiles(void);

	cPerson makePerson(void);
	cPerson* makePersonPointer(void);
 



private:
std::vector<std::string> m_vectorBoyNames;
std::vector<std::string> m_vectorGirlNames;
std::vector<std::string> m_vectorLastNames;

std::vector<cPerson*> g_vecPeople;

bool loadNames(std::string fileName);

};