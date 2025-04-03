#include "MemoryCell.h"

namespace Prog3 {

    MemoryCell::MemoryCell() : Descriptor(), data(0) {}

    MemoryCell::MemoryCell(int num) : Descriptor(), data(num) {}

    MemoryCell::MemoryCell(int num, bool definition) : Descriptor(definition), data(num){}

    MemoryCell::MemoryCell(const MemoryCell& other) : Descriptor(other.IsDefined), data(other.data) {}

    MemoryCell::MemoryCell(MemoryCell&& other) noexcept : Descriptor(other.IsDefined), data(other.data){
        other.IsDefined = false;
    }

    MemoryCell& MemoryCell::operator=(const MemoryCell& other) {
        if (this != &other) {
            data = other.data;
            IsDefined = other.IsDefined;
        }
        return *this;
    }

    MemoryCell& MemoryCell::operator=(MemoryCell&& other) noexcept {
        if (this != &other) {
            data = other.data;
            IsDefined = other.IsDefined;
            other.IsDefined = false;
        }
        return *this;
    }

    Descriptor::DescriptorType MemoryCell::getType() const {
        return DescriptorType::CELL;
    }

    [[nodiscard]] std::size_t MemoryCell::getDescriptorSize() const {
        return sizeof(int);
    }

    std::string MemoryCell::getDescriptorInfo() const {
        return "Memory Cell: Data - " + std::to_string(data) + ", Defined - " + (IsDefined ? "true" : "false");
    }

    int MemoryCell::getData() const {
        return data;
    }

    void MemoryCell::setData(int newData) {
        data = newData;
    }

    void MemoryCell::setDefined(){
        IsDefined = true;
    }

    void MemoryCell::setDefinition(bool defined){
        IsDefined = defined;
    }

    bool MemoryCell::getDefinition() const {
        return IsDefined;
    }

    void MemoryCell::changeDefinition(){
        IsDefined = !IsDefined;
    }

}