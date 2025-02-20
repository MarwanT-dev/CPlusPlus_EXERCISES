#include <iostream >
#include <queue>
#include <algorithm>
using namespace std;


bool valid_paranthesis(vector<char> &q){// my solution
    while(!q.empty()){
        char top = q.front();

        if(q.size()==1&&top==']'||top=='}'||top==')')
            return 0;
        else
        {

            if(top=='{'){

                int i =1;
                while(q[i]==')'&&q[i]==']'&&q[i]!='}'&&i<q.size())i++;

                if(i!=q.size()&&q[i]!=')'&&q[i]!=']'){
                    q.erase(q.begin()+i);
                    q.erase(q.begin());
                }
                else
                    return 0;



            }
            else if(top=='['){

                int i =1;
                while(q[i]==')'&&q[i]=='}'&&q[i]!=']'&&i<q.size())i++;

                if(i!=q.size()&&q[i]!=')'&&q[i]!='}'){
                    q.erase(q.begin()+i);
                    q.erase(q.begin());
                }
                else
                    return 0;



            }
            else if(top=='('){

                int i =1;
                while(q[i]==']'&&q[i]=='}'&&q[i]!=')'&&i<q.size())i++;

                if(i!=q.size()&&q[i]!=']'&&q[i]!='}'){
                    q.erase(q.begin()+i);
                    q.erase(q.begin());
                }

                else
                    return 0;



            }
        }
    }
    return 1;


}

bool isValid(string str){
    map<char , char> mp ;
    mp[')'] = '(';
    mp[']'] = '[';
    mp['}'] = '{';

    stack <char> paranthesis;

    for(char ch : str){
        if(mp.count(ch)){
            //A close one. It must match open one
            if(paranthesis.empty())
                return false ;
            char open = mp[ch];
            char cur_open = paranthesis.top();

            if(open != cur_open){
                return false ;
                paranthesis.pop();
            }
            else
                paranthesis.push(ch);

        }
        return paranthesis.empty();
    }





}

int main(){
while(true){
    cout<<"Enter string length : ";int n ;cin>>n;


    if(n==0) return 0;


    if(n%2==0){
        vector <char> q(n);
        for(int i =0;i<n;i++)cin>>q[i];

        if(valid_paranthesis(q))cout<<"Valid"<<endl; else cout<<"Invalid"<<endl;
    }
    else cout<<"Invalid"<<endl;
}

return 0;
}

