#include "SortOfSmartArrays.h"

#include <iostream>


unsigned int cSortOfSmartArray::getSize(void)
{
	return this->m_NextInsertIndexLocation;
}

unsigned cSortOfSmartArray::getCapacity()
{
	return this->m_CurrentArraySize;
}

void cSortOfSmartArray::insertAtEnd(cPerson thePerson)
{
	if(this->m_NextInsertIndexLocation == this->m_CurrentArraySize)
	{
		std::cout << "Not Big enough Current Size"<< this->m_CurrentArraySize<<"Resizing" << std::endl;
		this->m_GrowArray();
		return;
	}

	// Add person to the array
	this->m_theData[this->m_NextInsertIndexLocation] = thePerson;

	// Move to the next location
	this->m_NextInsertIndexLocation++;

	return;
}


cPerson cSortOfSmartArray::getAtIndex(unsigned int index)
{

	return this->m_theData[index];
}

void cSortOfSmartArray::m_GrowArray()
{
	//Check the size
	unsigned int newArraySize = this->m_CurrentArraySize + (this->m_CurrentArraySize/2);
 
	//create a new array
	cPerson * pNewArray = new cPerson[newArraySize];

	for(unsigned int index = 0; index < this->m_CurrentArraySize; index++)
	{
		pNewArray[index] = this->m_theData[index];
	}
	//delete the old array
	delete [] this->m_theData;

	//re assign the pointer and update the counters
	this->m_theData = pNewArray;
	this->m_CurrentArraySize = newArraySize;

	return;
}


cSortOfSmartArray::cSortOfSmartArray()
{
	this->m_theData = new cPerson[INITIAL_ARRAY_SIZE];
	this->m_CurrentArraySize = INITIAL_ARRAY_SIZE;
}

cSortOfSmartArray::~cSortOfSmartArray()
{
	delete[] this->m_theData;
}



