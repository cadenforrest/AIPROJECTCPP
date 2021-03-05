#ifndef VARIABLE_H
#define VARIABLE_H

class Variable{

  public:
    Variable(); 
    ~Variable(); 

    void setQuestion(std::string questionsstring); //sets question = question string
    std::string getQuestion(); // returns question
    void Instantiate(bool userAnswer); //sets isInstantiated to true and answer to userAnswer
    bool getInstantiated(); //returns isInstantiated
    void setVariableName(std::string namestring);

  private: 
    std::string variablename; 
    bool isInstantiated = false; 
    bool answer = false; 
    std::string question;
};

#endif /* VARIABLE_H */