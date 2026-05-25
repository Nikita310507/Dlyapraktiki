#pragma once

#include <iostream>

using namespace std;

template <class T>
class MyList
{
    class Node
    {
    public:

        T info;
        Node* next;

        Node()
        {
            next = NULL;
        }

        Node(T info, Node* next = NULL)
        {
            this->info = info;
            this->next = next;
        }

        friend ostream& operator<<(ostream& os,
            Node* n)
        {
            return os << n->info;
        }
    };

public:

    Node* head;
    Node* tail;

    MyList()
    {
        head = NULL;
        tail = NULL;
    }

    ~MyList()
    {
        Node* current = head;

        while (current != NULL)
        {
            Node* next = current->next;

            delete current;

            current = next;
        }
    }

    // добавление в конец
    void addEnd(T t)
    {
        Node* newNode = new Node(t);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // добавление в начало
    void addBegin(T t)
    {
        Node* newNode = new Node(t);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    // удаление
    bool deleteNode(T del)
    {
        if (head == NULL)
            return false;

        if (head->info == del)
        {
            Node* temp = head;

            head = head->next;

            if (head == NULL)
                tail = NULL;

            delete temp;

            return true;
        }

        Node* prev = head;
        Node* curr = head->next;

        while (curr != NULL &&
            !(curr->info == del))
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL)
            return false;

        prev->next = curr->next;

        if (curr == tail)
            tail = prev;

        delete curr;

        return true;
    }

    // вставка по порядку
    void addOrdered(T t)
    {
        Node* newNode = new Node(t);

        if (head == NULL ||
            t < head->info)
        {
            newNode->next = head;

            head = newNode;

            if (tail == NULL)
                tail = head;
        }
        else
        {
            Node* curr = head;

            while (curr->next != NULL &&
                curr->next->info < t)
            {
                curr = curr->next;
            }

            newNode->next = curr->next;

            curr->next = newNode;

            if (newNode->next == NULL)
                tail = newNode;
        }
    }

    // поиск
    Node* find(T value)
    {
        Node* temp = head;

        while (temp != NULL)
        {
            if (temp->info == value)
                return temp;

            temp = temp->next;
        }

        return NULL;
    }

    // пуст ли список
    bool isEmpty() const
    {
        return head == NULL;
    }

    friend ostream& operator<<(ostream& os,
        const MyList& list)
    {
        Node* node = list.head;

        while (node != NULL)
        {
            os << node->info << "\n";

            node = node->next;
        }

        return os;
    }
};