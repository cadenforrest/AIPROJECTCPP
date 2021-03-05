#include <iostream>
#include <list>
#include <string>
#include "Variable.h"
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

  std::list<Variable> VariableList; 

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

  // std::list<Variable>::iterator it; 
  // for (it = VariableList.begin(); it!= VariableList.end(); ++it) {
  //   std::cout << it->getQuestion();
  // }

  return 0;
}


