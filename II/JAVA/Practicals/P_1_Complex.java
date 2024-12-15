class Complex {
    private int x;// real part
    private int y;// imaginary part

    //Constructors
    Complex(int x, int y) {
        this.x = x;
        this.y = y;
    }

    //Methods
    Complex add(Complex c) {
        Complex tmp = new Complex(0, 0);
        tmp.x = this.x + c.x;
        tmp.y = this.y + c.y;
        return tmp;
    }

    Complex multiply(Complex c) {
        Complex tmp = new Complex(0, 0);
        tmp.x = (this.x * c.x) - (this.y * c.y);
        tmp.y = this.x * c.y + this.y * c.x;
        return tmp;
    }

    public String toString() {
        String str = String.valueOf(x);
        if (y >= 0)
            str += "+";
        str += y + "i";
        return str;
    }

}

public class P_1_Complex {
    public static void main(String[] args) {
        Complex c1,c2,c3;
        c1 = new Complex(2,3);
        c2 = new Complex(3,4);
        //Complex values
        System.out.println(" C1 : " + c1 + " \n C2 : " + c2);
        //Arithmetic
        c3 = c1.add(c2);
        System.out.println(" C1 + C2 = "  + c3.toString());
        c3 = c1.multiply(c2);
        System.out.println(" C1 * C2 = " + c3);
    }
}

