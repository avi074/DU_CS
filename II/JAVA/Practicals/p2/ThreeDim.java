package p2;

import p1.TwoDim;

public class ThreeDim extends TwoDim
{
    private int z;
    //Constructors
    public ThreeDim(){
        super();
        z = 0;
    }

    public ThreeDim(int a, int b, int c){
        super(a,b);
        z = c;
    }
    //methods
    public int getZ() {
        return z;
    }

    public void setZ(int z) {
        this.z = z;
    }

    public String toString(){
        String st = super.toString();
        st += "\nz : " + z;
        return st;
    }
}
