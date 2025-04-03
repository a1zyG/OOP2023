#include "ApplicationView.h"

namespace Prog3{
    void ApplicationView::printMainMenu() {
        std::cout << "1. Insert Identifier" << std::endl;
        std::cout << "2. Insert Descriptor" << std::endl;
        std::cout << "3. Define Variable" << std::endl;
        std::cout << "4. Exclude Variable" << std::endl;
        std::cout << "5. Show Short Information" << std::endl;
        std::cout << "6. Compute Total Size" << std::endl;
        std::cout << "7. Insert Cell In Vector" << std::endl;
        std::cout << "8. Insert Cell In Matrix" << std::endl;
        std::cout << "0. Exit" << std::endl;
    }

    void ApplicationView::printDescriptorMenu() {
        std::cout << "Select Descriptor Type:" << std::endl;
        std::cout << "1. MemoryCell" << std::endl;
        std::cout << "2. MemoryVector" << std::endl;
        std::cout << "3. MemoryMatrix" << std::endl;
        std::cout << "0. Cancel" << std::endl;
    }

    void ApplicationView::getUserInput(std::shared_ptr<Descriptor>& element) {
        std::cout << "Select Descriptor Type:" << std::endl;
        std::cout << "1. MemoryCell" << std::endl;
        std::cout << "2. MemoryVector" << std::endl;
        std::cout << "3. MemoryMatrix" << std::endl;
        std::cout << "0. Cancel" << std::endl;

        std::string userInput;
        std::getline(std::cin, userInput);

        if (userInput == "1") {
            int data;
            std::cout << "Enter data for MemoryCell: ";
            std::cin >> data;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            element = std::make_shared<MemoryCell>(data);
        } else if (userInput == "2") {
            std::size_t maxSize;
            std::cout << "Enter Max size of the vector: ";
            std::cin >> maxSize;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            element = std::make_shared<MemoryVector>(maxSize);
        } else if (userInput == "3") {
            std::size_t rows, cols;
            std::cout << "Enter number of rows: ";
            std::cin >> rows;
            std::cout << "Enter number of columns: ";
            std::cin >> cols;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            element = std::make_shared<MemoryMatrix>(rows, cols);
        } else {
            std::cout << "Canceling insertion." << std::endl;
            element = nullptr;
        }
    }

    void ApplicationView::getUserInput(std::string& userInput) {
        std::cout << "Enter your choice: ";
        std::getline(std::cin, userInput);
    }

    void ApplicationView::getUserInput(std::shared_ptr<MemoryCell>& cell) {
        int data;
        std::cout << "Enter data for MemoryCell: ";
        std::cin >> data;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cell = std::make_shared<MemoryCell>(data);
    }

    void ApplicationView::getUserInput(std::shared_ptr<MemoryVector>& vector) {
        std::size_t maxSize;
        std::cout << "Enter Max size of the vector: ";
        std::cin >> maxSize;
        vector = std::make_shared<MemoryVector>(maxSize);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void ApplicationView::getUserInput(std::shared_ptr<MemoryMatrix>& matrix) {
        std::size_t rows, cols;
        std::cout << "Enter number of rows: ";
        std::cin >> rows;
        std::cout << "Enter number of columns: ";
        std::cin >> cols;
        matrix = std::make_shared<MemoryMatrix>(rows, cols);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void ApplicationView::getUserInput(std::size_t& row, std::size_t& col) {
        std::cout << "Enter row and column indices (space-separated): ";
        std::cin >> row >> col;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void ApplicationView::getUserInput(int& num) {
        std::cout << "Enter data for MemoryMatrix: ";
        std::cin >> num;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}