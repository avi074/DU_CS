import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.lang.reflect.InvocationTargetException;

public class P_8_awt{
    public P_8_awt(){
        Frame f = new Frame("Practical 8");
        Dimension d = Toolkit.getDefaultToolkit().getScreenSize();

        f.setSize(d.width/3,d.height/3);
        f.setLocationByPlatform(true);
        f.addMouseListener(new MouseAdapter() {
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
            EventQueue.invokeAndWait(P_8_awt::new);
        } catch (InterruptedException | InvocationTargetException e) {
            e.printStackTrace();
        }
    }
}
