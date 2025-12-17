#include "HeroController.h"

void HeroController::addHero(const BaseHero& hero) { table.add(hero); }
void HeroController::removeHero(int index) { table.removeAt(index); }
void HeroController::updateHero(int index, const BaseHero& hero) { table.updateAt(index, hero); }

const HeroTable& HeroController::getTable() const { return table; }