SMART POINTERS

We use unique_ptr, shared_ptr, and weak_ptr to manage memory safely.
-- UNIQUE_PTR provides exclusive ownership of dynamically allocated memory, preventing memory leaks.
-- SHARED_PTR enables multiple pointers (a pointer in C++ is a variable that stores the memory address of another variable. Declared with `*`, it must point to a compatible data type) to share ownership of an object through reference counting.
-- WEAK_PTR offers a non-owning reference that helps break potential circular reference cycles.

How we can prevent dangling pointers, double deletion, and circular references (a reference variable is an alias for another object).
-- Dangling pointers are avoided by using 
smart pointers (a smart pointer is a class that holds and manages a pointer through RAII.) that manage object lifetimes automatically.
-- Double deletion is prevented through the smart pointer’s controlled memory management.
-- Circular references can be resolved using weak_ptr to break ownership cycles.



UNIQUE_PTR


One of our commonly used smart pointers is unique_ptr, which is part of the C++ Standard Library.

-- When we use unique_ptr, we can only have one pointer pointing to a given resource at any time, making it ideal for variables that we should only access in one part of a program.

-- When a unique_ptr goes out of scope, it automatically deallocates the memory it owns, eliminating our need for manual delete calls. This automatic management makes unique_ptr a safer alternative to raw pointers. Here is how we use a unique_ptr:
```
std::unique_ptr<int> ptr = std::make_unique<int>(20);  // Creates a unique_ptr managing an integer with value 20
std::cout << *ptr << std::endl; // prints 20
```


SHARED_PTR

While we use unique_ptr for exclusive ownership, we can use shared_ptr when we need multiple pointers to manage the same resource. This is particularly useful in more complex programs.

When we work with shared_ptr:

-- We can have multiple shared_ptrs pointing to the same resource. This helps us when multiple parts of our program need access to the same object:
```
// Creates a shared_ptr managing an integer with a value of 30
std::shared_ptr<int> ptr1 = std::make_shared<int>(30);

// ptr2 now shares ownership with ptr1
std::shared_ptr<int> ptr2 = ptr1;
```

-- We rely on reference counting to track how many shared_ptrs share ownership of the resource. To retrieve this value, we use the use_count() method like so:
```
cout << "Reference count: " << ptr1.use_count() << endl;  // Outputs 2, as ptr1 and ptr2 share ownership
```


Each time we create a shared_ptr, the count increases, and each time we destroy one, the count decreases. When the last shared_ptr managing a resource is destroyed, the memory is deallocated. We can destroy a shared pointer by using the reset() method like so:
ptr2.reset();


We can also destroy a shared pointer by reassigning it to point to another object. Once a shared pointer has been destroyed, we can no longer call the use_count() method (or any other method) from that pointer.

- - - - - - - - - - - - -
Though shared_ptr is powerful, we should remember it can introduce performance costs due to its reference counting system running in the background.
- - - - - - - - - - - - -

```
  shared_ptr<int> firstPtr = make_shared<int>(100);
  shared_ptr<int> secondPtr = firstPtr;

  cout << firstPtr.use_count() << endl;

  firstPtr.reset();

  cout << secondPtr.use_count() << endl;
```



WEAK_PTR

When we use shared_ptrs, we can sometimes create circular references, where two or more shared_ptrs reference each other, preventing their memory from being deallocated. This is where we can use a weak_ptr to solve the problem.

We use weak_ptr to provide a non-owning reference to an object managed by a shared_ptr. When we create a weak_ptr, it doesn’t increase the reference count of the object it points to, allowing the object to be deallocated when the last owning shared_ptr goes out of scope.

Key points we need to remember about weak_ptr:

-- We use weak_ptr to break circular references, making it important in situations where shared ownership can lead to memory leaks. For example:
```
std::shared_ptr<int> ptr1 = std::make_shared<int>(40);
std::weak_ptr<int> weakPtr = ptr1;  // weakPtr provides a non-owning reference to ptr1's object
```

-- When we want to access the object a weak_ptr points to, we must lock it into a shared_ptr of the same type (in our example, an int). This way, we can safely check if the object still exists before accessing it. We lock a weak_ptr like so:
```
std::shared_ptr<int> sharedPtr;
if (sharedPtr = weakPtr.lock()) {  // Attempts to lock weakPtr into a shared_ptr
  std::cout << "Object value: " << *sharedPtr << std::endl;
} else {
  std::cout << "Object no longer exists." << std::endl;
}
```

By using weak_ptr this way, we avoid circular references and ensure that resources are correctly deallocated when they’re no longer needed.

```
#include <iostream>
#include <memory>

class NodeB;

class NodeA {
public:
  std::shared_ptr<NodeB> nodeBPtr;
  ~NodeA() { std::cout << "NodeA destroyed\n"; }
};

class NodeB {
public:
  std::weak_ptr<NodeA> nodeAPtr;
  ~NodeB() { std::cout << "NodeB destroyed\n"; }

  void useNodeA() {
    std::shared_ptr<NodeA> nodeA;
    if (nodeA = nodeAPtr.lock()) {
      std::cout << "Accessing NodeA safely\n";
    } else {
      std::cout << "NodeA is no longer available\n";
    }
  }
};

int main() {
  std::shared_ptr<NodeA> nodeA = std::make_shared<NodeA>();
  std::shared_ptr<NodeB> nodeB = std::make_shared<NodeB>();
    
  nodeA->nodeBPtr = nodeB;
  nodeB->nodeAPtr = nodeA;

  nodeB->useNodeA();

  return 0;
}
```