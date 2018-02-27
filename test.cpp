#include "dsl.h"
#include <vector>
#include <fstream>
#include <string>
#include "jsoncpp/json/json.h"
#include <iostream>
#define L 5

using namespace std;

bool matchFound = false;
vector<int> output;
string path[L];


// 0 = vector , 1 = int
void printVector(vector<int> n ,string str){
	cout<<str<<" = ";
	for (int x : n){
		cout<<x<<" ";
	}
	cout<<"\n";
}

bool check(vector<int> pred){
	bool isSame = false;
	if (output.size() == pred.size()){
		isSame = true;
		matchFound = true;
		for(int I=0;I<output.size();I++){
			if (pred[I] != output[I]){
				matchFound = false;
				return false;
			}
		}
		if (isSame){
			printVector(pred,"predictions ");
		}
	}
	return isSame;
}


bool findFunc (vector<vector <int> > v , int level ,int type){
	vector<int> a;
	vector<vector <int>> out(1,a);
	
	if (matchFound){
		return true;
	}else if(level > L-1){
		return false;
	}

	if (v.size() == 2 && type == 0){
		a = zipwith(addTwo,v[0],v[1]);
		if (check(a)){
			path[level] = "zipwith + ";
			return true;
		}
		out[0]= a;
		if (findFunc(out,level+1,0)){
			path[level] = "zipwith + ";
			return true;
		}

		a = zipwith(subTwo,v[0],v[1]);
		if (check(a)){
			path[level] = "zipwith - ";
			return true;
		}
		out[0]= a;
		if (findFunc(out,level+1,0)){
			path[level] = "zipwith - ";
			return true;
		}

		a = zipwith(mulTwo,v[0],v[1]);
		if (check(a)){
			path[level] = "zipwith * ";
			return true;
		}
		out[0]= a;
		if (findFunc(out,level+1,0)){
			path[level] = "zipwith * ";
			return true;
		}

		a = zipwith(divTwo,v[0],v[1]);
		if (check(a)){
			path[level] = "zipwith / ";
			return true;
		}
		out[0]= a;
		if (findFunc(out,level+1,0)){
			path[level] = "zipwith / ";
			return true;
		}
	}

	if (v.size()==1 && type==0){
		a = filter(pos,v[0]);
		if (check(a)){
			path[level] = "filter + ";
			return true;
		}
		out[0]= a;
		if (findFunc(out,level+1,0)){
			path[level] = "filter + ";
			return true;
		}


		a = filter(neg,v[0]);
		if (check(a)){
			path[level] = "filter - ";
			return true;
		}
		out[0]= a;
		if (findFunc(out,level+1,0)){
			path[level] = "filter - ";
			return true;
		}


		a = filter(odd,v[0]);
		if (check(a)){
			path[level] = "filter %2 == 1 ";
			return true;
		}
		out[0]= a;
		if (findFunc(out,level+1,0)){
			path[level] = "filter %2 == 1 ";
			return true;
		}


		a = filter(even,v[0]);
		if (check(a)){
			path[level] = "filter %2 == 0 ";
			return true;
		}
		out[0]= a;
		if (findFunc(out,level+1,0)){
			path[level] = "filter %2 == 0 ";
			return true;
		}



		a = mapping(incr,v[0]);
		if (check(a)){
			path[level] = "map incr ";
			return true;
		}
		out[0]= a;
		if (findFunc(out,level+1,0)){
			path[level] = "map incr ";
			return true;
		}


		a = mapping(decr,v[0]);
		if (check(a)){
			path[level] = "map decr ";
			return true;
		}
		out[0]= a;
		if (findFunc(out,level+1,0)){
			path[level] = "map decr ";
			return true;
		}


		a = mapping(square,v[0]);
		if (check(a)){
			path[level] = "map square ";
			return true;
		}
		out[0]= a;
		if (findFunc(out,level+1,0)){
			path[level] = "map square ";
			return true;
		}



		a = mapping(multiply2,v[0]);
		if (check(a)){
			path[level] = "map *2 ";
			return true;
		}
		out[0]= a;
		if (findFunc(out,level+1,0)){
			path[level] = "map *2 ";
			return true;
		}


		a = mapping(multiply3,v[0]);
		if (check(a)){
			path[level] = "map *3 ";
			return true;
		}
		out[0]= a;
		if (findFunc(out,level+1,0)){
			path[level] = "map *3 ";
			return true;
		}

		a = mapping(multiply4,v[0]);
		if (check(a)){
			path[level] = "map *4 ";
			return true;
		}
		out[0]= a;
		if (findFunc(out,level+1,0)){
			path[level] = "map *4 ";
			return true;
		}


		a = mapping(half,v[0]);
		if (check(a)){
			path[level] = "map * 1/2 ";
			return true;
		}
		out[0]= a;
		if (findFunc(out,level+1,0)){
			path[level] = "map * 1/2 ";
			return true;
		}



		a = mapping(onethird,v[0]);
		if (check(a)){
			path[level] = "map * 1/3 ";
			return true;
		}
		out[0]= a;
		if (findFunc(out,level+1,0)){
			path[level] = "map * 1/3 ";
			return true;
		}



		a = mapping(onefourth,v[0]);
		if (check(a)){
			path[level] = "map * 1/4 ";
			return true;
		}
		out[0]= a;
		if (findFunc(out,level+1,0)){
			path[level] = "map * 1/4 ";
			return true;
		}



		a = mapping(invert,v[0]);
		if (check(a)){
			path[level] = "map * -1 ";
			return true;
		}
		out[0]= a;
		if (findFunc(out,level+1,0)){
			path[level] = "map * -1 ";
			return true;
		}


	}
	return false;
}

int main(){
	vector<int> v1{ -1,-2,-3,-4,-5 };
	vector<int> v2{ 1,2,3,4,5 };
	vector <int> o{-1,-4,-9,-16,-25};
	vector <vector <int>> in;
	in.push_back(v1);
	in.push_back(v2);
	output = o;
	findFunc(in,0,0);
	for(int I=0;I<5;I++){
		cout<<path[I]<<"\n";
	}
}