import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.lang.reflect.InvocationTargetException;

public class P_10_awt {
    public P_10_awt(){
        init();
    }

    private void init() {
        Frame f = new Frame("Practical 10");
        f.setLayout(new FlowLayout(FlowLayout.CENTER,15,20));
        f.setPreferredSize(new Dimension(250,200));
        f.setLocationRelativeTo(null);
        f.setResizable(false);
        f.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                f.dispose();
            }
        });
        //red button
        Button red = new Button("Red");
        red.setPreferredSize(new Dimension(70,50));
        red.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                f.setBackground(Color.red);
            }
        });
        f.add(red);
        //blue button
        Button blue = new Button("Blue");
        blue.setPreferredSize(new Dimension(70,50));
        blue.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                f.setBackground(Color.BLUE);
            }
        });
        f.add(blue);
        //if you want to pack the elements in frame then you have to use setPreferredSize() function.
        f.pack();
        f.setVisible(true);
    }

    public static void main(String[] args){
        try {
            EventQueue.invokeAndWait(P_10_awt::new);
        } catch (InterruptedException | InvocationTargetException e) {
            e.printStackTrace();
        }
    }
}
