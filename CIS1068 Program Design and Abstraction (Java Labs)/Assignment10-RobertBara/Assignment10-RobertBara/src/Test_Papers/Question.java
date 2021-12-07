package Test_Papers;
//Robert Bara
//CIS1068-Assignment10-Test Papers
//Question Class
class Question extends Test{
    private int points;
    private int difficulty;
    private int MIN_DIFFICULTY = 0;
    private int MAX_DIFFICULTY = 100;
    private int answerSpace;
    private String questionText;
    private String questionSpace;
    private String[] possibleAnswers;
    private String correctAnswer;
    private questionTypes questionType;
    //possible types of questions can be represented as an enum
    public enum questionTypes{
        OBJECTIVE, FILLINTHEBLANK, MULTIPLECHOICE;
    }

    // ObjectiveQuestion
    Question(int pts, int diff, int aSpace, String qText, String answer) {
        points = pts;
        difficulty = diff;
        answerSpace = aSpace;
        questionText = qText;
        correctAnswer = answer;
        setQuestionType(questionTypes.OBJECTIVE);
    }

    // FillInTheBlankQuestion
    Question(int pts, int diff, int aSpace, String qText, String qSpace, String answer) {
        points = pts;
        difficulty = diff;
        answerSpace = aSpace;
        questionText = qText;
        correctAnswer = answer;
        questionSpace = qSpace;
        correctAnswer = answer;
        setQuestionType(questionTypes.FILLINTHEBLANK);
    }

    // MultipleChoiceQuestion
    Question(int pts, int diff, int aSpace, String qText, String answer, String[] posAnswers) {
        points = pts;
        difficulty = diff;
        answerSpace = aSpace;
        questionText = qText;
        correctAnswer = answer;
        possibleAnswers = posAnswers;
        setQuestionType(questionTypes.MULTIPLECHOICE);
    }
    //setter for type of question
    public void setQuestionType(questionTypes type) {
        questionType = type;
    }
    //getter for type of question
    public questionTypes getQuestionType() {
        return questionType;
    }
    //getter for question
    public String getQuestionText() { 
        return questionText; 
    }
    //getter for points worth of the question
    public int getPoints() { 
        return points; 
    }
    //getter for the difficulty of the question
    public int getDifficulty() { 
        return difficulty; 
    }
    //getter for the possible answers
    public String[] getPossibleAnswers() { 
        return possibleAnswers; 
    }
    //getter for correct answer
    public String getCorrectAnswer() { 
        return correctAnswer; 
    }

}