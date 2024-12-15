import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.lang.reflect.InvocationTargetException;

public class P_12_awt {

    public P_12_awt(){
        String[] s = {" Name : Avinash \n Course : B.Sc(H) Computer Science \n Roll no. : 20201407 \n College : Ramanujan College ",
                "Semester : 2 \nCGPA : 9.45 / 10"};
        //Frame
        Frame f = new Frame("Practical 12");
        f.setLayout(new BorderLayout());
        f.setPreferredSize(new Dimension(400,400));
        f.setLocationRelativeTo(null);
        f.setResizable(false);
        f.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                f.dispose();
            }
        });
        //Panel
        Panel panel = new Panel();
        panel.setPreferredSize(new Dimension(100,100));
        panel.setLayout(new FlowLayout(FlowLayout.CENTER,10,5));
        //Status Field
        TextArea stat = new TextArea();
        stat.setPreferredSize(new Dimension(100,100));
        stat.setFont(new Font("Tahoma",Font.PLAIN,12));
        stat.setEditable(false);
        //A button
        Button a = new Button("A");
        a.setPreferredSize(new Dimension(40,40));
        a.addActionListener(e -> stat.setText(s[0]));
        panel.add(a);
        //B button
        Button b = new Button("B");
        b.setPreferredSize(new Dimension(40,40));
        b.addActionListener(e -> stat.setText(s[1]));
        panel.add(b);

        f.add(panel,BorderLayout.NORTH);
        f.add(stat,BorderLayout.CENTER);
        f.pack();
        f.setVisible(true);
    }

    public static void main(String[] args) {
        try {
            EventQueue.invokeAndWait(P_12_awt::new);
        } catch (InterruptedException | InvocationTargetException e) {
            e.printStackTrace();
        }
    }
}
