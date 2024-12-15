import javax.swing.*;
import javax.swing.plaf.ColorUIResource;
import javax.swing.plaf.DimensionUIResource;
import java.lang.reflect.InvocationTargetException;

public class P_16_swing {
    private JFrame f;
    private JButton r, b;

    public P_16_swing() {
        frameInit();
        buttonInit();
        f.add(r);
        f.add(b);
        f.pack();
        f.setVisible(true);
    }

    private void frameInit() {
        f = new JFrame("Practical 16");
        f.setLayout(null);
        f.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        f.setPreferredSize(new DimensionUIResource(350,350));
        f.setResizable(false);
    }

    private void buttonInit() {
        r = new JButton("Red");
        r.setBounds(50,50,50,50);
        r.setBorder(BorderFactory.createRaisedBevelBorder());
        r.addActionListener(e -> f.getContentPane().setBackground(ColorUIResource.red));

        b = new JButton("Blue");
        b.setBounds(110,50,50,50);
        b.setBorder(BorderFactory.createRaisedBevelBorder());
        b.addActionListener(e -> f.getContentPane().setBackground(ColorUIResource.blue));
    }

    public static void main(String[] args) {
        try {
            SwingUtilities.invokeAndWait(P_16_swing::new);
        } catch (InterruptedException | InvocationTargetException e) {
            e.printStackTrace();
        }
    }
}
