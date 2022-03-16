#include <iostream>
#include "stack.h"
#include "linked_list.h"

/**                                                                                                                      
Will read an unspecified number (until EOF)                                                                              
of input strings from STDIN                                                                                              
*/

int main() {
  Stack linked_list;
  std::string input;
  while (std::getline(std::cin, input)) {
    linked_list.push(input);
  }

  while (!linked_list.isEmpty()) {
    std::string word = linked_list.pop();

    std::cout << word << std::endl;
  }
}

