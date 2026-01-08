#pragma once
#include "../HeroTable/HeroTable.h"

class HeroController {
private:
    HeroTable table;

public:
    void addHero(const BaseHero& hero) { table.add(hero); }
    void removeHero(int index) { table.removeAt(index); }
    void updateHero(int index, const BaseHero& hero) { table.updateAt(index, hero); }

    int count() const { return table.getCount(); }

    HeroTable& getTableMutable() { return table; }       
    const HeroTable& getTable() const { return table; }
};
