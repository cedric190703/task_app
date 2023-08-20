#include "src.hpp"

void Book::get_all_item() {
    size_t size = this->get_size();
    for(size_t i = 0; i < size; i++) {
        cout << this->items[i]->get_ID() << endl;
        if(this->items[i]->get_done()) {
            cout << "Is done" << endl;
        } else {
            cout << "Not done" << endl;
        }

        this->items[i]->get_name();
        this->items[i]->get_details();
    }
    cout << endl;
}

void Book::add_item() {
    cout << "Enter a name: ";
    string name;
    cin.ignore();
    getline(cin, name);
    cout << endl;
    size_t lastID;
    if(this->get_size() == 0) {
        lastID = -1;
    } else {
        lastID = this->items[this->get_size()-1]->get_ID();
    }

    this->items.push_back(new Item(name.c_str(), lastID+1));
    this->size++;
    cout << "Item added successfully." << endl;
}

void Book::update_item() {
    cout << "Enter the ID:";
    size_t ID;
    cin >> ID;
    cout << endl;
    if(this->get_size() < ID) {
        printf("Don't have this ID.\n");
        return;
    }
    string name;
    cout << "Enter a name";
    getline(cin, name);
    
    this->items[ID]->set_name(name.c_str());
    string details;
    cout << "Enter a details";
    getline(cin, details);
    cout << endl;
    this->items[ID]->set_details(details.c_str());
    cout << "Item updated successfully." << endl;
}

void Book::delete_item() {
    cout << "Enter the ID:";
    size_t ID;
    cin >> ID;
    cout << endl;
    if(this->get_size() < ID) {
        printf("Don't have this ID.\n");
        return;
    }
    
    delete this->items[ID];
    this->items.erase(this->items.begin() + ID);
    cout << "Item deleted successfully." << endl;
}

void Book::add_details() {
    cout << "Enter an ID:";
    size_t ID;
    cin >> ID;
    cout << endl;
    if(this->get_size() < ID) {
        cout << "Your book doesn't have this ID" << endl;
        return;
    }
    
    cout << "Enter a detail:";
    string details;
    getline(cin , details);
    cout << endl;
    this->items[ID]->set_details(details.c_str());
    cout << "DEtails added successfully." << endl;
}

void Book::update_details() {
    cout << "Enter an ID:";
    size_t ID;
    cin >> ID;
    cout << endl;
    if(this->get_size() < ID) {
        cout << "Your book doesn't have this ID" << endl;
        return;
    }
    
    cout << "Enter a detail:";
    string details;
    getline(cin , details);
    cout << endl;
    this->items[ID]->update_details(details.c_str());
    cout << "Details updated successfully." << endl;
}

void Book::delete_details() {
    cout << "Enter an ID:";
    size_t ID;
    cin >> ID;
    cout << endl;
    if(this->get_size() < ID) {
        cout << "Your book doesn't have this ID" << endl;
        return;
    }
    
    this->items[ID]->delete_details();
    cout << "Details deleted successfully." << endl;
}

void Book::see_all_items() {
    cout << endl;
    for(Item* item : items) {
        cout << "ID : " << item->get_ID() << endl;
        char* details = item->get_details();
        
        if(details != NULL) {
            cout << "Details : " << details << endl;
        }

        cout << "Name : " << item->get_name() << endl;
        cout << "Done : " << item->get_done() << endl << endl;
    }
    
    cout << "End of the list." << endl;
    cout << endl;
}
