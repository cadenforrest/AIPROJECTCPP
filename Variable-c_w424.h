#ifndef VARIABLE_H
#define VARIABLE_H

class Variable{

  public:
    void setQuestion(std::string questionsstring); //sets question = question string
    std::string getQuestion(); // returns question
    void Instantiate(bool userAnswer); //sets isInstantiated to true and answer to userAnswer
    bool getInstantiated(); //returns isInstantiated
    bool getAnswer(); //returns answer
    void setVariableName(std::string namestring);
    void setTreatment(std::string treatment1);
    std::string getTreatment(); 

  private: 
    std::string variablename; 
    bool isInstantiated = false; 
    bool answer = false; 
    std::string question;
    std::string treatment; 
};

#endif /* VARIABLE_H */