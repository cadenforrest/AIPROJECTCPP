#include <iostream>
#include <vector>
#include <string>
#include "Variable.h"
#include "Conclusion.h"
using namespace std;

/*
Variable List
1. Gender
2. chestPain
backPain
abPain
sidePain
breastPain
pelvicPain
testiPain
coughBlood
urineBlood
rectalBlood
weightLoss
erectDys
freqUrine
breastLump

(if VariableList[1].isInstatiated() == false)

 then ask the question, store value in
 VariableList[1].value()

if (VariableList[1].Value() == yes 

(if VariableList[2].isInstatiated() == false)

then ask the question, store value in VariableList[2].Value()

Conclusion List
cancer



Knowledge Base
10: 
    contains some list containing: *VariableList[1], *VariableList[2]
  


*/




int main(){
  //make variable list
  std::vector<Variable> VariableList; 

  Variable Gender; 
  Gender.setQuestion("Is the patient female?"); 
  VariableList.push_back(Gender); 

  Variable chestPain; 
  chestPain.setQuestion("Is the patient experiencing chest pain?"); 
  VariableList.push_back(chestPain); 

  Variable backPain; 
  backPain.setQuestion("Ist the patient experiencing back pain?"); 
  VariableList.push_back(Gender); 

  Variable abPain; 
  abPain.setQuestion("Is the patient experiencing abdomenal pain?"); 
  VariableList.push_back(abPain); 

  Variable sidePain; 
  sidePain.setQuestion("Is the patient experiencing pain in their side?"); 
  VariableList.push_back(sidePain); 

  Variable testiPain; 
  testiPain.setQuestion("Is the patient experiencing pain in their testicles?"); 
  VariableList.push_back(testiPain); 

  Variable pelvicPain; 
  pelvicPain.setQuestion("Is the patient experiencing pelvic pain?"); 
  VariableList.push_back(pelvicPain); 

  Variable coughBlood; 
  coughBlood.setQuestion("Is the patient coughing up blood?"); 
  VariableList.push_back(coughBlood); 

  Variable urineBlood; 
  urineBlood.setQuestion("Is the patient urinating blood?"); 
  VariableList.push_back(urineBlood);

  Variable rectalBlood; 
  rectalBlood.setQuestion("Is the patient experiencing rectile bleeding?"); 
  VariableList.push_back(Gender); 

  Variable weightLoss; 
  weightLoss.setQuestion("Is the patient experiencing unexpected weight loss?"); 
  VariableList.push_back(Gender);

  Variable erectDys; 
  erectDys.setQuestion("Is the patient experiencing erectile dysfuction?"); 
  VariableList.push_back(erectDys); 

  Variable freqUrine; 
  freqUrine.setQuestion("Is the patient experiencing frequent urination?"); 
  VariableList.push_back(freqUrine); 
  
  Variable breastLump; 
  breastLump.setQuestion("Does the patient have a breast lump?"); 
  VariableList.push_back(breastLump); 

  //print variablelist
  std::vector<Variable>::iterator it; 
  for (it = VariableList.begin(); it!= VariableList.end(); ++it) {
    std::cout << it->getQuestion();
    std::cout << std::endl; 
  }

  
  std::vector<Conclusion> ConclusionList;
  Conclusion breastCancer; 
  breastCancer.setRuleNum(10);
  breastCancer.setConclusion("Patient has breast cancer");
  breastCancer.setRuleList({1, 2});
  ConclusionList.push_back(breastCancer); 

  


  
  // Conclusion endoCancer;
  // endoCancer.setRuleNum(???);
  // endoCancer.setConclusion(?????);
  // ConclusionList.push_back(endoCancer);

  // Conclusion lungCancer;
  // lungCancer.setRuleNum(??);
  // lungCancer.setConclusion(????);
  // ConclusionList.push_back(lungCancer);

  // Conclusion heartCancer;
  // heartCancer.setRuleNum(??);
  // heartCancer.setConclusion(??);
  // ConclusionList.push_back(heartCancer);
  

  return 0;
}

/*SEARCH FUNCTION PSUEDOCODE:

  Variable search(std::list<Variable> VariableList, string key){
    for i in list: 
      searchVariable = VariableList.pop();
      if(searchVariable.getName() = key){
        return searchVariable
      }
  }

  search = search(VariableList, "urineBlood");
  search.getInstantiated(); 




*/

//bool1 = (VARIABLE1 && VARIABLE2 && VARIABLE3);

//CONCLUSION10.SETRULE(LIST->GENDER.GETANSWER() == TRUE && LIST->BREASTPAIN.GETANSWER() == TRUE);

    //SETRULE(bool crule){
      // this->rule = crule;
    //}

//IF RULE1 == TRUE {
//  PRINT 
//}