//CIS1068 Assignment8: Robert Bara
//Fraction Class
public class Fraction{
    //initializing numerator and denominator
    private int numerator;
    private int denominator;
    //creates a fraction
    public Fraction(int n, int d){
        double fraction;
        numerator=n;
        if(d==0) throw new ArithmeticException("Can't divide by zero");
        denominator=d;
        fraction=numerator/denominator;
               
    }
    //Returns the numerator
    public int getNum(){
        return numerator;
    }
    //Returns the denominator
    public int getDenom(){
        return denominator;
    }
    //sets the numerator to input
    public void setNum(int n){
        numerator=n;
        reduce(n,denominator,denominator);
    }
    //sets the denominator to input
    public void setDenom(int d){
        if(d==0) throw new ArithmeticException("Can't divide by zero");
        denominator=d;
        reduce(numerator,denominator,denominator);
    }

    //method to find the Greatest Common Denominator
    public static int gcd(int gd, int d) {
        while (d != 0) {
            int temp = d;
            d = gd % d;
            gd = temp;
        }
        return gd; //return GCD
    }
    //method to reduce fraction
    public Fraction reduce(int num, int den, int gd){
        int numReduce=num/gd;//get reduced numerator
        int denomReduce=den/gd;//get reduced denominator
        Fraction reduced=new Fraction (numReduce,denomReduce);
        return reduced; //return reduced fraction
    }

    //add a fraction
    public Fraction add(Fraction a){
        int n=numerator; //get numerator
        int d=denominator;//get denominator
        int n1= a.getNum();//get numerator of subject
        int d1=a.getDenom();//get denominator of subject
        int num=(n*d1+n1*d); //addition for numerator
        int den=(d1*d1);    //addition for denominator
        int gd  = gcd(num,den); //find greatest common denominator
        Fraction sum=reduce(num, den,gd);//reduce the sum
        return sum;//return new fraction
    }
    //returns true if subject of method and argument of call are equal
    public boolean equals(Fraction a){
        int num=numerator;
        int denom=denominator;
        int n1=a.getNum();
        int d1=a.getDenom();
       //if equal return true, if false return false
        if(n1*denom==d1*num) return true;
        else return false;

    }
    //Returns a string representation of the fraction
    public String toString(){
        return numerator+"/"+denominator;
    }
}