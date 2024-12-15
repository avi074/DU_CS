import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.lang.reflect.InvocationTargetException;

public class P_11_awt{
    public P_11_awt(){
        Frame f = new Frame("Practical 11");
        f.setLayout(null);
        f.setPreferredSize(new Dimension(250,200));
        f.setLocationRelativeTo(null);
        f.setLocationByPlatform(true);
        f.setResizable(false);
        f.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                f.dispose();
            }
        });

        Label status = new Label("Status Window");
        status.setBounds(0,0,250,200);
        status.setFont(new Font("Tahoma",Font.BOLD,14));
        status.setAlignment(Label.CENTER);
        f.add(status);

        f.addKeyListener(new KeyAdapter() {
            @Override
            public void keyTyped(KeyEvent e) {
                status.setText("Typed Character is : \"" + e.getKeyChar() + "\"");
            }
        });

        f.pack();
        f.setVisible(true);
    }
    public static void main(String[] args) {
        try {
            EventQueue.invokeAndWait(P_11_awt::new);
        } catch (InterruptedException | InvocationTargetException e) {
            e.printStackTrace();
        }
    }
}
