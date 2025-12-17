#pragma once
#include "../HeroTable/HeroTable.h"

class HeroController {
private:
    HeroTable table;

public:
    void addHero(const BaseHero& hero);
    void removeHero(int index);
    void updateHero(int index, const BaseHero& hero);

    const HeroTable& getTable() const;
};

