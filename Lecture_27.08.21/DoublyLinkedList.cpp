#include "Node.h"
#include "DoublyLinkedList.h"

int main()
{
    try {
        DoublyLinkedList<int> my_list;
        
        for (int i{ 3 }; i > 0; i--) {
            my_list.insert_front(i);
            my_list.print_list();
        }

        for (int i{ 1 }; i < 4; i++) {
            my_list.insert_last(i + 3);
            my_list.print_list();
        }
        for (int i{ 1 }; i < 4; i++) {
            my_list.remove_first();
            my_list.print_list();
            my_list.remove_last();
            my_list.print_list();
        }
    }
    catch (std::runtime_error& e) {
        std::cout << "Error: " << e.what();
    }
}
