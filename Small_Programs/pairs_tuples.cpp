#include <iostream>
#include <queue>
#include <stack>
using namespace std;



int main(){
pair<int , string > p = make_pair(2 , "marwan");
pair <int ,string> p2 = make_pair(10 , "h");

cout<<p.first<<' ' <<p.second<<endl;

stack < pair<int , string > > s;
s.push(p);
s.push(p);

pair<int , pair<int , string > > my_p = make_pair(12 , make_pair(20 , "tamer"));
cout<<my_p.second.second<<' ' ;//btw u can access the third elem
my_p  = make_pair( 10 , p);

cout<<(p<p2);
//when u compare pairs first they should have equal elements
//then the complier compare them the first from here with the first from there etc.
return 0;

}
