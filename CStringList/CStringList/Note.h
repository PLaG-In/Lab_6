#pragma once

using namespace std;

class CNote
{
public:
	CNote(const std::string &s);
	~CNote();
	const shared_ptr<CNote> GetPrev() const;
	const shared_ptr<CNote> GetNext() const;
	string GetValue() const;
	void SetPrev(const shared_ptr<CNote> &prev);
	void SetNext(const shared_ptr<CNote> &next);

private:
	string m_value;
	shared_ptr<CNote> m_prev, m_next;
};