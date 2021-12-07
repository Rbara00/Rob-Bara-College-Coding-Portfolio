//CIS1068 Assignment 8: Robert Bara
//Driver for Fraction Class
public class FractionMain{
    public static void main(String[] args) {
        Fraction test=new Fraction(3,8);//create a fraction
        System.out.println("Numerator="+test.getNum()); // prints the numerator
        System.out.println("Denominator="+test.getDenom()); // prints the denominator
        System.out.println("Fraction is "+test.toString()); // prints the Fraction as a string

        //changing the fraction
        test.setNum(15);//setting the numerator
       // test.setDenom(0);//setting the denominator
        test.setDenom(45);//setting denominator
        System.out.println(test.toString()); // prints the new Fraction
        int n=test.getNum();
        int d=test.getDenom();
        int gd=test.gcd(n,d);
        test.reduce(n,d,gd);

        System.out.println(test);
        //Testing Addition
        System.out.println("Reduced Sum="+(new Fraction(3,4)).add(new Fraction(1,4)));
        System.out.println("Reduced Sum="+(new Fraction(5,25)).add(new Fraction(4,50)));
        System.out.println("Reduced Sum="+(new Fraction(1,4)).add(new Fraction(1,4)));
        //Testing Equality
        System.out.println("Are they equal="+(new Fraction(3,4)).equals(new Fraction(1,4)));
        System.out.println("Are they equal="+(new Fraction(3,4)).equals(new Fraction(3,4)));
    }

}