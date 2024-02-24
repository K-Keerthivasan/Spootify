#pragma once
#include "cPerson.h"

class cSortOfSmartArray
{
public:
	cSortOfSmartArray();
	~cSortOfSmartArray();

	unsigned int getSize(void);
	unsigned int getCapacity(void);


	void insertAtEnd(cPerson thePerson);

	cPerson getAtIndex(unsigned int index);

 

private:

	//cPerson m_theData[INITIAL_ARRAY_SIZE];

	static const unsigned int INITIAL_ARRAY_SIZE = 10;
	cPerson* m_theData = NULL;

	unsigned int m_NextInsertIndexLocation = 0;

	unsigned int m_CurrentArraySize;

	void m_GrowArray(void);
};