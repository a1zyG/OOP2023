#include "MemoryVector.h"

namespace Prog3 {

    MemoryVector::MemoryVector(int maxSize) : Descriptor(true), maxSize(maxSize),
    data(std::make_shared<std::vector<std::shared_ptr<MemoryCell>>>(std::vector<std::shared_ptr<MemoryCell>>{})) {}

    MemoryVector::MemoryVector(std::shared_ptr<MemoryCell> cell, std::size_t maxSize) : MemoryVector(maxSize){
        push_back(cell);
    }

    MemoryVector::MemoryVector(MemoryVector&& other) noexcept : Descriptor(other.IsDefined), data(std::move(other.data)), maxSize(other.maxSize) {
        other.IsDefined = false;
    }

    [[nodiscard]] std::size_t MemoryVector::getDescriptorSize() const {
        return size() * sizeof(int);
    }

    MemoryVector& MemoryVector::operator=(MemoryVector&& other) noexcept {
        if (this != &other) {
            data = std::move(other.data);
            maxSize = other.maxSize;
            IsDefined = other.IsDefined;
            other.IsDefined = false;  // После перемещения оставляем исходный объект неопределенным
        }
        return *this;
    }

    Descriptor::DescriptorType MemoryVector::getType() const {
        return DescriptorType::VECTOR;
    }

    std::string MemoryVector::getDescriptorInfo() const {
        std::stringstream ss;
        ss << "Memory Vector: Size - " + std::to_string(size()) + ", MaxSize - " + std::to_string(maxSize) +
               ", Defined - " + (getDefinition() ? "true\n" : "false\n");
        for(const auto& it: *data){
            ss << it -> getDescriptorInfo();
        }
        return ss.str();
    }

    std::size_t MemoryVector::size() const{
        if(data != nullptr) return data->size();
        else throw std::runtime_error("Vector was moved");
    }

    std::size_t MemoryVector::getMaxSize() const{
        return maxSize;
    }

    bool MemoryVector::getDefinition() const{
        return IsDefined;
    }

    bool MemoryVector::checkDefined() const {
        for (const auto& cell : *data) {
            if (!cell->getDefinition()) {
                return false;
            }
        }
        return true;
    }

    void MemoryVector::setMaxSize() {
        data->resize(maxSize, std::make_shared<MemoryCell>());
        IsDefined = checkDefined();
    }

    void MemoryVector::setData(int index) {
        if (index >= 0 && index < size()) {
            (*data)[index]->setDefinition(true);
        }
        else throw std::invalid_argument("Invalid index");
    }

    int MemoryVector::getData(int index) const {
        if (index >= 0 && index < size()) {
            return (*data)[index]->getData();
        }
        throw std::invalid_argument("Invalid index");
    }

    std::shared_ptr<MemoryCell>& MemoryVector::operator[](int i) {
        if (i >= 0 && i < size()) {
            return (*data)[i];
        }
        throw std::invalid_argument("Invalid index");
    }

    const std::shared_ptr<MemoryCell>& MemoryVector::operator[](int i) const {
        if (i >= 0 && i < size()) {
            return (*data)[i];
        }
        throw std::invalid_argument("Invalid index");
    }

    void MemoryVector::push_back(std::shared_ptr<MemoryCell> cell){
        if(size() < maxSize){
            data -> push_back(cell);
            if(!cell -> getDefinition()) IsDefined = false;
        }
        else throw std::runtime_error("Vector is full already");
    }

    void MemoryVector::setDefined(){
        for(int i = 0; i < size(); i++){
            data -> operator[](i) -> setDefined();
        }
        IsDefined = true;
    }

}