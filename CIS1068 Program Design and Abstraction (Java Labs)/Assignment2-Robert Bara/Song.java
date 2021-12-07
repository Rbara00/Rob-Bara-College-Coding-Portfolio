// Robert Louis Bara
// Section 9
// 8/30/21
// Assignment 2. Song
//
// Program prints the lyrics of an Abridged Version of the American Folk Song "Bought Me a Cat"
//

public class Song {
    //Main Function
    public static void main(String[] args) {
        verseOne();
        verseTwo();
        verseThree(); 
        verseFour();
        verseFive();
        verseSix();
    }
    //verseOne
    public static void verseOne() {
        System.out.println("Bought me a cat and the cat pleased me,\n");
        System.out.println("I fed my cat under yonder tree.\n");
        cat(); 
    }
    //verseTwo
    public static void verseTwo() {
        System.out.println("\nBought me a hen and the hen pleased me,\n");
        System.out.println("I fed my hen under yonder tree.\n");
        hen();
        cat(); 
    }
    //verseThree
    public static void verseThree() {
        System.out.println("\nBought me a duck and the duck pleased me,\n");
        System.out.println("I fed my duck under yonder tree.\n");
        duck();
        hen();
        cat(); 
    }
    //verseFour
    public static void verseFour() {
        System.out.println("\nBought me a goose and the goose pleased me,\n");
        System.out.println("I fed my goose under yonder tree.\n");
        goose();
        duck();
        hen();
        cat(); 
    }
    //verseFive
    public static void verseFive() {
        System.out.println("\nBought me a sheep and the sheep pleased me,\n");
        System.out.println("I fed my sheep under yonder tree.\n");
        sheep();
        goose();
        duck();
        hen();
        cat(); 
    }
    //verseSix
    public static void verseSix() {
        System.out.println("\nBought me a pig and the pig pleased me,\n");
        System.out.println("I fed my pig under yonder tree.\n");
        System.out.println("Pig goes oink, oink,\n");
        sheep();
        goose();
        duck();
        hen();
        cat();
        System.out.println("\nThankyou Toronto, keep on Rockin in the FreeWorld!\n"); 
    }            
    //Common Cat Line Function
    public static void cat() {
        System.out.println("Cat goes fiddle-i-fee.\n"); 
    }
    //Common Hen Line Function
    public static void hen() {
        System.out.println("Hen goes chimmy-chuck, chimmy-chuck,\n"); 
    }
    //Common Duck Line Function
    public static void duck() {
        System.out.println("Duck goes quack, quack,\n"); 
    }
    //Common Goose Line Function
    public static void goose() {
        System.out.println("Goose goes hissy, hissy,\n"); 
    }   
    //Common Sheep Line Function
    public static void sheep() {
        System.out.println("Sheep goes baa, baa,\n"); 
    }  
}