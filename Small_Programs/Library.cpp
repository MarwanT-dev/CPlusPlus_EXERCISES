
#include<iostream >

#include <algorithm>

using namespace std;

struct user {
  string name;
  int id, borrowed_books = 0;
  int books_id[25] {};

  void print_user() {
    cout << "user " << name << " id " << id<<' '<< " borrowed books ids: " ;
    for (int i = 0; i < borrowed_books; i++) {
      cout << books_id[i] << ' ';
    }
    cout << endl;
  }

  void return_book(int book_id) {
    for (int i = 0; i < borrowed_books; i++)
      if (books_id[i] == book_id) {
        books_id[i] = 0;
        break;
      }

    borrowed_books--;

  }

  void borrow_book(int book_id) {
    books_id[borrowed_books] = book_id;
    borrowed_books++;
  }

};

struct book {
  string name;
  int id, quantity, borrowed = 0;
  string people_borrowed[50];

  void return_book(string user_borrowed) {
    for (int i = 0; i < borrowed; i++)
      if (people_borrowed[i] == user_borrowed) {
        people_borrowed[i] = "-1"; // like abbreviation for removed person
        break;
      }

    borrowed--;
    quantity++;
  }

  void borrow_book(string user_borrowed) {
    people_borrowed[borrowed] = user_borrowed;
    borrowed++;
    quantity--;
  }

  void print_who_borrowed() {
    for (int i = 0; i < borrowed; i++)
      cout << people_borrowed[i]<<endl;
  }

  void print_library_by_id() {
    cout << "id = " << id << " name = " << name << " total_quantity = " << quantity << " total_borrowed " << borrowed << endl;
  }

  void print_library_by_name() {
    cout << "id = " << id << " name = " << name << " total_quantity = " << quantity << " total_borrowed " << borrowed << endl;
  }

};



bool compare_by_name(book a, book b) {
    return a.name < b.name;
  }

  bool compare_by_id(book a, book b) {
    return a.id < b.id;
  }





struct library_sys {
  book books[1000];
  user users[100];
  int added_books = 0, added_users = 0;

  void print_menu(){
  cout<<"1) add book"<<endl <<"2) search_books_by_prefix"<<endl<<"3) print_who_borrowed_book_by_name"<<endl <<"4) print_library_by_id"<<endl <<"5) print_library_by_name"<<endl <<"6) add_user"<<endl <<"7) user_borrow_book"<<endl <<"8) user_return_book"<<endl<<"9) print_users"<<endl<<"10) print_menu"<<endl;
  }

  bool is_prefix(string str, string prefix){
            for(int j = 0;j<prefix.size();j++)
                if(str[j]!=prefix[j])
                    return false;

            return true;
    }

  void print_users() {
    for (int i = 0; i < added_users; i++)
      users[i].print_user();
  }

  void user_return_book() {
    cout << "Enter user name and book name ";
    string user_name, book_name;
    cin >> user_name >> book_name;

    int book_id;
    bool book_not_found = 1 , user_not_found = 1;



      while(book_not_found){
            for (int i = 0; i < added_books; i++) {
                  if (book_name == books[i].name) {
                    books[i].return_book(user_name);
                    book_id = books[i].id;
                    book_not_found = 0;
                    break;
            }

            if(!book_not_found)
                break;

            cout<<"Invalid book name,enter right one : ";
            cin>>book_name;
            i = 0;

        }
    }



      while(user_not_found){
            for (int i = 0; i < added_users; i++) {
                if (user_name == users[i].name) {
                    users[i].return_book(book_id);
                    user_not_found = 0;
                    break;
            }

            if(!user_not_found)
                break;

            cout<<"Invalid user name,enter right one : ";
            cin>>user_name;
            i = 0;
        }
    }



  }

  void user_borrow_book() {
    cout << "Enter user name and book name ";
    string user_name, book_name;
    cin >> user_name >> book_name;

    int book_id;
    bool book_not_found = 1 , user_not_found = 1;



      while(book_not_found){

           for (int i = 0; i < added_books; i++) {
              if (book_name == books[i].name) {
                books[i].borrow_book(user_name);
                book_id = books[i].id;
                book_not_found = 0;
                break;
            }
        }
        if(!book_not_found)
            break;

        cout<<"Invalid book name,enter right one : ";
        cin>>book_name;

    }

      while(user_not_found){
           for (int i = 0; i < added_users; i++) {
              if (user_name == users[i].name) {
                users[i].borrow_book(book_id);
                user_not_found = 0;
                break;
            }
            if(!user_not_found)
                break;

            cout<<"Invalid user name,enter right one : ";
            cin>>user_name;
        }
    }

  }

  void add_user() {
    cout << "Enter user name & national id ";
    cin >> users[added_users].name >> users[added_users].id;
    ++added_users;

  }

  void print_library_by_name() {

    sort(books, books + added_books, compare_by_name);

    for (int i = 0; i < added_books; i++)
      books[i].print_library_by_name();
  }

  void print_library_by_id() {
    sort(books, books + added_books, compare_by_id);

    for (int i = 0; i < added_books; i++)
      books[i].print_library_by_id();
  }

  void print_who_borrowed_book_by_name() {
    string book_name;
    cout << "Enter book name: ";
    cin >> book_name;
    bool found = 0;
    for (int i = 0; i<added_books; i++) {
      if (book_name == books[i].name) {
        books[i].print_who_borrowed();
        found = 1;
      }
    }
    if(!found)
        cout<<"Invalid book name. "<<endl;
  }

  void add_book() {
    cout << "Enter book info: id & name & total quantity: ";
    cin >> books[added_books].id >> books[added_books].name >> books[added_books].quantity;
    ++added_books;
  }

  void search_books_by_prefix(){
      string prefix;
      cout << "Enter book name prefix: ";
      cin>>prefix;
      bool no_such_book = 1;
      for(int i =0;i<added_books;i++){
          string s=   books[i].name;

          if(is_prefix(s,prefix)){
              cout<<s<<endl;
              no_such_book = 0;
          }
      }
      if(no_such_book)
        cout<<"No books with such prefix " <<endl;

  }

  int menu() {
    int choice = -1;
    cout<<"Enter your menu choice[1-11]: ";
    while (choice == -1) {
      cin >> choice;
      if (!(choice >= 1 && choice <= 11)) {
        choice = -1;
        cout << "Invalid input , try again ";
      }

    }
    return choice;
  }

  void run() {
    while (true) {
      int choice = menu();
      if (choice == 1)
        add_book();
      else if (choice == 2)
        search_books_by_prefix();
      else if (choice == 3)
        print_who_borrowed_book_by_name();
      else if (choice == 4)
        print_library_by_id();
      else if (choice == 5)
        print_library_by_name();
      else if (choice == 6)
        add_user();
      else if (choice == 7)
        user_borrow_book();
      else if (choice == 8)
        user_return_book();
      else if (choice == 9)
        print_users();
      else if(choice == 10)
        print_menu();
      else
        break;
    }
  }

};

int main() {
  library_sys hospital;
  hospital.run();


  return 0;
}
