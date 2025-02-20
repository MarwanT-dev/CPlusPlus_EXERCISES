#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;

class Mypair {
protected:
	int first, second;

public:
	Mypair(int first, int second) :
			first(first), second(second) {
	}

	void print() {
		cout << "(" << first << "," << second << ")\n";
	}
	int GetFirst() const {
		return first;
	}
	void SetFirst(int first) {
		this->first = first;
	}
	int GetSecond() const {
		return second;
	}
	void SetSecond(int second) {
		this->second = second;
	}

    bool operator<(const Mypair &p2){
        return tie(first,second)>tie(p2.first,p2.second);
    }

};

class NamedPair : public Mypair {
private:
	string name;

public:
	NamedPair(string name , int first , int second) :
			name(name),Mypair(first,second) {
	}

	void print() {
		cout << "(" <<name<<","<< first<< "," << second << ")\n";
	}

    bool operator<( NamedPair p2){
        if(name<p2.name)
            return 1;
        else
            return (Mypair)(*this)<(Mypair)p2;

    }

};


test(){

    vector<NamedPair>v{{"arwan",3,5},{"zli",4,6}};


    sort(v.begin(),v.end());

    for(auto elem:v)
        elem.print();
}

int main() {
    test();


	return 0;
}
