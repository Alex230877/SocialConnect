#include "Graph.h"

Graph::Graph()
{
    for (size_t i = 0; i < SIZE; i++) {
        for (size_t j = 0; j < SIZE; j++)
            friendMatrix[i][j] = 0;
    }
    personsCount = 1;
}

void Graph::addPerson(const std::string name)
{
    persons[personsCount++].name = name;
}

void Graph::addFriend(int pers1, int pers2)
{
    friendMatrix[pers1][pers2] = 1;
    friendMatrix[pers2][pers1] = 1;
}

bool Graph::friendExists(int pers1, int pers2)
{
    return friendMatrix[pers1][pers2] > 0;
}

bool Graph::personExists(const std::string name)
{
    for (size_t i = 0; i < personsCount; i++)
    {
        if (persons[i].name == name)
            return true;
    }
    return false;
}

size_t Graph::findPersonByName(const std::string name)
{
    for (size_t i = 0; i < personsCount; i++)
    {
        if (persons[i].name == name)
            return i;
    }
    return -1;
}

std::string Graph::findPersonByIndex(int index)
{
    return persons[index].name;
}

size_t Graph::findCouplesThroughThreeHandshakes(int from, int to) // �������� ������ ���� ��� ��������� ����� ��� ����������� �� ������ ��������� ������ � �������
{
    bool visited[SIZE]{}; // ������ ���������� ������
    for (int i = 0; i < SIZE; i++)
        visited[i] = false;
    size_t min = VERYBIGINT; // ��������� ����������� ����������
    int currentDistance = 0;

    findMinWayInner(from, to, visited, min, currentDistance);
    return min;
}

void Graph::findMinWayInner(int current, int to, bool* visited, size_t& min, int currentDistance)
{
    if (current == to)
    {
        // ���� ������ � ������� �������, ���������� ������� ���� � �����������
        if (min > currentDistance)
        {
            // ���� ����� ���������� ������, ����������
            min = currentDistance;
        }
        return;
    }
    visited[current] = true; // ��������� ������� ����������
    for (int i = 0; i < SIZE; i++)
    {
        if (friendExists(current, i) && !visited[i])
        {
            // ��������� �������� ��� ���� ������������ ������� ������
            int newDist = currentDistance + friendMatrix[current][i];
            findMinWayInner(i, to, visited, min, newDist);
        }
    }
    // ��������, ��� ���� ��� �� �������� ��� �������
    visited[current] = false;
}

size_t Graph::getPersonsCount() const
{
    return personsCount;
}