#include "BoundingBox.hpp"
#include "formats/osm/pbf/OsmPbfParser.hpp"
#include "formats/osm/TestOsmDataVisitor.hpp"
#include "config.hpp"

#include <boost/test/unit_test.hpp>

#include <fstream>

using namespace utymap::formats;

struct Formats_Pbf_OsmPbfParserFixture
{
    Formats_Pbf_OsmPbfParserFixture() :
        istream(TEST_PBF_FILE, std::ios::binary)
    { BOOST_TEST_MESSAGE("setup fixture"); }

    ~Formats_Pbf_OsmPbfParserFixture() { BOOST_TEST_MESSAGE("teardown fixture"); }

    OsmPbfParser<TestOsmDataVisitor> parser;
    TestOsmDataVisitor visitor;
    std::ifstream istream;
};

BOOST_FIXTURE_TEST_SUITE( Formats_Pbf_Parser, Formats_Pbf_OsmPbfParserFixture )

BOOST_AUTO_TEST_CASE( GivenDefaultPbf_WhenParserParse_ThenHasExpectedElementCount )
{
    parser.parse(istream, visitor);

    BOOST_CHECK_EQUAL( visitor.nodes, 151506 );
    BOOST_CHECK_EQUAL( visitor.ways, 27791 );
    BOOST_CHECK_EQUAL( visitor.relations, 362);
}

BOOST_AUTO_TEST_SUITE_END()