#ifndef bits
#define bits
#include<bits/stdc++.h>
#endif
long long gcd(long long a,long long b){
	return (a%b)?gcd(b,a%b):b;
}
long long gcd_array(std::vector<long long> &a){
	while(a.size()>=2){
		long long f=a.back();a.pop_back();
		long long s=a.back();a.pop_back();
		a.push_back(gcd(f,s));
	}
	return a.back();
}
long long lcd(long long a,long long b){
	long long g=gcd(a,b);
	return a/g*b;
}
long long lcd_array(std::vector<long long> &a){
	while(a.size()>=2){
		long long f=a.back();a.pop_back();
		long long s=a.back();a.pop_back();
		a.push_back(lcd(f,s));
	}
	return a.back();
}
template <typename T>
T abs(T a){
	return (a>0)?a:-a;
}
