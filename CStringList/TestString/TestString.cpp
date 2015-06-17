// TestString.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


#include "stdafx.h"
#include "../CStringList/Note.h"
#include "../CStringList/CStringList.h"

using namespace std;

BOOST_AUTO_TEST_CASE(CheckEmptyList)
{
	CStringList list;
	BOOST_CHECK(list.GetFirst() == nullptr);
	BOOST_CHECK(list.GetLast() == nullptr);
}

BOOST_AUTO_TEST_CASE(CanGetLinkToFirstAndLast)
{
	CStringList list;
	list.Insert("newline");
	BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), "newline");
	BOOST_CHECK_EQUAL(list.GetFirst()->GetValue(), "newline");
	list.Insert("abu");
	BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), "abu");
	BOOST_CHECK_EQUAL(list.GetFirst()->GetValue(), "newline");
}

BOOST_AUTO_TEST_CASE(CanInsertToEndByDefault)
{
	CStringList list;
	list.Insert("newline");
	BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), "newline");
}

BOOST_AUTO_TEST_CASE(CanInsertAfterGivenArg)
{
	CStringList list;
	list.Insert("y");
	BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), "y");
	list.Insert("e");
	BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), "e");
	list.Insert("a");
	BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), "a");
	auto it = list.GetLast()->GetPrev();
	list.Insert("h", it);
	BOOST_CHECK_EQUAL(list.GetLast()->GetPrev()->GetValue(), "h");
	BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), "a");
}

BOOST_AUTO_TEST_CASE(CanDeleteElem)
{
	{
		CStringList list;
		list.Insert("y");
		list.Insert("e");
		list.Insert("a");
		auto it = list.GetLast()->GetPrev();
		list.Insert("h", it);
		list.Delete(list.GetLast());
		BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), "h");
		BOOST_CHECK_EQUAL(list.GetFirst()->GetValue(), "y");
		list.Delete(list.GetFirst());
		BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), "h");
		BOOST_CHECK_EQUAL(list.GetFirst()->GetValue(), "e");
		list.Delete(list.GetLast());
		BOOST_CHECK_EQUAL(list.GetLast()->GetValue(), "e");
		BOOST_CHECK_EQUAL(list.GetFirst()->GetValue(), "e");
		list.Delete(list.GetLast());
		BOOST_CHECK_EQUAL(list.GetLast(), shared_ptr<CNote>());
		BOOST_CHECK_EQUAL(list.GetFirst(), shared_ptr<CNote>());
	}
	{
		CStringList list;
		list.Insert("y");
		list.Insert("e");
		list.Insert("s");
		list.Delete(list.GetLast()->GetPrev());
		BOOST_CHECK_EQUAL(list.GetNext(list.GetFirst())->GetValue(), "s");
	}
}


BOOST_AUTO_TEST_CASE(CanGetStringValue)
{
	CNote note = "line";
	BOOST_CHECK_EQUAL(note.GetValue(), "line");
}

BOOST_AUTO_TEST_CASE(CanGetPointerToNextPrevElement)
{
	CNote note = "line";
	BOOST_CHECK_EQUAL(note.GetNext(), shared_ptr<CNote>());
	BOOST_CHECK_EQUAL(note.GetPrev(), shared_ptr<CNote>());
}

BOOST_AUTO_TEST_CASE(CanSetPointerToNextPrevElement)
{
	CNote note = "line";
	auto it = make_shared<CNote>("note");
	note.SetNext(it);
	note.SetPrev(it);
	BOOST_CHECK_EQUAL(note.GetNext(), it);
	BOOST_CHECK_EQUAL(note.GetPrev(), it);
}
