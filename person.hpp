#pragma once

class Person
{
private:
    char *firstname;
    char *lastname;
    int age;
    int number;
    int series;

public:
    int getAge()
    {
        return this->age;
    }

    int getNumber()
    {
        return this->number;
    }

    int getSeries()
    {
        return this->series;
    }

    char* getFirstname()
    {
        return this->firstname;
    }

    char* getLastname()
    {
        return this->lastname;
    }
};