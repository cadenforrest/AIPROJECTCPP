#include <iostream>
#include <vector>
#include "Conclusion.h"
#include "Variable.h"
using namespace std;

void Conclusion::setRuleNum(int n){
  this->ruleNum = n;
}//set rule number
int Conclusion::getRuleNum(){
  return this->ruleNum;
}//get rule number

void Conclusion::setConclusion(string c){
  this->conclusion = c;
}//set conclusion result

string Conclusion::getConclusion(){
  return this->conclusion;
}//get conclusion result

void Conclusion::setRuleList(std::vector<int> list){
  for (int i = 0; i < list.size(); i++){
    this->ruleList.push_back(list[i]);
  }
}



// void Conclusion::setknowledgeBase(string c){
//   this->cancer = c;
// }

// string Conclusion::getknowlegeBase(){
//   return this->cancer;
// }