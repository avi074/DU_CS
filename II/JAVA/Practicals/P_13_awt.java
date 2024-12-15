import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.lang.reflect.InvocationTargetException;

public class P_13_awt extends Frame implements Runnable{
    private Label txt;

    public P_13_awt(){
        frameInit();
        fieldInit();
        add(txt);
        pack();
        setVisible(true);
    }

    @SuppressWarnings("deprecation")
    private void frameInit() {
        setTitle("Practical 13");
        setLayout(null);
        setPreferredSize(new Dimension(400,150));
        setLocationRelativeTo(null);
        setResizable(false);
        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                dispose();
            }
        });
    }

    private void fieldInit() {
        txt = new Label("Hello World !!!");
        txt.setBounds(50,50,100,30);
        txt.setAlignment(Label.CENTER);
        txt.setBackground(Color.PINK);
        txt.setFont(new Font("Arial",Font.BOLD,14));
    }

    public static void main(String[] args) throws InterruptedException {
        Thread t = new Thread(new P_13_awt());
        t.start();
        t.join();
    }

    @Override
    public void run() {
        Point p = txt.getLocation();
        for(int i = p.x; i != getWidth() - txt.getWidth(); i += 2){
            txt.setLocation(i,p.y);
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
