//Robert Bara
// CIS1068 Section 9
// 10/11/21
//Assignment 6:webify
// Converts Text file into html
import java.util.*;
import java.io.*;
public class webify{
    public static void main(String[] args)
        throws FileNotFoundException{
        
        //Prompt for file
        System.out.println("Input File:");
        Scanner scan = new Scanner(System.in);
        String file = scan.nextLine();

        //For my testing sanity, I bypassed the prompt, ignore next line
        //String file="sponge.txt";
        

        //read in file, output to new file with html extension
        Scanner in = new Scanner(new File(file));
        PrintStream out = new PrintStream(new File(file.substring(0, file.length() - 4)+".html"));
        
        //call function and pass in files to convert to html
        toHtml(file,in,out);

        //when finished let user know and specify name of file
        System.out.println("Output File: "+file.substring(0, file.length() - 4)+".html");    
    }

    public static void toHtml(String file, Scanner in, PrintStream out)
        throws FileNotFoundException{ 
        //Define Boolean that determines when to be inside a list
        boolean inList=false; 
        //begin formatting html 
        out.println("<html>");
        out.println("<body>");
        
        //While there is something in the file to read
        while (in.hasNextLine()==true){
            String line = in.nextLine();
            //convert index of char in substring to integer for comparing
            int underscoreIdx = line.indexOf('_');
            int hyphenIdx = line.indexOf('-');
            int opBracketIdx = line.indexOf('[');
            int closedBracketIdx = line.indexOf(']');

            //if first index is '_'
            if(underscoreIdx==0){
                //print out substring without the leading and trailing '_'
                out.println("<h1>"+line.substring(1, line.length() - 1)+"</h1>");
            }
            //if first index is '-' and not in list
            if(hyphenIdx==0 && inList==false){
                inList=true; //enter list
                //print out hypen as bullet point
                out.println("<ul>");
            }
            //if fist index is '-' and in list, print line after bullet point 
            if(hyphenIdx == 0 &&inList==true){
                out.println("<li>"+line.substring(1, line.length())+"</li>");
            }
             //if substring (current line) is finished iterating upon, exit list, print new line
            if(line.length() == 0){
                if(inList==true) out.println("</ul>"); inList=false; //ends list
                out.println("<p>");
            }
           //read line and put a break when no priority logic is necessary
            if(underscoreIdx !=0 && hyphenIdx!=0 && opBracketIdx!=0 && line.length() != 0){
                out.println(line+"<br />");
            }
            //if first char is a bracket, that means it will be a link.
            //Make hyper link based upon text to display without brackets
            if(opBracketIdx == 0){
                out.println("<a href=\""+line.substring(2, closedBracketIdx)+"\">"+line.substring(closedBracketIdx+2, line.length()-2)+"</a>");
            }
        }

        //Finish formatting html
        out.println("</body>");
        out.println("</html>");
    }
}