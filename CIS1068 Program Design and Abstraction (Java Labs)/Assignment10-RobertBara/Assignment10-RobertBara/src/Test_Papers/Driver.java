package Test_Papers;
//Robert Bara
//CIS1068-Assignment10-Test Papers
//Driver for Test and Question Classes
public class Driver {
    public static void main(String[] args) {
        //create a test with 3 questions, worth 100 points
        Test test = new Test(3,100);
        test.addQuestion(40,1,1,"The civil war was neither civil nor a war. Discuss.","Pretty crazy dude, pickett's charge was pretty bad");
        test.addQuestion(35,1,1,"was the 16th US President.",test.blank,"Abraham Lincoln");
        String[] possibleAnswers = {"A. Peter Griffin","B. Scooby Doo","C. Spongebob Squarepants","D. Eric Cartman"};
        test.addQuestion(25,1,1,"Who lives in a pineapple under the sea?","C. Spongebob Squarepants",possibleAnswers);
        //set parameter to 0 to print only the test, set to 1 to print the answer key and test
        test.printTest(0);
        test.printTest(1);
    }
}