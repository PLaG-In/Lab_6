#pragma once
#include "Note.h"

using namespace std;

class CStringList
{
public:
	CStringList();
	~CStringList();
	shared_ptr<CNote> GetFirst() const;
	shared_ptr<CNote> GetLast() const;
	shared_ptr<CNote> GetNext(const shared_ptr<CNote> &ptr) const;
	shared_ptr<CNote> GetPrev(const shared_ptr<CNote> &ptr) const;
	string GetVal(const shared_ptr<CNote> &ptr) const;
	void Insert(const string &s, shared_ptr<CNote> &ptr = shared_ptr<CNote>());
	void Delete(const shared_ptr<CNote> elem);

private:
	shared_ptr<CNote> m_first;
	shared_ptr<CNote> m_last;
};