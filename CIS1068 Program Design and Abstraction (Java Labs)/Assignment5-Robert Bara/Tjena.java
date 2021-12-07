// Robert Louis Bara
// Section 9
// 10/3/21
// Assignment 5. Tjena
//
// Program allows users to play Tjena with the computer
//
import java.util.Random;
import java.util.Scanner;

public class Tjena {
//Main Function
public static void main(String[] args) {
    int numOfRounds=0;
    int wins=0;
    int losses=0;
    int ties=0;
    int outcome=0;

    //call function to prompt if they want to play Tjena
    System.out.println("Welcome to Tjena.");
    rules();
    prompt(numOfRounds,wins,losses,ties,outcome);
        
}
public static void prompt(int numOfRounds,int wins,int losses,int ties,int outcome) {
    String input;
    Scanner scan = new Scanner (System.in);

    //Prompt user to play
    System.out.print("\nPlay a round? [y=yes], [n=no or q=quit]\n");
    input=scan.next();
    
    //if user plans to play
    if(input.contains("y")||input.contains("Y")){
        numOfRounds++;//increment number of rounds
        outcome=round(); //outcome will return an int which determines number of wins, loses, ties to be printed
        if(outcome==1) wins++; 
        if(outcome==0) losses++;
        if(outcome==-1) ties++;
        prompt(numOfRounds,wins,losses,ties,outcome);
    }
    //if user does not plan to play
    if(input.contains("n")||input.contains("N")||input.contains("q")||input.contains("Q")){
        //print the number of rounds and outcomes
        System.out.println("Rounds:"+numOfRounds+" Wins:"+wins+" Losses:"+losses+" Ties:"+ties+"\tQuitting");
        System.exit(0);//exits the program;
    }
    //if input is invalid, keep prompting
    else System.out.println("invalid input, try again"); prompt(numOfRounds,wins,losses,ties,outcome);     
}
    
//Printing the Rules of the Game
public static void rules() {
    System.out.println("\n\tRules\n-Lillasjon beats Insvep, Dromsack\n"
                        +"-Insvep beats Tjena, Nordli\n"
                        +"-Tjena beats Lillasjon, Dromsack\n"
                        +"-Dromsack Beats Nordli, Insvep\n"
                        +"-Nordli beats Lillasjon, Tjena");
}

//Playing a round
public static int round(){
    String in;
    int aI;
    int outcome=0;
    Random rand = new Random(); //for random input
    Scanner scan = new Scanner (System.in);//for iser input

    aI=rand.nextInt(4);//generates a random integer between 0-4
    //prompt the user to select a character
    System.out.print("\nSelect a character\n0=Lillasjon 1=Invsp, 2=Tjena, 3=Dromsack, 4=Nordli\nCharacter:");
    in=scan.next();
   
    //if the input is valid, check who wins and store in outcome to return
    if((in.contains("0"))||(in.contains("1"))||(in.contains("2"))||(in.contains("3"))||(in.contains("4"))){
        //convert string to integer and pass to function compare
        int input=Integer.parseInt(in);
        outcome=compare(input,aI,outcome);
    }
    //if the input is anything other than the character selections, prompt again
    else{
        System.out.println("Invalid selection, try again");
        round();
    }
    //return who won, -1=tie, 0=AI wins, 1=User win,
    return outcome;
}

//Function compares the user's choice to the randomly generated computer choice and determines who wins
public static int compare(int input, int aI,int outcome){
    switch(input){
        case(0)://User picked Lillasjon
        System.out.println("Your move is Lillasjon");
        //compare with the AI's choice
            switch(aI){
                case(1):System.out.println("AI picked Insvep, you win"); outcome=1;break;//AI picked Insvep, User Wins
                case(2):System.out.println("AI picked Tjena, you lose"); outcome=0;break;//AI Picked Tjena, User Loses
                case(3):System.out.println("AI picked Dromsack, you win"); outcome=1;break;//AI picked Dromsack, User Wins
                case(4):System.out.println("AI picked Nordli, you lose"); outcome=0;break;//AI picked Nordli, User Loses
                default:System.out.println("AI picked Lillasjon, tie"); outcome=-1;break;//AI picked Lillasjon, tie
            }break;
        case(1)://User picked Insvep
        System.out.println("Your move is Insvep");
            switch(aI){
                case(0):System.out.println("AI picked Lillasjon, you lose"); outcome=0;break;//AI picked Lillasjon, User loses
                case(2):System.out.println("AI picked Tjena, you win"); outcome=1;break;//AI picked Tjena, User Wins
                case(3):System.out.println("AI picked Dromsack, you lose"); outcome= 0;break;//AI picked Dromsack, User loses
                case(4):System.out.println("AI picked Nordli, you win"); outcome=1;break;//AI picked Nordli, User Wins
                default:System.out.println("AI picked Insvep,tie"); outcome=-1;break;//AI picked Insvep, tie 
            }break;
        case(2)://User picked Tjena
            System.out.println("Your move is Tjena");
            switch(aI){
                case(0):System.out.println("AI picked Lillasjon, you win"); outcome=1;break;//AI picked Lillasjon, User wins
                case(1):System.out.println("AI picked Insvep, you lose"); outcome=0;break;//AI picked Insvep, User loses
                case(3):System.out.println("AI picked Dromsack, you win"); outcome=1;break;//AI picked Dromsack, User wins
                case(4):System.out.println("AI picked Nordli, you lose"); outcome=0;break;//AI picked Nordli, User loses
                default:System.out.println("AI picked Tjena, tie"); outcome=-1;break;//AI picked Tjena, tie
            }break;    
        case(3)://User picked Dromsack
        System.out.println("Your move is Dromsack");
            switch(aI){
                case(0):System.out.println("AI picked Lillasjon, you lose"); outcome=0;break;//AI picked Lillasjon, User loses
                case(1):System.out.println("AI picked Insvep, you win"); outcome=1;break;//AI picked Insvep, User wins
                case(2):System.out.println("AI picked Tjena, you lose"); outcome=0;break;//AI picked Tjena, User loses
                case(3):System.out.println("AI picked Nordli, you win"); outcome=1;break;//AI picked Nordli, User wins
                default:System.out.println("AI picked Dromsack, tie"); outcome=-1;break;//AI picked Dromsack, tie
            }break;
        case(4)://User picked Nordli
        System.out.println("Your move is Nordli");
            switch(aI){
                case(0):System.out.println("AI picked Lillasjon, you win"); outcome=1;break;//AI picked Lillasjon, User wins
                case(1):System.out.println("AI picked Insvep, you lose"); outcome=0;break;//AI picked Insvep, User loses
                case(2):System.out.println("AI picked Tjena, you win"); outcome=1;break;//AI picked Tjena, User Wins
                case(3):System.out.println("AI picked Dromsack, you lose"); outcome=0;break;//AI picked Dromsack, User loses
                default:System.out.println("AI picked Nordli, tie"); outcome=-1;break;//AI picked Nordli, tie
            }break;
        }
    return outcome;
}
}