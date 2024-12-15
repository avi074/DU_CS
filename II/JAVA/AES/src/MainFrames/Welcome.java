package MainFrames;

import GUI.GFrame;
import Database.UserPref;

import javax.swing.*;
import java.util.Objects;

public class Welcome extends GFrame implements Runnable {
    /**
     * Create the frame.
     */
    public Welcome() {
        super();
        setLayout(null);
        setUndecorated(true);
        setSize(600,340);
        try {
            JLabel label = new JLabel(new ImageIcon(Objects.requireNonNull(getClass().getClassLoader().getResource("welcome.gif"))));
            setContentPane(label);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    public void run() {
        try {
            setVisible(true);
            UserPref.createPref();
            Thread.sleep(5000);
            dispose();
            new MainMenu().setVisible(true);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
