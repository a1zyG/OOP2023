#include "MemoryTable.h"

namespace Prog3 {

    void MemoryTable::insertElement(const std::string& identifier, std::shared_ptr<Descriptor> descriptor) {
        auto it = table.find(identifier);
        if(it == table.end()) table[identifier] = descriptor;

    }

    std::shared_ptr<Descriptor> MemoryTable::findElement(const std::string& identifier) const {
        auto it = table.find(identifier);
        if (it != table.end()) {
            return it->second;
        }
        return nullptr;
    }

    void MemoryTable::removeElement(const std::string& identifier) {
        auto it = table.find(identifier);
        if(it != table.end()) table.erase(identifier);
    }

    void MemoryTable::showTable() const {
        for (const auto& entry : table) {
            if (entry.second != nullptr) std::cout << "Identifier: " << entry.first << ", Descriptor: " << entry.second->getDescriptorInfo() << std::endl;
            else std::cout << "Identifier: " << entry.first << ", Descriptor: nullptr" << std::endl;
        }
    }

    std::size_t MemoryTable::computeTotalSize() const {
        std::vector<std::future<std::size_t>> futures;

        for (const auto& entry : table) {
            futures.emplace_back(std::async([&entry] {
                if(entry.second != nullptr) return entry.second->getDescriptorSize();
                else return std::size_t(0);
            }));
        }

        std::vector<std::size_t> sizes;
        for (auto& future : futures) {
            sizes.push_back(future.get());
        }

        return std::accumulate(sizes.begin(), sizes.end(), 0);
    }

}
