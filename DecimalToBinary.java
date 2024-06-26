

import java.util.Scanner;



public class DecimalToBinary {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a number : ");
        int num = scanner.nextInt();

        String s = "";
        int Temp = num;
        while (Temp>0) {
            int rem = Temp%2;
            Temp = Temp/2;
            s = rem+s;
        }
        System.out.println("Decimal = "+num+": Binary = "+s);
    }

    
}
