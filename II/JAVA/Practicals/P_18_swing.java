import javax.swing.*;
import javax.swing.plaf.DimensionUIResource;
import javax.swing.plaf.FontUIResource;
import java.lang.reflect.InvocationTargetException;

public class P_18_swing {
    private final String[] s = {
            " Name    : Avinash \n Course  : B.Sc(H) Computer Science \n Roll no. : 20201407 \n College : Ramanujan College ",
            "Semester : 2 \nCGPA : 10 / 10"
    };

    public P_18_swing() {
        //Frame
        JFrame f = new JFrame("Practical 18");
        f.setLayout(new BoxLayout(f.getContentPane(), BoxLayout.Y_AXIS));
        f.setPreferredSize(new DimensionUIResource(400,400));
        f.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        f.setResizable(false);
        //Status Field
        JTextArea status = new JTextArea();
        status.setPreferredSize(new DimensionUIResource(200,200));
        status.setFont(new FontUIResource("Tahoma",FontUIResource.BOLD,16));
        status.setEditable(false);
        //A button
        JButton a = new JButton("A");
        a.setPreferredSize(new DimensionUIResource(50,50));
        a.addActionListener(e -> status.setText(s[0]));
        //B button
        JButton b = new JButton("B");
        b.setPreferredSize(new DimensionUIResource(50,50));
        b.addActionListener(e -> status.setText(s[1]));
        //Panel
        JPanel pane = new JPanel();
        pane.setPreferredSize(new DimensionUIResource(100,100));
        pane.add(a);
        pane.add(b);
        // Add to frame
        f.add(pane);
        f.add(status);
        f.pack();
        f.setVisible(true);
    }

    public static void main(String[] args) {
        try {
            SwingUtilities.invokeAndWait(P_18_swing::new);
        } catch (InterruptedException | InvocationTargetException e) {
            e.printStackTrace();
        }
    }
}
