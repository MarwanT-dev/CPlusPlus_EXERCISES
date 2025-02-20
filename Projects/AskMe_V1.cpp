#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

bool EXIT = 0;
bool FIRST = 1;


struct system1 {


    map<string,map<string,vector<int>>>mp_ques;// map for new questions

    map<int , pair<string , string> >mp_ids;

    map<int , vector<tuple<int , string , string , string>>>threads_mp;//the tuple contains <id , question , answer , person that sends the question>


    int new_q_ids {}; //new questions ids

    int thread_q_ids {};//thread questions ids

    string username{};//this the user that logged in

    bool account = 0;

void load_data(char ch_user = '*'){//done
    ifstream fin("questions.txt");
    ifstream id_in("ids.txt");

    string str{};
    string user_name {};//the user that found  in the file
    string question_type{};

    string rciv_prson {};

    char temp_ch = '*'; //to inform the input filestream that it's the person section header

    int last_main_id{};

    id_in>>new_q_ids>>thread_q_ids;

    while(getline(fin,str)){
        stringstream iss(str);


        string temp_user{};


        iss>>temp_ch;

        if( temp_ch == ch_user  ){
            iss>>temp_user;

            user_name = temp_user;

            mp_ques[user_name];

            continue;
        }

        char to_symbol  = temp_ch;//not imp we can check in the if statement if the temp_ch == > directly

        if(to_symbol == '>'){
            iss>>temp_user;

            rciv_prson = temp_user;

            continue;
        }


        else{
                stringstream q_in(str);//we make another one cuz when you read the temp_ch this will take the 'm' of the main so to solve this check below that question_type == "ain"
                int id{};
                q_in>>question_type>>id;

                if(question_type == "main"){
                    last_main_id = id;

                    mp_ques[user_name][rciv_prson].push_back(last_main_id);

                    getline(fin,str);

                    mp_ids[last_main_id].first = str;

                    getline(fin,str);

                    mp_ids[last_main_id].second = str;
                }
                else{
                    string sender , question , ans;

                    q_in>>sender;

                    getline(fin,str);

                    question = str;

                    getline(fin,str);

                    ans = str;

                    tuple<int,string,string,string>t;

                    t = make_tuple(id , question , ans , sender);

                    threads_mp[last_main_id].push_back(t);

                }
        }


    }
    fin.close();

}

void login(){//done
    string entered_username , pass;

    stringstream iss("");

    ifstream fin("users_info.txt");

    string str;

    cout<<"Enter user name : ";cin>>entered_username;
    cout<<"Enter password : ";cin>>pass;

    bool failed = 1;

    while(getline(fin,str)){
        iss<<str;
        string temp_username , temp_pass;

        iss>>temp_username>>temp_pass;

        if(temp_username == entered_username && temp_pass == pass){
            cout<<"\nSuccessful login \n\n";
            username = entered_username;
            failed = 0 , account = 1;

            break;
        }
        else
            iss.clear();


    }
    if(failed){
        cout<<"invalid input , try again \n";
        login();
    }


}

void sign_up(){//done
    string username , pass;

    ofstream users_fout("users_info.txt",ios::app);


    cout<<"Enter your username: ";

    cin>>username;

    cout<<"Enter your passwrod: ";

    cin>>pass;

    users_fout<<username<<' '<<pass<<endl;

    mp_ques[username];

    referesh_data_base();

    users_fout.close();

}

void ask(){//done

    string q; //question

    string reciever_person;//the person you want to ask

    int main_q_id {};

    cout<<"Enter Person's Username or -1 to cancel: ";

    cin>>reciever_person;

    if(reciever_person=="-1")
        return ;


    if(!mp_ques.count(reciever_person))//not present this person in the system
    {
        cout<<"Person not found , try again\n";
        ask();
    }
    else{
        cout<<"For thread question: Enter Question id or -1 for new question: ";

        cin>>main_q_id ;

        if(main_q_id == -1){
            cout<<"Enter question text: ";
            cin.ignore(256,'\n');

            getline(cin,q);

            new_q_ids++;

            mp_ques[username][reciever_person].push_back(new_q_ids);

            mp_ids[new_q_ids].first = q;

            referesh_data_base();
        }
        else if(mp_ids.count(main_q_id)){
            cout<<"Enter question text: ";
            cin.ignore(256,'\n');

            getline(cin,q);

            thread_q_ids++;

            tuple<int , string , string , string> t;

            t = make_tuple(thread_q_ids , q ,"" , username);

            threads_mp[main_q_id].push_back(t);

            referesh_data_base();
        }
        else{
            cout<<"Question id not found , try again\n";
            ask();
        }
    }



}

void menu(int choice){//done

        if(!account){
            switch(choice){
                case 1:
                    login();
                    break;

                case 2:
                    sign_up();
                    break;
                default:
                    cout << "ERROR: invalid number...Try again\n Enter number from 1-2: ";
                    cin>>choice ;
                    menu(choice);
                    break;
            }
        }
        else{
            switch(choice){
                case 1:
                    print_questions_to_me();
                    break;

                case 2:
                    print_questions_from_me();
                    break;

                case 3:
                    answer();
                    break;

                case 4:
                    delete_ques();
                    break;

                case 5:
                    ask();
                    break;

                case 6:
                    list_sys_users();
                    break;
                case 7:
                    system_feed();
                    break;
                case 8:
                    logout();
                    break;

                case 9:
                    exit();
                    break;
                default:
                    cout << "ERROR: invalid number...Try again\n Enter number from 1-9: ";
                    cin>>choice ;
                    menu(choice);
                    break;


        }
    }

}

void run(){//done
    if(FIRST){
        load_data();
        FIRST = 0;
    }

    if(!account){
            cout<<"Enter number \n"<<
            "1: Login \n"<<
            "2: SignUp \n";
    }

    if(account){
        cout<<"1: Print Questions To Me \n"<<
              "2: Print Questions From Me\n"<<
              "3: Answer Question\n"<<
              "4: Delete Question\n"<<
              "5: Ask Question\n"<<
              "6: List System Users\n"<<
              "7: Feed\n"<<
              "8: LogOut\n"<<
              "9: Exit \n";
    }

    int choice ;cin>>choice ;

    menu(choice);

}

void print_questions_from_me(){//done
     for(auto const & item : mp_ques[username]){
        for(auto const & id : item.second){

            cout<<"\nQuestion Id ("<<id<<") to user "<<item.first;
            cout<<"         Question: "<<mp_ids[id].first;

            if(mp_ids[id].second!="")
                cout<<"     Answer: "<<mp_ids[id].second<<endl;
            else
                cout<<"     NOT Answered YET"<<endl;
        }
     }


        for(auto const &pair_ : mp_ques){
            for(auto const &mp : pair_.second){
                for(auto const &id: mp.second){
                    if(threads_mp.count(id)){
                        for(auto const &tup : threads_mp[id]){
                            if(get<3>(tup) == username){
                                cout<<"\nQuestion Id ("<<get<0>(tup)<<") to user("<<mp.first<<')';
                                cout<<"         Question: "<<get<1>(tup);

                                if(get<2>(tup)!="")
                                    cout<<"     Answer: "<<get<2>(tup)<<endl;
                                else
                                    cout<<"     NOT Answered YET"<<endl;
                            }
                        }
                    }
                }
            }
        }
        cout<<endl;
}

void print_questions_to_me() {//done
    for (auto pair_ : mp_ques) {

        for (auto mp : pair_.second) {

            if (mp.first == username) {

                for (auto id : mp.second) {
                    cout<<"\nQuestion Id ("<<id<<") from user ("<<pair_.first<<')';
                    cout<<"         Question: "<<mp_ids[id].first<<endl;

                    if(mp_ids[id].second != "")
                        cout<<"         Answer: "<<mp_ids[id].second<<endl;
                    else
                        cout<<endl;


                    if(threads_mp.count(id)){
                        for(auto tup : threads_mp[id]){

                            cout<<"\n         Thread: Question Id ("<<get<0>(tup)<<") from user ("<<get<3>(tup)<<')';
                            cout<<"         Question: "<<get<1>(tup)<<endl;

                            if(get<2>(tup) != "")
                                cout<<"         Thread:         Answer: "<<get<2>(tup)<<endl;
                            else
                                cout<<endl;


                        }

                    }
                }
                break;  // Exit the inner loop once the questions for the logged-in user are printed
            }
        }
    }
    cout<<endl;
}

void logout(){//done
    account = 0;

//here we will save the data that come during running the program before logging out
//we should update the file with every ask and answer functions to achieve the parallel sessions property
}

void referesh_data_base(){//done
    ofstream fout("questions.txt" , ios::trunc);
    ofstream id_out("ids.txt" , ios::trunc);
    for(auto item : mp_ques){
        fout<<'*'<<item.first<<endl;

        for(auto pair_ : item.second){

            fout<<'>'<<pair_.first<<endl;

            auto vec = pair_.second;

            for(auto id : vec){
                fout<<"main"<<' '<<id<<endl;
                fout<<mp_ids[id].first<<endl<<mp_ids[id].second<<endl; //the question and the answer

                if(threads_mp.count(id)){
                    for(auto thread : threads_mp[id]){

                        auto [thread_id , q , ans , sender] = thread;

                        fout<<"thread"<<' '<<thread_id<<' '<<sender<<endl;
                        fout<<q<<endl<<ans<<endl;

                    }

                }

            }

        }

    }

    id_out<<new_q_ids<<endl<<thread_q_ids;
}

void answer(){//done ..

    int q_id {};

    //tuple<int , string , string , string> tuple_of_thread ;

    cout<<"Enter Question id or -1 to cancel: ";

    cin>>q_id;

    if(q_id==-1)
        return ;

    answer_main_q(q_id);

}

void answer_thread_q(int q_id){//done

    string asked_user;

    bool found = 0;

    cin.sync();

    for(auto &pair_ : threads_mp){

        auto &vec = pair_.second;

        if(found)
            break;
        for(auto &tup : vec)
            if(get<0>(tup)==q_id){

                asked_user = get<3>(tup);

                cout<<"Question Id ("<<q_id<<") from user ("<<asked_user<<")        Question: " <<get<1>(tup)<<endl;

                if(get<2>(tup) != ""){
                    cout<<"        Answer: "<<get<2>(tup)<<endl;
                    cout<<"Warning: Already answered . Answer will be updated\n";
                    cout<<"Enter answer: ";
                    getline(cin,get<2>(tup));
                }
                else{
                    cout<<"Enter the answer: ";
                    getline(cin,get<2>(tup));
                }

                found = 1;

                break;
            }
    }

    if(!found){
        cout<<"can't find the question , try again";
        answer();
    }
    else
        referesh_data_base();

}

void answer_main_q(int q_id){//done
    string asked_user;

    bool found = 0;

    cin.sync();

    for(auto &x : mp_ques){

        if(found)
            break;

        for(auto &item : x.second){
            auto it = find(item.second.begin(),item.second.end(),q_id);
            if(it!=item.second.end() && item.first == username){
                found = 1;

                asked_user =  x.first;

                break;
            }
        }
    }
    if(!found){
        answer_thread_q(q_id);
    }
    else{

        cout<<"Question Id ("<<q_id<<") from user ("<<asked_user<<")        Question: " <<mp_ids[q_id].first<<endl;


        if(mp_ids[q_id].second != ""){
            cout<<"        Answer: "<<mp_ids[q_id].second<<endl;
            cout<<"Warning: Already answered . Answer will be updated\n";
            cout<<"Enter answer: ";
            getline(cin,mp_ids[q_id].second);
        }
        else{
            cout<<"Enter the answer: ";
            getline(cin,mp_ids[q_id].second);
        }



        referesh_data_base();

    }
}

void delete_ques(){//done check if the q is present && (reduce the id by if q is deleted) wronnnnng
    int q_id{};
    bool found = 0;

    cout<<"Enter Question id or -1 to cancel: ";

    cin>>q_id;

    if(q_id == -1)
        return ;

    for(auto &pair_ : mp_ques){
        if(pair_.first != username)
                continue;
        for(auto &item : pair_.second){

            auto vec = item.second;

            auto it = find(vec.begin(),vec.end(),q_id);
            if(it != vec.end()){
                vec.erase(it);

                mp_ids.erase(q_id);

                if(threads_mp.count(q_id))
                    threads_mp.erase(q_id);

                found = 1;

                if(vec.empty())
                    mp_ques[pair_.first].erase(item.first);
                break;
            }
        }
    }

    if(!found){
        for(auto &item : threads_mp){

            auto &vec = item.second;

            for(auto it = vec.begin(); it != vec.end() ; )
                if(get<0>(*it)==q_id && get<3>(*it)==username){
                    it = vec.erase(it);

                    found = 1;

                    if(vec.empty())
                        threads_mp.erase(item.first);

                    break;
                }
                else
                    ++it;

        }
    }

    if(!found){
        cout<<"Can't find this question , try again\n";
        delete_ques();
    }
    else
        referesh_data_base();

}

void list_sys_users(){//done
    ifstream fin("users_info.txt");
    string str{};

    cout<<endl;

    while(getline(fin,str)){
        stringstream iss(str);
        string user{};
        iss>>user;
        cout<<user<<endl;
    }

    cout<<endl;
}

void system_feed(){//done
    for(auto const &pair_ : mp_ques){
        for(auto const &mp : pair_.second){
            for(auto const &id : mp.second){
                if(mp_ids[id].second!=""){
                    cout<<"\nQuestion Id ("<<id<<") from user ("<<pair_.first<<") to user ("<<mp.first<<')';
                    cout<<"         Question: "<<mp_ids[id].first<<endl;
                    cout<<"         Answer: "<<mp_ids[id].second<<endl;
                }
                if(threads_mp.count(id)){
                    for(auto const &tup : threads_mp[id]){
                        if(get<2>(tup)!=""){
                            cout<<"\nThread parent Question Id ("<<id<<") Question Id("<<get<0>(tup)<<") from user ("<<get<3>(tup)<<')';
                            cout<<"to user ("<<mp.first<<")         Question: "<<get<1>(tup)<<endl;
                            cout<<"         Answer: "<<get<2>(tup)<<endl;
                        }
                    }
                }

            }
        }
    }
    cout<<endl;
}

void exit(){//done
    EXIT = 1;
}

};



int main()
{
    system1 sys;
    while(!EXIT)
        sys.run();

    return 0;
}
//handle to show from whom the message is asked or to whom it's sent
//handle if the user enter wrong data type / wrong value

