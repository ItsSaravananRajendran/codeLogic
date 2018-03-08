#include <functional> 
#include <iostream>
#include <stdio.h>
#include <vector> 
#include <algorithm>

using namespace std;


// vector -> int

function<int(vector<int>)> head = [](vector<int> v) {
if (v.size()>0) 
	return v[0];
else 
	return (int)NULL;
};

function<int (vector <int>)> tail = [](vector <int>v ){
if (v.size()>0)
	return v.back();
else 
	return (int)NULL;
};



function <int (vector <int>)> minimum = [] (vector <int> v){
	int min = 999999;
	for (int I=0;I<v.size();I++){
		if (min < v[I]){
			min = v[I];
		}
	}
	return min;
};


function <int (vector <int>)> maximum = [] (vector <int> v){
	int max = -999999;
	for (int I=0;I<v.size();I++){
		if (max > v[I]){
			max = v[I];
		}
	}
	return max;
};


function <int(vector<int>)> sum = [](vector <int> v){
	int sum=0;
	for (int I=0;I<v.size();I++){
		sum += v[I];
	}
	return sum;
};


function <int (vector<int>,int)> access = [] (vector <int> v, int n){
	if (v.size()>0 && v.size()>n)
		return v[n];
	else
		return (int)NULL;
};

//vector -> vector

function <vector<int> (vector<int>,int)> take = [](vector <int>v,int n ){
	vector <int> res ;
	for (int I =0; I< n; I++){
		res.push_back(v[I]);
	} 
	return res;
};

function <vector <int> (vector<int>,int)> drop = [](vector <int>v , int n ){
	vector <int> res;
	for (int I=n;I<v.size();I++){
		res.push_back(v[I]);
	}
	return res;
};


function <vector <int> (vector <int>)> sorted = [] (vector <int> v){
	std::sort(v.begin(),v.end());
	return v;
};


function <vector <int> (vector <int>)> reversed = [] (vector <int> v){
	std::sort (v.begin(),v.end(),greater<int>());
	return v;
};


//int -> bool
function <bool (int)> pos = [] (int n){
	if (n > 0)
		return true;
	else
		return false;
};


function <bool (int)> neg = [] (int n){
	if (n < 0)
		return true;
	else
		return false;
};


function <bool (int)> even = [] (int n){
	if (n %2 == 0)
		return true;
	else
		return false;
};

function <bool (int)> odd = [] (int n){
	if (n %2 == 1)
		return true;
	else
		return false;
};


//int -> int
function <int (int)> incr = [](int n){
	return n+1;
};


function <int (int)> decr = [](int n){
	return n-1;
};



function <int (int)> multiply2 = [](int n){
	return 2*n;
};


function <int (int)> square = [](int n){
	return n*n;
};

function <int (int)> half = [](int a){
	return a/2;
};

function <int (int)> onethird = [](int a){
	return a/3;
};

function <int (int)> onefourth = [](int a){
	return a/2;
};


function <int (int)> multiply3 = [](int a){
	return a*3;
};

function <int (int)> multiply4 = [](int a){
	return a*4;
};


function <int (int)> invert = [](int a){
	return a*-1;
};


//function (int) ,vec -> vector 

function <vector<int>(function<int(int)>,vector <int> )> mapping = [](function<int(int)> f, vector<int> v){
	vector<int> res;
	for (int I=0;I<v.size();I++){
		res.push_back(f(v[I]));
	}
	return res;
};


function <vector<int>(function<bool(int)>,vector <int>)> filter = [](function<bool(int)> f, vector<int> v ){
	vector <int> res;
	for (int I=0;I<v.size();I++){
		if (f(v[I]))
			res.push_back(v[I]);
	}
	return res;
};


//function (int) ,vec -> int
function <int(function<bool(int)>,vector <int>)> counting = [](function<bool(int)> f, vector<int> v ){
	vector <int> res;
	for (int I=0;I<v.size();I++){
		if (f(v[I]))
			res.push_back(v[I]);
	}
	return res.size();
};


// int , int -> int
function <int (int,int)> addTwo = [](int a,int b ){
	return a+b;
};


function <int (int,int)> subTwo = [](int a,int b ){
	return a-b;
};

function <int (int,int)> mulTwo = [](int a,int b ){
	return a*b;
};

function <int (int,int)> divTwo = [](int a,int b ){
	return a/b;
};

function <int (int,int)> miniTwo = [](int a,int b ){
	return min(a,b);
};


function <int (int,int)> maxTwo = [](int a,int b ){
	return max(a,b);
};

function <vector <int>(function <int(int,int)>,vector<int> , vector<int>)> zipwith = [](function <int(int,int)> f, vector<int> v1 , vector<int> v2 ){
	vector<int> res;
	for(int I=0;I<min(v1.size(),v2.size());I++){
		res.push_back(f(v1[I],v2[I]));
	}
	return res;
};


function <vector <int> (function <int(int,int)> , vector<int>)> scanl = [](function <int(int,int)> f ,vector <int>v){
	vector <int> res ;
	res.push_back(v[0]);
	for (int I=1;I<v.size();I++){
		res.push_back(f(res[I-1],v[I]));
	}
	return res;
};