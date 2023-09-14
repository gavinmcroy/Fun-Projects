//
//  main.swift
//  Learning-Swift
//
//  Created by Gavin Taylor Mcroy on 5/19/23.
//

import Foundation

let name = "Gavin"
let age  = 22
let message  = "I'm \(name) and I'm \(age) years old. "

var colors = ["color","red","blue"]
let numbers = [1,2,3,34,5,6,6]

let employee = [
    "name": "Taylor",
    "job":"singer"
]


var data = Set([1,3,4,5,6,7,8,9,90,1,1,1,1,1,1])
data.insert(10)
print(data.contains(5))

enum Weekday{
    case Monday,Tuesday,Wed,Thursday,Friday,Saturday,Sunday
}

var day = Weekday.Monday
day = .Friday
print(day)

//Type Annotation
var score : Double = 0
var value : String = "tub"
var teams = [String]()
teams.insert("This is the team", at: 0)

print(teams)

var age1  = 25
age1 = 10;
var number = 15;
var answer = number+age

if !false{
    print("This awesome sentance")
}else if age1 < 12 {
    print("Leave")
}

let dataStruct = [1,2,34,45,5,67,7,8]

for i in 0...dataStruct.count-1{
    //print("This data is 5x \(i*5)")
}

let files = ["file.txt","map.jpeg","int.cpp","gav.jpeg"]
var count = 0;

for files in files{
    if(!files.hasSuffix(".jpeg")){
        count+=1
        continue
    }else{
        print("Found file at \(count)")
    }
}

func printTimesTable(number: Int){
    for i in 1...number{
        for j in 1...number{
            print(i*j,terminator: " ")
        }
        print("")
    }
}

func rollDice() -> Int {
    return Int.random(in: 1...6)
}

print(rollDice())

func makeUpper( _ string : String) ->String{
    return string.uppercased()
}

func greet(_ person: String, formal: Bool = false){
    if(formal){
        print("Hello \(person)")
    }else{
        print("Yo \(person)")
    }
}


var string = "this is all lower case"
print(makeUpper(string))

greet("Gavin")
greet("Gavin",formal: true)

enum PasswordError: Error{
    case short, obvious
}

func checkPassword(_ pass: String) throws -> String{
    if(pass.count < 10){
        throw PasswordError.short
    }else if (pass == "ABC"){
        throw PasswordError.obvious
    }else{
        return "Good"
    }
}

do{
    let result = try checkPassword("String")
    print("Rating \(result)")
}catch (PasswordError.obvious){
    print("lol, I have the same combination?? ")
}catch(PasswordError.short){
    print("you are joking, that short? ")
}catch{
    print("critical failure ")
}

let team = ["gav","wes","taylor","connor","wyatt"]
let onlyW = team.filter({ (name: String) -> Bool in
    return name.hasPrefix("T")
})

print("Enter your favorite color")
let screamer = readLine()
print("Awesome \(screamer!) is my favorite too")

//print(employee["job",default: "Uknown"])
//print(data)
//print(numbers)
//print(colors)
//print(message)
