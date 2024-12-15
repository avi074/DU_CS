import MainFrames.Welcome;

public class Main {
    public static void main(String[] args) {
       Thread t =new Thread(new Welcome());
       t.start();
    }
}