#include "HeroTable.h"

HeroTable::HeroTable() : data(nullptr), size(0) {}

void HeroTable::freeAll() {
    for (int i = 0; i < size; ++i) delete data[i];
    delete[] data;
    data = nullptr;
    size = 0;
}

HeroTable::HeroTable(const HeroTable& other) : data(nullptr), size(0) {
    if (other.size == 0) return;

    data = new BaseHero*[other.size];
    size = other.size;
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i]->clone();
    }
}

HeroTable& HeroTable::operator=(const HeroTable& other) {
    if (this == &other) return *this;
    freeAll();

    if (other.size == 0) return *this;

    data = new BaseHero*[other.size];
    size = other.size;
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i]->clone();
    }
    return *this;
}

HeroTable::~HeroTable() {
    freeAll();
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
    if (size == 0) std::exit(1);
    if (index < 0) index = 0;
    if (index >= size) index = size - 1;
    return *data[index];
}

const BaseHero& HeroTable::operator[](int index) const {
    if (size == 0) std::exit(1);
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
