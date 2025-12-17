#include "HeroTable.h"

HeroTable::HeroTable() : data(nullptr), size(0) {}

HeroTable::~HeroTable() {
    for (int i = 0; i < size; ++i) delete data[i];
    delete[] data;
}

int HeroTable::getCount() const { return size; }

void HeroTable::add(const BaseHero& hero) {
    BaseHero** newData = new BaseHero*[size + 1];
    for (int i = 0; i < size; ++i) newData[i] = data[i];
    newData[size] = hero.clone();    
    delete[] data;
    data = newData;
    ++size;
}

void HeroTable::removeAt(int index) {
    if (index < 0 || index >= size) return;

    delete data[index];

    if (size == 1) {
        delete[] data;
        data = nullptr;
        size = 0;
        return;
    }

    BaseHero** newData = new BaseHero*[size - 1];
    int j = 0;
    for (int i = 0; i < size; ++i) {
        if (i == index) continue;
        newData[j++] = data[i];
    }
    delete[] data;
    data = newData;
    --size;
}

void HeroTable::updateAt(int index, const BaseHero& hero) {
    if (index < 0 || index >= size) return;
    delete data[index];
    data[index] = hero.clone();
}

BaseHero& HeroTable::operator[](int index) {
    if (size == 0) *(int*)0 = 0;
    if (index < 0) index = 0;
    if (index >= size) index = size - 1;
    return *data[index];
}

const BaseHero& HeroTable::operator[](int index) const {
    if (size == 0) *(int*)0 = 0;
    if (index < 0) index = 0;
    if (index >= size) index = size - 1;
    return *data[index];
}

std::ostream& operator<<(std::ostream& os, const HeroTable& table) {
    os << "HeroTable: " << table.size << " record(s)\n";
    for (int i = 0; i < table.size; ++i) {
        os << "[" << i << "] " << *table.data[i] << "\n";
    }
    return os;
}