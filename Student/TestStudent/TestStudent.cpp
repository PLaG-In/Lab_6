// TestStudent.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Student/CStudent.h"


BOOST_AUTO_TEST_CASE(StudentHasNameSurnamePatronymic)
{
	CStudent student("Niccolo", "Machiavelli", "diBernardo", 42);
	BOOST_CHECK_EQUAL(student.GetName(), "Niccolo");
	BOOST_CHECK_EQUAL(student.GetSurname(), "Machiavelli");
	BOOST_CHECK_EQUAL(student.GetPatronymic(), "diBernardo");
	BOOST_CHECK_EQUAL(student.GetAge(), 42);
}

BOOST_AUTO_TEST_CASE(BadSymbolsInStudentName)
{
	BOOST_CHECK_THROW(CStudent student("rus15", "Machiavelli", "diBernardo", 15), invalid_argument);
	BOOST_CHECK_THROW(CStudent student("Niccolo", "Not_EXIST", "diBernardo", 16), invalid_argument);
	BOOST_CHECK_THROW(CStudent student("Niccolo", "Machiavelli", "Ven.,us!?", 17), invalid_argument);
}

BOOST_AUTO_TEST_CASE(EmptyStudentNameOrSurnameCausesException)
{
	BOOST_CHECK_THROW(CStudent student("", "Machiavelli", "diBernardo", 15), invalid_argument);
	BOOST_CHECK_THROW(CStudent student("Niccolo", "", "diBernardo", 16), invalid_argument);
}

BOOST_AUTO_TEST_CASE(EmptyStudentPatronymic)
{
	CStudent student("Niccolo", "Machiavelli", "", 33);
	BOOST_CHECK_EQUAL(student.GetPatronymic(), "");
}

BOOST_AUTO_TEST_CASE(AgeIsOutOfRange)
{
	BOOST_CHECK_THROW(CStudent student("Niccolo", "Machiavelli", "diBernardo", 13), out_of_range);
	BOOST_CHECK_THROW(CStudent student("Niccolo", "Machiavelli", "diBernardo", 61), out_of_range);
}

BOOST_AUTO_TEST_CASE(AgeCanOnlyGrow)
{
	CStudent student("Niccolo", "Machiavelli", "diBernardo", 32);

	BOOST_CHECK_THROW(student.SetAge(30), domain_error);
	BOOST_CHECK_EQUAL(student.GetAge(), 32);

	student.SetAge(33);
	BOOST_CHECK_EQUAL(student.GetAge(), 33);

	student.SetAge(44);
	BOOST_CHECK_EQUAL(student.GetAge(), 44);
}

BOOST_AUTO_TEST_CASE(StudentRenameTests)
{
	CStudent student("Niccolo", "Machiavelli", "diBernardo", 44);
	{
		BOOST_CHECK_THROW(student.Rename("", "Machiavelli", "diBernardo"), invalid_argument);
		BOOST_CHECK_EQUAL(student.GetName(), "Niccolo");
		BOOST_CHECK_EQUAL(student.GetSurname(), "Machiavelli");
		BOOST_CHECK_EQUAL(student.GetPatronymic(), "diBernardo");
	}
	{
		BOOST_CHECK_THROW(student.Rename("Niccolo", "", "diBernardo"), invalid_argument);
		BOOST_CHECK_EQUAL(student.GetName(), "Niccolo");
		BOOST_CHECK_EQUAL(student.GetSurname(), "Machiavelli");
		BOOST_CHECK_EQUAL(student.GetPatronymic(), "diBernardo");
	}
	{
		student.Rename("Niccolo", "Machiavelli", "");
		BOOST_CHECK_EQUAL(student.GetName(), "Niccolo");
		BOOST_CHECK_EQUAL(student.GetSurname(), "Machiavelli");
		BOOST_CHECK_EQUAL(student.GetPatronymic(), "");
	}
	{
		student.Rename("Niccolo", "Machiavelli", "diBernardo");
	}
	{
		BOOST_CHECK_THROW(student.Rename("w8", "Machiavelli", "diBernardo"), invalid_argument);
		BOOST_CHECK_EQUAL(student.GetName(), "Niccolo");
		BOOST_CHECK_EQUAL(student.GetSurname(), "Machiavelli");
		BOOST_CHECK_EQUAL(student.GetPatronymic(), "diBernardo");
	}
	{
		BOOST_CHECK_THROW(student.Rename("Niccolo", "_.1337._", "diBernardo"), invalid_argument);
		BOOST_CHECK_EQUAL(student.GetName(), "Niccolo");
		BOOST_CHECK_EQUAL(student.GetSurname(), "Machiavelli");
		BOOST_CHECK_EQUAL(student.GetPatronymic(), "diBernardo");
	}
	{
		BOOST_CHECK_THROW(student.Rename("Niccolo", "Machiavelli", "Igne/666"), invalid_argument);
		BOOST_CHECK_EQUAL(student.GetName(), "Niccolo");
		BOOST_CHECK_EQUAL(student.GetSurname(), "Machiavelli");
		BOOST_CHECK_EQUAL(student.GetPatronymic(), "diBernardo");
	}
	{
		student.Rename("Nikola", "Tesla", "Energy");
		BOOST_CHECK_EQUAL(student.GetName(), "Nikola");
		BOOST_CHECK_EQUAL(student.GetSurname(), "Tesla");
		BOOST_CHECK_EQUAL(student.GetPatronymic(), "Energy");
	}
}