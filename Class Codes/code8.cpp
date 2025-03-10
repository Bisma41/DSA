#include <iostream>
	
using namespace std;

class Stack{
		int pos, size, *data;
	public:
		Stack(int size = 10){
			this -> size = size;
			data = new int[size];
			pos = 0;
		}
		void push (int element){
			data[pos++] = element; 
		}
		void pop (){
			pos--; 
		}
		int top() const{
			return data[pos - 1];
		}
		bool full() const{
			return pos == size;
		}
		bool empty() const{
			return pos == 0;
		}
		~Stack(){
			delete []data;
		}
};
int main(){
	Stack st;
	cout << "push 25, 15, 35\n";
	st.push(25);
	st.push(15);
	st.push(35);
	cout << "Element on Top: ";
	cout << st.top() << "\n";
	cout << "Element on Top: ";
	cout << st.top() << "\n";
	st.pop();
	cout << "pop one element\n";
	cout << "Element on Top: ";
	cout << st.top() << "\n";
	cout << "push 20\n";
	st.push(20);
	cout << "Element on Top: ";
	cout << st.top() << "\n";
	cout << "pop one element\n";
	st.pop();
	cout << "Element on Top: ";
	cout << st.top() << "\n";
	cout << "pop one element\n";
	st.pop();
	cout << "Element on Top: ";
	cout << st.top() << "\n";
	return 0;
}
