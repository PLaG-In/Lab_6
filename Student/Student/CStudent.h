#pragma once

using namespace std;
class CStudent
{
public:
	CStudent(string const& name, string const& surname,
		string const& patronymic, int age);
	~CStudent();

	string GetName() const;
	string GetSurname() const;
	string GetPatronymic() const;
	int GetAge() const;

	void Rename(string const& name, string const& surname,
		string const& patronymic);
	void SetAge(int age);

private:
	string m_name;
	string m_surname;
	string m_patronymic;
	int m_age;

	bool IsLetter(string const& str);
	void ErrorsInAge(int age);
	void ErrorsInName(string const& name,
		string const& surname, string const& patronymic);
};