#include<iostream>
#include<stdio.h>

using namespace std;

struct list_node{
	int val;
	list_node* next;
	list_node(int x): val(x), next(NULL){}
};

struct adj_tab{
	int in_degree;
	list_node *head;
	adj_tab(int x){
		head = new adj_tab(x);
		in_degree = 0;
	}
};

