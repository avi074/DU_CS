import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import javax.swing.filechooser.FileSystemView;
import javax.swing.plaf.DimensionUIResource;
import javax.swing.plaf.FontUIResource;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.lang.reflect.InvocationTargetException;

public class P_17_swing {

    public P_17_swing() {
        JFrame f = new JFrame("Practical 17");
        f.setPreferredSize(new DimensionUIResource(400,400));
        f.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        f.setResizable(false);

        JLabel msg = new JLabel("Status Window");
        msg.setHorizontalAlignment(0);
        msg.setVerticalAlignment(0);
        msg.setFont(new FontUIResource("Arial",FontUIResource.BOLD,14));
        msg.setPreferredSize(new DimensionUIResource(200,200));

        f.addKeyListener(new KeyAdapter() {
            @Override
            public void keyTyped(KeyEvent e) {
                msg.setText("Typed Character is : "+ e.getKeyChar());
            }
        });
        f.add(msg);
        f.pack();
        f.setVisible(true);
    }

    public static void main(String[] args) {
        try {
            SwingUtilities.invokeAndWait(P_17_swing::new);
        } catch (InterruptedException | InvocationTargetException e) {
            e.printStackTrace();
        }
    }
}
