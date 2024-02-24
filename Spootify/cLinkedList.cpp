#include "cLinkedList.h"


cLinkedList::cLinkedList()
{
	this->pHeadNode = NULL;

	this->pCurrent = NULL;

}
cLinkedList::~cLinkedList()
{

}

void cLinkedList::insertAtStart(cPerson newPerson)
{


	return;
}

void cLinkedList::insertAtCurrent(cPerson newPerson)
{
	if (this->pHeadNode == NULL)
	{
		cNode* pNewNode = new cNode();
		pNewNode->thePerson = newPerson;

		this->pHeadNode = pNewNode;
		this->pCurrent = this->pHeadNode;
	}

	cNode* pNewNode = new cNode();
	pNewNode->thePerson = newPerson;

	pNewNode->pNextNode = this->pCurrent;
	pNewNode->pPriorNode = this->pCurrent->pPriorNode;

	//Update the current Node
	this->pCurrent->pPriorNode = pNewNode;


	this->pCurrent = pNewNode;


	return;
}

void cLinkedList::moveToHead()
{
	this->m_FineHeadNode();
	this->pCurrent = this->pHeadNode;
	return;
}


void cLinkedList::moveToTail()
{
	this->m_FindTailNode();
	this->pCurrent = this->pTailNode;
	return;
}



bool cLinkedList::moveNext(void)
{
	if (this->pCurrent->pNextNode == NULL)
	{
		return false;
	}

	this->pCurrent = this->pCurrent->pNextNode;

	return true;
}

bool cLinkedList::movePrior(void)
{
	if (this->pCurrent->pPriorNode == NULL)
	{
		return false;
	}

	this->pCurrent = this->pCurrent->pPriorNode;

	return true;
}


cPerson cLinkedList::getAtCurrent(void)
{
	return this->pCurrent->thePerson;
}


void cLinkedList::m_FineHeadNode(void)
{
	cNode* pPossibleHead = this->pCurrent;

	while (pPossibleHead->pPriorNode != NULL)
	{
		//Point to the prior node
		pPossibleHead = pPossibleHead->pPriorNode;
	}
	this->pHeadNode = pPossibleHead;

	return;
}

void cLinkedList::m_FindTailNode(void)
{
	cNode* pPossibleTail = this->pCurrent;

	while (pPossibleTail->pNextNode != NULL)
	{
		//Point to the next node
		pPossibleTail = pPossibleTail->pNextNode;
	}

	this->pTailNode = pPossibleTail;

	return;
}
