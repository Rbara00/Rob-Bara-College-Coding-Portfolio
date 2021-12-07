// Robert Louis Bara
// Section 9
// 9/7/21
// Assignment 3. ASCII Art
//
// Program utilizes Java's Loops and Functions to print the Lincoln Stadium
//

//assigning class constants
public class AsciiArt {
public static final int SIZE=4; 
public static final char DOT='.'; 
public static final char STAR='*';  
public static final char LINE='_';
public static final char BAR='|';
public static final char SLASH='/';
public static final char BACKSLASH='\\';
public static final char SPACE=' ';
public static final char NEWLINE='\n';

//Main Function calls the lot function and two functions to create the stadium
public static void main(String[] args) {   
    Lot();
    Stadium();
}
//Stadium Function
public static void Stadium() {
    topWall();
    topHalf();
    footballField();
    bottomHalf();
}
//Parking Lot
public static void Lot() {
    int rows=0;    //counter for iteration
    for (int space = 1; space <=SIZE*2+2; space++) {
        System.out.print(SPACE);                
    }
    for (int line = 1; line <=SIZE*4+1; line++) {
        System.out.print(LINE);                
    }   //doubly nested for loops
    for(rows=0;rows<=SIZE*2;rows++){
        System.out.print(NEWLINE);
        for (int bar = SIZE; bar <= SIZE; bar++) {
            for (int space = 1; space <=bar*2+1; space++) {
                System.out.print(SPACE);
            }
            System.out.print(BAR);
            for (int line = 1; line <=bar*2; line++) {
                System.out.print(LINE);
            }
            System.out.print(BAR);
            for (int line = 1; line <=bar*2; line++) {
                System.out.print(LINE);
            }
            System.out.print(BAR);
        }
    }
    System.out.print(NEWLINE);  
}

public static void topWall() {
  //Top Wall of stadium with scaling
    System.out.print(SPACE);                
    for (int line = 1; line <=SIZE*8+2; line++) {
        System.out.print(LINE);                
    }
    System.out.print(NEWLINE);
    //Top side walls
    System.out.print(BAR); 
    for (int space = 1; space <=SIZE*4; space++) {
        System.out.print(SPACE);                
    }
    //top of the seats
    for (int line = 1; line <=SIZE/SIZE+SIZE/SIZE; line++) {
        System.out.print(LINE);                
    }
    for (int space = 1; space <=SIZE*4; space++) {
       System.out.print(SPACE);                
    }
    System.out.print(BAR);
    System.out.print(NEWLINE);
}

public static void footballField(){
    int a=0, b=0;//counter to decrease dots and spaces
//upper Middle/Football field
for (int bar = 1; bar <= SIZE; bar++) {
    System.out.print(BAR);
    for (int space=1; space <= (bar * -2 + (2*SIZE)); space++) {
        System.out.print(SPACE);
        b=space;
    }
    System.out.print(LINE);
    System.out.print(SLASH);
    for (int dot = 1; dot <= bar*2+(SIZE-1); dot++) {
        System.out.print(DOT);
        a=dot;
    }
    for (int star = 1; star <= SIZE * 2; star++) {
        System.out.print(STAR);
    }
    for (int dot = 1; dot <= bar*2+(SIZE-1); dot++) {
        System.out.print(DOT);
    }
    System.out.print(BACKSLASH);
    System.out.print(LINE);
    for (int space=1; space <= (bar * -2 + (2*SIZE)); space++) {
        System.out.print(SPACE);
    }
    System.out.println(BAR);
}

//Lower Football Field
for (int bar = 1; bar <= SIZE; bar++) {
    System.out.print(BAR);
    for (int space=b; space <= (bar * 2); space++) {
        System.out.print(SPACE);
    }
    System.out.print(BACKSLASH);
    System.out.print(LINE);
    for (int dot=a; dot >= bar*2; dot--) {
       System.out.print(DOT);
    }
    for (int star = 1; star <= SIZE * 2; star++) {
      System.out.print(STAR);
    }
    for (int dot=a; dot >= bar*2; dot--) {
        System.out.print(DOT);
     }
    System.out.print(LINE);
    System.out.print(SLASH);
    for (int space=b; space <= (bar * 2); space++) {
        System.out.print(SPACE);
    }
    System.out.print(BAR);
    System.out.print(NEWLINE);


    }
}

public static void topHalf(){
//upper shape of stadium 
for (int line = 1; line <= SIZE; line++) {
    System.out.print(BAR);
    for (int space = 1; space <= (line * -2 + (4*SIZE)); space++) {
        System.out.print(SPACE);
    }
    System.out.print(LINE);
    System.out.print(SLASH);
    for (int dot = 1; dot <= (line * 4 - 2); dot++) {
        System.out.print(DOT);
    }
    System.out.print(BACKSLASH);
    System.out.print(LINE);
    for (int space = 1; space <= (line * -2 + (4*SIZE)); space++) {
        System.out.print(SPACE);
    }
    System.out.println(BAR);
    }
}

//Bottom Half of Stadium
public static void bottomHalf() {
for (int line = SIZE-1; line >= 1; line--) {
    System.out.print(BAR);
    for (int space = 1; space <= (line*-2 + (4*SIZE))-1; space++) {
        System.out.print(SPACE);
    }
    System.out.print(BACKSLASH);
    System.out.print(LINE);
    for (int dot = 1; dot <= (line * 4); dot++) {
        System.out.print(DOT);
    }
    System.out.print(LINE);
    System.out.print(SLASH);
    for (int space = 1; space <= (line * -2 + (4*SIZE))-1; space++) {
        System.out.print(SPACE);
    } 
    System.out.println(BAR);
}

// Bottom Wall of stadium
System.out.print(BAR);                
for (int space = 1; space <=SIZE*4-1; space++) {
    System.out.print(SPACE);                
}
System.out.print(BACKSLASH); 
for (int line = 1; line <=SIZE/SIZE+SIZE/SIZE; line++) {
    System.out.print(LINE);                
}
System.out.print(SLASH); 
for (int space = 1; space <=SIZE*4-1; space++) {
    System.out.print(SPACE);                
}
System.out.print(BAR);
System.out.print(NEWLINE);

System.out.print(BAR);                
for (int line = 1; line <=SIZE*8+2; line++) {
    System.out.print(LINE);                
}
System.out.print(BAR); 
System.out.print(NEWLINE);
}
}
