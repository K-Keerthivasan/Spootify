#include <string>
#include <fstream>
#include <iostream>
#include "cPersonMaker.h"
#include "tSortOfSmartArray.h"

#include "cPerson.h"
#include <vector>

#include "cLinkedList.h"
#include "SortOfSmartArrays.h"





//int main()
//{
//
//	cPersonMaker personMaker;
//
//	personMaker.LoadNameFiles();
//
//	const unsigned int NUMBER_OF_PEOPLE = 100;
//
//	cSortOfSmartArray myPeople;
//
// 
//
//	for (unsigned int count = 0; count < NUMBER_OF_PEOPLE; count++)
//	{
//
//		cPerson pNewPerson = personMaker.makePerson();
//
//
//		myPeople.insertAtEnd(pNewPerson);
//
// 
//	}
//
//	for (unsigned int index = 0; index != myPeople.getSize(); index++)
//	{
//		std::cout << myPeople.getAtIndex(index).firstName << " "
//			<< myPeople.getAtIndex(index).middleName << " "
//			<< myPeople.getAtIndex(index).lastName << " "
//			<< myPeople.getAtIndex(index).age << " "
//			<< std::endl;
//	}
//
//
//	return 0;
//}


////Main with checking  with stl
//int main()
//{
//
//	cPersonMaker personMaker;
//
//	personMaker.LoadNameFiles();
//
//	const unsigned int NUMBER_OF_PEOPLE = 5;
//
//	cSortOfSmartArray myPeople;
//
//	//tSortOfSmartArray<cPerson> myPeople;
// 
//	for (unsigned int count = 0; count < NUMBER_OF_PEOPLE; count++)
//	{
//
//		cPerson pNewPerson = personMaker.makePerson();
//
//
//		myPeople.insertAtEnd(pNewPerson);
//
//
//	}
//
//	for (unsigned int index = 0; index != myPeople.getSize(); index++)
//	{
//		std::cout << myPeople.getAtIndex(index).firstName << " "
//			<< myPeople.getAtIndex(index).middleName << " "
//			<< myPeople.getAtIndex(index).lastName << " "
//			<< myPeople.getAtIndex(index).age << " "
//			<< std::endl;
//	}
//
//
//	return 0;
//}


void PrintPerson(const cPerson& thePerson)
{
	std::cout << thePerson.firstName << " "
		<< thePerson.middleName << " "
		<< thePerson.lastName << " "
		<< thePerson.age << " "
		<< std::endl;
	return;
}  
 
//Main with checking  with list
int main()
{

	cPersonMaker personMaker;
	personMaker.LoadNameFiles();

	const unsigned int NUMBER_OF_PEOPLE = 10;

	cLinkedList myPeople;

	//cPerson pNewPerson = personMaker.makePerson();
	//myPeople.insertAtCurrent(pNewPerson);

	//cPerson currentPerson = myPeople.getAtCurrent();

	for (unsigned int count = 0; count < NUMBER_OF_PEOPLE; count++)
	{

		cPerson newPerson = personMaker.makePerson();

		myPeople.insertAtCurrent(newPerson);

	}


	myPeople.moveToHead();
	PrintPerson(myPeople.getAtCurrent());

	myPeople.moveToTail();

	PrintPerson(myPeople.getAtCurrent());
	do
	{
		PrintPerson(myPeople.getAtCurrent());
	}
	while (myPeople.moveNext());


	return 0;
}


