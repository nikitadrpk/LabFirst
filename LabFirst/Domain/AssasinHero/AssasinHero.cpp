#include "AssasinHero.h"

AssasinHero::AssasinHero()
    : BaseHero("Unknown", "Assasin", "Dagger"),
      stealthLevel(0),
      hasPoison(false)
{
}

AssasinHero::AssasinHero(const AssasinHero& other)
    : BaseHero(other),
      stealthLevel(other.stealthLevel),
      hasPoison(other.hasPoison)
{
}

AssasinHero::AssasinHero(const std::string& name,
                         const std::string& itemInHand,
                         int stealthLevel,
                         bool hasPoison)
    : BaseHero(name, "Assasin", itemInHand),
      stealthLevel(stealthLevel),
      hasPoison(hasPoison)
{
}

AssasinHero::~AssasinHero() {}

int AssasinHero::getStealthLevel() const {
    return stealthLevel;
}

bool AssasinHero::getHasPoison() const {
    return hasPoison;
}

void AssasinHero::setStealthLevel(int stealthLevel) {
    this->stealthLevel = stealthLevel;
}

void AssasinHero::setHasPoison(bool hasPoison) {
    this->hasPoison = hasPoison;
}

AssasinHero& AssasinHero::operator=(const AssasinHero& other) {
    if (this != &other) {
        BaseHero::operator=(other);
        stealthLevel = other.stealthLevel;
        hasPoison = other.hasPoison;
    }
    return *this;
}

BaseHero* AssasinHero::clone() const {
    return new AssasinHero(*this);
}

std::ostream& operator<<(std::ostream& os, const AssasinHero& hero) {
    os << static_cast<const BaseHero&>(hero)
       << " | Stealth: " << hero.stealthLevel
       << " | Poison: " << (hero.hasPoison ? "Yes" : "No");
    return os;
}