import javax.swing.*;
import javax.swing.plaf.ColorUIResource;
import javax.swing.plaf.DimensionUIResource;
import javax.swing.plaf.FontUIResource;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.lang.reflect.InvocationTargetException;

public class P_19_swing extends JFrame{
    private JLabel txt;
    private final Thread t;

    public P_19_swing(){
        frameInit();
        fieldInit();
        add(txt);
        pack();
        t = new Thread(() -> {
            Point p = txt.getLocation();
            for (int i = p.x, j = getWidth() - txt.getWidth() - 10; i != j; i += 2) {
                txt.setLocation(i, p.y);
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });
        t.start();
    }
    @SuppressWarnings("deprecation")
    protected void frameInit() {
        super.frameInit();
        setTitle("Practical 19");
        setLayout(null);
        setPreferredSize(new DimensionUIResource(400,200));
        setResizable(false);
        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e){
                t.stop();
                dispose();
            }
        });
    }

    private void fieldInit() {
        txt = new JLabel("Hello");
        txt.setBounds(50,50,60,50);
        txt.setHorizontalAlignment(JLabel.CENTER);
        txt.setFont(new FontUIResource("Times New Roman",FontUIResource.BOLD,16));
    }

    public static void main(String[] args) {
        new P_19_swing().setVisible(true);
    }
}
