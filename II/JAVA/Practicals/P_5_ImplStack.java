import java.util.Arrays;

class StackExceptions extends Exception{
    private final String msg1 = "Stack Overflow Exception : Stack is full !!!";
    private final String msg = "Stack Underflow Exception : Stack is empty !!!";
    private final boolean chk;

    public StackExceptions(int i) {
        chk = (i == -1);
    }

    @Override
    public void printStackTrace() {
        if(chk)
            System.out.println(msg);
        else
            System.out.println(msg1);
    }

    @Override
    public String toString() {
        if(chk)
            return msg;
        else
            return msg1;
    }
}

class stack <E> {
    private int index;
    private final E[] arr;

    @SuppressWarnings("unchecked")
    public stack() {
        index = -1;
        arr = (E[]) new Object[10];
    }


    @SafeVarargs
    public stack(E... arr) throws StackExceptions {
        if(arr.length > 10)
            throw new StackExceptions(arr.length);
        else{
            index = arr.length - 1;
            this.arr = Arrays.copyOf(arr,10);
        }
    }

    public void push(E var) throws StackExceptions {
        if(index == 9)
            throw new StackExceptions(index);
        else
            arr[++index] = var;
    }

    public E pop() throws StackExceptions {
        if(isEmpty())
            throw new StackExceptions(index);
        else {
            return arr[index--];
        }
    }

    public boolean isEmpty(){
        return  (index == -1);
    }

    @Override
    public String toString() {
        if(isEmpty())
            return "[]";
        else{
            StringBuilder str = new StringBuilder("[ ");
            for(int i = 0; ; i++){
                str.append(arr[i]);
                if(i == index)
                    return str.append(" ]").toString();
                str.append(", ");
            }
        }
    }
}

public class P_5_ImplStack{
    public static void main(String[] args) {
        try {
            stack <Integer> s = new stack<>(45,47);
            System.out.println("\nYour Stack is : " + s.toString());
            for (int i = 0; i < 10; i++){
                s.push(i);
                System.out.println(s.pop());
            }
        } catch (StackExceptions e) {
            e.printStackTrace();
        }
    }
}
