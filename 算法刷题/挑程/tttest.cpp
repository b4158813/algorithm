#include<iostream>
#include<cmath>
using namespace std;

class Book{
	public:
		string title;
		string author;
		int pages;
		
		Book(){
			title = "no title";
			author = "no author";
			pages = 0;
		}
		Book(string aTitle, string aAuthor, int aPages){
			title = aTitle;
			author = aAuthor;
			pages = aPages;
		}
};

int main(){
	
	Book book1("Mybook","WLX",233);
	
	
}
