// Datei: unit_tests_charlistenknoten.cpp

#include "catch.h"

#include "CharListenKnoten.h"

TEST_CASE("Pruefung der Methoden CharListenKnoten::get_data() / CharListenKnoten::set_data()") {

	CharListenKnoten k;

	k.set_data('a');
	REQUIRE(k.get_data() == 'a');

	k.set_data('b');
	REQUIRE(k.get_data() == 'b');
}

TEST_CASE("Pruefung der Methoden CharListenKnoten::get_next() / ::set_next()") {

	CharListenKnoten k1, k2;

	REQUIRE(k1.get_next() == nullptr);
	REQUIRE(k2.get_next() == nullptr);

	k1.set_next(&k2);

	REQUIRE(k1.get_next() == &k2);
	REQUIRE(k2.get_next() == nullptr);
}
