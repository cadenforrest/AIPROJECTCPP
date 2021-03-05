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
3. backPain
4. abPain
5. sidePain
6. breastPain
7. pelvicPain
8. testiPain
9. coughBlood
10. urineBlood
11. rectalBlood
12. weightLoss
13. erectDys
14. freqUrine
15. breastLump
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
  backPain.setQuestion("Is the patient experiencing back pain?"); 
  VariableList.push_back(backPain); 

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
  VariableList.push_back(rectalBlood); 

  Variable weightLoss; 
  weightLoss.setQuestion("Is the patient experiencing unexpected weight loss?"); 
  VariableList.push_back(weightLoss);

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
  std::cout << "---------------------VARIABLE LIST---------------------" << std::endl << std::endl;
  int i = 1; 
  std::vector<Variable>::iterator it; 
  for (it = VariableList.begin(); it!= VariableList.end(); ++it) {
    std::cout << i << ". " << it->getQuestion();
    std::cout << std::endl; 
    i++; 
  }
  std::cout << std::endl << std::endl; 


  ////////////////////////////////////////////////
  
  std::vector<Conclusion> ConclusionList;


  Conclusion breastCancer; 
  breastCancer.setRuleNum(10);
  breastCancer.setConclusion("Patient has breast cancer");
  breastCancer.setRuleList({1, 2});
  breastCancer.setRuleAnswers({true, true}); 
  ConclusionList.push_back(breastCancer); 

  Conclusion endoCancer;
  endoCancer.setRuleNum(20); 
  endoCancer.setConclusion("Patient has endometrial cancer"); 
  endoCancer.setRuleList({1, 3});
  endoCancer.setRuleAnswers({true, true}); 
  ConclusionList.push_back(endoCancer); 

  Conclusion lungCancer; 
  lungCancer.setRuleNum(30); 
  lungCancer.setConclusion("Patient has lung cancer"); 
  lungCancer.setRuleList({1, 2, 12, 9});
  lungCancer.setRuleAnswers({true, true, true, true}); 
  ConclusionList.push_back(lungCancer);

  Conclusion heartCancer;
  heartCancer.setRuleNum(40);
  heartCancer.setConclusion("Patient has heart cancer");
  heartCancer.setRuleList({1, 2, 12, 15});
  heartCancer.setRuleAnswers({true, true, true, false});
  ConclusionList.push_back(heartCancer);

  Conclusion breastCancer1; 
  breastCancer1.setRuleNum(50); 
  breastCancer1.setConclusion("Patient has breast cancer"); 
  breastCancer1.setRuleList({1, 2, 12, 15}); 
  breastCancer1.setRuleAnswers({true, true, true, true}); 
  ConclusionList.push_back(breastCancer1); 

  Conclusion noCancer; 
  noCancer.setRuleNum(60); 
  noCancer.setConclusion("Patient does not have cancer"); 
  noCancer.setRuleList({1, 2, 12, 15}); 
  noCancer.setRuleAnswers({true, true, false, false}); 
  ConclusionList.push_back(noCancer);

  Conclusion bladderCancer;
  bladderCancer.setRuleNum(70); 
  bladderCancer.setConclusion("Patient has bladder cancer");
  bladderCancer.setRuleList({1, 2, 3, 10, 14}); 
  bladderCancer.setRuleAnswers({true, false, true, true, true}); 
  ConclusionList.push_back(bladderCancer); 

  Conclusion kidneyCancer; 
  kidneyCancer.setRuleNum(80); 
  kidneyCancer.setConclusion("Patient has kidney cancer"); 
  kidneyCancer.setRuleList({1, 2, 3, 10, 14, 12}); 
  kidneyCancer.setRuleAnswers({true, false, true, true, false, true}); 
  ConclusionList.push_back(kidneyCancer); 

  Conclusion bladderCancer1; 
  bladderCancer1.setRuleNum(90); 
  bladderCancer1.setConclusion("Patient has bladder cancer"); 
  bladderCancer1.setRuleList({1, 2, 3, 10, 14, 12}); 
  bladderCancer1.setRuleAnswers({true, false, true, true, false, false}); 
  ConclusionList.push_back(bladderCancer1); 

  Conclusion colorCancer;
  colorCancer.setRuleNum(100); 
  colorCancer.setConclusion("Patient has colorectal cancer"); 
  colorCancer.setRuleList({1, 2, 3, 4, 12, 11}); 
  colorCancer.setRuleAnswers({true, false, false, true, true, true}); 
  ConclusionList.push_back(colorCancer); 

  Conclusion kidneyCancer1; 
  kidneyCancer1.setRuleNum(110); 
  kidneyCancer1.setConclusion("Patient has kidney cancer"); 
  kidneyCancer1.setRuleList({1, 2, 3, 4, 12, 11}); 
  kidneyCancer1.setRuleAnswers({true, false, false, true, true, false}); 
  ConclusionList.push_back(kidneyCancer1); 

  Conclusion bladderCancer2; 
  bladderCancer2.setRuleNum(120); 
  bladderCancer2.setConclusion("Patient has bladder cancer"); 
  bladderCancer2.setRuleList({1, 2, 3, 12, 10}); 
  bladderCancer2.setRuleAnswers({true, false, false, false, true}); 
  ConclusionList.push_back(bladderCancer2); 

  Conclusion noCancer1; 
  noCancer1.setRuleNum(130); 
  noCancer1.setConclusion("Patient does not have cancer"); 
  noCancer1.setRuleList({1, 2, 3, 4, 12, 10}); 
  noCancer1.setRuleAnswers({true, false, false, false, false}); 
  ConclusionList.push_back(noCancer1); 

  Conclusion bladderCancer3; 
  bladderCancer3.setRuleNum(140); 
  bladderCancer3.setConclusion("Patient has bladder cancer"); 
  bladderCancer3.setRuleList({1, 2, 3, 4, 5, 10}); 
  bladderCancer3.setRuleAnswers({true, false, false, false, true, true}); 
  ConclusionList.push_back(bladderCancer3); 

  Conclusion noCancer2; 
  noCancer2.setRuleNum(150); 
  noCancer2.setConclusion("Patient does not have cancer"); 
  noCancer2.setRuleList({1, 2, 3, 4, 5}); 
  noCancer2.setRuleAnswers({true, false, false, false, false}); 
  ConclusionList.push_back(noCancer2); 

  Conclusion proCancer; 
  proCancer.setRuleNum(160); 
  proCancer.setConclusion("Patient has prostate cancer"); 
  proCancer.setRuleList({1, 3, 9, 14, 13}); 
  proCancer.setRuleAnswers({false, true, true, true, true}); 
  ConclusionList.push_back(proCancer); 

  Conclusion bladderCancer4;
  bladderCancer4.setRuleNum(170);
  bladderCancer4.setConclusion("Patient has bladder cancer"); 
  bladderCancer4.setRuleList({1, 3, 9, 14, 13}); 
  bladderCancer4.setRuleAnswers({false, true, true, true, false});  
  ConclusionList.push_back(bladderCancer4); 

  Conclusion kidneyCancer2; 
  kidneyCancer2.setRuleNum(180); 
  kidneyCancer2.setConclusion("Patient has kidney cancer"); 
  kidneyCancer2.setRuleList({1, 2, 10, 14, 12}); 
  kidneyCancer2.setRuleAnswers({false, true, true, false, true}); 
  ConclusionList.push_back(kidneyCancer2); 

  Conclusion bladderCancer5; 
  bladderCancer5.setRuleNum(190); 
  bladderCancer5.setConclusion("Patient has bladder cancer"); 
  bladderCancer5.setRuleList({1, 2, 10, 14, 12}); 
  bladderCancer5.setRuleAnswers({false, true, true, false, false}); 
  ConclusionList.push_back(bladderCancer5);

  Conclusion noCancer3; 
  noCancer3.setRuleNum(200); 
  noCancer3.setConclusion("Patient does not have cancer"); 
  noCancer3.setRuleList({1, 3, 10}); 
  noCancer3.setRuleAnswers({false, true, false}); 
  ConclusionList.push_back(noCancer3); 

  Conclusion lungCancer1; 
  lungCancer1.setRuleNum(210); 
  lungCancer1.setConclusion("Patient has lung cancer");
  lungCancer1.setRuleList({1, 3, 2, 12, 9}); 
  lungCancer1.setRuleAnswers({false, false, true, true, true});
  ConclusionList.push_back(lungCancer1); 

  Conclusion heartCancer1; 
  heartCancer1.setRuleNum(220); 
  heartCancer1.setConclusion("Patient has heart cancer"); 
  heartCancer1.setRuleList({1, 3, 2, 12, 9}); 
  heartCancer1.setRuleAnswers({false, false, true, true, false}); 
  ConclusionList.push_back(heartCancer1); 

  Conclusion breastCancer2; 
  breastCancer2.setRuleNum(230); 
  breastCancer2.setConclusion("Patient has breast cancer"); 
  breastCancer2.setRuleList({1, 3, 2, 12, 15}); 
  breastCancer2.setRuleAnswers({false, false, true, false, true}); 
  ConclusionList.push_back(breastCancer2); 

  Conclusion noCancer4; 
  noCancer4.setRuleNum(240); 
  noCancer4.setConclusion("Patient does not have cancer"); 
  noCancer4.setRuleList({1, 3, 2, 12, 15}); 
  noCancer4.setRuleAnswers({false, false, true, false, false}); 
  ConclusionList.push_back(noCancer4); 


  Conclusion colorCancer1; 
  colorCancer1.setRuleNum(250); 
  colorCancer1.setConclusion("Patient has colorectal cancer"); 
  colorCancer1.setRuleList({1, 3, 2, 4, 12, 11}); 
  colorCancer1.setRuleAnswers({false, false, false, true, true, true}); 
  ConclusionList.push_back(colorCancer1); 


  Conclusion kidneyCancer3; 
  kidneyCancer3.setRuleNum(260); 
  kidneyCancer3.setConclusion("Patient has kidney cancer"); 
  kidneyCancer3.setRuleList({1, 3, 2, 4, 12, 11}); 
  kidneyCancer3.setRuleAnswers({false, false, false, true, true, false}); 
  ConclusionList.push_back(kidneyCancer3); 

  Conclusion proCancer1; 
  proCancer1.setRuleNum(270); 
  proCancer1.setConclusion("Patient has prostate cancer"); 
  proCancer1.setRuleList({1, 3, 2, 4, 12, 13}); 
  proCancer1.setRuleAnswers({false, false, false, true,false, true});
  ConclusionList.push_back(proCancer1); 

  Conclusion bladderCancer6; 
  bladderCancer6.setRuleNum(280); 
  bladderCancer6.setConclusion("Patient has bladder cancer"); 
  bladderCancer6.setRuleList({1, 3, 2, 4, 12, 13}); 
  bladderCancer6.setRuleAnswers({false, false, false, true, false, false}); 
  ConclusionList.push_back(bladderCancer6);

  Conclusion colorCancer2; 
  colorCancer2.setRuleNum(290); 
  colorCancer2.setConclusion("Patient has colorectal cancer"); 
  colorCancer2.setRuleList({1, 3, 2, 4, 5, 10, 12, 11});
  colorCancer2.setRuleAnswers({false, false, false, false, true, true, true, true}); 
  ConclusionList.push_back(colorCancer2);

  Conclusion noCancer5; 
  noCancer5.setRuleNum(300); 
  noCancer5.setConclusion("Patient does not have cancer"); 
  noCancer5.setRuleList({1, 3, 2, 4, 5, 10, 12, 13}); 
  noCancer5.setRuleAnswers({false, false, false, false, true, true, true, false}); 
  ConclusionList.push_back(noCancer5); 


  Conclusion proCancer2;
  proCancer2.setRuleNum(310);
  proCancer2.setConclusion("Patient has prostate cancer");
  proCancer2.setRuleList({1, 3, 2, 4, 5, 12, 13});
  proCancer2.setRuleAnswers({false, false, false, false, true, false,                                                              true});
  ConclusionList.push_back(proCancer2);

  Conclusion bladderCancer7;
  bladderCancer7.setRuleNum(320);
  bladderCancer7.setConclusion("Patient has bladder cancer");
  bladderCancer7.setRuleList({1, 3, 2, 4, 5, 10, 12, 13});
  bladderCancer7.setRuleAnswers({false, false, false, false, true,                                                 true, false, false});
  ConclusionList.push_back(bladderCancer7);
  
  Conclusion noCancer7;
  noCancer7.setRuleNum(330);
  noCancer7.setConclusion("Patient does not have cancer");
  noCancer7.setRuleList({1, 3, 2, 4, 5, 10});
  noCancer7.setRuleAnswers({false, false, false, false, true, false});
  ConclusionList.push_back(noCancer7);

  Conclusion noCancer8;
  noCancer8.setRuleNum(340);
  noCancer8.setConclusion("Patient does not have cancer");
  noCancer8.setRuleList({1, 3, 2, 4, 5});
  noCancer8.setRuleAnswers({false, false, false, false, false});
  ConclusionList.push_back(noCancer8);

  Conclusion testiCancer;
  testiCancer.setRuleNum(350);
  testiCancer.setConclusion("Patient has testicular cancer");
  testiCancer.setRuleList({1, 8});
  testiCancer.setRuleAnswers({false, true});
  ConclusionList.push_back(testiCancer);


  //PRINT CONCLUSION LIST
  std::cout << "---------------------CONCLUSION LIST---------------------" << std::endl << std::endl;
  i = 1; 
  std::vector<Conclusion>::iterator it1; 
  for (it1 = ConclusionList.begin(); it1!= ConclusionList.end(); ++it1) {
    std::cout << i << ". " << it1->getConclusion();
    std::cout << std::endl; 
    i++; 
  }

  std::cout << std::endl << std::endl; 

  
  
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