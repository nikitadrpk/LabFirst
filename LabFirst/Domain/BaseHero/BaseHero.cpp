#include "BaseHero.h"

BaseHero::BaseHero()
    : name("Unknown"), heroClass("None"), itemInHand("Empty") {}

BaseHero::BaseHero(const BaseHero& other)
    : name(other.name), heroClass(other.heroClass), itemInHand(other.itemInHand) {}

BaseHero::BaseHero(const char* name, const char* heroClass, const char* itemInHand)
    : name(name), heroClass(heroClass), itemInHand(itemInHand) {}

BaseHero::~BaseHero() = default;

const char* BaseHero::getName() const { return name.c_str(); }
const char* BaseHero::getHeroClass() const { return heroClass.c_str(); }
const char* BaseHero::getItemInHand() const { return itemInHand.c_str(); }

void BaseHero::setName(const char* name) { this->name.set(name); }
void BaseHero::setHeroClass(const char* heroClass) { this->heroClass.set(heroClass); }
void BaseHero::setItemInHand(const char* itemInHand) { this->itemInHand.set(itemInHand); }

BaseHero& BaseHero::operator=(const BaseHero& other) {
    if (this != &other) {
        name = other.name;
        heroClass = other.heroClass;
        itemInHand = other.itemInHand;
    }
    return *this;
}

void BaseHero::print(std::ostream& os) const {
    os << name << " | " << heroClass << " | " << itemInHand;
}
