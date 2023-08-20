#include "src/src.hpp"

void get_instructions();

int main() {
    // Init objects
    Book book;

    int status = 1;
    char key;
    
    while(status) {
        // Switch key to call functions
        get_instructions();
        cout << "Enter a key" << endl;
        key = cin.get();
        switch(key) {
            case('A'):
                book.add_item();
                break;
            case('U'):
                book.update_item();
                break;
            case('D'):
                book.delete_item();
                break;
            case('S'):
                book.see_all_items();
                break;
            case('a'):
                book.add_details();
                break;
            case('u'):
                book.update_details();
                break;
            case('d'):
                book.delete_details();
                break;
            case('q'):
            case('Q'):
                status = 0;
                break;
            default:
                cout << "Unkonw key." << endl;
        }
    }
    
    return 0;
}

void get_instructions() {
    cout << "You can:" << endl;
    cout << "Add an item -> 'A'" << endl;
    cout << "Update an item -> 'U'" << endl;
    cout << "Delete an item -> 'D'" << endl;
    cout << "See all items -> 'S'" << endl;

    cout << "Add details on an item -> 'a'" << endl;
    cout << "Update details on an item -> 'u'" << endl;
    cout << "Delete details on an item -> 'd'" << endl;

    cout << "Quit the cli -> 'Q' or 'q'" << endl << endl;
}
