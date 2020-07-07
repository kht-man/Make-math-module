#ifndef bits
#include<bits/stdc++.h>
#define bits
#endif
#ifndef stdlib
#include<stdlib.h>
#define stdlib
#endif
class int_matrix{
	private:
		int high;
		int wide;
	public:
		std::vector<int*> mat;
		int_matrix(int h,int w,bool empty_box=false){
			if(empty_box){
				this->high=h;
				this->wide=w;
				for(int i=0;i<h;i++){
					int *a=(int*)malloc(sizeof(int)*w);
					for(int j=0;j<w;j++){
						a[j]=0;
					}
					this->mat.push_back(a);
				}
			}
			else{
				this->high=h;
				this->wide=w;
				for(int i=0;i<h;i++){
					int* a=(int*)malloc(sizeof(int)*w);
					for(int j=0;j<w;j++){
						scanf("%d",&a[j]);
					}
					this->mat.push_back(a);
				}
			}
		}	
		~int_matrix(){
			while(!this->mat.empty()){
				free(this->mat.back());
				mat.pop_back();
			}
		}
		int_matrix operator+(int_matrix &a){
			if(a.high!=high||a.wide!=wide){
				return a;
			}
			else{
				int_matrix t(high,wide,true);
				for(int i=0;i<high;i++){
					for(int j=0;j<wide;j++){
						t.mat[i][j]+=mat[i][j]+a.mat[i][j];
					}
				}
				return t;
			}
		}
		int_matrix operator*(int_matrix &a){
			if(a.high!=wide){
				return a;
			}
			int_matrix t(high,a.wide,true);
			for(int i=0;i<high;i++){
				for(int j=0;j<a.wide;j++){
					for(int k=0;k<wide;k++){
						t.mat[i][j]+=mat[i][k]*a.mat[k][j];
					}
				}
			}
			return t;
		}
		void print_mat(){
			for(int i=0;i<high;i++){
				for(int j=0;j<wide;j++){
					printf("%d ",mat[i][j]);
				}
				printf("\n");
			}
		}
};
