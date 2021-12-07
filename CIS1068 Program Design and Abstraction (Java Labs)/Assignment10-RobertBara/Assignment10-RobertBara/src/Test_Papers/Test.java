package Test_Papers;
//Robert Bara
//CIS1068-Assignment10-Test Papers
//Test Class
public class Test {
    //initialize variables
    private int totalQuestions;
    private int NumQuestions=0;
    private int totalPoints;
    Question[] question;
    String blank = "_______________ ";
    public Test() {}
    //creating a test
    public Test(int questions, int totalPts ) {
        totalQuestions = questions;
        totalPoints = totalPts;
        question = new Question[totalQuestions];
        setNumQuestions(0);
    }
    //Add a question
    void addQuestion(int points, int difficulty, int answerSpace, String questionText, String correctAnswer){
        question[getNumQuestions()]=new Question(points,difficulty,answerSpace,questionText,correctAnswer);
        setNumQuestions(NumQuestions+1);
    }
    //Add a question
    void addQuestion(int points, int difficulty, int answerSpace, String questionText, String questionSpace, String correctAnswer){
        question[getNumQuestions()]=new Question(points,difficulty,answerSpace,questionText,questionSpace,correctAnswer);
        setNumQuestions(NumQuestions+1);
    }
    //Add a question
    void addQuestion(int points, int difficulty, int answerSpace, String questionText, String correctAnswer, String[] possibleAnswers){
        question[getNumQuestions()]=new Question(points,difficulty,answerSpace,questionText,correctAnswer,possibleAnswers);
        setNumQuestions(NumQuestions+1);
    }
    //setter for number of questions
    public void setNumQuestions(int NumQ) { 
        NumQuestions = NumQ;
    }
    //getter for number of questions
    public int getNumQuestions() { 
        return NumQuestions; 
    }
    //method to print the test out with answer key
    void printTest(int printAnswer){
        for(int i = 0; i<getNumQuestions();i++){
            //pritning an objective
            if(question[i].getQuestionType()== Question.questionTypes.OBJECTIVE){
                System.out.print("Question "+(i+1)+") "+question[i].getPoints()+"pts. "+question[i].getQuestionText()+"\n");
                if(printAnswer==1) System.out.print("***"+question[i].getCorrectAnswer()+"***\n\n");
            }
            //printing a fill in the blank
            if(question[i].getQuestionType()== Question.questionTypes.FILLINTHEBLANK){
                System.out.print("Question "+(i+1)+") "+question[i].getPoints()+"pts. "+blank+question[i].getQuestionText()+"\n");
                if(printAnswer==1) System.out.print("***"+question[i].getCorrectAnswer()+"***\n\n");
            }
            //printing a multiple choice
            if(question[i].getQuestionType()== Question.questionTypes.MULTIPLECHOICE){
                System.out.print("Question "+(i+1)+") "+question[i].getPoints()+"pts. "+question[i].getQuestionText()+"\n");
                    for(int j = 0;j<question[i].getPossibleAnswers().length;j++){
                    System.out.print(question[i].getPossibleAnswers()[j]+"\n");
                }
                if(printAnswer==1)System.out.print("***"+question[i].getCorrectAnswer()+"***\n\n");
            }
        }
    }
}