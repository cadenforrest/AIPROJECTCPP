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
}//set conclusion to c 

string Conclusion::getConclusion(){
  return this->conclusion;
}//get conclusion string

void Conclusion::setRuleList(std::vector<int> list){
  for (int i = 0; i < list.size(); i++){
    this->ruleList.push_back(list[i]);
  }
}

std::vector<int> Conclusion::getRuleList(){
  return this->ruleList; 
}

std::vector<bool> Conclusion::getRuleAnswers(){ 
  return this->ruleAnswers;
}

void Conclusion::setRuleAnswers(std::vector<bool> list){
  for (int i = 0; i < list.size(); i++){ 
    this->ruleAnswers.push_back(list[i]); 
  }
}

void Conclusion::setTreatment(std::string usertreatment){
  this->treatment = usertreatment;
}

std::string Conclusion::getTreatment(){
  return this->treatment; 
}
