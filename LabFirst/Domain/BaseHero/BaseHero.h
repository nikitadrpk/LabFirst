#pragma once
#include <string>
#include <ostream>
#include "../MyString.h"


class BaseHero {
protected:
    MyString name;
    MyString heroClass;
    MyString itemInHand;

public:
    BaseHero();
    BaseHero(const BaseHero& other);
    BaseHero(const char* name, const char* heroClass, const char* itemInHand);
    virtual ~BaseHero();
    
    const char* getName() const;
    const char* getHeroClass() const;
    const char* getItemInHand() const; 

    void setName(const char* name);
    void setHeroClass(const char* heroClass);
    void setItemInHand(const char* itemInHand);

    BaseHero& operator=(const BaseHero& other);
    
    virtual void print(std::ostream& os) const;
    virtual BaseHero* clone() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const BaseHero& hero) {
        hero.print(os);
        return os;
    }
};
