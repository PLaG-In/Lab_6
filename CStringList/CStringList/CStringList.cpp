#include "stdafx.h"
#include "CStringList.h"

using namespace std;

CStringList::CStringList()
	:m_first()
	, m_last()
{
}


CStringList::~CStringList()
{
}

shared_ptr<CNote> CStringList::GetFirst() const
{
	return m_first;
}

shared_ptr<CNote> CStringList::GetLast() const
{
	return m_last;
}

shared_ptr<CNote> CStringList::GetNext(const shared_ptr<CNote> &ptr) const
{
	return ptr->GetNext();
}

shared_ptr<CNote> CStringList::GetPrev(const shared_ptr<CNote> &ptr) const
{
	return ptr->GetPrev();
}

string CStringList::GetVal(const shared_ptr<CNote> &ptr) const
{
	return ptr->GetValue();
}

void CStringList::Insert(string const&s, shared_ptr<CNote> &ptr)
{
	auto newPtr = make_shared<CNote>(s);
	if (!m_first)
	{
		m_first = newPtr;
		m_last = newPtr;
		return;
	}
	if (ptr)
	{
		newPtr->SetPrev(ptr);
		auto it = ptr->GetNext();
		newPtr->SetNext(it);
		if (it)
		{
			it->SetPrev(newPtr);
		}
		ptr->SetNext(newPtr);
		if (m_last == ptr)
		{
			m_last = newPtr;
		}
	}
	else
	{
		newPtr->SetPrev(m_last);
		newPtr->SetNext(shared_ptr<CNote>());
		m_last->SetNext(newPtr);
		m_last = newPtr;
	}
}

void CStringList::Delete(const shared_ptr<CNote> elem)
{
	auto it = elem->GetNext();
	if (it)
	{
		elem->GetNext()->SetPrev(elem->GetPrev());
	}
	else
	{
		m_last = elem->GetPrev();
	}
	it = elem->GetPrev();
	if (it)
	{
		elem->GetPrev()->SetNext(elem->GetNext());
	}
	else
	{
		m_first = elem->GetNext();
	}
}