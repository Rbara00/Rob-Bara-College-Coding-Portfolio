//CIS 1068 Assignment 8: Robert Bara 
//Car Class
public class Car{
    private String make; //brand of car
    private String model; //model of car
    private int year; //year it was made
    private double mpg; //miles per gallon
    private double milesDriven; //total number of miles driven
    private double fuelCapacity; //size in gallons of the fuel tank
    private double fuelRemaining; //amount of fuel remaining in gas tank
    
    //Constructor initializes variables
    public Car(String initialMake, String initialModel, int initialYear, double initialMPG,
                            int initialMilesDriven, int initialFuelCap, int initialFuelRem){
        make=initialMake;
        model=initialModel;
        year=initialYear;
        mpg=initialMPG;
        milesDriven=initialMilesDriven;
        fuelCapacity=initialFuelCap;
        fuelRemaining=initialFuelRem;
        }
    //adds up gallons of gas to fuel tank but not more than the fuel capacity
    public double fillTank(double g){
        //if less than max capacity, fill up the tank
        if(fuelRemaining<fuelCapacity) fuelRemaining=fuelRemaining+g;
        //otherwise return the gallons
        return fuelRemaining;
    }
    //simulates driving "m" miles in the car, adding to the total number of miles
    //driven and reducing the amount of gas according to the car's avergage MPG
    public void drive(double m){
        milesDriven=milesDriven+m;
        double galLoss=m/mpg;
        fuelRemaining=fuelRemaining-galLoss;//reduce gas by subtracting average MPG
    }
    //Returns the information of the car as a string
    public String toString(){
        return "Make:"+make+" Model:"+model+" Year:"+year+" MPG:"+mpg+" Miles Driven:"+milesDriven+" Fuel Capacity:"+fuelCapacity+" Fuel Remaining:"+fuelRemaining;
    }
    //A "Getter" to return the amount of fuel remaining
    public double getFuelRemaining(){
        return fuelRemaining;
    }
}