package GUI;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class GPanel extends JPanel implements BasicFunctionality{
    public GPanel() {
        super();
        setLayout(null);
    }
    public void setReg_no(int x, int y,String text){
        JLabel reg_key = new JLabel("Registration No.");
        reg_key.setHorizontalAlignment(SwingConstants.LEFT);
        reg_key.setFont(new Font("Lao UI", Font.BOLD, 14));
        reg_key.setBounds(x, y, 250, 20);

        JTextField reg_no = new JTextField(text);
        reg_no.setEditable(false);
        reg_no.setHorizontalAlignment(SwingConstants.CENTER);
        reg_no.setFont(new Font("Meiryo UI", Font.PLAIN, 12));
        reg_no.setBounds(120,0,100,22);
        reg_key.add(reg_no);
        this.add(reg_key);
    }
}
