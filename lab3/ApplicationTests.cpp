#define CATCH_CONFIG_MAIN
#include "Catch/Catch.hpp"
#include "../Classes/Application/Application.h"

using namespace Prog3;

TEST_CASE("Application Insert Identifier", "[Application]") {
    Application application;

    application.insertIdentifier("Variable1");
    REQUIRE(application.computeTotalSize() == 0);

    application.insertIdentifier("Variable2");
    REQUIRE(application.computeTotalSize() == 0);

    application.insertIdentifier("Variable1"); // Duplicate insertion
    REQUIRE(application.computeTotalSize() == 0);
}

TEST_CASE("Application Insert Descriptor", "[Application]") {
    Application application;

    auto cellDescriptor = std::make_shared<MemoryCell>();
    application.insertDescriptor("Cell", cellDescriptor);
    REQUIRE(application.computeTotalSize() == sizeof(int));

    auto vectorDescriptor = std::make_shared<MemoryVector>(5);
    application.insertDescriptor("Vector", vectorDescriptor);
    REQUIRE(application.computeTotalSize() == sizeof(int));

    auto matrixDescriptor = std::make_shared<MemoryMatrix>(3, 4);
    application.insertDescriptor("Matrix", matrixDescriptor);
    REQUIRE(application.computeTotalSize() == sizeof(int) + 3 * 4 * sizeof(int));
}

TEST_CASE("Application Define Variable", "[Application]") {
    Application application;

    auto cellDescriptor = std::make_shared<MemoryCell>();
    application.insertDescriptor("Cell", cellDescriptor);

    auto vectorDescriptor = std::make_shared<MemoryVector>(5);
    application.insertDescriptor("Vector", vectorDescriptor);

    auto matrixDescriptor = std::make_shared<MemoryMatrix>(3, 4);
    application.insertDescriptor("Matrix", matrixDescriptor);

    application.defineVariable("Cell");
    application.defineVariable("Vector");
    application.defineVariable("Matrix");

    REQUIRE(cellDescriptor->getDefinition());
    REQUIRE(vectorDescriptor->getDefinition());
    REQUIRE(matrixDescriptor->getDefinition());
}

TEST_CASE("Application Exclude Variable", "[Application]") {
    Application application;

    auto cellDescriptor = std::make_shared<MemoryCell>();
    application.insertDescriptor("Cell", cellDescriptor);

    auto vectorDescriptor = std::make_shared<MemoryVector>(5);
    application.insertDescriptor("Vector", vectorDescriptor);

    auto matrixDescriptor = std::make_shared<MemoryMatrix>(3, 4);
    application.insertDescriptor("Matrix", matrixDescriptor);

    application.excludeVariable("Cell");
    REQUIRE(application.computeTotalSize() == 3 * 4 * sizeof(int));

    application.excludeVariable("Vector");
    REQUIRE(application.computeTotalSize() == 3 * 4 * sizeof(int));

    application.excludeVariable("NonexistentVariable");
    REQUIRE(application.computeTotalSize() == 3 * 4 * sizeof(int)); // No change
}

TEST_CASE("Application Show Short Info", "[Application]") {
    Application application;

    auto cellDescriptor = std::make_shared<MemoryCell>();
    application.insertDescriptor("Cell", cellDescriptor);

    auto vectorDescriptor = std::make_shared<MemoryVector>(5);
    application.insertDescriptor("Vector", vectorDescriptor);

    auto matrixDescriptor = std::make_shared<MemoryMatrix>(3, 4);
    application.insertDescriptor("Matrix", matrixDescriptor);

    std::ostringstream stream;
    auto cout_buff = std::cout.rdbuf();
    std::cout.rdbuf(stream.rdbuf());

    application.showShortInfo();

    std::cout.rdbuf(cout_buff);
}

TEST_CASE("Application Insert Cell In Vector", "[Application]") {
    Application application;

    auto vectorDescriptor = std::make_shared<MemoryVector>(5);
    application.insertDescriptor("Vector", vectorDescriptor);

    auto cell1 = std::make_shared<MemoryCell>();
    application.insertCellInVector("Vector", cell1);
    REQUIRE(vectorDescriptor->size() == 1);
    REQUIRE(application.computeTotalSize() == 1 * sizeof(int));

    auto cell2 = std::make_shared<MemoryCell>();
    application.insertCellInVector("Vector", cell2);
    REQUIRE(vectorDescriptor->size() == 2);
    REQUIRE(application.computeTotalSize() == 2 * sizeof(int));
}

TEST_CASE("Application Insert Cell In Matrix", "[Application]") {
    Application application;

    auto matrixDescriptor = std::make_shared<MemoryMatrix>(3, 4);
    application.insertDescriptor("Matrix", matrixDescriptor);

    application.insertCellInMatrix("Matrix", 1, 2, 42);
    REQUIRE(matrixDescriptor->getData(1, 2) == 42);
    REQUIRE(application.computeTotalSize() == 3 * 4 * sizeof(int));
}
