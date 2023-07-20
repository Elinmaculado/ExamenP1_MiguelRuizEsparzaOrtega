#include <iostream>
#include "Critter.h"

using namespace std;

Critter::Critter(int hunger, int boredom, int thirst) :
    m_Hunger(hunger),
    m_Boredom(boredom),
    m_Thirst(thirst)
{}


void Critter::PassTime(int time)
{
    m_Hunger += time;
    m_Boredom += time;
    m_Thirst += time;
}

void Critter::Talk()
{
    //Hambre
    if (m_Hunger <= 5)
    {
        cout << "estoy bien de hambre" << endl;
    }
    else if (m_Hunger > 5 && m_Hunger < 10)
    {
        cout << "Tengo algo de hambre, podria comer ahorita" << endl;
    }
    else if (m_Hunger >= 10 && m_Hunger <= 15)
    {
        cout << "Tengo demasiada hambre, por favor dame comida" << endl;
    }
    else if (m_Hunger > 15)
    {
        cout << "mori de hambre, espero que estes feliz" << endl;
        return; //como ya murio no hay necesida de leer los demas valores
    }

    //Diversion
    if (m_Boredom <= 5)
    {
        cout << "estoy entretenido" << endl;
    }
    else if (m_Boredom > 5 && m_Boredom < 10)
    {
        cout << "Estoy muy aburrido, vamos a jugar" << endl;
    }
    else if (m_Boredom >= 10 && m_Boredom <= 15)
    {
        cout << "Estoy demasiado aburrido, tienes que jugar conmigo" << endl;
    }
    else if (m_Boredom > 15)
    {
        cout << "Tu mascota se escapo por que estaba aburrida, jamas la volveras a ver" << endl;
        return;
    }

    //Sed
    if (m_Thirst <= 5)
    {
        cout << "Estoy bien hidratado" << endl;
    }
    else if (m_Thirst > 5 && m_Thirst < 10)
    {
        cout << "Tengo  sed, por favor dame agua" << endl;
    }
    else if (m_Thirst >= 10 && m_Thirst <= 15)
    {
        cout << "Tengo demasiada sed, necesito agua ahorita" << endl;
    }
    else if (m_Thirst >= 15)
    {
        cout << "Tu mascota murio por deshidratacion, bien hecho campeon" << endl;
        return;
    }
    PassTime();
}

void Critter::Eat(int food)
{
    cout << "\nBrrupp. \n";
    m_Hunger -= food;
    if (m_Hunger < 0)
    {
        m_Hunger = 0;
    }
    PassTime();
}

void Critter::Play(int fun)
{
    cout << "\nWheee!\n";
    m_Boredom -= fun;
    if (m_Boredom < 0)
    {
        m_Boredom = 0;
    }
    PassTime();
}

void Critter::Drink(int water)
{
    cout << "\ngluc gluc.\n";
    m_Thirst -= water;
    if (m_Thirst < 0)
    {
        m_Thirst = 0;
    }
    PassTime();
}

void Critter::DisplayStatus()
{
    cout << "El estado de tu mascota es:" << endl;
    cout << "Hambre: " << m_Hunger << endl;
    cout << "Aburrimiento: " << m_Boredom << endl;
    cout << "Sed: " << m_Thirst << endl;
}
