#include <iostream >
#include <queue>
using namespace std;

void queue_print(queue<int > &q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

}
void deque_print_front(deque<int > &q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop_front();
    }

}

int main(){
queue<int > q;//u can know the queue functions by typing queue. and codeblocks will show u the list
q.push(12);
q.push(15);
q.push(20);
queue_print(q);
cout<<q.size()<<' ';//zero cuz we delete all elements after printing

cout<<q.front()<<' ';//same reason as above

cout<<q.back();

// the order of the numbers in queue is FIFO
// so the they will be : 12 15 20

// note that u can't access queue like this q[0] u only can get the first one








/*               DEQUE SECTION            */

deque<int > deq;
deq.push_back(1);
deq.push_front(2);
deq.push_front(3);


cout<<deq[0]<<endl;//we can deal with the deque as an array
cout<<deq.at(0);//this check if the deque has at this place an element if yes it will print

//cout<<deq.at(1000);
// unlike if u made deq[1000] it will crash the program

deque_print_front(deq);










/*               PRIORITY QUEUE                                     */

//NOTHING NEW JUST IT SORT THE NUMBERS FROM BIGGEST TO SMALLEST
priority_queue<int> pq;
pq.push(4);
pq.push(3);
// if u want to sort them from smallest to largest assign values as neg nums then when u print them take the abs

return 0;
}
