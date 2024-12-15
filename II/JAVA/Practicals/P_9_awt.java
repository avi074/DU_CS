import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.lang.reflect.InvocationTargetException;

public class P_9_awt {
    public P_9_awt(){
        Frame f = new Frame("Practical 9");
        f.setSize(400,300);
        f.setBackground(Color.PINK);
        f.setLayout(new FlowLayout());
        f.add(new Label("Hello World"));
        f.setLocationByPlatform(true);
        f.setLocationRelativeTo(null);
        f.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                f.dispose();
            }
        });
        f.setVisible(true);
    }

    public static void main(String[] args) {
        try {
            EventQueue.invokeAndWait(P_9_awt::new);
        } catch (InterruptedException | InvocationTargetException e) {
            e.printStackTrace();
        }
    }
}
