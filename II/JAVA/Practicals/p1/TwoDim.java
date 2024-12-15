package p1;

public class TwoDim {
    private int x;
    private int y;
    //Constructors
    public TwoDim(){
        x = 0;
        y = 0;
    }

    public TwoDim(int a, int b){
        x = a;
        y = b;
    }
    //Methods
    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public void setX(int a){
            x = a;
    }

    public void setY(int y) {
        this.y = y;
    }

    public String toString(){
        return ("x : " + x + "\ny : " + y);
    }
}

