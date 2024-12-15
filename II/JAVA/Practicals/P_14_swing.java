import javax.swing.*;
import javax.swing.event.MouseInputAdapter;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.lang.reflect.InvocationTargetException;

public class P_14_swing {

    public P_14_swing(){
        Dimension  d =  Toolkit.getDefaultToolkit().getScreenSize();

        JFrame f = new JFrame("Practical 14");
        f.setSize(d.width/3,d.height/3);
        f.setLocation(d.width/3,d.height/3);
        f.addMouseListener(new MouseInputAdapter(){
            @Override
            public void mouseClicked(MouseEvent e) {
                Point p = MouseInfo.getPointerInfo().getLocation();
                f.setSize(d.width/3,d.height/3);
                f.setLocation(p.x/2,p.y/2);
            }

            @Override
            public void mouseEntered(MouseEvent e) {
                f.setSize(3*d.width, 3*d.height);
                f.setLocation(0,0);
            }

            @Override
            public void mouseExited(MouseEvent e) {
                System.exit(0);
            }
        });
        f.setVisible(true);
    }

    public static void main(String[] args) {
        try {
            SwingUtilities.invokeAndWait(P_14_swing::new);
        } catch (InterruptedException | InvocationTargetException e) {
            e.printStackTrace();
        }
    }
}
