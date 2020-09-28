import java.util.Scanner;
public class lec_01{
    public static Scanner scn = new Scanner(System.in);
    public static void printDec(int a, int b){
        if(a==b-1)    return;
        System.out.print(a+" ");
        printDec(a-1,b);
    }
    
    public static int firstIdx(int [] arr, int i, int data){
        if(i == arr.length) return -1;
        if(arr[i] == data)  return i;
        return firstIdx(arr,i+1,data);
    }

    public static int lastIdx(int [] arr, int idx, int data){
        
       if(arr.length == idx)    return -1;
       int res = lastIdx(arr,idx+1,data);
       if(res != -1)    return res;
       return arr[idx] == data ? idx : -1;
    }

    public static void main(String [] args){
        // printDec(7,0);
        int [] arr = {1,2,5,9,5,6,2,1};
        System.out.print(lastIdx(arr,0,5));
    }
}