#include "cPersonMaker.h"


cPerson cPersonMaker::makePerson(void)
{
	cPerson* pPerson = this->makePersonPointer();

	cPerson personToReturn = *pPerson;

	delete pPerson;

	return personToReturn;

}

 

cPerson* cPersonMaker::makePersonPointer(void)
{
	cPerson* pPerson = new cPerson();

	if (rand() % 10 > 5)		// 50-50 chance
	{
		// Pick from boys list
		// HACK:
		pPerson->firstName = this->m_vectorBoyNames[rand() % (this->m_vectorBoyNames.size() - 1)];
	}
	else
	{
		// Pick from girls list
		// HACK:
		pPerson->firstName = this->m_vectorGirlNames[rand() % (this->m_vectorGirlNames.size() - 1)];
	}

	if (rand() % 10 > 5)		// 50-50 chance
	{
		// Pick from boys list
		// HACK:
		pPerson->middleName = this->m_vectorBoyNames[rand() % (this->m_vectorBoyNames.size() - 1)];
	}
	else
	{
		// Pick from girls list
		// HACK:
		pPerson->middleName = this->m_vectorGirlNames[rand() % (this->m_vectorGirlNames.size() - 1)];
	}

	// HACK:
	pPerson->lastName = this->m_vectorLastNames[rand() % (this->m_vectorLastNames.size() - 1)];

	pPerson->age = rand() % 120;

 

	return pPerson;
}

 

bool cPersonMaker:: LoadNameFiles(void)
{
	this->loadNames("dist.male.first.txt");
	 this->loadNames("dist.female.first.txt");
	 this->loadNames("US_LastNames.txt");

	return true;
}



bool cPersonMaker ::loadNames(std::string fileName)
 {

	 std::ifstream nameFile(fileName.c_str());

	 if (!nameFile.is_open())
	 {
		 return false;
	 }

	 std::string currentName;
	 while (nameFile >> currentName)
	 {
		 m_vectorBoyNames.push_back(currentName);
		 m_vectorGirlNames.push_back(currentName);
		 m_vectorLastNames.push_back(currentName);

		 float discardData;
		 nameFile >> discardData;
		 nameFile >> discardData;
		 nameFile >> discardData;


	 }

	 return true;
 }
