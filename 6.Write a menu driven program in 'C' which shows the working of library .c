#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct book {
    char title[100];
    char author[100];
    int isbn;
    float price;
};

struct book library[MAX_BOOKS];
int num_books = 0;

void add_book() {
    if (num_books >= MAX_BOOKS) {
        printf("Sorry, the library is full.\n");
        return;
    }
    
    printf("Enter book title: ");
    scanf("%s", library[num_books].title);
    printf("Enter author name: ");
    scanf("%s", library[num_books].author);
    printf("Enter ISBN number: ");
    scanf("%d", &library[num_books].isbn);
    printf("Enter price: ");
    scanf("%f", &library[num_books].price);
    
    num_books++;
    printf("Book added to library.\n");
}

void display_book(struct book b) {
    printf("%s by %s (ISBN: %d, price: %.2f)\n", b.title, b.author, b.isbn, b.price);
}

void display_books() {
    if (num_books == 0) {
        printf("The library is empty.\n");
        return;
    }
    int i;
    printf("Library contents:\n");
    
    for (i = 0; i < num_books; i++) {
        display_book(library[i]);
    }
}

void list_books_by_author() {
    char author[100];
    int found = 0;
    
    printf("Enter author name: ");
    scanf("%s", author);
    int i;
    for (i = 0; i < num_books; i++) {
        if (strcmp(library[i].author, author) == 0) {
            display_book(library[i]);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No books found by author %s.\n", author);
    }
}

void list_book_count() {
    printf("There are %d books in the library.\n", num_books);
}

int main() {
    int choice;
    
    do {
        printf("\nLibrary menu:\n");
        printf("1. Add book\n");
        printf("2. Display all books\n");
        printf("3. List books by author\n");
        printf("4. List book count\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                display_books();
                break;
            case 3:
                list_books_by_author();
                break;
            case 4:
                list_book_count();
                break;
            case 5:
                printf("Exiting library system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}

