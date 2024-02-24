//#include <string>
//#include <fstream>
//#include <iostream>
//
//#include "cPerson.h"
//#include <vector>
//
//#include "cPersonMaker.h"
//
//
//cPerson* makePerson(void);
//
//std::vector<cPerson*> g_vecPeople;
//
//
//int main()
//{
//
//	cPersonMaker personMaker;
//
//
//
//	const unsigned int NUMBER_OF_PEOPLE = 10;
//
//	//::g_vecPeople.reserve(NUMBER_OF_PEOPLE);
//
//	for (unsigned int count = 0; count < NUMBER_OF_PEOPLE; count++)
//	{
//
//		cPerson* pPerson = makePerson();
//
//
//
//	}
//
//	return 0; 
//}
//bool loadNames(std::string fileName)
//{
//
//	std::ifstream nameFile(fileName.c_str());
//
//	if (!nameFile.is_open())
//	{
//		return false;
//	}
//
//	std::string currentName;
//	while (nameFile >> currentName)
//	{
//		g_vectorBoyNames.push_back(currentName);
//		g_vectorGirlNames.push_back(currentName);
//		g_vectorLastNames.push_back(currentName);
//
//		float discardData;
//		nameFile >> discardData;
//		nameFile >> discardData;
//		nameFile >> discardData;
//
//
//	}
//
//	return true;
//}
//
//
//cPerson* makePerson(void)
//{
//	
//
//
//
//	return pPerson;
//}