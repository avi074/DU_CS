import java.util.Scanner;

class UnderAge extends Exception{
    private final int age;
    //Constructor
    public UnderAge(int age){
        this.age = age;
    }
    //Methods

    @Override
    public void printStackTrace() {
        System.out.println("Under Age Exception " + age);
    }

    @Override
    public String toString() {
        return "Under Age {" +" age=" + age + '}';
    }
}
public class P_4_exceptionDemo {
    public static void main(String[] args){
        byte age;
        try(Scanner sc = new Scanner(System.in)) {
            System.out.print("Enter your Age : ");
            age = sc.nextByte();
            test(age);
        } catch (UnderAge underAge) {
            underAge.printStackTrace();
            System.out.println("You are not eligible to drive & vote !!!");
        }
    }

    private static void test(byte i) throws UnderAge{
        if(i < 18)
            throw new UnderAge(i);
        else
            System.out.println("You are eligible to drive & vote !!!");
    }
}
