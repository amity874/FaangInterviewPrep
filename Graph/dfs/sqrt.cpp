#include<bits/stdc++.h>
double f(int x){
	int i=1;
	for(i=1;i<=x;i++){
		if(x%i==0){
			return i;
		}
	}
return i;	
}
int main(int argc, char const *argv[]){
	std::cout<<f(8);
	return 0;
}