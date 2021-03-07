#include <iostream>
#include <vector>
#include <string>
#include "Variable-c_w424.h"
#include "Conclusion-c_w424.h"
using namespace std;



int Diagnosis(std::vector<Conclusion> ConclusionList, std::vector<Variable> VariableList);
void Treatment(std::vector<Conclusion> ConclusionList, std::vector<Variable> VariableList, int index);
std::vector<Variable> makeVariableList(); 
std::vector<Conclusion> makeKnowledgeBase(); 
void printVariableList(std::vector<Variable> VariableList); 
void printKnowledgeBase(std::vector<Conclusion> ConclusionList, std::vector<Variable> VariableList); 


int main(){

  std::vector<Variable> VariableList = makeVariableList(); 
  std::vector<Conclusion> ConclusionList = makeKnowledgeBase(); 
  
  printVariableList(VariableList); 
  printKnowledgeBase(ConclusionList, VariableList); 

  std::cout << std::endl << std::endl; 

  int diagnosisIndex = Diagnosis(ConclusionList, VariableList); 
  std::cout << std::endl << std::endl;

  Treatment(ConclusionList, VariableList, diagnosisIndex); 
  std::cout << std::endl << std::endl; 

  std::cout << "Goodbye!" << std::endl; 

  return 0;
}



int Diagnosis(std::vector<Conclusion> ConclusionList, std::vector<Variable> VariableList){ 

  std::cout << "---------------------DIAGNOSIS---------------------" << std::endl << std::endl;

  string diagnosis;
  bool end = false; 
  std::string useranswer;
  bool userbool; 

  //loop through entire conclusion list
  for (int i = 0; i < ConclusionList.size(); i++)
  { 
    //loop through rule list within conclusion i
    for (int j = 0; j < ConclusionList[i].getRuleList().size(); j++)
    {
      //if variable isn't instantiated, ask question and instantiate
      if (!VariableList[ConclusionList[i].getRuleList()[j] - 1].getInstantiated()){
        //ask question
        std::cout << VariableList[ConclusionList[i].getRuleList()[j] - 1].getQuestion() << ": "; 
        //cin answer
        std::cin >> useranswer;
        //validate
        while (useranswer != "YES" && useranswer !="yes" && useranswer !="NO" && useranswer !="no"){ 
          std::cout << "Answer invalid - please answer 'YES' or 'NO'" << std::endl << std::endl; 
          //re-print question
          std::cout << VariableList[ConclusionList[i].getRuleList()[j] - 1].getQuestion() << ": "; 
          //cin answer
          std::cin >> useranswer;
        }
        //convert to boolean
        if (useranswer == "YES" || useranswer == "yes"){
          userbool = true; 
        }
        else if (useranswer == "NO" || useranswer == "no"){
          userbool = false;
        }

        //instantiate variable and store answer
        VariableList[ConclusionList[i].getRuleList()[j] - 1].Instantiate(userbool);
        
        //check if corresponding answer in conclusion list matches. if match, continue 
        if (VariableList[ConclusionList[i].getRuleList()[j]-1].getAnswer() == ConclusionList[i].getRuleAnswers()[j]){
          int matchcount = 0; 
          //if we're at the end of the list of relevant variables and everything matches, print diagnosis and end program

          //sum number of matching answers
          for (int a = 0; a < ConclusionList[i].getRuleList().size(); a++){
            if (VariableList[ConclusionList[i].getRuleList()[a]-1].getAnswer() == ConclusionList[i].getRuleAnswers()[a]){
              matchcount++; 
            }
          }

          //if matching answers meets the required amount, print diagnosis and terminate the program
          if (matchcount == ConclusionList[i].getRuleList().size()){
            std::cout << "Diagnosis reached. Patient has " << ConclusionList[i].getConclusion() << std::endl;
            // return diagnosis index back to main from function
            return i; 
          }
          continue; 
        }

        else{
          break;
        }
      }

      //if variable is instantiated, check if corresponding answer in conclusion list matches. if match, continue to next question
      else{
        //check if corresponding answer in conclusion list matches
        if (VariableList[ConclusionList[i].getRuleList()[j]-1].getAnswer() == ConclusionList[i].getRuleAnswers()[j]){
          //if we're at the end of the variable list and everything matches, print the conclusion and end the program
          int matchcount = 0; 
          for (int a = 0; a < ConclusionList[i].getRuleList().size(); a++){
            if (VariableList[ConclusionList[i].getRuleList()[a]-1].getAnswer() == ConclusionList[i].getRuleAnswers()[a]){
              matchcount++; 
            }
          }

          //if matching answers meets the required amount, print diagnosis and terminate the program
          if (matchcount == ConclusionList[i].getRuleList().size()){
            std::cout << "Diagnosis reached. Patient has " << ConclusionList[i].getConclusion() << std::endl; 

            // return diagnosis index back to main from function
            return i; 
          }
          continue; 
        }
        //if it doesnt match, go to the next rule
        else{
          break;
        }
      }
    }
  }

  std::cout << "uh oh, something went wrong. " << std::endl;
  return 0; 
}

void Treatment(std::vector<Conclusion> ConclusionList, std::vector<Variable> VariableList, int index){

  std::cout << "---------------------TREATMENT---------------------" << std::endl << std::endl;

  std::cout << "Recommended cancer treatment: " << ConclusionList[index].getTreatment() << std::endl << std::endl; 

  std::cout << "Suggested symptom-specific treatment: " << std::endl << std::endl; 

  int count = 1;
  for (int i = 1; i < ConclusionList[index].getRuleList().size(); i++){
    if (ConclusionList[index].getRuleAnswers()[i]){
      std::cout << count << ")  " << VariableList[ConclusionList[index].getRuleList()[i] - 1].getTreatment() << std::endl;  
      count++; 
    }
  }
}

void printVariableList(std::vector<Variable> VariableList){
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
}


void printKnowledgeBase(std::vector<Conclusion> ConclusionList, std::vector<Variable> VariableList){

  std::cout << "---------------------CONCLUSION LIST---------------------" << std::endl << std::endl;

  for (int i = 0; i < ConclusionList.size(); i++) {
    std::cout << i+1 << ". " << ConclusionList[i].getConclusion() << std::endl; 

    for (int j = 0; j < ConclusionList[i].getRuleList().size(); j++){ 
      std::cout << "  " << VariableList[ConclusionList[i].getRuleList()[j] - 1].getQuestion() << " = " 
      << ConclusionList[i].getRuleAnswers()[j] 
      << std::endl; 
    }
    std::cout << std::endl;
  
  }

}


std::vector<Variable> makeVariableList(){

  std::vector<Variable> VariableList; 

  Variable Gender; 
  Gender.setQuestion("Is the patient female?");
  Gender.setTreatment("");  
  VariableList.push_back(Gender); 

  Variable chestPain; 
  chestPain.setQuestion("Is the patient experiencing chest pain?"); 
  chestPain.setTreatment("Prescribe painkillers to treat chest pain");
  VariableList.push_back(chestPain); 

  Variable backPain; 
  backPain.setQuestion("Is the patient experiencing back pain?"); 
  backPain.setTreatment("Prescribe painkillers to treat back pain");
  VariableList.push_back(backPain); 

  Variable abPain; 
  abPain.setQuestion("Is the patient experiencing abdomenal pain?"); 
  abPain.setTreatment("Prescribe painkillers to treat abdominal pain");
  VariableList.push_back(abPain); 

  Variable sidePain; 
  sidePain.setQuestion("Is the patient experiencing pain in their side?"); 
  sidePain.setTreatment("Prescribe painkillers to treat side pain");
  VariableList.push_back(sidePain); 
  
  Variable breastPain;
  breastPain.setQuestion("Is the patient experiencing breast pain?");
  breastPain.setTreatment("Prescribe painkillers to treat breast pain");
  VariableList.push_back(breastPain); 

  Variable pelvicPain; 
  pelvicPain.setQuestion("Is the patient experiencing pelvic pain?");
  pelvicPain.setTreatment("Prescribe painkillers to treat pelvic pain");
  VariableList.push_back(pelvicPain); 
  
  Variable testiPain; 
  testiPain.setQuestion("Is the patient experiencing pain in their testicles?"); 
  testiPain.setTreatment("Prescribe painkillers to treat testi pain"); 
  VariableList.push_back(testiPain);

  Variable coughBlood; 
  coughBlood.setQuestion("Is the patient coughing up blood?"); 
  coughBlood.setTreatment("Prescribe cough suppressants to limit cough");
  VariableList.push_back(coughBlood); 

  Variable urineBlood; 
  urineBlood.setQuestion("Is the patient urinating blood?"); 
  urineBlood.setTreatment("Prescribe antibotics to treat potential UTI's");
  VariableList.push_back(urineBlood);

  Variable rectalBlood; 
  rectalBlood.setQuestion("Is the patient experiencing rectile bleeding?"); 
  rectalBlood.setTreatment("Prescribe ointment or oral medication to resolve any constipation issues");
  VariableList.push_back(rectalBlood); 

  Variable weightLoss; 
  weightLoss.setQuestion("Is the patient experiencing unexpected weight loss?"); 
  weightLoss.setTreatment("Suggest a change in diet to address weight loss");
  VariableList.push_back(weightLoss);
  

  Variable erectDys; 
  erectDys.setQuestion("Is the patient experiencing erectile dysfuction?"); 
  erectDys.setTreatment("Prescribe oral medication for erectile dysfunction");
  VariableList.push_back(erectDys); 

  Variable freqUrine; 
  freqUrine.setQuestion("Is the patient experiencing frequent urination?"); 
  freqUrine.setTreatment("Prescribe oral medication for frequent urination");
  VariableList.push_back(freqUrine); 
  
  Variable breastLump; 
  breastLump.setQuestion("Does the patient have a breast lump?"); 
  VariableList.push_back(breastLump); 
  breastLump.setTreatment("Obtain X-ray of breast lump every 6 months");

  return VariableList;
}

std::vector<Conclusion> makeKnowledgeBase(){ 

  std::vector<Conclusion> ConclusionList;

  Conclusion breastCancer; 
  breastCancer.setRuleNum(10);
  breastCancer.setConclusion("breast cancer");
  breastCancer.setTreatment("Surgery to remove tumor from breast");
  breastCancer.setRuleList({1, 6});
  breastCancer.setRuleAnswers({true, true}); 
  ConclusionList.push_back(breastCancer); 

  Conclusion endoCancer;
  endoCancer.setRuleNum(20); 
  endoCancer.setConclusion("endometrial cancer"); 
  endoCancer.setTreatment("Chemotherapy to kill tumor in uterus");
  endoCancer.setRuleList({1, 7});
  endoCancer.setRuleAnswers({true, true}); 
  ConclusionList.push_back(endoCancer); 

  Conclusion lungCancer; 
  lungCancer.setRuleNum(30); 
  lungCancer.setConclusion("lung cancer"); 
  lungCancer.setTreatment("Chemotherapy to kill tumor in lungs");
  lungCancer.setRuleList({1, 2, 12, 9});
  lungCancer.setRuleAnswers({true, true, true, true}); 
  ConclusionList.push_back(lungCancer);

  Conclusion heartCancer;
  heartCancer.setRuleNum(40);
  heartCancer.setConclusion("heart cancer");
  heartCancer.setTreatment("Chemotherapy to kill tumor in heart");
  heartCancer.setRuleList({1, 2, 12, 15});
  heartCancer.setRuleAnswers({true, true, true, false});
  ConclusionList.push_back(heartCancer);

  Conclusion breastCancer1; 
  breastCancer1.setRuleNum(50); 
  breastCancer1.setConclusion("breast cancer"); 
  breastCancer1.setTreatment("Surgery to remove tumor from breast");
  breastCancer1.setRuleList({1, 2, 12, 15}); 
  breastCancer1.setRuleAnswers({true, true, false, true});
  ConclusionList.push_back(breastCancer1); 

  Conclusion noCancer; 
  noCancer.setRuleNum(60); 
  noCancer.setConclusion("no cancer"); 
  noCancer.setTreatment("No treatment necessary.");
  noCancer.setRuleList({1, 2, 12, 15}); 
  noCancer.setRuleAnswers({true, true, false, false}); 
  ConclusionList.push_back(noCancer);

  Conclusion bladderCancer;
  bladderCancer.setRuleNum(70); 
  bladderCancer.setConclusion("bladder cancer");
  bladderCancer.setTreatment("Surgery to remove tumor from bladder");
  bladderCancer.setRuleList({1, 2, 3, 10, 14}); 
  bladderCancer.setRuleAnswers({true, false, true, true, true}); 
  ConclusionList.push_back(bladderCancer); 

  Conclusion kidneyCancer; 
  kidneyCancer.setRuleNum(80); 
  kidneyCancer.setConclusion("kidney cancer"); 
  kidneyCancer.setTreatment("Surgery to remove tumor from kidney");
  kidneyCancer.setRuleList({1, 2, 3, 10, 14, 12}); 
  kidneyCancer.setRuleAnswers({true, false, true, true, false, true});
  ConclusionList.push_back(kidneyCancer); 

  Conclusion bladderCancer1; 
  bladderCancer1.setRuleNum(90); 
  bladderCancer1.setConclusion("bladder cancer"); 
  bladderCancer1.setTreatment("Surgery to remove tumor from bladder");
  bladderCancer1.setRuleList({1, 2, 3, 10, 14, 12}); 
  bladderCancer1.setRuleAnswers({true, false, true, true, false, false}); 
  ConclusionList.push_back(bladderCancer1); 

  Conclusion colorCancer;
  colorCancer.setRuleNum(100); 
  colorCancer.setConclusion("colorectal cancer"); 
  colorCancer.setTreatment("Surgery to remove tumor within colon");
  colorCancer.setRuleList({1, 2, 3, 4, 12, 11}); 
  colorCancer.setRuleAnswers({true, false, false, true, true, true});
  ConclusionList.push_back(colorCancer); 

  Conclusion kidneyCancer1; 
  kidneyCancer1.setRuleNum(110); 
  kidneyCancer1.setConclusion("kidney cancer"); 
  kidneyCancer1.setTreatment("Surgery to remove tumor from kidney");
  kidneyCancer1.setRuleList({1, 2, 3, 4, 12, 11}); 
  kidneyCancer1.setRuleAnswers({true, false, false, true, true, false}); 
  ConclusionList.push_back(kidneyCancer1); 

  Conclusion bladderCancer2; 
  bladderCancer2.setRuleNum(120); 
  bladderCancer2.setConclusion("bladder cancer"); 
  bladderCancer2.setTreatment("Surgery to remove tumor from bladder");
  bladderCancer2.setRuleList({1, 2, 3, 12, 10}); 
  bladderCancer2.setRuleAnswers({true, false, false, false, true}); 
  ConclusionList.push_back(bladderCancer2); 

  Conclusion noCancer8;
  noCancer8.setRuleNum(125); 
  noCancer8.setConclusion("no cancer");
  noCancer8.setTreatment("No treatment necessary."); 
  noCancer8.setRuleList({1, 2, 3, 10});
  noCancer8.setRuleAnswers({true, false, true, false}); 
  ConclusionList.push_back(noCancer8); 

  Conclusion noCancer1; 
  noCancer1.setRuleNum(130); 
  noCancer1.setConclusion("no cancer"); 
  noCancer1.setTreatment("No treatment necessary.");
  noCancer1.setRuleList({1, 2, 3, 4, 12, 10}); 
  noCancer1.setRuleAnswers({true, false, false, true, false, false}); 
  ConclusionList.push_back(noCancer1); 

  Conclusion bladderCancer3; 
  bladderCancer3.setRuleNum(140); 
  bladderCancer3.setConclusion("bladder cancer");
  bladderCancer3.setTreatment("Surgery to remove tumor from bladder"); 
  bladderCancer3.setRuleList({1, 2, 3, 4, 5, 10}); 
  bladderCancer3.setRuleAnswers({true, false, false, false, true, true}); 
  ConclusionList.push_back(bladderCancer3); 

  Conclusion noCancer2; 
  noCancer2.setRuleNum(150); 
  noCancer2.setConclusion("no cancer"); 
  noCancer2.setTreatment("No treatment necessary.");
  noCancer2.setRuleList({1, 2, 3, 4, 5}); 
  noCancer2.setRuleAnswers({true, false, false, false, false}); 
  ConclusionList.push_back(noCancer2); 

  Conclusion testiCancer;
  testiCancer.setRuleNum(160);
  testiCancer.setConclusion("testicular cancer");
  testiCancer.setTreatment("Surgery to remove the testicle");
  testiCancer.setRuleList({1, 8});
  testiCancer.setRuleAnswers({false, true});
  ConclusionList.push_back(testiCancer);

  Conclusion proCancer; 
  proCancer.setRuleNum(170); 
  proCancer.setConclusion("prostate cancer"); 
  proCancer.setTreatment("Chemotherapy to kill tumor in prostate");
  proCancer.setRuleList({1, 3, 10, 14, 13}); 
  proCancer.setRuleAnswers({false, true, true, true, true}); 
  ConclusionList.push_back(proCancer); 

  Conclusion bladderCancer4;
  bladderCancer4.setRuleNum(180);
  bladderCancer4.setConclusion("bladder cancer"); 
  bladderCancer4.setTreatment("Surgery to remove tumor from bladder");
  bladderCancer4.setRuleList({1, 3, 10, 14, 13}); 
  bladderCancer4.setRuleAnswers({false, true, true, true, false});  
  ConclusionList.push_back(bladderCancer4); 

  Conclusion kidneyCancer2; 
  kidneyCancer2.setRuleNum(190); 
  kidneyCancer2.setConclusion("kidney cancer"); 
  kidneyCancer2.setTreatment("Surgery to remove tumor from kidney");
  kidneyCancer2.setRuleList({1, 3, 10, 14, 12}); 
  kidneyCancer2.setRuleAnswers({false, true, true, false, true}); 
  ConclusionList.push_back(kidneyCancer2); 

  Conclusion bladderCancer5; 
  bladderCancer5.setRuleNum(200); 
  bladderCancer5.setConclusion("bladder cancer"); 
  bladderCancer5.setTreatment("Surgery to remove tumor from bladder");
  bladderCancer5.setRuleList({1, 3, 10, 14, 12}); 
  bladderCancer5.setRuleAnswers({false, true, true, false, false}); 
  ConclusionList.push_back(bladderCancer5);

  Conclusion noCancer3; 
  noCancer3.setRuleNum(210); 
  noCancer3.setConclusion("no cancer"); 
  noCancer3.setTreatment("No treatment necessary.");
  noCancer3.setRuleList({1, 3, 10}); 
  noCancer3.setRuleAnswers({false, true, false}); 
  ConclusionList.push_back(noCancer3); 

  Conclusion lungCancer1; 
  lungCancer1.setRuleNum(220); 
  lungCancer1.setConclusion("lung cancer");
  lungCancer1.setTreatment("Chemotherapy to kill tumor in lungs");
  lungCancer1.setRuleList({1, 3, 2, 12, 9}); 
  lungCancer1.setRuleAnswers({false, false, true, true, true});
  ConclusionList.push_back(lungCancer1); 

  Conclusion heartCancer1; 
  heartCancer1.setRuleNum(230); 
  heartCancer1.setConclusion("heart cancer"); 
  heartCancer1.setTreatment("Chemotherapy to kill tumor in heart");
  heartCancer1.setRuleList({1, 3, 2, 12, 9}); 
  heartCancer1.setRuleAnswers({false, false, true, true, false}); 
  ConclusionList.push_back(heartCancer1); 

  Conclusion breastCancer2; 
  breastCancer2.setRuleNum(240); 
  breastCancer2.setConclusion("breast cancer"); 
  breastCancer2.setTreatment("Surgery to remove tumor from breast");
  breastCancer2.setRuleList({1, 3, 2, 12, 15}); 
  breastCancer2.setRuleAnswers({false, false, true, false, true}); 
  ConclusionList.push_back(breastCancer2); 

  Conclusion noCancer4; 
  noCancer4.setRuleNum(250); 
  noCancer4.setConclusion("no cancer"); 
  noCancer4.setTreatment("No treatment necessary.");
  noCancer4.setRuleList({1, 3, 2, 12, 15}); 
  noCancer4.setRuleAnswers({false, false, true, false, false}); 
  ConclusionList.push_back(noCancer4); 

  Conclusion colorCancer1; 
  colorCancer1.setRuleNum(260); 
  colorCancer1.setConclusion("colorectal cancer"); 
  colorCancer1.setTreatment("Surgery to remove tumor within colon");
  colorCancer1.setRuleList({1, 3, 2, 4, 12, 11}); 
  colorCancer1.setRuleAnswers({false, false, false, true, true, true}); 
  ConclusionList.push_back(colorCancer1); 

  Conclusion colorCancer3; 
  colorCancer3.setRuleNum(265); 
  colorCancer3.setConclusion("colorectal cancer"); 
  colorCancer3.setTreatment("Surgery to remove tumor within colon");
  colorCancer3.setRuleList({1, 3, 2, 4, 5, 10, 12, 11}); 
  colorCancer3.setRuleAnswers({false, false, false, false, true, true, true, true}); 
  ConclusionList.push_back(colorCancer3); 

  Conclusion kidneyCancer3; 
  kidneyCancer3.setRuleNum(270); 
  kidneyCancer3.setConclusion("kidney cancer"); 
  kidneyCancer3.setTreatment("Surgery to remove tumor from kidney");
  kidneyCancer3.setRuleList({1, 3, 2, 4, 12, 11}); 
  kidneyCancer3.setRuleAnswers({false, false, false, true, true, false}); 
  ConclusionList.push_back(kidneyCancer3); 

  Conclusion kidneyCancer4; 
  kidneyCancer4.setRuleNum(275); 
  kidneyCancer4.setConclusion("kidney cancer"); 
  kidneyCancer4.setTreatment("Surgery to remove tumor from kidney");
  kidneyCancer4.setRuleList({1, 3, 2, 4, 5, 10, 12, 11}); 
  kidneyCancer4.setRuleAnswers({false, false, false, false, true, true, true, false}); 
  ConclusionList.push_back(kidneyCancer4); 

  Conclusion proCancer1; 
  proCancer1.setRuleNum(280); 
  proCancer1.setConclusion("prostate cancer"); 
  proCancer1.setTreatment("Chemotherapy to kill tumor in prostate");
  proCancer1.setRuleList({1, 3, 2, 4, 12, 13}); 
  proCancer1.setRuleAnswers({false, false, false, true,false, true});
  ConclusionList.push_back(proCancer1); 

  Conclusion bladderCancer6; 
  bladderCancer6.setRuleNum(290); 
  bladderCancer6.setConclusion("bladder cancer"); 
  bladderCancer6.setTreatment("Surgery to remove tumor from bladder");
  bladderCancer6.setRuleList({1, 3, 2, 4, 12, 13}); 
  bladderCancer6.setRuleAnswers({false, false, false, true, false, false}); 
  ConclusionList.push_back(bladderCancer6);

  Conclusion colorCancer2; 
  colorCancer2.setRuleNum(300); 
  colorCancer2.setConclusion("colorectal cancer"); 
  colorCancer2.setTreatment("Surgery to remove tumor within colon");
  colorCancer2.setRuleList({1, 3, 2, 4, 5, 10, 12, 11});
  colorCancer2.setRuleAnswers({false, false, false, false, true, true, true, true}); 
  ConclusionList.push_back(colorCancer2);

  Conclusion proCancer2;
  proCancer2.setRuleNum(310);
  proCancer2.setConclusion("prostate cancer");
  proCancer2.setTreatment("Chemotherapy to kill tumor in prostate");
  proCancer2.setRuleList({1, 3, 2, 4, 5, 10, 12, 13});
  proCancer2.setRuleAnswers({false, false, false, false, true, true, false, true});
  ConclusionList.push_back(proCancer2);

  Conclusion bladderCancer7;
  bladderCancer7.setRuleNum(320);
  bladderCancer7.setConclusion("bladder cancer");
  bladderCancer7.setTreatment("Surgery to remove tumor from bladder");
  bladderCancer7.setRuleList({1, 3, 2, 4, 5, 10, 12, 13});
  bladderCancer7.setRuleAnswers({false, false, false, false, true, true, false, false});
  ConclusionList.push_back(bladderCancer7);
  
  Conclusion noCancer6;
  noCancer6.setRuleNum(330);
  noCancer6.setConclusion("no cancer");
  noCancer6.setTreatment("No treatment necessary.");
  noCancer6.setRuleList({1, 3, 2, 4, 5, 10});
  noCancer6.setRuleAnswers({false, false, false, false, true, false});
  ConclusionList.push_back(noCancer6);

  Conclusion noCancer7;
  noCancer7.setRuleNum(340);
  noCancer7.setConclusion("no cancer");
  noCancer7.setTreatment("No treatment necessary.");
  noCancer7.setRuleList({1, 3, 2, 4, 5});
  noCancer7.setRuleAnswers({false, false, false, false, false});
  ConclusionList.push_back(noCancer7);

  return ConclusionList; 
}