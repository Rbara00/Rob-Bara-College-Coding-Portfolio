//Assignment 7: Array Practice
//Robert Bara CIS 1068 Section 9
package arraypractice;

public class ArrayPractice {
  /* sets every item in A[] to initialValue */
  public static void initialize(int A[], int initialValue) {
	 for(int i=0;i<A.length;i++) {
		 A[i]=initialValue;//iterate across entire array and set current value to initialValue
	 } 
    return;
  }

  /* returns the average of the items in A
   * Be careful: A[] is an array of int and the method returns
   * double. What do we do to handle this? */
  public static double average(int A[]) {
	  double Avg=0.0,B=0.0,C=0.0;;
	  for(int i=0;i<A.length;i++) {
	  	  C=A.length;//typecast int to double
	      B = B+A[i]; //add up all values
	  }
	  Avg=B/C;//divide by length of array
    return Avg;
  }

  /* returns the number of times that x appears in A[] */
  public static int numOccurrences(int A[], int x) {
	  int k=0;//counter for x
	  for(int i=0;i<A.length;i++) {
		  if(A[i]==x) k++;//add one everytime x appears
	  }
    return k;
  }


  /* returns the index of the first occurrence of
   * x in A[] or -1 if x doesn't exist in A[] */
  public static int find(int A[], int x) {
	  for(int i=0;i<A.length;i++) {
		  if(A[i]==x) return i;//returns first index of x
	  }
    return -1; //otherwise return -1
  }

  /* Returns the index of the first occurrence of
   * item within the first n elements of A[] or -1
   * if item is not among the first n elements of A[] */
  public static int findN(int A[], int item, int n) {
	  for(int i=0;i<n;i++) { //only iterates up to n elements
		  if(A[i]==item) return i;//returns first index of x
	  }
    return -1;
  }

  /* returns the index of the last occurrence of
   * x in A[] or -1 if x doesn't exist in A[] */
  public static int findLast(int A[], int x) {
	  int k=0;
	  for(int i=0;i<A.length;i++) {
		  if(A[i]==x) k=i;//hold last value of i when x was found
	  }
	  if(k!=0) return k;//returns last index
	  return -1;
  }

  /* returns the largest item found in A */
  public static int largest(int A[]) {
	  int k=A[0];
	  for(int i=1;i<A.length;i++) {
		  if(k<A[i]) k=A[i];//hold largest value found
	  }
    return k;//return largest value
  }

  /* returns the index of the largest item found in A */
  public static int indexOfLargest(int A[]) {
	  int k=A[0],j=0;
	  for(int i=1;i<A.length;i++) {
		  if(k<A[i]) j=i;//hold index of largest value found
	  }
    return j;//return largest index
  }

  /* returns the index of the largest odd number
   * in A[] or -1 if A[] contains no odd numbers */
  public static int indexOfLargestOdd(int A[]) {
	  int k=A[0],j=0;
	  for(int i=1;i<A.length;i++) {
		  if(k<A[i]) { //check for max
			  if((A[i]%2)!=0) j=i; //check if odd
		  }
	  }
	  if(j!=0)return j;//return largest index of odd number
	  else return -1;
  }

  /* inserts n into A[] at A[index] shifting all */
  /*  the previous items one place to the right. For example */
  /*  if A is  */
  /*   |---+---+---+---+---+---+---+---+---+---| */
  /*   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | */
  /*   |---+---+---+---+---+---+---+---+---+---| */
  /*   | 5 | 7 | 6 | 9 | 4 | 3 | 0 | 0 | 0 | 0 | */
  /*   |---+---+---+---+---+---+---+---+---+---| */

  /*   and we call insert(A, 15, 1), A then becomes */

  /*   |---+----+---+---+---+---+---+---+---+---| */
  /*   | 0 |  1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | */
  /*   |---+----+---+---+---+---+---+---+---+---| */
  /*   | 5 | 15 | 7 | 6 | 9 | 4 | 3 | 0 | 0 | 0 | */
  /*   |---+----+---+---+---+---+---+---+---+---| */
  /*  the element in A[] that's in the right-most */
  /*    position is removed.                      */
  /*                                              */
  /*  if index < 0 or index >= A.length-1, the method */
  /*                                    does nothing */
  public static void insert(int A[], int n, int index) {
  	if(index<0||index>=A.length-1) return;//priority logic
  	else {
	for (int i = A.length-1; i > index; i--){
		  A[i] = A[i-1];
  	}    	
  	A[index] = n;
      return;
  	}
  }

  /* returns a new array consisting of all of the
   * elements of A[] */
  public static int[] copy(int A[]) {
	int[] b=A.clone();//clone array into B
    return b;
  }

  /* Returns a new array consisting of all of the
     first n elements of A[]. If n>A.length, returns a
     new array of size n, with the first A.length elements
     exactly the same as A, and the remaining n-A.length elements
     set to 0. If n<=0, returns null. */
  public static int[] copyN(int A[], int n) {
	  if (n <= 0)return null;//priority logic
	  int B[] = new int [n];
	  for(int i = 0; i < B.length; i++){
		  B[i] = 0;
	  	}
	  if(n>A.length) {
		  for (int i = 0; i < (A.length); i++) {
	  		  B[i] = A[i];
		  	}  
	  }
	  if(n<A.length) {
		  for (int i = 0; i < n; i++) {
	  		  B[i] = A[i];
		  	}   
	  }
  		return B;
 }

  /* returns a new array consisting of all of the
   * elements of A[] followed by all of the
   * elements of B[]. For example, if 
   A[] is: {10,20,30} and 
   B[] is: {5, 9, 38}, the method returns the
   array : {10,20,30,5,9,38} */
  public static int[] copyAll(int A[], int B[]) {
	  int length=A.length+B.length;
	  int [] C=new int[length]; //make new array of combined length
	  System.arraycopy(A, 0, C, 0, A.length);  //copy A start to end into C
	  System.arraycopy(B, 0, C, A.length, B.length); //copy B after A ends into C
	  return C;	//return new array
  }

  /* reverses the order of the elements in A[].
   * For example, if A[] is:
   {10,20,30,40,50}, after the method, A[] would
   be {50,40,30,20,10} */
  public static void reverse(int A[]) {
	 int j = 0;//counter
	 int B[] = new int[A.length];//reverse array
  	 for(int i = A.length-1; i != -1; i--){
  		 B[j] = A[i];
  		 j++;
  	 }
  	for(int i = 0; i < B.length; i++){
  		A[i] = B[i];
  	}
      return;
}

  /* Extra credit:
   *
   * Returns a new array consisting of all of the
   * elements of A, but with no duplicates. For example,
   * if A[] is {10,20,5,32,5,10,9,32,8}, the method returns
   * the array {10,20,5,32,9,8} 
  public static int[] uniques(int A[]) {
    return null;
  }

  public static void main(String[] args) {
    return;
  }*/
}
