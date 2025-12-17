#include "BaseHero.h"


BaseHero::BaseHero()
    : name("Unknown"),
      heroClass("None"),
      itemInHand("Empty")
{
}

BaseHero::BaseHero(const BaseHero& other)
    : name(other.name),
      heroClass(other.heroClass),
      itemInHand(other.itemInHand)
{
}

BaseHero::BaseHero(const std::string& name,
                   const std::string& heroClass,
                   const std::string& itemInHand)
    : name(name),
      heroClass(heroClass),
      itemInHand(itemInHand)
{
}

BaseHero::~BaseHero() {}

std::string BaseHero::getName() const {
    return name;
}

std::string BaseHero::getHeroClass() const {
    return heroClass;
}

std::string BaseHero::getItemInHand() const {
    return itemInHand;
}

void BaseHero::setName(const std::string& name) {
    this->name = name;
}

void BaseHero::setHeroClass(const std::string& heroClass) {
    this->heroClass = heroClass;
}

void BaseHero::setItemInHand(const std::string& itemInHand) {
    this->itemInHand = itemInHand;
}

BaseHero& BaseHero::operator=(const BaseHero& other) {
    if (this != &other) {
        name = other.name;
        heroClass = other.heroClass;
        itemInHand = other.itemInHand;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const BaseHero& hero) {
    os << hero.name << " | "
       << hero.heroClass << " | "
       << hero.itemInHand;
    return os;
}
