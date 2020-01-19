// Datei: unit_tests_deep_copy.cpp

#include "catch.h"

#include "CharListenKnoten.h"
#include "MyString2.h"

TEST_CASE("Pruefung der Methode void MyString2::deep_copy()") {

	MyString2 s;
	s.append('a'); s.append('b'); s.append('c');

	REQUIRE(s.get_anker() != nullptr);
	REQUIRE(s.get_anker()->get_data() == 'a');
	REQUIRE(s.get_anker()->get_next() != nullptr);
	REQUIRE(s.get_anker()->get_next()->get_data() == 'b');
	REQUIRE(s.get_anker()->get_next()->get_next() != nullptr);
	REQUIRE(s.get_anker()->get_next()->get_next()->get_data() == 'c');
	REQUIRE(s.get_anker()->get_next()->get_next()->get_next() == nullptr);

	SECTION("MyString2::deep_copy()") {

		CharListenKnoten* ptr = s.deep_copy();

		REQUIRE(ptr != nullptr);
		REQUIRE(ptr != s.get_anker());
		REQUIRE(ptr->get_data() == 'a');
		REQUIRE(ptr->get_next() != nullptr);
		REQUIRE(ptr->get_next() != s.get_anker()->get_next());
		REQUIRE(ptr->get_next()->get_data() == 'b');
		REQUIRE(ptr->get_next()->get_next() != nullptr);
		REQUIRE(ptr->get_next()->get_next() != s.get_anker()->get_next()->get_next());
		REQUIRE(ptr->get_next()->get_next()->get_data() == 'c');
		REQUIRE(ptr->get_next()->get_next()->get_next() == nullptr); 
	}
}
