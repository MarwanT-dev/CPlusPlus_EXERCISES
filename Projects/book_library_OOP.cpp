
#include<iostream >
#include<vector>
#include <algorithm>

using namespace std;


int EXIT = 0;
class user {
private:

    vector<pair<string,int>> sessions{};
    string name{} ;
    string username{};
    string email{};
    string type{};
    string pass{};

public:



    user(){

    }
    user(string name , string username , string email , string type , string pass):
       name(name) , username(username) , email(email) , type(type) , pass(pass) {

    }

    //all getters done
    string get_name()const{
        return name;
    }
    vector<pair<string,int>> get_sessions()const{
        return sessions;
    }
    string get_username()const{
        return username;
    }
    string get_email()const{
        return email;
    }
    string get_type()const{
        return type;
    }

    //all setters done
    void set_name(string name_){
        name = name_;
    }
    void set_username(string username_){
        username = username_;
    }
    void set_email(string email_){
        email = email_;
    }
    void set_type(string type_){
        type = type_;
    }


    void view_prof(){//done
        cout<<"Name: "<<name<<endl;
        cout<<"Email: "<<email<<endl;
        cout<<"User name: "<<username<<endl;
    }

    pair<string , int> list_from_reading_his(){//done
            for(int cnt = 0;cnt<sessions.size();cnt++){
                pair<string , int> session = sessions[cnt];
                cout<<cnt+1<<": "<<session.first<<"page"<<' '<<session.second;
            }

            int choice ;
            cout<<"What session do you want to choose 1-"<<sessions.size()<<": ";
            cin>>choice;

            return sessions[choice-1];
    }

    bool pass_check(string pass_){
        if(pass_==pass)
            return 1;
        return 0;
    }

    void last_session(string book_name , int page){
        this->sessions.push_back(make_pair(book_name,page));
    }
};

class book {
private:
    string name;
    vector<string>content;
public:

    book(){

    }

    book(string name):name(name){
    }

    string get_name()const{
        return name;
    }
    vector<string> get_content()const{
        return content;
    }
    void set_content(vector<string> &content_){
        content = content_;
    }

int display_content(int st_page = 0){//there's a problem with the returning page
    for(int page = 0;page<content.size();page++){
        cout<<"Current Page: "<<page+1<<'/'<<content.size()<<endl;
        cout<<content[page]<<endl;
        cout<<"Menu:\n        1: Next Page\n        2: Previous Page\n      3: Stop Reading\n";
        int choice;
        cin>>choice;
        switch(choice){
        case 1:
            continue;
        break;
        case 2:
            if(page){
                page-=2;
            }
            else
                page-=1;
        break;
        case 3:
            return page;
            break;
        }
    }
    return content.size();

}


};


class database {
private:
    vector<book>books;
    vector<user>user_database;

public:

vector<book> get_books(){
    return books;
}

bool signin_check(string username , string pass) const{//done
        for(auto user : user_database){
            string right_username = user.get_username();
            if(right_username==username)
                if(user.pass_check(pass))
                    return 1;
        }

        return 0;
}

user get_user(string username , string pass){//done
    for(auto user:user_database){
        string right_username = user.get_username();
            if(right_username==username)
                if(user.pass_check(pass))
                    return user;


    }
    user empty_user;
    return empty_user;

}

book& list_select_available_books(){
    for(int i = 0;i<(int)books.size();i++){
        string book_name = books[i].get_name();
        cout<<i+1<<':'<<book_name<<endl;
    }

    int choice;
    cout<<"choose a book[1-"<<books.size()<<"]:";
    cin>>choice;///needs validation
    return books[choice-1];


}

void add_user(user user_){//done
    user_database.push_back(user_);
}

void add_book(){//done
    string book_name;
    cout<<"Enter Title: ";
    cin>>book_name;
    cout<<"Enter how many pages do you want : ";
    int pages_num ;
    cin>>pages_num;
    book temp_book(book_name);

    vector<string>temp_content;


    for(int i =0;i<pages_num;i++){
        string pg_content;
        cin>>pg_content;
        temp_content.push_back(pg_content);
    }
    temp_book.set_content(temp_content);
    books.push_back(temp_book);
}

bool books_empty(){
    if(books.empty())
        return 1;
    return 0;

}
};

class library_sys{
private:
    bool account{};
    user marwan{"Marwan_Tamer","maro123","marwan@gmail.com","admin","1234"};
    bool first = 1;
    user current_user;
    book current_book;
    database DB;

public :
void menu(){
    int choice {};
    if(first){
        DB.add_user(marwan);
    }
    first = 0;
    cout<<"Menu:\n";

if(!account){
    cout<<"         1: Login\n"
        <<"         2: Sign_up\n"
        <<"         3: Exit\n"
        <<"Enter number in range 1 - 3: ";
    cin>>choice;

    switch(choice){
        case 1 :
            {


            string username , pass;
            cout<<"Enter user name (no spaces): ";
            cin>>username;
            cout<<"Enter password (no spaces): ";
            cin>>pass;
            if(DB.signin_check(username,pass)){
                current_user = DB.get_user(username,pass);
                cout<<"hello "<<username<<" |"<<current_user.get_type()<<"view\n";

                account = 1;
            }
            else
                cout<<"Wrong input ,try again\n";
            //solve if the data was wrong so we can't login
            break;
            }
        case 2:{
            string username_ , pass_ , name , email;
            cout<<"Enter user name (No spaces): ";
            cin>>username_;
            cout<<"Enter password (No spaces): ";
            cin>>pass_;
            cout<<"Enter name (No spaces): ";
            cin>>name;
            cout<<"Enter email (No spaces): ";
            cin>>email;
            //make a temp user obj and then assign it to the add_user fun in the database
            user temp{name,username_,email,"user",pass_};
            DB.add_user(temp);
            current_user = temp;
            account = 1;
            break;
        }
        case 3:
            exit();
            break;
        }
}

else if(account&&current_user.get_type()=="user"){

    cout<<"         1: View Profile\n"
        <<"         2: List & Select from Reading History\n"
        <<"         3: List & Select from Available books\n"
        <<"         4: Logout\n"
        <<"         5: Exit\n"
        <<"Enter number in range 1 - 5: ";
    cin>>choice;

    switch(choice){
        case 1 :
            current_user.view_prof();
            break;
        case 2:
            list_select_from_reading_his();
            break;
        case 3:{
            if(DB.books_empty()){
                cout<<"no current books\n";
                break;
            }
            current_book = DB.list_select_available_books();
            int last_page_read = current_book.display_content();
            current_user.last_session(current_book.get_name(),last_page_read);
            break;
        }
        case 4:
            logout();
            break;
        case 5:
            exit();
            break;
        }

}
else{
    cout<<"         1: View Profile\n"
        <<"         2: add book\n"
        <<"         3: Logout\n"
        <<"         4: Exit\n"
        <<"Enter number in range 1 - 4: ";
    cin>>choice;
    switch(choice){
        case 1 :
            current_user.view_prof();
            break;
        case 2:
            DB.add_book();
            break;
        case 3:
            logout();
            break;
        case 4:
            exit();
            break;

        }
}


}
void run(){
        menu();
}

void list_select_from_reading_his(){//done
    if(current_user.get_sessions().empty()){
        cout<<"no previous sessions\n";
        return;
    }
    auto selected_session = current_user.list_from_reading_his();
    for(auto book:DB.get_books()){
        if(book.get_name()==selected_session.first){
            book.display_content(selected_session.second);
            break;
        }
    }


}

bool login(string username , string pass){

    if(DB.signin_check(username , pass)){
        current_user = DB.get_user(username , pass);
        return 1;
    }

    else
        return 0;
}

void logout(){
    account = 0;
}

void exit(){
    EXIT = 1;
}

};

int main()
{
    library_sys hospital;
    while(!EXIT)
        hospital.run();


    return 0;
}
