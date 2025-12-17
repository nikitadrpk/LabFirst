#pragma once
#include <ostream>
#include "../../Domain/BaseHero/BaseHero.h"

class HeroTable {
private:
    BaseHero** data;
    int size;

public:
    HeroTable();
    ~HeroTable();

    void add(const BaseHero& hero);
    void removeAt(int index);
    void updateAt(int index, const BaseHero& hero);

    int getCount() const;

    BaseHero& operator[](int index);
    const BaseHero& operator[](int index) const;

    friend std::ostream& operator<<(std::ostream& os, const HeroTable& table);
};