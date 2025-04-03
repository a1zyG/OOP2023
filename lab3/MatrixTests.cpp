#define CATCH_CONFIG_MAIN
#include "Catch/Catch.hpp"
#include "../Classes/MemoryMatrix/MemoryMatrix.h"

using namespace Prog3;

TEST_CASE("MemoryMatrix Constructor", "[MemoryMatrix]") {
    MemoryMatrix matrix(3, 4);
    REQUIRE(matrix.getDefinition() == false);
    REQUIRE(matrix.numRows() == 3);
    REQUIRE(matrix.numCols() == 4);
}

TEST_CASE("MemoryMatrix Move Constructor", "[MemoryMatrix]") {
    MemoryMatrix source(2, 2);
    MemoryMatrix matrix(std::move(source));
    REQUIRE(matrix.getDefinition() == false);
    REQUIRE(matrix.numRows() == 2);
    REQUIRE(matrix.numCols() == 2);
    REQUIRE_THROWS(source.getDefinition() == false);
    REQUIRE(source.numRows() == 0);
    REQUIRE(source.numCols() == 0);
}

TEST_CASE("MemoryMatrix Move Assignment Operator", "[MemoryMatrix]") {
    MemoryMatrix source(2, 2);
    MemoryMatrix matrix(2, 2);
    matrix = std::move(source);
    REQUIRE(matrix.getDefinition() == false);
    REQUIRE(matrix.numRows() == 2);
    REQUIRE(matrix.numCols() == 2);
    REQUIRE_THROWS(source.getDefinition() == false);
    REQUIRE(source.numRows() == 0);
    REQUIRE(source.numCols() == 0);
}

TEST_CASE("MemoryMatrix getType", "[MemoryMatrix]") {
    MemoryMatrix matrix(3, 4);
    REQUIRE(matrix.getType() == Descriptor::DescriptorType::MATRIX);
}

TEST_CASE("MemoryMatrix getDescriptorSize", "[MemoryMatrix]") {
    MemoryMatrix matrix(3, 4);
    REQUIRE(matrix.getDescriptorSize() == 3 * 4 * sizeof(int));
}

TEST_CASE("MemoryMatrix getDescriptorInfo", "[MemoryMatrix]") {
    MemoryMatrix matrix(2, 2);
    std::string info = matrix.getDescriptorInfo();
}

TEST_CASE("MemoryMatrix numRows", "[MemoryMatrix]") {
    MemoryMatrix matrix(3, 4);
    REQUIRE(matrix.numRows() == 3);
}

TEST_CASE("MemoryMatrix numCols", "[MemoryMatrix]") {
    MemoryMatrix matrix(3, 4);
    REQUIRE(matrix.numCols() == 4);
}

TEST_CASE("MemoryMatrix getDefinition", "[MemoryMatrix]") {
    MemoryMatrix matrix(3, 4);
    REQUIRE(matrix.getDefinition() == false);
}

TEST_CASE("MemoryMatrix setData", "[MemoryMatrix]") {
    MemoryMatrix matrix(2, 2);
    matrix.setData(0, 0, 42);
    REQUIRE(matrix(0, 0)->getDefinition() == true);
    REQUIRE(matrix(0, 0)->getData() == 42);
}

TEST_CASE("MemoryMatrix getData", "[MemoryMatrix]") {
    MemoryMatrix matrix(2, 2);
    matrix.setData(1, 1, 24);
    REQUIRE(matrix.getData(1, 1) == 24);
}

TEST_CASE("MemoryMatrix operator()", "[MemoryMatrix]") {
    MemoryMatrix matrix(2, 2);
    matrix.setData(1, 0, 15);
    REQUIRE(matrix(1, 0)->getData() == 15);
}

TEST_CASE("MemoryMatrix setDefined", "[MemoryMatrix]") {
    MemoryMatrix matrix(2, 2);
    matrix.setDefined();
    REQUIRE(matrix.getDefinition() == true);
    REQUIRE(matrix(0, 0)->getDefinition() == true);
}
