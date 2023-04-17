#pragma once
#include <iostream>

constexpr auto VERYBIGINT = 1000000000;

constexpr auto SIZE = 20;

class Graph {
public:
    Graph();
    void addPerson(const std::string name); // �������� ��������
    void addFriend(int pers1, int pers2); // ��������� ������
    bool friendExists(int pers1, int pers2); // ��������� ������� ������
    bool personExists(const std::string name); // ������� ����������� �������� � �����
    size_t findPersonByName(const std::string name);
    std::string findPersonByIndex(int index);
    size_t getPersonsCount() const;
    size_t findCouplesThroughThreeHandshakes(int from, int to);
    void findMinWayInner(int current, int to, bool* visited, size_t& min, int currentDistance);

private:
    struct Person
    {
        std::string name;
    };
    int friendMatrix[SIZE][SIZE]; // ������� ���������� ��������� ����� ����� ������
    Person persons[SIZE]; // ��������� ���� �����
    size_t personsCount; // ���������� ����������� �����


};