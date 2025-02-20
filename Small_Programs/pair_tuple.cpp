#include <iostream>
#include <bits/stdc++.h>
#include <tuple>
using namespace std;

int main (){
pair<int , int > p1 = make_pair(3,4);
stack <pair<int ,int >> s;
s.push(p1);
s.push(p1);
pair<int , int > p2 = make_pair(5,4);

cout<<(p1>p2)<<endl;//pairs comparison will compare the first with first etc and the pairs should be both of the same type for the first and second item and also in length not to compare a three-element pair with two one

pair <int , pair<int , string > > p3 = make_pair(4,make_pair(5,"marwan"));

pair <int , pair<int , string > > p4 = make_pair(6,make_pair(7,"khaled"));

cout<<(p3>p4)<<endl;

cout<<p3.second.second<<' ';//this to acess the third element
cout<<p3.second.first;//this to acess the second one





/* TUPLE SECTION */
tuple <int , string , char , double > t1; // you put as much as u like this what charactrise it from the pair
t1 = make_tuple(3,"marwan" , 'm' , 3.2);

// another way of defining the tuple and pair

tuple <int ,string ,char , double > t2;
t2 = {3,"maro",'d',33.1};

//third way of defining the tuple (c++17 only)


auto  [c,b] = make_tuple(12,'a');


//there's an error in the third defining search it

//get<position>
cout<<get<0> (t1)<<' '<< get<1> (t1) << endl;

//set<position>
get<0> (t1) = 'd';

cout<<(t1<t2);//comparing tuples


char ch;
int val ;
string name;
double d;

//tie unpack the tuple values into separate variables
tie(val, name , ch , d ) = t1;
cout<<name<<"\n";

//concatenating 2 tuples to return a new tuple

auto t5 = tuple_cat(t1, make_tuple(3.4));


return 0;
}
