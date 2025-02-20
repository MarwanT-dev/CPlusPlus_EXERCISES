#include <iostream>
using namespace std;

struct employee {
	int*ptr = NULL;
	employee(){
		ptr = new int[3]{1,2,3};
	}
	~employee(){
		cout<<"bye\n";
		delete[] ptr;
	}
	void print(){
		for(int x : {ptr[0]})
			cout<<x;
	}
};


int main() {
	employee e1;
	employee e2 = e1;

	return 0;
}
