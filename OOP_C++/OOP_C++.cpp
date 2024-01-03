// The Shop class contains an array of objects of the Goods class. The Goods class includes
// the name of the product, the quality certificate, and the price. The Customer class includes a list
// of the required goods. Define the necessary data, constructors, destructors,
// and methods for working with data elements. Implement the purchase and determine
// the price of goods according to the list.
#include <iostream>
#include <string.h>

using namespace std;

#define Number 3    //products

class Store;

class Products {
    string name;
    string quality;
    int cost;
public:
    Products(string name = "", string quality = "DSTU4239", int cost = 0) {
        this->name = name;
        this->quality = quality;
        this->cost = cost;
    }

    void SetProducts(string name = "", string quality = "DSTU4239", int cost = 0) {
        this->name = name;
        this->quality = quality;
        this->cost = cost;
    }

    void print() {
        cout << "Name: " << name << "\t" << "Quality: " << quality << "\t" << "Cost: " << cost << endl;
    }

    void copy(Products& obj) {
        this->name = obj.name;
        this->quality = obj.quality;
        this->cost = obj.cost;
    }

    friend Store;

    bool operator==(const Products& other) const {
        return (name == other.name) && (cost == other.cost) && (quality == other.quality);
    }
};

class Buyer;

class Store {
public:
    Products sale[Number];


    void setP(Products& obj, string ename, string equality, int ecost) {
        obj.name = ename;
        obj.quality = equality;
        obj.cost = ecost;
    }

    int return_cost(Products& obj) {
        int c = 0;
        c = obj.cost;
        return c;
    }

    void printassortment() {
        cout << "\nStore assortment" << endl;
        for (int i = 0; i < Number; i++)
        {
            cout << i + 1 << ". ";
            sale[i].print();
        }
    }
    void setassortment() {
        string ename;
        string equality;
        int ecost = 0;
        for (int i = 0; i < Number; i++)
        {
            cout << "\nEnter name, quality, cost for " << i + 1 << " product" << endl;
            cin >> ename >> equality >> ecost;
            sale[i].SetProducts(ename, equality, ecost);
        }
        cout << "Thanks" << endl;
    }
    friend Buyer;

    ~Store() {
        cout << "Deleted store object" << endl;
    }
};

class Buyer : public Products {
public:
    Products list[10];

    int calculate(Store& obj) {
        int a = 0, b = 0, s = 0;
        while (a < Number)
        {
            while (b < Number) {
                if (list[a] == obj.sale[b]) {
                    s = s + obj.return_cost(obj.sale[b]);
                }
                b++;
            }
            b = 0;
            a++;
        }
        return s;
    }

    void printlist() {
        cout << "\nBuyer list" << endl;
        for (int i = 0; i < Number; i++)
        {
            list[i].print();
        }
    }

    void setL(Store& obj) {
        int index = 0;

        for (int i = 0; i < Number; i++)
        {
            cout << "Please enter number of product" << endl;
            cin >> index;
            list[i].copy(obj.sale[index - 1]);
        }
        cout << "\nFrom you " << calculate(obj) << " $\n" << "Thank you for purchasing!\n" << endl;

    }

    ~Buyer() {
        cout << "Deleted buyer object" << endl;
    }
};

int main()
{
    int UserChoice = 0;
    Store s;
    Buyer b;
    cout << "\n\t\t\t\tWelcome to our store, here you can buy products\n" << endl;
    while (true)
    {
        cout << "Who are you?\n1. Seller\n2. Buyer\n3.Please, let me out of the store" << endl;
        cin >> UserChoice;
        while (UserChoice != 1 && UserChoice != 2 && UserChoice != 3)
        {
            cout << "You enter wrong data" << endl;
            cin >> UserChoice;
        }

        if (UserChoice == 1)
        {
            cout << "Hello seller\nEnter products of our store" << endl;
            s.setassortment();
        }

        if (UserChoice == 2)
        {
            cout << "Hello user\nIn our store we have " << endl;
            s.printassortment();
            cout << "Enter shopping list\n";
            b.setL(s);

        }

        if (UserChoice == 3)
        {
            cout << "\n\t\t\t\t\t\t\tGood bye" << endl;
            break;
        }
    }

    return 0;

}
