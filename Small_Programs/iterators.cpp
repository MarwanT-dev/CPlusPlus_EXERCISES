#include <bits/stdc++.h>
using namespace std;


template <class T>
void print_dequeue_v1(deque<T>& q){

    auto it = q.begin();

    while(it!=q.end()){
        cout<<*it<<' ';
        it++;
    }
    cout<<endl;

}
// u can define an iterator like deque<"datatype">::iterator iterator_name = q.begin()
// but i made a template and the i can use the generic var only while defining the arguments unlike template classes
template <class T>
void print_back (deque<T> &q ){

    auto it = q.rbegin();
    while(it!=q.rend()){
        cout<<*it<<' ' ;
        it++;//imagine that u reversed the content so we still adding to the iterator not subtracting from it
    }
    cout<< endl;
}

void lets_play(){
    deque<int > q = {1,2,3,4,5};
    auto it = q.begin();
    cout<<*(it+3); // 4
    cout<<*(it--); // 4 and the it will be after that step 3
    cout<<*(--it); // 2 cuz the prefix
    it+=3 ;
    cout<<*it;//5

    for(auto it = q.begin();it!= q.end();it++)//making all the deque assign with 10
        *it = 10;
}
template<class T>
void print_front_const(deque<T> &q){
    auto it = q.cbegin();
    while (it!= q.cend ()){
        cout<<*it <<' ';
        //*it = 10;    // can't - const iterator
        ++it;
    }
    cout<<endl;

    // there are similarlly   crend() and crbegin()
}

// iterators actually iterate on most DS except ( queue , stack , priority queue )

int count_lowers(const string & str ){
    int cnt = 0;

    // the iterator type here is of type ( string :: iterator )

    for(auto it = str.begin();it!=str.end();it++){
        char ch = *it;
        cnt+= (islower(ch)>0);//we made that cuz the islower it return a number greater than one if it true
    }
    return cnt;
}
int main(){
deque <string > q {"hello"," marwan "};
print_dequeue_v1(q);


deque <int > q1 {1,33,4};
print_dequeue_v1(q1);






return 0;
}
