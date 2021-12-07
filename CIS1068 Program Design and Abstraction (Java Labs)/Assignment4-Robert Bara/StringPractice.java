//Robert Bara Assignment 4
//Class program for strings to be tested
public class StringPractice {	
  /* returns true if c is a punctuation mark or false otherwise
   * 
   * Punctuation mark is defined as:
   * apostrophe '
   * comma ,
   * period .
   * semicolon ;
   * colon :
   * exclamation point !
   * question mark ? 
   * 
   * (You don't have to worry about any others)
   */
  public static boolean isPunct(char c){
	  char[] arr= {'\'',',','.',';',':','!','?'};//create array of char
	  for(int i=0;i<arr.length;i++){//iterate across string
		  if(arr[i]==c) {//if string has punctuation
			  return true;//return true
		  }
	  }
	  return false; 
  }

  /*
   * returns the number of punctuation marks
   * found in s.
   *
   * call your isPunct( ) method. Do not compy and paste
   * the same logic into this function */
  public static int numPunct(String s){
	  int j=0;
	  for(int i=0;i<s.length();i++){
		  isPunct(s.charAt(i));
		  if(isPunct(s.charAt(i))==true)j++;//Whenever there is a punct mark, add 1 to counter
	  }
	  return j;	//if it is invalid, don't increment
  }
  
  /*
   * returns the number of punctuation marks
   * found in s starting at the given index.
   *
   * call your isPunct( ) method. Do not compy and paste
   * the same logic into this function */
  public static int numPunct(String s, int startIndex){
	  int j=0;
	  for(int i=startIndex;i<s.length();i++) {	//notice that i starts at the startIndex now
		  isPunct(s.charAt(i));
		  if(isPunct(s.charAt(i))==true)j++;//Whenever there is a punct mark, add 1 to counter
	  }
	  return j;	//if it is invalid, don't increment
}

  /*
   * returns the index of the first occurrence
   * of a punctuation mark in s starting
   * from index startPosition or -1 if there are
   * none at index startPosition or later.
   *
   * When implementing this function, call your isPunct( ) method.
   * Do not simply copy and paste the body of isPunct( ) into this method.
   */
  public static int indexOfFirstPunct(String s, int startPosition){
	  int i;
	  for(i=startPosition;i<s.length();i++){
		  isPunct(s.charAt(i));
		  if(isPunct(s.charAt(i))==true)return i;//Whenever there is a punct mark, return index
	  }
	  return i=-1;//if it has no punctuation marks
  }

  /*
   * returns the index of the first punctuation mark in s or
   * -1 if s contains no punctuation marks
   *
   * use your solution to indexOfFirstPunct(String s, int startPosition)
   * in this function. Do not repeat the same logic.
   * 
   * Notice that this method has the same name as the
   * previous one, but that it takes a different number of arguments. This is
   * perfectly legal in Java. It's called "method overloading"
   *
   */
  
  //I would like to say, I am slightly confused by the do not repeat same logic requirement
  //The method is slightly different since I changed the for loop iteration
  public static int indexOfFirstPunct(String s){
	  int i;
	  for(i=0;i<s.length();i++){	//start at first index of string as default when no position is entered
		  isPunct(s.charAt(i));
		  if(isPunct(s.charAt(i))==true)return i;//Whenever there is a punct mark, return index
	  }
	  return i=-1;//if it has no punctuation marks
  }

  /*
   * returns the index of the last occurrence of a punctuation
   * mark in s or -1 if s contains no punctuation
   * 
   * When implementing this function, call your isPunct( ) method.
   * Do not simply copy and paste the body of isPunct( ) into this method.
   */
  public static int indexOfLastPunct(String s){
	  int i;
	  for(i=s.length()-1;i>=0;i--){	//start at last value and decrement
		  isPunct(s.charAt(i));
		  if(isPunct(s.charAt(i))==true)return i;//Whenever there is a punct mark, return index
	  }
	  return i=-1;//if it has no punctuation marks
  }

  /*
   * returns a new String which is the same as s but with
   * each instance of oldChar replaced with newChar
   */
  public static String substitute(String s, char oldChar, char newChar){
	  String s2=s.replace(oldChar, newChar);
    return s2;
  }

  /*
   * returns a new String which is the same as s, but
   * with each instance of a punctuation mark replaced
   * with a single space character
   *
   * Use at least one of your other functions in your
   * solution to this.
   *
   */
  public static String substitutePunct(String s){
	  char space=' ';//white space for replacing punctuation
	  String s2=s;	//new string
	  char[] arr= {'\'',',','.',';',':','!','?'};//create array of char for punctuation
	  for(int i=0;i<arr.length;i++){//iterate across string
		  s2=substitute(s2,arr[i],space);//use substitute function
	  }
	  return s2;	  
  }
  
  /*
   * returns a new String which is the same as s,
   * but with all of the punctuation
   * marks removed.
   *
   * Use at least one of your other functions
   * in your solution to this one.
   * 
   */
  
  //Asked Ben Rittenhouse if this is okay to use and he said yea. I know we have not talked about
  //posix character classes in lecture, but I've had some experience with them from
  //working in Dr Bai's ECE research lab and decided to use it because I got kind of lazy.
  public static String withoutPunct(String s){
	   String s2 = s;
	  if(numPunct(s2)!=0) {	//if there is punctuation in a string 
		  s2=s2.replaceAll ("\\p{Punct}", "");	//remove all punctuation in a string
		  return s2; //return new string without punc 
	  } 
	  return s2; //return copy of old string if there is no punc
 }

  /* returns true if c is found in s or false otherwise */
  public static boolean foundIn(String s, char c){
	char[] sTest=s.toCharArray();
	  for(int i=0;i<sTest.length;i++){//iterate across string
		  if(sTest[i]==c) return true;
	  }
	  return false;
  }

  /*
   * Returns true of s contains none of the characters
   * found in chars or false otherwise.
   */
  public static boolean containsNone(String s, String chars){
		char[] cTest=chars.toCharArray();
		for(int i=0;i<cTest.length;i++){//iterate across string
		if(foundIn(s,cTest[i])==true)return false;
		}
		return true;
  }
  
  /*
   * Returns true of s is comprised of only punctuation or
   * false otherwise
   *
   * Use at least one of your other
   * functions in this one.
   */
  public static boolean onlyPunct(String s){
	  int a=numPunct(s);//returns the number of punctuation in a string 
	  //if the number of punct=string length then its only punct
	  if(s.length()==a)return true;
    return false;
  }

  /*
   * Returns true of s contains no punctuation or
   * false otherwise
   *
   * Use at least one of your other
   * functions in this one.
   */
  public static boolean noPunct(String s){
	  int j=0;
	  for(int i=0;i<s.length();i++){
		  isPunct(s.charAt(i));
		  if(isPunct(s.charAt(i))==true)j++;//Whenever there is a punct mark, add 1 to counter
	  }
	  if(j!=0)return false; //if there is some punctuation return false
	  return true;//otherwise there is no punctuation
  }

  /*
   * returns true if s has two punctuation marks
   * right next to each other or false otherwise
   *
   * use at least one of your other methods
   * in your solution to this method
   */
  public static boolean consecutivePuncts(String s){
	  for(int i=0;i<s.length();i++){
		  boolean a, b;
		  int j=i+1;
		  a=isPunct(s.charAt(i));
		  b=isPunct(s.charAt(j));
		  if(a==b)return true;
	  }
	  return false;//otherwise there is no punctuation
  }
}