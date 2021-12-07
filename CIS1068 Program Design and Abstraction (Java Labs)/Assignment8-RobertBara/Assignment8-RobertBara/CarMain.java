//Assignment 8: Robert Bara 
//main for Car Class
public class CarMain{
    public static void main(String[] args) {
        Car oldJunker=new Car("Ford", "Escape", 2019, 100, 250, 12, 8);//create a car object
        System.out.println(oldJunker.toString()); // prints intial attributes of the car to the screen
        oldJunker.drive(5); // drives the Car 5 miles
        System.out.println("Gas up-Fuel Remaining:"+oldJunker.fillTank(1)); // put in a gallon of gas
        oldJunker.drive(10); // drives the Car 10 miles
        System.out.println(oldJunker.toString()); // prints the attributes of the car to the screen
        oldJunker.drive(20); // drives the Car 50 miles
        System.out.println("Fuel Remaining:"+oldJunker.getFuelRemaining()); // prints the amount of fuel left
    }
}