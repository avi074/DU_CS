package p;

import p1.TwoDim;
import p2.ThreeDim;

public class P_2_Main {
    public static void main(String[] args) {
        TwoDim obj;
        System.out.println("\nDynamic Method Dispatch of TwoDim Object");
        obj = new TwoDim(5,7);
        System.out.println("\nTwoDim Object pointing to a 2D point : \n" + obj);
        obj = new ThreeDim(2,3,9);
        System.out.println("\nTwoDim Object pointing to a 3D point : \n" + obj);
    }
}
