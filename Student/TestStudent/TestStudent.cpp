// TestStudent.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Student/CStudent.h"


BOOST_AUTO_TEST_CASE(StudentHasNameSurnamePatronymic)
{
	CStudent student("Ivanov", "Ivan", "Ivanovich", 42);
	BOOST_CHECK_EQUAL(student.GetName(), "Ivanov");
	BOOST_CHECK_EQUAL(student.GetSurname(), "Ivan");
	BOOST_CHECK_EQUAL(student.GetPatronymic(), "Ivanovich");
	BOOST_CHECK_EQUAL(student.GetAge(), 42);
}
