// T04TBST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
template<typename TypeKey, typename TypeData>
class tree
{
    class node
    {
    public:
        TypeKey Key;
        TypeData Data;
        node *Less, *More;
        node( const TypeKey &NewKey, const TypeData &NewData,
            node* L = nullptr, node* M = nullptr ) : Key(NewKey), Data(NewData), Less(L), More(M)
        {
        }
        ~node( void )
        {
            if (Less != nullptr)
                delete Less;
            if (More != nullptr)
                delete More;
        }
    } *Root;

    public: 
    tree( void ) : Root(nullptr)
    {
    }
    ~tree( void )
    {
        if (Root != nullptr)
            delete Root;
    }
    TypeData *Get( const TypeKey &NewKey )
    {
        node** ptr = &Root;
        while (*ptr != nullptr)
        {
            if ((*ptr)->Key == NewKey)
            {
                std::cout << "Data found: " << (*ptr)->Data << "\n";
                return &(*ptr)->Data;
            }
            else if ((*ptr)->Key < NewKey)
            {
                ptr = &(*ptr)->More;
            }
            else
            {
                ptr = &(*ptr)->Less;
            }
        }
        std::cout << "Data not found\n";
        return nullptr;
    }
    
    TypeData *Set( const TypeKey &NewKey, const TypeData &NewData )
    {
        node** ptr = &Root;
        while (*ptr != nullptr)
        {
            if ((*ptr)->Key == NewKey)
            {
                (*ptr)->Data = NewData;
                std::cout << "Data update\n";
                return &(*ptr)->Data;
            }
            else if ((*ptr)->Key < NewKey)
            {
                ptr = &(*ptr)->More;
            }
            else
            {
                ptr = &(*ptr)->Less;
            }
        }
        *ptr = new node(NewKey, NewData);
        std::cout << "Data added\n";
        return &(*ptr)->Data;
    }
    void PutTree( void )
    {
        NPutTree(Root);
    }
    void NPutTree(node* T) 
    {
        if (T == nullptr)
            std::cout << "*";
        else
        {
            std::cout << T->Key << ":" << T->Data << "(";
            NPutTree(T->Less);
            std::cout << ",";
            NPutTree(T->More);
            std::cout << ")";
        }
    }
};
int main()
{
    tree<std::string, int> vars;
    std::string p1 = "Oleg";
    std::string p2 = "Edik";
    std::string p3 = "Platon";
    std::string p4 = " ";
    vars.Set(p1, 10);
    vars.Set(p2, 15);
    vars.Set(p1, 15);
    vars.Set(p3, 25);
    vars.Get(p1);
    vars.Get(p2);
    vars.Get(p4);
    vars.PutTree();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project

