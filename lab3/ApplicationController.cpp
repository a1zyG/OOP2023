#include "ApplicationController.h"

namespace Prog3{

    void ApplicationController::handleMainMenu() {
        std::string userInput;

        while (true) {
            ApplicationView::printMainMenu();
            ApplicationView::getUserInput(userInput);

            if (userInput == "1") {
                std::string identifier;
                std::cout << "Enter identifier: ";
                std::getline(std::cin, identifier);
                model.insertIdentifier(identifier);
            } else if (userInput == "2") {
                std::string identifier;
                std::shared_ptr<Descriptor> element;

                ApplicationView::getUserInput(element);

                std::cout << "Enter identifier: ";
                std::getline(std::cin, identifier);

                model.insertDescriptor(identifier, element);
            } else if (userInput == "3") {
                std::string identifier;
                std::cout << "Enter identifier: ";
                std::getline(std::cin, identifier);
                model.defineVariable(identifier);
            } else if (userInput == "4") {
                std::string identifier;
                std::cout << "Enter identifier: ";
                std::getline(std::cin, identifier);
                model.excludeVariable(identifier);
            } else if (userInput == "5") {
                model.showShortInfo();
            } else if (userInput == "6") {
                std::cout << "Total Size: " << model.computeTotalSize() << " bytes" << std::endl;
            } else if (userInput == "7") {
                std::string identifier;
                std::shared_ptr<MemoryCell> cell;

                std::cout << "Enter identifier: ";
                std::getline(std::cin, identifier);

                ApplicationView::getUserInput(cell);

                model.insertCellInVector(identifier, cell);
            } else if (userInput == "8") {
                std::string identifier;
                std::size_t row, col;
                int num;

                std::cout << "Enter identifier: ";
                std::getline(std::cin, identifier);

                ApplicationView::getUserInput(row, col);
                ApplicationView::getUserInput(num);

                model.insertCellInMatrix(identifier, row, col, num);
            } else if (userInput == "0") {
                break;
            } else {
                std::cout << "Invalid input. Try again." << std::endl;
            }
        }
    }
}