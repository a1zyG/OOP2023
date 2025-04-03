#define CATCH_CONFIG_MAIN
#include "Catch/Catch.hpp"
#include "../Classes/MemoryTable/MemoryTable.h"

using namespace Prog3;

TEST_CASE("MemoryTable Insert Element", "[MemoryTable]") {
    MemoryTable memoryTable;

    auto cellDescriptor = std::make_shared<MemoryCell>();
    memoryTable.insertElement("Cell", cellDescriptor);
    REQUIRE(memoryTable.findElement("Cell") == cellDescriptor);

    auto vectorDescriptor = std::make_shared<MemoryVector>(5);
    memoryTable.insertElement("Vector", vectorDescriptor);
    REQUIRE(memoryTable.findElement("Vector") == vectorDescriptor);

    auto matrixDescriptor = std::make_shared<MemoryMatrix>(3, 4);
    memoryTable.insertElement("Matrix", matrixDescriptor);
    REQUIRE(memoryTable.findElement("Matrix") == matrixDescriptor);
}

TEST_CASE("MemoryTable Remove Element", "[MemoryTable]") {
    MemoryTable memoryTable;

    auto cellDescriptor = std::make_shared<MemoryCell>();
    memoryTable.insertElement("Cell", cellDescriptor);
    REQUIRE(memoryTable.findElement("Cell") == cellDescriptor);

    memoryTable.removeElement("Cell");
    REQUIRE(memoryTable.findElement("Cell") == nullptr);
}

TEST_CASE("MemoryTable Show Table", "[MemoryTable]") {
    MemoryTable memoryTable;

    auto cellDescriptor = std::make_shared<MemoryCell>();
    memoryTable.insertElement("Cell", cellDescriptor);

    auto vectorDescriptor = std::make_shared<MemoryVector>(5);
    memoryTable.insertElement("Vector", vectorDescriptor);

    auto matrixDescriptor = std::make_shared<MemoryMatrix>(3, 4);
    memoryTable.insertElement("Matrix", matrixDescriptor);

    std::ostringstream stream;
    auto cout_buff = std::cout.rdbuf();
    std::cout.rdbuf(stream.rdbuf());

    memoryTable.showTable();

    std::cout.rdbuf(cout_buff);

    }

TEST_CASE("MemoryTable Compute Total Size", "[MemoryTable]") {
    MemoryTable memoryTable;

    auto cellDescriptor = std::make_shared<MemoryCell>();
    memoryTable.insertElement("Cell", cellDescriptor);

    auto vectorDescriptor = std::make_shared<MemoryVector>(5);
    memoryTable.insertElement("Vector", vectorDescriptor);

    auto matrixDescriptor = std::make_shared<MemoryMatrix>(3, 4);
    memoryTable.insertElement("Matrix", matrixDescriptor);

    REQUIRE(memoryTable.computeTotalSize() == sizeof(int) + 3 * 4 * sizeof(int));
}