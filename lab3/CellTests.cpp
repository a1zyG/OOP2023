#define CATCH_CONFIG_MAIN
#include "Catch/Catch.hpp"
#include "../Classes/MemoryCell/MemoryCell.h"

using namespace Prog3;

TEST_CASE("MemoryCell Default Constructor", "[MemoryCell]") {
    MemoryCell cell;
    REQUIRE(cell.getDefinition() == false);
    REQUIRE(cell.getData() == 0);
}

TEST_CASE("MemoryCell Parameterized Constructor", "[MemoryCell]") {
    MemoryCell cell(42);
    REQUIRE(cell.getDefinition() == false);
    REQUIRE(cell.getData() == 42);
}

TEST_CASE("MemoryCell Parameterized Constructor with Definition", "[MemoryCell]") {
    MemoryCell cell(42, true);
    REQUIRE(cell.getDefinition() == true);
    REQUIRE(cell.getData() == 42);
}

TEST_CASE("MemoryCell Copy Constructor", "[MemoryCell]") {
    MemoryCell source(42, true);
    MemoryCell cell(source);
    REQUIRE(cell.getDefinition() == true);
    REQUIRE(cell.getData() == 42);
}

TEST_CASE("MemoryCell Move Constructor", "[MemoryCell]") {
    MemoryCell source(42, true);
    MemoryCell cell(std::move(source));
    REQUIRE(cell.getDefinition() == true);
    REQUIRE(cell.getData() == 42);
    REQUIRE(source.getDefinition() == false);
}

TEST_CASE("MemoryCell Copy Assignment Operator", "[MemoryCell]") {
    MemoryCell source(42, true);
    MemoryCell cell;
    cell = source;
    REQUIRE(cell.getDefinition() == true);
    REQUIRE(cell.getData() == 42);
}

TEST_CASE("MemoryCell Move Assignment Operator", "[MemoryCell]") {
    MemoryCell source(42, true);
    MemoryCell cell;
    cell = std::move(source);
    REQUIRE(cell.getDefinition() == true);
    REQUIRE(cell.getData() == 42);
    REQUIRE(source.getDefinition() == false);
}

TEST_CASE("MemoryCell getType", "[MemoryCell]") {
    MemoryCell cell;
    REQUIRE(cell.getType() == Descriptor::DescriptorType::CELL);
}

TEST_CASE("MemoryCell getDescriptorSize", "[MemoryCell]") {
    MemoryCell cell;
    REQUIRE(cell.getDescriptorSize() == sizeof(int));
}

TEST_CASE("MemoryCell getDescriptorInfo", "[MemoryCell]") {
    MemoryCell cell(42, true);
    REQUIRE(cell.getDescriptorInfo() == "Memory Cell: Data - 42, Defined - true");
}

TEST_CASE("MemoryCell getData", "[MemoryCell]") {
    MemoryCell cell(42);
    REQUIRE(cell.getData() == 42);
}

TEST_CASE("MemoryCell setData", "[MemoryCell]") {
    MemoryCell cell;
    cell.setData(42);
    REQUIRE(cell.getData() == 42);
}

TEST_CASE("MemoryCell setDefined", "[MemoryCell]") {
    MemoryCell cell;
    cell.setDefined();
    REQUIRE(cell.getDefinition() == true);
}

TEST_CASE("MemoryCell changeDefinition", "[MemoryCell]") {
    MemoryCell cell;
    cell.changeDefinition();
    REQUIRE(cell.getDefinition() == true);
    cell.changeDefinition();
    REQUIRE(cell.getDefinition() == false);
}
