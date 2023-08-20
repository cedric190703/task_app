#pragma once
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Item {
    private:
        int done;
        char* name;
        char* details;
        size_t ID;

    public:
        Item(const char* name, size_t ID) {
            this->name = new char[strlen(name)+1];
            this->done = 0;
            this->ID = ID;
            strcpy(this->name, name);
            this->details = NULL;
        };
        ~Item() {
            delete[] name;
            if(details != NULL) {
                delete[] details;
            }
        };
        int get_done() { return this->done; };
        void set_done() { this->done = done; };
        
        char* get_name() { return name; };
        void set_name(const char* new_name) { strcpy(this->name, new_name); };

        char* get_details() { return this->details; };
        void update_details(const char* details) { strcpy(this->details, details); };
        void set_details(const char* details) { 
            this->details = new char[strlen(details)+1];
            strcpy(this->details, details);
        }; 
        void delete_details() {
            delete[] details;
            details = NULL;
        }

        int get_ID() { return this->ID; };
};

class Book {
    private:
        vector<Item*> items;
        size_t size;

    public:
        Book() {
            size = 0;
        };
        ~Book() {
            for(Item* item : items) {
                delete item;
            }
            items.clear();
        };
        size_t get_size() { return this->size; };
        void set_size(size_t size) {  this->size = size; };
        void get_all_item();
        void add_item();
        void update_item();
        void delete_item();
        void add_details();
        void update_details();
        void delete_details();
        void see_all_items();
};
