package applyOnline;

import Database.Aspirant;
import Database.DB;
import GUI.GFrame;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.ResultSet;
import java.sql.SQLException;

public class Dashboard extends GFrame implements ActionListener {
    private JLabel main;
    private JPanel right;
    private JButton profile,education,apply,application,back;
    private ResultSet rs;
    private String reg;
    
    /**
     * Create the frame.
     */
    public Dashboard(String reg) {
        this.reg = reg;

        Dimension size = new Dimension(820, 760);
        setTitle("Dashboard - ");
        setResizable(false);
        setPreferredSize(size);

        main = new JLabel();
        main.setLayout(null);
        setContentPane(main);

        leftPanel();
        right = new JPanel();
        right.setLayout(null);
        right.setBounds(175,0,745,750);
        setResultSet();
        setRight(new Profile(rs));

        main.add(right);
        pack();
    }

    private void leftPanel() {
        JPanel panel = new JPanel();
        panel.setBounds(0, 0, 174, 722);
        panel.setBackground(new Color(153, 0, 255));
        main.add(panel);
        panel.setLayout(null);

        JLabel photo = new JLabel("");
        photo.setIcon(resize(getClass().getClassLoader().getResource("user.png"),new Dimension(145,138)));
        photo.setHorizontalAlignment(CENTER);
        photo.setBorder(BorderFactory.createTitledBorder(Round_border));
        photo.setBounds(10, 11, 150, 140);
        panel.add(photo);

        profile = new JButton("Profile");
        profile.setForeground(new Color(0, 0, 51));
        profile.setHorizontalAlignment(CENTER);
        profile.setBounds(0, 198, 168, 38);
        profile.addActionListener(this);
        profile.setEnabled(true);
        panel.add(profile);

        education = new JButton("Qualifications");
        education.setForeground(new Color(0, 0, 51));
        education.setHorizontalAlignment(CENTER);
        education.setBounds(0, 237, 168, 38);
        education.addActionListener(this);
        panel.add(education);

        apply = new JButton("Apply for admission");
        apply.setForeground(new Color(0, 0, 51));
        apply.setHorizontalAlignment(CENTER);
        apply.setBounds(0, 277, 170, 38);
        apply.addActionListener(this);
        panel.add(apply);

        application = new JButton("My Applications");
        application.setForeground(new Color(0, 0, 51));
        application.setHorizontalAlignment(CENTER);
        application.setBounds(0, 320, 168, 38);
        application.addActionListener(this);
        panel.add(application);

        back = new JButton("LogOut");
        back.setForeground(new Color(0, 0, 51));
        back.setHorizontalAlignment(CENTER);
        back.setBounds(0, 361, 168, 38);
        back.addActionListener(this);
        panel.add(back);

        setParameters(Transparent,null,new Font("Nirmala UI", Font.BOLD, 15),profile,education,apply,application,back);
        Animation(new Color(190, 0, 255,170),profile.getBackground(),profile,education,apply,application,back);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == back){
            if(JOptionPane.showInternalConfirmDialog(null,"Do you want to LogOut ?","LogOut",JOptionPane.YES_NO_OPTION,JOptionPane.WARNING_MESSAGE) == JOptionPane.YES_OPTION){
                try {
                    rs.close();
                    dispose();
                    new Login().setVisible(true);
                } catch (SQLException throwables) {
                    DB.ShowError(throwables);
                }
            }
        }
        else if(e.getSource().equals(profile))
            setRight(new Profile(rs));
        else if(e.getSource().equals(education))
            setRight(new qualification(rs));
        else if(e.getSource().equals(apply))
            setRight(new apply(rs));
        else
            setRight(new MyApplication(rs));
    }

    private void setRight(JPanel p){
        right.removeAll();
        right.repaint();
        right.revalidate();
        right.add(p);
        right.repaint();
        right.revalidate();
        setResultSet();
    }

    private void setResultSet() {
        rs = Aspirant.getTable("reg_no = '"+ reg + "'");
    }
}