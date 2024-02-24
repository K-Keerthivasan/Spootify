#pragma once
#include <iostream>

#include "cPerson.h"


template <class T>
class tSortOfSmartArray
{
public:
	tSortOfSmartArray()
	{
		this->m_theData = new cPerson[INITIAL_ARRAY_SIZE];
		this->m_CurrentArraySize = INITIAL_ARRAY_SIZE;
	}
	~tSortOfSmartArray()
	{
		delete[] this->m_theData;
	}

	unsigned int getSize(void)
	{
		return this->m_CurrentArraySize;
	}
	unsigned int getCapacity(void)
	{
		return this->m_NextInsertIndexLocation;
	}


	//void insertAtEnd(cPerson thePerson)
	void insertAtEnd(T thePerson)
	{
		if (this->m_NextInsertIndexLocation == this->m_CurrentArraySize)
		{
			std::cout << "Not Big enough Current Size " << this->m_CurrentArraySize << " Resizing" << std::endl;
			this->m_GrowArray();
			return;
		}

		// Add person to the array
		this->m_theData[this->m_NextInsertIndexLocation] = thePerson;

		// Move to the next location
		this->m_NextInsertIndexLocation++;

		return;
	}

	//cPerson getAtIndex(unsigned int index)
	T getAtIndex(unsigned int index)
	{
		return this->m_theData[index];
	}



private:

	//cPerson m_theData[INITIAL_ARRAY_SIZE];

	static const unsigned int INITIAL_ARRAY_SIZE = 10;
	//cPerson* m_theData = NULL;
	T* m_theData = NULL;

	unsigned int m_NextInsertIndexLocation = 0;

	unsigned int m_CurrentArraySize;

	void m_GrowArray(void)
	{
		//Check the size
		unsigned int newArraySize = this->m_CurrentArraySize + (this->m_CurrentArraySize / 2);

		//create a new array
		//cPerson* pNewArray = new cPerson[newArraySize];
		T* pNewArray = new cPerson[newArraySize];

		for (unsigned int index = 0; index < this->m_CurrentArraySize; index++)
		{
			pNewArray[index] = this->m_theData[index];
		}
		//delete the old array
		delete[] this->m_theData;

		//re assign the pointer and update the counters
		this->m_theData = pNewArray;
		this->m_CurrentArraySize = newArraySize;

		return;
	}
};