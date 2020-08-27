import java.util.Scanner;
public class lec_01{
    public static Scanner scn = new Scanner(System.in);
    public static void printDec(int a, int b){
        if(a==b-1)    return;
        System.out.print(a+" ");
        printDec(a-1,b);
    }
    public static void main(String [] args){
        printDec(7,0);
    }
}