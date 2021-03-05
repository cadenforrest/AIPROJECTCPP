#include <iostream>
#include "Variable.h"


void Variable::setQuestion(std::string questionsstring){
  this->question = questionsstring; 
}

std::string Variable::getQuestion(){ 
  return this->question; 
}

bool Variable::getInstantiated(){
  return this->isInstantiated; 
}

void Variable::Instantiate(bool userAnswer){
  this->isInstantiated = true; 
  this->answer = userAnswer; 
}

void Variable::setVariableName(std::string namestring){
  this->variablename = namestring; 

}
