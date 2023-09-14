//
//  main.swift
//  Simple-App
//
//  Created by Gavin Taylor Mcroy on 5/23/23.
//

import Foundation

print("Hello, World!")

let values = [1,2,3,4,5,6,7,8,9,10]

func printData(_ data: [Int]) -> Int{
    for i in data{
        print(i,terminator: " ")
    }
    return data.count;
}

func printDataReverse(_ data: [Int]) -> Int {
    for i in data.reversed(){
        print(i,terminator: " ")
    }
    return -1;
}

print(printDataReverse(values))

print("Enter your name and information")
let value = readLine()
print(value!)

//File IO
