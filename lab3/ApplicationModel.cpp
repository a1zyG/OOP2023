#include "ApplicationModel.h"

namespace Prog3 {

    void ApplicationModel::insertIdentifier(const std::string& identifier) {
        application.insertIdentifier(identifier);
    }

    void ApplicationModel::insertDescriptor(const std::string& identifier, std::shared_ptr<Descriptor> element) {
        application.insertDescriptor(identifier, element);
    }

    void ApplicationModel::defineVariable(const std::string& identifier) {
        application.defineVariable(identifier);
    }

    void ApplicationModel::excludeVariable(const std::string& identifier) {
        application.excludeVariable(identifier);
    }

    void ApplicationModel::showShortInfo() const {
        application.showShortInfo();
    }

    std::size_t ApplicationModel::computeTotalSize() const {
        return application.computeTotalSize();
    }

    void ApplicationModel::insertCellInVector(const std::string& identifier, std::shared_ptr<MemoryCell> cell) {
        try {
            application.insertCellInVector(identifier, cell);
        } catch (std::exception& e){
            std::cerr << e.what();
        }
    }

    void ApplicationModel::insertCellInMatrix(const std::string& identifier, std::size_t row, std::size_t col, int num) {
        try {
            application.insertCellInMatrix(identifier, row, col, num);
        } catch (std::exception& e){
            std::cerr << e.what();
        }
    }

}