#define CATCH_CONFIG_MAIN
#include "Catch/Catch.hpp"
#include "../Classes/MemoryVector/MemoryVector.h"

using namespace Prog3;

TEST_CASE("MemoryVector Explicit Constructor", "[MemoryVector]") {
    MemoryVector vector(5);
    REQUIRE(vector.getDefinition() == true);
    REQUIRE(vector.size() == 0);
    REQUIRE(vector.getMaxSize() == 5);
}

TEST_CASE("MemoryVector Parameterized Constructor", "[MemoryVector]") {
    auto cell = std::make_shared<MemoryCell>(42, true);
    MemoryVector vector(cell, 3);
    REQUIRE(vector.getDefinition() == true);
    REQUIRE(vector.size() == 1);
    REQUIRE(vector.getMaxSize() == 3);
    REQUIRE(vector.getData(0) == 42);
}

TEST_CASE("MemoryVector Move Constructor", "[MemoryVector]") {
    auto cell = std::make_shared<MemoryCell>(42, true);
    MemoryVector source(cell, 3);
    MemoryVector vector(std::move(source));
    REQUIRE(vector.getDefinition() == true);
    REQUIRE(vector.size() == 1);
    REQUIRE(vector.getMaxSize() == 3);
    REQUIRE(vector.getData(0) == 42);
    REQUIRE(source.getDefinition() == false);
    REQUIRE_THROWS(source.size() == 0);
}

TEST_CASE("MemoryVector Move Assignment Operator", "[MemoryVector]") {
    auto cell = std::make_shared<MemoryCell>(42, true);
    MemoryVector source(cell, 3);
    MemoryVector vector(3);
    vector = std::move(source);
    REQUIRE(vector.getDefinition() == true);
    REQUIRE(vector.size() == 1);
    REQUIRE(vector.getMaxSize() == 3);
    REQUIRE(vector.getData(0) == 42);
    REQUIRE(source.getDefinition() == false);
    REQUIRE_THROWS(source.size() == 0);
}

TEST_CASE("MemoryVector getType", "[MemoryVector]") {
    MemoryVector vector(5);
    REQUIRE(vector.getType() == Descriptor::DescriptorType::VECTOR);
}

TEST_CASE("MemoryVector getDescriptorSize", "[MemoryVector]") {
    MemoryVector vector(5);
    REQUIRE(vector.getDescriptorSize() == 0);  // As the vector is empty
}

TEST_CASE("MemoryVector getDescriptorInfo", "[MemoryVector]") {
    auto cell1 = std::make_shared<MemoryCell>(42, true);
    auto cell2 = std::make_shared<MemoryCell>(24, false);
    MemoryVector vector(3);
    vector.push_back(cell1);
    vector.push_back(cell2);
    std::string info = vector.getDescriptorInfo();
    REQUIRE(info.find("Memory Vector: Size - 2, MaxSize - 3, Defined - false") != std::string::npos);
    REQUIRE(info.find("Memory Cell: Data - 42, Defined - true") != std::string::npos);
    REQUIRE(info.find("Memory Cell: Data - 24, Defined - false") != std::string::npos);
}

TEST_CASE("MemoryVector size", "[MemoryVector]") {
    auto cell1 = std::make_shared<MemoryCell>(42, true);
    auto cell2 = std::make_shared<MemoryCell>(24, false);
    MemoryVector vector(3);
    REQUIRE(vector.size() == 0);
    vector.push_back(cell1);
    vector.push_back(cell2);
    REQUIRE(vector.size() == 2);
}

    TEST_CASE("MemoryVector getMaxSize", "[MemoryVector]") {
    MemoryVector vector(5);
    REQUIRE(vector.getMaxSize() == 5);
}

TEST_CASE("MemoryVector getDefinition", "[MemoryVector]") {
    MemoryVector vector(5);
    REQUIRE(vector.getDefinition() == true);
}

TEST_CASE("MemoryVector checkDefined", "[MemoryVector]") {
    auto cell1 = std::make_shared<MemoryCell>(42, true);
    auto cell2 = std::make_shared<MemoryCell>(24, false);
    MemoryVector vector(3);
    vector.push_back(cell1);
    vector.push_back(cell2);
}

TEST_CASE("MemoryVector setMaxSize", "[MemoryVector]") {
    auto cell1 = std::make_shared<MemoryCell>(42, true);
    auto cell2 = std::make_shared<MemoryCell>(24, false);
    MemoryVector vector(3);
    vector.push_back(cell1);
    vector.push_back(cell2);
    vector.setMaxSize();
    REQUIRE(vector.size() == 3);
    REQUIRE(vector.getDefinition() == false);
}

TEST_CASE("MemoryVector setData", "[MemoryVector]") {
    auto cell1 = std::make_shared<MemoryCell>(42, true);
    auto cell2 = std::make_shared<MemoryCell>(24, false);
    MemoryVector vector(3);
    vector.push_back(cell1);
    vector.push_back(cell2);
    vector.setData(1);
    REQUIRE(vector[1]->getDefinition() == true);
}

TEST_CASE("MemoryVector getData", "[MemoryVector]") {
    auto cell1 = std::make_shared<MemoryCell>(42, true);
    auto cell2 = std::make_shared<MemoryCell>(24, false);
    MemoryVector vector(3);
    vector.push_back(cell1);
    vector.push_back(cell2);
    REQUIRE(vector.getData(0) == 42);
    REQUIRE(vector.getData(1) == 24);
}

TEST_CASE("MemoryVector push_back", "[MemoryVector]") {
    auto cell1 = std::make_shared<MemoryCell>(42, true);
    auto cell2 = std::make_shared<MemoryCell>(24, false);
    MemoryVector vector(3);
    vector.push_back(cell1);
    vector.push_back(cell2);
    REQUIRE(vector.size() == 2);
    REQUIRE(vector[0]->getData() == 42);
    REQUIRE(vector[1]->getData() == 24);
}

TEST_CASE("MemoryVector setDefined", "[MemoryVector]") {
    auto cell1 = std::make_shared<MemoryCell>(42, true);
    auto cell2 = std::make_shared<MemoryCell>(24, false);
    MemoryVector vector(3);
    vector.push_back(cell1);
    vector.push_back(cell2);
    vector.setDefined();
    REQUIRE(vector.getDefinition() == true);
    REQUIRE(vector[0]->getDefinition() == true);
    REQUIRE(vector[1]->getDefinition() == true);
}
