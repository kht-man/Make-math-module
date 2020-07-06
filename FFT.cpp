#ifndef bits
#define bits
#include<bits/stdc++.h>
#endif
#define _USE_MATH_DEFINES
typedef std::complex<double> cpx;
const int max_size=1<<21;
void swap(cpx* a,cpx* b){
	cpx t=*a;
	*a=*b;
	*b=t;
}
void FFT(cpx f[],bool inverse=false){
	int n=max_size;
	for(int i=1,j=0;i<n;i++){
		int b=n/2;
		while(!((j^=b))&b)b/=2;
		if(i<j){
			swap(&f[i],&f[j]);
		}
	}
	for(int k=1;k<n;k*=2){
		double a=(inverse?M_PI/k:-M_PI/k);
		cpx w(cos(a),sin(a));
		for(int i=0;i<n;i+=k*2){
			cpx wp(1,0);
			for(int j=0;j<k;j++){
				cpx x=f[i+j],y=f[i+j+k]*wp;
				f[i+j]=x+y;
				f[i+j+k]=x-y;
				wp*=w;
			}
		}
	}
	if(inverse){
		for(int i=0;i<n;i++){
			f[i]/=n;
		}
	}
}
void FFT_cross(cpx f[],cpx g[]){
	FFT(f);FFT(g);
	for(int i=0;i<max_size;i++){
		f[i]*=g[i];
	}
	FFT(f,true);
}
