#include <iostream>
#include <string>
using namespace std;

int main() {
	string sen;
	int small, large, num, wh;
  
	for(int i = 0; i<100; i++) {
		small = 0, large = 0, num = 0, wh = 0;
		getline(cin, sen);
    
		if(sen.length() == 0)
			break;
    
		for(int j = 0; sen[j]!='\0'; j++) {
			if(sen[j]>=65 && sen[j]<=90) 
				large++;
			else if(sen[j]>=97 && sen[j]<=122) 
				small++;
			else if(sen[j]>=48 && sen[j]<=57) 
				num++;
			else if(sen[j] == ' ') 
				wh++;
		}
    
		cout<<small<<' '<<large<<' '<<num<<' '<<wh<<endl;		
	}
} 

