#include "stdafx.h"
#include "Note.h"

using namespace std;

CNote::CNote(const string &s)
	: m_value(s)
	, m_prev(shared_ptr<CNote>())
	, m_next(shared_ptr<CNote>())
{
}

CNote::~CNote()
{
}

const shared_ptr<CNote> CNote::GetPrev() const
{
	return m_prev;
}

const shared_ptr<CNote> CNote::GetNext() const
{
	return m_next;
}

string CNote::GetValue() const
{
	return m_value;
}

void CNote::SetPrev(const shared_ptr<CNote> &prev)
{
	m_prev = prev;
}

void CNote::SetNext(const shared_ptr<CNote> &next)
{
	m_next = next;
}