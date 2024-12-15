package p;

import P3.Circle;
import p1.Shape;
import p2.Rectangle;

import java.util.Scanner;

public class P_3_Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        Shape p;
        byte op;

        System.out.print("\n Choose the type of the shape : \n 1. Rectangle \n 2. Circle \n Enter your Option : ");
        op = scan.nextByte();
        if(op == 1){
            System.out.print("\n Enter the length & breadth of the Rectangle : ");
            p = new Rectangle(scan.nextFloat(), scan.nextFloat());
            System.out.println(" Area of rectangle : " + p.Area());
        }
        else if(op == 2){
            System.out.print("\n Enter the radius of the Circle : ");
            p = new Circle(scan.nextFloat());
            System.out.println(" Area of circle : " + p.Area());
        }
        else
            System.out.println("\n Invalid input !!!");
        scan.close();
    }
}
