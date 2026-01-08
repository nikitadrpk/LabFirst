#include "AssasinHero.h"

AssasinHero::AssasinHero()
    : BaseHero("Unknown", "Assasin", "Dagger"),
      stealthLevel(0),
      hasPoison(false) {}

AssasinHero::AssasinHero(const AssasinHero& other)
    : BaseHero(other),
      stealthLevel(other.stealthLevel),
      hasPoison(other.hasPoison) {}

AssasinHero::AssasinHero(const char* name,
                         const char* itemInHand,
                         int stealthLevel,
                         bool hasPoison)
    : BaseHero(name, "Assasin", itemInHand),
      stealthLevel(stealthLevel),
      hasPoison(hasPoison) {}

AssasinHero::~AssasinHero() = default;

int AssasinHero::getStealthLevel() const { return stealthLevel; }
bool AssasinHero::getHasPoison() const { return hasPoison; }

void AssasinHero::setStealthLevel(int stealthLevel) { this->stealthLevel = stealthLevel; }
void AssasinHero::setHasPoison(bool hasPoison) { this->hasPoison = hasPoison; }

AssasinHero& AssasinHero::operator=(const AssasinHero& other) {
    if (this != &other) {
        BaseHero::operator=(other);
        stealthLevel = other.stealthLevel;
        hasPoison = other.hasPoison;
    }
    return *this;
}

void AssasinHero::print(std::ostream& os) const {
    BaseHero::print(os);
    os << " | Stealth: " << stealthLevel
       << " | Poison: " << (hasPoison ? "Yes" : "No");
}

BaseHero* AssasinHero::clone() const {
    return new AssasinHero(*this);
}
