#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <math.h>
#include <string>
using namespace std;

class Row {
    Row() {
    }
    void SetFrom(const Row& other) {
        this->Key = other.Key;
        this->Name = other.Name;
        this->Surname = other.Surname;
    }
public:
    int Key;
    string Name;
    string Surname;
    Row(int key, string name, string surname) :
        Key(key), Name(name), Surname(surname) {
    }
    Row(const Row& other) {
        SetFrom(other);
    }

    Row& operator =(const Row& other) {
        SetFrom(other);
        return *this;
    }
    bool operator ==(const Row& other) {
        bool result;
        result = this->Key == other.Key;
        return result;
    }
    bool operator <(const Row& other) {
        bool result;
        result = this->Key < other.Key;
        return result;
    }
};

class Node {
    Node() :
        Element(1, "", "") {

    }
public:
    Row Element;
    Node* LeftSon;
    Node* RightSon;
    Node(Row element) : Element(element) {
        LeftSon = nullptr;
        RightSon = nullptr;
    }
};

class SimpleTable {
    Node* root = nullptr;

    Node* FindNode(const Row& key, Node* parent_node) {
        Node* result = nullptr;
        if (parent_node != nullptr) {
            if (parent_node->Element == key) {
                result = parent_node;
            }
            else {
                if (parent_node->Element < key) {

                    // if( parent_node->RightSon == nullptr)
                    //parent_node->RightSon = new Node(row)
                    result = FindNode(key, parent_node->RightSon);
                }
                else {
                    result = FindNode(key, parent_node->LeftSon);
                }
            }
        }
        return result;
    }
public:
    bool Find(int key, Row& row) {
        bool result = false;
        Node* node;
        node = FindNode(Row(key, "", ""), root);
        if (node != nullptr) {
            row = node->Element;
            result = true;
        }
        return result;
    }

};


TEST_CASE("Simple table find nonexisting") {
    SimpleTable table;
    Row found_row(1, "", "");
    bool found_result = table.Find(123, found_row);

    CHECK(found_result == false);
}
/*
TEST_CASE("testing stack 2") {
    CHECK(stack.Pop() == 33);
    CHECK(stack.Pop() == 22);
    CHECK(stack.Pop() == 11);
    CHECK(stack.IsEmpty() == true);
}*/