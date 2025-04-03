#include "Application.h"

namespace Prog3 {

    void Application::insertIdentifier(const std::string& identifier) {
        if (memoryTable.findElement(identifier) == nullptr) {
            memoryTable.insertElement(identifier, nullptr);
        }
    }

    void Application::insertDescriptor(const std::string& identifier, std::shared_ptr<Descriptor> element){
        if(memoryTable.findElement(identifier) == nullptr){
            memoryTable.insertElement(identifier, element);
        }
    }

    void Application::defineVariable(const std::string& identifier) {
        auto element = memoryTable.findElement(identifier);
        if(element != nullptr){
            element -> setDefined();
        }
    }

    void Application::excludeVariable(const std::string& identifier) {
        memoryTable.removeElement(identifier);
    }

    void Application::showShortInfo() const {
        memoryTable.showTable();
    }

    std::size_t Application::computeTotalSize() const {
        return memoryTable.computeTotalSize();
    }

    void Application::insertCellInVector(const std::string& identifier, std::shared_ptr<MemoryCell> cell){
        auto element = memoryTable.findElement(identifier);
        if(dynamic_cast<MemoryVector*>(element.get()) != nullptr) dynamic_cast<MemoryVector*>(element.get()) -> push_back(cell);
        else throw std::invalid_argument("Invalid Identifier");
    }

    void Application::insertCellInMatrix(const std::string& identifier, std::size_t row, std::size_t col, int num){
        auto element = memoryTable.findElement(identifier);
        if(dynamic_cast<MemoryMatrix*>(element.get()) != nullptr) dynamic_cast<MemoryMatrix*>(element.get()) -> setData(row, col, num);
        else throw std::invalid_argument("Invalid Identifier");
    }

}