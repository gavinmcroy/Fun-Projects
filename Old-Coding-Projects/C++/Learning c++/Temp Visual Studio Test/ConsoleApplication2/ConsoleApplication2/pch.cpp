// pch.cpp: source file corresponding to pre-compiled header; necessary for compilation to succeed
#include<iostream>
using namespace std; 
#include "pch.h"
int add(int a, int b) {
	return a + b;
}
int subtract(int a, int b) {
	return a - b;
} 
// In general, ignore this file, but keep it around if you are using pre-compiled headers.
