
Conversation opened. 1 read message.

Skip to content
Using PUCIT, University of the Punjab, Lahore Mail with screen readers

21 of 1,646
Today's codes
Inbox

Abdul Mateen
Attachments
Mar 6, 2025, 1:44 PM (4 days ago)
to bsdsf21a035, BSDSF21M041, BSDSF21M053-Misbah, BSDSF21M059, BSDSF22A030-Sidra, BSDSF22A034, me, BSDSF22M008-Maham, BSDSF22M044-Fatima, BSDSF23A003-Ali, BSDSF23A016, BSDSF23A018, BSDSF23A028, BSDSF23A029, BSDSF23A031, BSDSF23A033, BSDSF23A035, BSDSF23A040, BSDSF23A041, BSDSF23M008-Muhammad, BSDSF23M009, BSDSF23M013, BSDSF23M020, BSDSF23M023-Muhammad, BSDSF23M025, BSDSF23M030, BSDSF23M036, BSDSF23M041, BSDSF23M045, BSDSF23M046, BSDSF23M047, BSDSF23M048, BSDSF23M050-Hasima, MSDSF23M010, Muhammad, Muhammad

Asalaam-o-Alikum from Abdul Mateen!

Well I am unable to understand why most of you are not attending the classes, despite my clear email that today's class will be held. If you are not interested to attend the course, inform so that I can remove you from the list.

Anyhow, today we have discussed Stack Data Structure. Here, you find, couple of codes related to Stack.

All the best.

Wasalaam-o-Alikum
Email: amateen@pucit.edu.pk
Ext: 149
Whatsapp: +923334532548

Go Green!

Print this email only if genuinely required.

********** DISCLAIMER **********


This email including any attachment(s) contains information that is privileged, private and confidential and is intended for the addressee(s) only. If you receive this email in error, please notify the sender by reply email and delete it from your system. Unauthorized use, disclosure, distribution, printing, forwarding or copying is strictly prohibited. Any views or opinions presented in this email are solely those of the author and do not necessarily represent the FCIT. Although the management has taken reasonable precautions to ensure no viruses are present in this email, the FCIT cannot accept responsibility for any loss or damage arising from the use of this email or attachment(s).

 2 Attachments
  •  Scanned by Gmail
#include <iostream>
#include <cstdlib>
#include <ctime>
	
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
	srand(time(0));
	Stack st;
	int val;
	while (!st.full()){
		val = rand();
		cout << "push " << val << "\n";
		st.push(val);
	}
	while (!st.empty()){
		cout << st.top() << ' ';
		st.pop();
	}
	cout << "\n";
	return 0;
}
code2.cpp
Displaying code1.cpp.
