# Inventory App

Step 1: Set Up Your Development Environment
- Install a C++ compiler such as GCC or Clang on your computer.
- Choose a text editor or an Integrated Development Environment (IDE) to write your code. Some popular options include Visual Studio Code, Xcode, or Code::Blocks.

Step 2: Create a New C++ File
- Create a new C++ source file with a `.cpp` extension, such as `inventory.cpp`.

Step 3: Define the Item Structure
- In the `inventory.cpp` file, define the `Item` structure to hold information about each item in the inventory.
- The `Item` structure should have two members: `name` (a string) and `quantity` (an integer).

Step 4: Implement the Functions
- Define and implement the necessary functions for adding, removing, and displaying items in the inventory.
- The `addItem` function should take the inventory vector, item name, and quantity as parameters and add a new item to the inventory.
- The `removeItem` function should take the inventory vector and item name as parameters and remove one unit of the item from the inventory.
- The `displayInventory` function should take the inventory vector as a parameter and display the items in the inventory.

Step 5: Implement the Main Function
- In the `main` function, create an empty inventory vector to store the items.
- Use a loop to present a menu of options to the user, such as adding an item, removing an item, displaying the inventory, and exiting the program.
- Based on the user's choice, call the corresponding function to perform the desired operation.

Step 6: Compile and Run the Program
- Open a terminal or command prompt and navigate to the directory where your `inventory.cpp` file is located.
- Use the C++ compiler to compile the program. For example, if you're using GCC, run the command `g++ -o inventory inventory.cpp`.
- Once the compilation is successful, run the program by executing the generated executable file, such as `./inventory` on Unix-like systems or `inventory.exe` on Windows.

Step 7: Test and Refine
- Test the program by adding, removing, and displaying items in the inventory.
- Refine the code as needed, fixing any bugs or adding additional features to meet your requirements.

That's it! You've recreated the inventory management program in C++. You can continue expanding and enhancing the program based on your needs and understanding of C++ programming concepts.

Remember to save your progress regularly and consult C++ documentation or online resources for further guidance on specific topics or functionalities. Happy coding!