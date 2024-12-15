package applyOnline;

import Database.Aspirant;
import Database.DB;
import GUI.GPanel;

import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.beans.PropertyChangeEvent;
import java.beans.PropertyChangeListener;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.sql.Blob;
import java.sql.ResultSet;
import java.sql.SQLException;

public class Profile extends GPanel {
    private JLabel photo, sign;
    private JTextField name, f_name, m_name;
    private JTextField mob, email,key,ddob;
    private JPasswordField pwf;
    private JButton btn;
    private JComboBox<String> gen, Categ;
    private boolean active = false;
    private File f;
    private ResultSet rset;
    private Blob blob;
    /**
     * Create the panel.
     */
    public Profile(ResultSet rs){
        try {
            rset = rs;
            active = (rs.getBlob("photo") == null);
            setBounds(0,0,745,750);

            label_init();
            fieldInit();

            setReg_no(10,11,rs.getString("reg_no"));
            setParameters(Color.darkGray,Round_border,new Font("Tahoma",Font.PLAIN,14),photo,sign);
            change(active, gen,Categ,name,f_name,m_name,mob,ddob,key,email,pwf);

        } catch (SQLException |IOException throwables) {
            DB.ShowError(throwables);
        }
    }

    private void label_init() throws SQLException, IOException {
        photo = new JLabel();
        photo.setIcon(BlobtoIcon("photo"));
        photo.setHorizontalAlignment(CENTER);
        photo.setToolTipText("(Maximum size 50 kb)");
        photo.setBounds(127, 60, 117, 115);
        photo.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                if(active){
                    f = getFile(photo,50);
                    try {
                        if(f != null){
                            photo.setText("");
                            photo.setIcon(resize(f.getAbsolutePath(),new Dimension(115,115)));
                            Aspirant.setImage(f,"photo","reg_no = '"+ rset.getString("reg_no")+ "'");
                        }
                    } catch (SQLException throwables) {
                       DB.ShowError(throwables);
                    }
                }
            }
        });
        photo.addPropertyChangeListener(new PropertyChangeListener() {
            @Override
            public void propertyChange(PropertyChangeEvent evt) {
                if (photo.getIcon() != null) {
                    photo.setText("");
                } else {
                    photo.setText("User Photo");
                }
            }
        });
        add(photo);

        sign = new JLabel("User Sign");
        sign.setHorizontalAlignment(CENTER);
        sign.setIcon(BlobtoIcon("sign"));
        sign.setToolTipText("(Maximum size 20 kb)");
        sign.setBounds(400, 60, 117, 115);
        sign.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                if(f != null && active){
                    f = getFile(sign,20);
                    try{
                        if(f != null){
                            sign.setText("");
                            sign.setIcon(resize(f.getAbsolutePath(),new Dimension(115,115)));
                            Aspirant.setImage(f,"sign","reg_no = '"+ rset.getString("reg_no")+ "'");
                        }
                    } catch (SQLException throwables) {
                        DB.ShowError(throwables);
                    }
                }
            }
        });
        sign.addPropertyChangeListener(new PropertyChangeListener() {
            @Override
            public void propertyChange(PropertyChangeEvent evt) {
                if (sign.getIcon() != null) {
                    sign.setText("");
                } else {
                    sign.setText("User Photo");
                }
            }
        });
        add(sign);

        JLabel l_name = new JLabel("Applicant's Name");
        l_name.setHorizontalAlignment(SwingConstants.CENTER);
        l_name.setFont(new Font("Lao UI", Font.BOLD, 16));
        l_name.setBounds(72, 244, 172, 26);
        add(l_name);

        JLabel l_name_1 = new JLabel("Father's Name");
        l_name_1.setHorizontalAlignment(SwingConstants.CENTER);
        l_name_1.setFont(new Font("Lao UI", Font.BOLD, 16));
        l_name_1.setBounds(72, 282, 172, 26);
        add(l_name_1);

        JLabel l_name_2 = new JLabel("Mother's Name");
        l_name_2.setHorizontalAlignment(SwingConstants.CENTER);
        l_name_2.setFont(new Font("Lao UI", Font.BOLD, 16));
        l_name_2.setBounds(72, 320, 172, 26);
        add(l_name_2);

        JLabel l_dob = new JLabel("Date of Birth");
        l_dob.setHorizontalAlignment(SwingConstants.CENTER);
        l_dob.setFont(new Font("Lao UI", Font.BOLD, 16));
        l_dob.setBounds(72, 434, 172, 26);
        add(l_dob);

        JLabel l_mob = new JLabel("Mobile No.");
        l_mob.setHorizontalAlignment(SwingConstants.CENTER);
        l_mob.setFont(new Font("Lao UI", Font.BOLD, 16));
        l_mob.setBounds(72, 473, 172, 26);
        add(l_mob);

        JLabel l_email = new JLabel("E - mail");
        l_email.setHorizontalAlignment(SwingConstants.CENTER);
        l_email.setFont(new Font("Lao UI", Font.BOLD, 16));
        l_email.setBounds(72, 510, 172, 26);
        add(l_email);

        JLabel l_gen = new JLabel("Gender");
        l_gen.setHorizontalAlignment(SwingConstants.CENTER);
        l_gen.setFont(new Font("Lao UI", Font.BOLD, 16));
        l_gen.setBounds(72, 358, 172, 26);
        add(l_gen);

        JLabel l_key = new JLabel("Security Key");
        l_key.setHorizontalAlignment(SwingConstants.CENTER);
        l_key.setFont(new Font("Lao UI", Font.BOLD, 16));
        l_key.setBounds(72, 548, 172, 26);
        add(l_key);

        JLabel l_pwd = new JLabel("Password");
        l_pwd.setHorizontalAlignment(SwingConstants.CENTER);
        l_pwd.setFont(new Font("Lao UI", Font.BOLD, 16));
        l_pwd.setBounds(72, 586, 172, 26);
        add(l_pwd);

        JLabel l_categ = new JLabel("Category");
        l_categ.setHorizontalAlignment(SwingConstants.CENTER);
        l_categ.setFont(new Font("Lao UI", Font.BOLD, 16));
        l_categ.setBounds(72, 395, 172, 26);
        add(l_categ);
    }

    private void fieldInit() throws SQLException {
        name = new JTextField(rset.getString("name"));
        name.setFont(new Font("Meiryo UI", Font.BOLD, 15));
        name.setHorizontalAlignment(CENTER);
        name.setBounds(333, 243, 260, 26);
        add(name);

        f_name = new JTextField(rset.getString("f_name"));
        f_name.setFont(new Font("Meiryo UI", Font.BOLD, 15));
        f_name.setHorizontalAlignment(CENTER);
        f_name.setBounds(333, 281, 260, 26);
        add(f_name);

        m_name = new JTextField(rset.getString("m_name"));
        m_name.setFont(new Font("Meiryo UI", Font.BOLD, 15));
        m_name.setHorizontalAlignment(CENTER);
        m_name.setBounds(333, 319, 260, 26);
        add(m_name);

        gen = new JComboBox<String>(new String[] {"Male", "Female", "TransGender"});
        gen.setFont(new Font("Tahoma", Font.BOLD, 14));
        gen.setBounds(333, 357, 260, 26);
        gen.setSelectedIndex(rset.getInt("gen") - 1);
        add(gen);

        Categ = new JComboBox<String>(new String[] {"GEN", "OBC/PWD", "SC", "ST"});
        Categ.setFont(new Font("Tahoma", Font.BOLD, 14));
        Categ.setBounds(333, 394, 260, 26);
        Categ.setSelectedIndex(rset.getInt("categ")-1);
        add(Categ);

        ddob = new JTextField(rset.getString("dob"));
        ddob.setFont(new Font("Meiryo UI", Font.BOLD, 15));
        ddob.setBounds(333, 433, 260, 26);
        add(ddob);

        mob = new JTextField(rset.getString("mob"));
        mob.setFont(new Font("Meiryo UI", Font.BOLD, 15));
        mob.setHorizontalAlignment(SwingConstants.CENTER);
        mob.setBounds(333, 472, 260, 26);
        add(mob);

        email = new JTextField(rset.getString("email"));
        email.setFont(new Font("Meiryo UI", Font.BOLD, 15));
        email.setHorizontalAlignment(SwingConstants.CENTER);
        email.setBounds(333, 510, 260, 26);
        add(email);

        key = new JTextField(rset.getString("sec_key"));
        key.setFont(new Font("Meiryo UI", Font.BOLD, 15));
        key.setHorizontalAlignment(CENTER);
        key.setBounds(333, 548, 260, 26);
        add(key);

        pwf = new JPasswordField(rset.getString("password"));
        pwf.setFont(new Font("Meiryo UI", Font.BOLD, 15));
        pwf.setHorizontalAlignment(CENTER);
        pwf.setBounds(333, 586, 260, 26);
        add(pwf);

        btn = new JButton("Edit");
        btn.setFont(new Font("Tahoma", Font.BOLD, 14));
        btn.setBounds(225,640, 172, 34);
        btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                active = !active;
                change(active, gen,Categ,name,f_name,m_name,mob,ddob,key,email,pwf);
                if(active){
                    btn.setText("Save");
                    btn.setActionCommand("Save");
                }else{
                    btn.setText("Edit");
                    btn.setActionCommand("Edit");
                }
            }
        });
        this.add(btn);
    }

    private File getFile(JLabel c, int size){
        File img = null;
        JFileChooser file = new JFileChooser("user.home");
        file.setFileFilter(new FileNameExtensionFilter("image files","jpg","png","gif","jpeg","bmp"));
        int rs = file.showOpenDialog(c);
        if(rs == JFileChooser.APPROVE_OPTION){
            img = file.getSelectedFile();
            if(isIMG(img)) {
                if (file.getSelectedFile().length() / 1024 > size)
                    JOptionPane.showMessageDialog(null, "Please Choose an appropriate file.\nPhoto should be not more than 50 kb !\nSign should not be more than 20 kb !", "FileSizeError", JOptionPane.ERROR_MESSAGE);
            }else
                JOptionPane.showMessageDialog(null,"Please choose an appropriate file type !!!","FileTypeError",JOptionPane.ERROR_MESSAGE);
        }
        return img;
    }

    private boolean isIMG(File f){
        boolean img = false;
        String[] ext = {".JPG",".jpg",".png",".bmp",".jpeg",".gif"};

        for (String s : ext)
            if (f.getName().endsWith(s)) {
                img = true;
                break;
            }
        return img;
    }
    private Icon BlobtoIcon(String field) throws SQLException, IOException {
        blob = rset.getBlob(field);
        String path = "C:\\Windows\\temp\\" + field +".jpg";
        if(blob != null){
            FileOutputStream fout = new FileOutputStream(path);
            f = new File(path);
            fout.write(blob.getBytes(1, (int) blob.length()));
            return resize(path,new Dimension(115,115));
        }
        return null;
    }
}