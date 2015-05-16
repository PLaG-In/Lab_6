// TestStudent.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Student/CStudent.h"


BOOST_AUTO_TEST_CASE(StudentHasNameSurnamePatronymic)
{
	CStudent student("Ivan", "Ivanov", "Ivanovich", 42);
	BOOST_CHECK_EQUAL(student.GetName(), "Ivan");
	BOOST_CHECK_EQUAL(student.GetSurname(), "Ivanov");
	BOOST_CHECK_EQUAL(student.GetPatronymic(), "Ivanovich");
	BOOST_CHECK_EQUAL(student.GetAge(), 42);
}

BOOST_AUTO_TEST_CASE(BadSymbolsInStudentName)
{
	BOOST_CHECK_THROW(CStudent student("rus15", "Ivanov", "Ivanovich", 15), invalid_argument);
	BOOST_CHECK_THROW(CStudent student("Ivan", "Not_EXIST", "Ivanovich", 16), invalid_argument);
	BOOST_CHECK_THROW(CStudent student("Ivan", "Ivanov", "Ven.,us!?", 17), invalid_argument);
}

BOOST_AUTO_TEST_CASE(EmptyStudentNameOrSurnameCausesException)
{
	BOOST_CHECK_THROW(CStudent student("", "Ivanov", "Ivanovich", 15), invalid_argument);
	BOOST_CHECK_THROW(CStudent student("Ivan", "", "Ivanovich", 16), invalid_argument);
}

BOOST_AUTO_TEST_CASE(EmptyStudentPatronymic)
{
	CStudent student("Ivan", "Ivanov", "", 33);
	BOOST_CHECK_EQUAL(student.GetPatronymic(), "");
}

BOOST_AUTO_TEST_CASE(AgeIsOutOfRange)
{
	BOOST_CHECK_THROW(CStudent student("Ivan", "Ivanov", "Ivanovich", 13), out_of_range);
	BOOST_CHECK_THROW(CStudent student("Ivan", "Ivanov", "Ivanovich", 61), out_of_range);
}
