#pragma once

#include "cPerson.h"

class cNode
{
public:
	cPerson thePerson;

	cNode* pNextNode=NULL;
	cNode* pPriorNode=NULL;

};

class cLinkedList
{

public:
	cLinkedList();
	~cLinkedList();

	void insertAtStart(cPerson newPerson);
	cPerson getAtCurrent(void);


	bool moveNext(void);
	bool movePrior(void);

	void updateAtCurrent(cPerson updatedPerson);

	unsigned int getSize(void);

	void insertAtEnd(cPerson newPerson);
	void insertAtCurrent(cPerson newPerson);

	void moveToHead(void);
	void moveToTail(void);

private:
	cNode* pHeadNode;
	cNode* pTailNode;

	void m_FineHeadNode(void);
	void m_FindTailNode(void);

	cNode* pCurrent; //Where we are pointing to


};

