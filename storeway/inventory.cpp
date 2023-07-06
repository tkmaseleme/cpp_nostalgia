#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>

namespace Color {
    const std::string Reset = "\033[0m";
    const std::string Black = "\033[30m";
    const std::string Red = "\033[31m";
    const std::string Green = "\033[32m";
    const std::string Yellow = "\033[33m";
    const std::string Blue = "\033[34m";
    const std::string Magenta = "\033[35m";
    const std::string Cyan = "\033[36m";
    const std::string White = "\033[37m";
    const std::string BoldBlack = "\033[1m\033[30m";
    const std::string BoldRed = "\033[1m\033[31m";
    const std::string BoldGreen = "\033[1m\033[32m";
    const std::string BoldYellow = "\033[1m\033[33m";
    const std::string BoldBlue = "\033[1m\033[34m";
    const std::string BoldMagenta = "\033[1m\033[35m";
    const std::string BoldCyan = "\033[1m\033[36m";
    const std::string BoldWhite = "\033[1m\033[37m";
}

struct Item {
    std::string name;
    int quantity;

    Item(const std::string& itemName, int itemQuantity) : name(itemName), quantity(itemQuantity) {}
};

void addItem(std::vector<Item>& inventory, const std::string& itemName, int itemQuantity) {
    Item newItem(itemName, itemQuantity);
    inventory.push_back(newItem);
    std::cout << "Item added successfully!\n";
}

void removeItem(std::vector<Item>& inventory, const std::string& itemName) {
    for (size_t i = 0; i < inventory.size(); ++i) {
        if (inventory[i].name == itemName && inventory[i].quantity > 0) {
            --inventory[i].quantity;
            std::cout << "Item removed successfully!\n";
            return;
        }
    }

    std::cout << Color::Red;
    std::cout << "Item not found in the inventory or quantity is already 0.\n";
    std::cout << Color::Reset;
}


void displayInventory(const std::vector<Item>& inventory) {
    std::cout << "Inventory:\n";
    if (inventory.empty()) {
        std::cout << "Empty\n";
    } else {
        for (const Item& item : inventory) {
            std::cout << "Name: " << item.name << ", Quantity: " << item.quantity << "\n";
        }
    }
}

void saveInventoryToFile(const std::vector<Item>& inventory, const std::string& filename) {
    std::ofstream file(filename, std::ios::trunc);
    if (file.is_open()) {
        for (const Item& item : inventory) {
            file << item.name << "," << item.quantity << "\n";
        }
        file.close();
        std::cout << "Inventory saved to file.\n";
    } else {
        std::cout << Color::Red;
        std::cout << "Unable to open file for loading inventory.\n\n";
        std::cout << Color::Reset;
    }
}

std::vector<Item> loadInventoryFromFile(const std::string& filename) {
    std::vector<Item> inventory;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::size_t commaPos = line.find(',');
            if (commaPos != std::string::npos) {
                std::string itemName = line.substr(0, commaPos);
                int itemQuantity = std::stoi(line.substr(commaPos + 1));
                inventory.emplace_back(itemName, itemQuantity);
            }
        }
        file.close();
        std::cout << "Inventory loaded from file.\n";
    } else {
        std::cout << Color::Red;
        std::cout << "Unable to open file for loading inventory.\n\n";
        std::cout << Color::Reset;
    }
    return inventory;
}

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::vector<Item> inventory;
    const std::string filename = "inventory.txt";

    inventory = loadInventoryFromFile(filename);

    std::cout << Color::BoldCyan;
    std::cout << "********************************************\n";
    std::cout << "*                                          *\n";
    std::cout << "*   Welcome to the Pantry Manager          *\n";
    std::cout << "*                                          *\n";
    std::cout << "********************************************\n";
    std::cout << Color::Reset;


    while (true) {
        std::cout << Color::BoldCyan;
        std::cout << "\nInventory Management System\n\n";
        std::cout << Color::Reset;
        std::cout << Color::Green;
        std::cout << "1. Add Item\n";
        std::cout << Color::Reset;
        std::cout << Color::Red;
        std::cout << "2. Remove Item\n";
        std::cout << Color::Reset;
        std::cout << Color::Green;
        std::cout << "3. Display Inventory\n";
        std::cout << "4. Save Inventory to File\n";
        std::cout << Color::Reset;
        std::cout << Color::Red;
        std::cout << "5. Quit\n";
        std::cout << Color::Reset;
        std::cout << Color::BoldCyan;
        std::cout << "\nEnter your choice (1-5): ";
        std::cout << Color::Reset;

        int choice;
        std::cin >> choice;

        // Clear input buffer
        clearInputBuffer();

        switch (choice) {
            case 1: {
                std::cout << "Enter item name: ";
                std::string itemName;
                std::getline(std::cin, itemName);
                std::cout << "Enter item quantity: ";
                int itemQuantity;
                std::cin >> itemQuantity;
                clearInputBuffer();
                addItem(inventory, itemName, itemQuantity);
                break;
            }
            case 2: {
                std::cout << "Enter item name to remove: ";
                std::string itemName;
                std::getline(std::cin, itemName);
                removeItem(inventory, itemName);
                break;
            }
            case 3:
                displayInventory(inventory);
                break;
            case 4:
                saveInventoryToFile(inventory, filename);
                break;
            case 5:
                std::cout << "Exiting the program. Goodbye!\n";
                saveInventoryToFile(inventory, filename); // Save inventory before quitting
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}