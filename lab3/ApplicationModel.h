
#ifndef KLAB3_APPLICATIONMODEL_H
#define KLAB3_APPLICATIONMODEL_H

#include "../../Classes/Application/Application.h"

namespace Prog3 {

    class ApplicationModel {
    private:
        Application application;

    public:
        void insertIdentifier(const std::string& identifier);
        void insertDescriptor(const std::string& identifier, std::shared_ptr<Descriptor> element);
        void defineVariable(const std::string& identifier);
        void excludeVariable(const std::string& identifier);
        void showShortInfo() const;
        [[nodiscard]] std::size_t computeTotalSize() const;
        void insertCellInVector(const std::string& identifier, std::shared_ptr<MemoryCell> cell);
        void insertCellInMatrix(const std::string& identifier, std::size_t row, std::size_t col, int num);
    };

}

#endif //KLAB3_APPLICATIONMODEL_H
