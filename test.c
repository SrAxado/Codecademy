#include <iostream>
#include <memory>

class NodeB;
class NodeC;

class NodeA {
public:
  int numA = 10;
  std::shared_ptr<NodeC> nodeCPtr;
  ~NodeA() { std::cout << "NodeA destroyed" << std::endl; }
};

class NodeB {
public:
  int numB = 20;
  std::weak_ptr<NodeA> nodeAPtr;
  ~NodeB() { std::cout << "NodeB destroyed" << std::endl; }

  void useNodeA() {
    std::cout << "-- Node B --" << std::endl;
    std::shared_ptr<NodeA> nodeA;
    if (nodeA = nodeAPtr.lock()) {
      std::cout << "Accessing NodeA safely" << std::endl;
      std::cout << "NumA: " << nodeA->numA << std::endl;
    } else {
      std::cout << "NodeA is no longer available" << std::endl;
    }
  }
};

class NodeC {
  public:
    std::weak_ptr<NodeB> nodeBPtr;
    ~NodeC() { std::cout << "NodeC destroyed" << std::endl; }

    void useNodeB() {
      std::cout << "-- Node C --" << std::endl;
      std::shared_ptr<NodeB> nodeB;
      if (nodeBPtr.expired()) {
        std::cout << "NodeB expired" << std::endl;
      } else {
        std::cout << "NodeB still exists." << std::endl;
        // std::cout << "NumB: " << nodeB->numB << std::endl;
        if (nodeB = nodeBPtr.lock()) {
          std::cout << "Accessing NodeB safely\n";
          std::cout << "NumB: " << nodeB->numB << std::endl;
        } else {
          std::cout << "NodeB is not available\n";
        }
      }
    }
};

int main() {
  std::shared_ptr<NodeA> nodeA = std::make_shared<NodeA>();
  std::shared_ptr<NodeB> nodeB = std::make_shared<NodeB>();
  std::shared_ptr<NodeC> nodeC = std::make_shared<NodeC>();
    
  nodeA->nodeCPtr = nodeC;
  nodeB->nodeAPtr = nodeA;
  nodeC->nodeBPtr = nodeB; 

  nodeB->useNodeA();
  nodeC->useNodeB();

  return 0;
}
