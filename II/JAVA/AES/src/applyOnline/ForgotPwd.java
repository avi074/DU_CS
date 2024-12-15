package applyOnline;

import Database.Aspirant;
import Database.ChkErrors;

import javax.swing.*;
import java.awt.Font;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.Objects;

public class ForgotPwd extends JDialog implements ActionListener{
    private final JLabel l_1, l_2;
    private final JTextField txt_1;
    private final JPasswordField txt_2;
    private final JButton ccBtn;
    private String key;

    /**
     * Create the dialog.
     */
    public ForgotPwd() {
        setTitle("ForgotPassword - Admission Enquiry System");
        setIconImage(new ImageIcon(Objects.requireNonNull(getClass().getClassLoader().getResource("Logo.png"))).getImage());
        setDefaultCloseOperation(JDialog.DO_NOTHING_ON_CLOSE);
        setBounds(100, 100, 484, 311);
        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                dispose();
                new Login().setVisible(true);
            }
        });
        getContentPane().setLayout(null);

        l_1 = new JLabel("User E- mail");
        l_1.setHorizontalAlignment(SwingConstants.CENTER);
        l_1.setFont(new Font("Dialog", Font.BOLD, 14));
        l_1.setBounds(10, 84, 180, 33);
        getContentPane().add(l_1);

        JLabel l_fpwd = new JLabel("Forgot Password");
        l_fpwd.setHorizontalAlignment(SwingConstants.CENTER);
        l_fpwd.setFont(new Font("Dialog", Font.BOLD, 16));
        l_fpwd.setBounds(110, 5, 251, 33);
        getContentPane().add(l_fpwd);

        l_2 = new JLabel("Security Key");
        l_2.setHorizontalAlignment(SwingConstants.CENTER);
        l_2.setFont(new Font("Dialog", Font.BOLD, 14));
        l_2.setBounds(10, 135, 180, 33);
        getContentPane().add(l_2);

        ccBtn = new JButton("Check");
        ccBtn.setToolTipText("Click to check your details");
        ccBtn.setActionCommand("Check");
        ccBtn.setFont(new Font("Times New Roman", Font.BOLD | Font.ITALIC, 16));
        ccBtn.setBounds(167, 214, 105, 33);
        ccBtn.addActionListener(this);
        getContentPane().add(ccBtn);

        txt_1 = new JTextField();
        txt_1.setFont(new Font("DialogInput", Font.BOLD, 14));
        txt_1.setBounds(213, 88, 221, 28);
        getContentPane().add(txt_1);
        txt_1.setColumns(10);

        txt_2 = new JPasswordField();
        txt_2.setFont(new Font("DialogInput", Font.BOLD, 14));
        txt_2.setColumns(10);
        txt_2.setBounds(213, 139, 221, 28);
        getContentPane().add(txt_2);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String pass = String.valueOf(txt_2.getPassword());
        if(e.getActionCommand().equals("Check")) {
            key = Aspirant.get("sec_key","email = '"+txt_1.getText()+"'");
            if((!ChkErrors.fieldError(txt_1,txt_2)) && key.equals(pass)) {
                l_1.setText("Enter new Password");
                l_2.setText("Re-enter the Password");
                ccBtn.setText("Update");
                ccBtn.setActionCommand("Update");
                ccBtn.setToolTipText("Click to update your password");
            }else
                JOptionPane.showInternalMessageDialog(null,"Entered data is invalid or incorrect !!!","DataNotFound",JOptionPane.ERROR_MESSAGE);
        }else {
            if((!ChkErrors.fieldError(txt_1,txt_2)) && txt_1.getText().equals(pass)){
                Aspirant.Update("password",pass,"sec_key = '"+key+"'");
                JOptionPane.showMessageDialog(null,"Your password has been updated successfully !!!","UpdatePassword",JOptionPane.INFORMATION_MESSAGE);
                dispose();
                new Login().setVisible(true);
            }
        }
    }
}