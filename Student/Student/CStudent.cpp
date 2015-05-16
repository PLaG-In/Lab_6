
#include "stdafx.h"
#include "CStudent.h"

using namespace std;

CStudent::CStudent(string const& name, string const& surname,
	string const& patronymic, int age)
	:m_name(name)
	, m_surname(surname)
	, m_patronymic(patronymic)
	, m_age(age)
{
	ErrorsInAge(m_age);
	ErrorsInName(m_name, m_surname, m_patronymic);
}

CStudent::~CStudent()
{
}

string CStudent::GetName() const
{
	return m_name;
}

string CStudent::GetSurname() const
{
	return m_surname;
}

string CStudent::GetPatronymic() const
{
	return m_patronymic;
}

int CStudent::GetAge() const
{
	return m_age;
}

void CStudent::Rename(string const& name,
	string const& surname, string const& patronymic)
{
	ErrorsInName(name, surname, patronymic);

	string cName(name);
	string cSurname(surname);
	string cPatronymic(patronymic);

	m_name = move(cName);
	m_surname = move(cSurname);
	m_patronymic = move(cPatronymic);
}

void CStudent::ErrorsInAge(int age)
{
	if (age < minAge || age > maxAge)
	{
		throw out_of_range("Age must be in that range (14, 60)!");
	}
}

void CStudent::SetAge(int age)
{
	ErrorsInAge(age);

	if (age < m_age)
	{
		throw domain_error("It is impossible to reduce the age!");
	}

	m_age = age;
}

bool CStudent::IsLetter(string const& str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!isalpha(str[i]))
		{
			return false;
		}
	}
	return true;
}

void CStudent::ErrorsInName(string const& name,
	string const& surname, string const& patronymic)
{
	if (name.empty() || !IsLetter(name))
	{
		throw invalid_argument("Incorrect name!");
	}

	if (surname.empty() || !IsLetter(surname))
	{
		throw invalid_argument("Incorrect surname!");
	}

	if (!IsLetter(patronymic))
	{
		throw invalid_argument("Incorrect patronymic!");
	}
}