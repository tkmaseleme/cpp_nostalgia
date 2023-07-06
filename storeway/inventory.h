#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>

namespace Color {
    extern const std::string Reset;
    extern const std::string Bold;
    extern const std::string Cyan;
    extern const std::string Yellow;
}

struct Item {
    std::string name;
    int quantity;

    Item(const std::string& itemName, int itemQuantity);
};

void addItem(std::vector<Item>& inventory, const std::string& itemName, int itemQuantity);
void removeItem(std::vector<Item>& inventory, const std::string& itemName);
void displayInventory(const std::vector<Item>& inventory);
void saveInventoryToFile(const std::vector<Item>& inventory, const std::string& filename);
std::vector<Item> loadInventoryFromFile(const std::string& filename);
void clearInputBuffer();

#endif  // INVENTORY_H
