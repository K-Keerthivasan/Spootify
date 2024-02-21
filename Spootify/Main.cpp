#include <string>
#include <fstream>
#include <iostream>

#include "cPerson.h"
#include <vector>

std::vector<std::string> g_vectorBoyNames;
std::vector<std::string> g_vectorGirlNames;
std::vector<std::string> g_vectorLastNames;

bool loadNames(std::string fileName);


cPerson* makePerson(void);

std::vector<cPerson*> g_vecPeople;

int main()
{
	loadNames("dist.male.first.txt");
	loadNames("dist.female.first.txt");
	loadNames("US_LastNames.txt");

	const unsigned int NUMBER_OF_PEOPLE = 10;

	::g_vecPeople.reserve(NUMBER_OF_PEOPLE);

	for(unsigned int count = 0; count < NUMBER_OF_PEOPLE; count++)
	{
	cPerson * pPerson = makePerson();

		::g_vecPeople.push_back(pPerson());

		
		::g_vecPeople.insert(::g_vecPeople.end(), pPerson);

		::g_vecPeople.insert(::g_vecPeople.begin(), pPerson);


	}

 for (std::vector<cPerson*>::iterator itPerson =::g_vecPeople.begin(); 
	 itPerson != ::g_vecPeople.end(); 
	 itPerson++)
	{
	 	  std::cout <<(*itPerson)->firstName << std::endl;
		cPerson* pCurPerson = *itPerson;
	std::cout<<pCurPerson->firstName << " " << pCurPerson->middleName << " " << pCurPerson->lastName << std::endl;

	}

	return 0;
}
 
 bool loadNames(std::string fileName)
{

	 std::ifstream nameFile(fileName.c_str());

	if(!nameFile.is_open())
	{
		return false;
	}
 
	std::string currentName;
	while(nameFile >> currentName)
	{
		g_vectorBoyNames.push_back(currentName);
		g_vectorGirlNames.push_back(currentName);
		g_vectorLastNames.push_back(currentName);

		float discardData;
		nameFile >> discardData;
		nameFile >> discardData;
		nameFile >> discardData;
	 

	}
 
	 return true;
}


cPerson* makePerson(void)
{
	cPerson* pPerson = new cPerson();


	if(rand() % 10>5)
	{
		//From Boys List
		pPerson->firstName = g_vectorBoyNames[rand() % :: g_vectorBoyNames.size()];
	}
	else
	{
		//From Girls List
		pPerson->firstName = g_vectorGirlNames[rand() % ::g_vectorGirlNames.size()];
	}

	if (rand() % 10 > 5)
	{
		//From Boys List
		pPerson->middleName = g_vectorBoyNames[rand() % ::g_vectorBoyNames.size()];
	}
	else
	{
		//From Girls List
		pPerson->middleName = g_vectorGirlNames[rand() % ::g_vectorGirlNames.size()];
	}

	if (rand() % 10 > 5)
	{
		//From Boys List
		pPerson->lastName = g_vectorBoyNames[rand() % ::g_vectorBoyNames.size()];
	}
	else
	{
		//From Girls List
		pPerson->lastName = g_vectorGirlNames[rand() % ::g_vectorGirlNames.size()];
	}



	return pPerson;
}