import javax.swing.JFrame;
import javax.swing.SwingUtilities;
import javax.swing.plaf.ColorUIResource;
import javax.swing.plaf.DimensionUIResource;
import javax.swing.plaf.FontUIResource;
import java.awt.Graphics;
import java.lang.reflect.InvocationTargetException;

public class P_15_swing {
    public P_15_swing(){
        JFrame f = new JFrame("Practical 15"){
            @Override
            public void paint(Graphics g) {
                super.paint(g);
                g.setColor(ColorUIResource.pink);
                g.fillRect(0,0,350,350);
                g.setColor(ColorUIResource.BLACK);
                g.setFont(new FontUIResource("Segoe UI",FontUIResource.BOLD,18));
                g.drawString("Hello World", 130,175);
                g.dispose();
            }
        };
        f.setPreferredSize(new DimensionUIResource(350,350));
        f.setResizable(false);
        f.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        f.pack();
        f.setVisible(true);
    }
    public static void main(String[] args) {
        try {
            SwingUtilities.invokeAndWait(P_15_swing::new);
        } catch (InterruptedException | InvocationTargetException e) {
            e.printStackTrace();
        }
    }
}
