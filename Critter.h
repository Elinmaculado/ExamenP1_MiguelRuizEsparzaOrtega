#pragma once
#include <iostream>

using namespace std;

class Critter
{
public:
    Critter(int hunger = 0, int boredom = 0, int m_Thirst = 0);
    void Talk();
    void Eat(int food = 4);
    void Play(int fun = 4);
    void Drink(int water = 4);
    void DisplayStatus();

private:
    int m_Hunger;
    int m_Boredom;
    int m_Thirst;
    void PassTime(int time = 1);
};