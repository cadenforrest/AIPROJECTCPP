#include <iostream>
#include "Variable-c_w424.h"


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
  if (userAnswer == true){ 
    this->answer = true; 
  }
  else{
    this->answer = false;
  }
}

void Variable::setVariableName(std::string namestring){
  this->variablename = namestring; 

}

bool Variable::getAnswer(){
  return this->answer;
}

void Variable::setTreatment(std::string treatment1){ 
  this->treatment = treatment1; 
}

std::string Variable::getTreatment(){
  return this->treatment; 
}