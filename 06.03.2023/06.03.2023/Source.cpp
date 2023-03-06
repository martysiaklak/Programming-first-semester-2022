#include <iterator>
using namespace std;
class Map 
{

    static class Map* root;

    // Number of elements in the map

    static int n;

    // Left child, right child and parent

    Map *left, *right, *par;



    // First is key, second is value 

    // and depth is height of the subtree 

    // for the given node

    int key, value, depth;
//
//    void insert(int key, int value)
//    {
//
//        Map* temp = iterator(key);
//
//
//        // If element doesnot exist already
//
//        if (temp == nullptr)
//
//            insert(key)->value = value;
//
//
//
//        // If element exists already update it
//
//        else
//
//            temp->value = value;
//    }
//


    Map* insert(int first)
    {

        // Increase the number of elements

        n++;

        Map* newnode = create(first);


        // If empty tree simply create the root

        if (root == nullptr) {

            root = newnode;

            return root;

        }

        Map* temp = root, * prev = nullptr;

        while (temp != nullptr) {

            prev = temp;

            if (first < temp->first)

                temp = temp->left;

            else if (first > temp->first)

                temp = temp->right;

            else {

                free(newnode);


                // If element already exists

                // decrease the count

                cnt--;


                // If the key is found then it is

                // returned by reference so that it is

                // updatable

                return temp;

            }

        }

        if (first < prev->first)

            prev->left = newnode;

        else

            prev->right = newnode;



        newnode->par = prev;


        // Once inserted Check and balance the tree

        // at every node in path from "newnode" to "root"

        balance(newnode);


        // New object is inserted and returned to

        // initialize in the main during assignment

        return newnode;
    }


    int& operator[](int key) {

        return insert(key)->second;
    }

};