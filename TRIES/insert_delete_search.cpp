#include<bits/stdc++.h>
using namespace std;
#include<memory>

/*
  Complexity
  Search.insert delete - O(m) -- m is the size of the key and d is the alphabet size
  BST would have been O(m log n) 

 */



class TrieNode {
public:

  std::unordered_map<char, std::shared_ptr<TrieNode>> children;
  bool isEndOfWord = false;  // indicates terminal node

};





class Trie {

private:
    std::shared_ptr<TrieNode> root = std::make_shared<TrieNode>();
public:
  void insert(const std::string & word){
    auto node  = root;
    for (char ch: word){
      if (node->children.find(ch) == node->children.end()){
	node->children[ch] = std::make_shared<TrieNode>();
      }
      // change the pointer to now pointing to the ch's child node
      node = node->children[ch];
    }

    node->isEndOfWord = true;

  }

  // const func -- function cannot modify the object               // ENHANCES READABILITY!!!!!!!
  // on which it is called -- object's state doesn't change
  // 

  bool search(const std::string & word) const{
    auto node = root;
    for (char ch:word){
      if (node->children.find(ch) == node->children.end()){
	return false;
      }
      node = node->children[ch];
    }
    return node->isEndOfWord;
  }
  
  // Delete a word from the Trie
  void remove(const std::string &word) {
    deleteRecursively(root, word, 0);
  }

  bool deleteRecursively(std::shared_ptr<TrieNode>& node, const std::string &word, int depth) {

    if (!node) return false;                // word not found.

    if ((depth) == word.size()) {
      if (node->isEndOfWord) {         // Front---->Back

	node->isEndOfWord = false;

	return node->children.empty();      // Condition to let it propogate backward......
      }
      return false;                                   // word not found.
    }

    char ch = word[depth];
    if (node->children.find(ch) == node->children.end()) return false;              // word not found.....

    bool shouldDeleteChild = deleteRecursively(node->children[ch], word, depth+1);

    if (shouldDeleteChild) {
      node->children.erase(ch);
      return node->children.empty() && !node->isEndOfWord;   // condition to continue backprop.....(shouldn't be a part of another word!!!)
    }

    return false;             // backprop stop.....
  }


  // Pretty print the Trie
  void print() const {

    printRecursively(root, "");

  }
  
  void printRecursively(const std::shared_ptr<TrieNode>& node,std::string currentWord) const {
			      
    if (node->isEndOfWord) {
      std::cout << currentWord << "\n";
    }
    for (const auto &pair : node->children) {
      printRecursively(pair.second, currentWord + pair.first);
    }
  }
};

int main() {

    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("banana");
    std::cout << "Contents of Trie:" << std::endl;
    trie.print();

    std::cout << "Deleting 'app'..." << std::endl;
    trie.remove("app");
    trie.print();
    return 0;
}























