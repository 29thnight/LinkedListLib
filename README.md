# LinkedList Library

A simple, lightweight C++ implementation of a doubly-linked list designed for efficient management and traversal of custom objects using `LinkProperty`.

## Key Features and Advantages

### 1. Seamless Integration with Custom Classes
   - `LinkProperty` is designed to be inherited by any custom class, enabling easy management of objects within the linked list while keeping a clear separation between the list structure and object-specific details.

### 2. Efficient Memory Management
   - This doubly-linked list uses pointers to the previous (`pPrv`) and next (`pNext`) nodes, allowing quick insertion and deletion without reallocation or copying. Ideal for high-performance applications with minimal memory overhead.

### 3. Robust Unlinking Mechanism
   - The `Unlink` method allows nodes to be safely removed, automatically updating the neighboring nodes' pointers. This ensures the list's consistency and prevents dangling pointers, contributing to safer and more predictable code.

### 4. Customizable Iteration
   - Use the `ForEach` function to traverse and process each element in the list, with support for custom lambda functions. This enables flexible and concise iteration, aligning well with functional programming patterns.

### 5. Easy-to-Use API
   - With `Link`, `Unlink`, and `ClearLink` for adding, removing, or clearing elements, along with `GetHead`, `GetTail`, `GetNext`, and `GetPrv` for accessing and traversing elements, the API is designed for simplicity and convenience.

### 6. Minimal Dependencies
   - No requires any library, making this library lightweight and easy to integrate into larger projects without additional external libraries.

## Example Usage

To use this linked list, inherit `LinkProperty` in your custom class and add instances to the `LinkedList`:

```cpp
#include "LinkedList.hpp"

class MyObject : public LinkProperty<MyObject> {
   public:
   MyObject() : LinkProperty(this) //LinkProperty Initalized MyObject Pointer
    // Custom object code
};

int main() {
    LinkedList<MyObject> list;
    MyObject obj;

    list.Link(&obj);

    for(auto& element : list)
    {
       //iterator work
    }

    return 0;
}
