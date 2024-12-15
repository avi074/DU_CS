package GUI;

import MainFrames.MainMenu;

import javax.swing.*;
import javax.swing.plaf.nimbus.NimbusLookAndFeel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.Objects;

public class GFrame extends JFrame implements BasicFunctionality{
    private JButton Main;
    // Constructors
    public GFrame() throws HeadlessException {
        super();
        setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
        setIconImage(new ImageIcon(Objects.requireNonNull(getClass().getClassLoader().getResource("Logo.png"))).getImage());
        setLookAndFeel(new NimbusLookAndFeel());
        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                if(JOptionPane.showInternalConfirmDialog(null,"Do you want to exit ?","Exit",JOptionPane.YES_NO_OPTION,JOptionPane.WARNING_MESSAGE) == JOptionPane.OK_OPTION) {
                    System.gc();
                    System.exit(0);
                }
            }
        });
    }

    //Method
    @Override
    public void setTitle(String title){
        super.setTitle(title + "Admission Enquiry System");
    }
    public void setLookAndFeel(LookAndFeel newLookAndFeel){
        try {
            UIManager.setLookAndFeel(newLookAndFeel);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    public void setVisible(boolean b) {
        Dimension screen = Toolkit.getDefaultToolkit().getScreenSize();
        setLocation(screen.width / 4, screen.height / 4);
        super.setVisible(b);
    }

    public void setMainbtn(int x, int y) {
        Color c = new Color(250, 175, 175, 238);
    	Main = new JButton("Main Menu");
		Main.setFont(new Font("Tahoma", Font.BOLD, 12));
		Main.setToolTipText("Back to Main");
		Main.setBounds(x, y, 110, 30);
		Main.setBackground(c);
		Main.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new MainMenu().setVisible(true);
                dispose();
            }
        });
		Animation(new Color(219, 46, 150,200),c,Main);
		getContentPane().add(Main);
    }

    public JButton getMainbtn(int x, int y) {
        setMainbtn(x,y);
        return Main;
    }
}
