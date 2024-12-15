package applyOnline;

import Database.Aspirant;
import Database.ChkErrors;
import Database.DB;
import GUI.GFrame;
import com.toedter.calendar.JDateChooser;
import javax.swing.*;
import javax.swing.event.MouseInputAdapter;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Register extends GFrame {

	// @User Data
	private JTextField name, f_name, m_name;
	private JTextField mob, email, pass;
	private JPasswordField c_pass;
	private JComboBox <String> Gen, categ;
	private JDateChooser dob;

	/**
	 * @create Register Frame
	 * @create bg as image Background
	 *
	 * @Fields User Data
	 */
	public Register(){
		setTitle("Register - ");
		setResizable(false);
		setPreferredSize(new Dimension(650,650));

		//background
		JLabel bg = new JLabel(resize(getClass().getClassLoader().getResource("Menu_bg.jpg"), new Dimension(650, 650)));
		bg.setBounds(0,0,650,650);
		bg.setLayout(null);
		bg.setLabelFor(this);
		setContentPane(bg);

		//heading
		JLabel heading = new JLabel("Register");
		heading.setHorizontalAlignment(SwingConstants.CENTER);
		heading.setFont(new Font("Segoe Print", Font.BOLD, 26));
		heading.setBounds(105, 11, 441, 49);
		getContentPane().add(heading);

		//Other Settings
		fieldInit();
		buttonInit();
		settings();
		setMainbtn(500,562);
		pack();
	}

	/**
	 * @create User fields
	 */

	private void fieldInit(){
		//User Name
		name = new JTextField(10);
		name.setFont(new Font("SansSerif", Font.BOLD, 16));
		name.setHorizontalAlignment(SwingConstants.CENTER);
		name.setToolTipText("Enter the Applicant's Name");
		name.setBounds(130, 100, 390, 35);
		getContentPane().add(name);

		//Father's Name
		f_name = new JTextField(10);
		f_name.setFont(new Font("SansSerif", Font.BOLD, 16));
		f_name.setHorizontalAlignment(SwingConstants.CENTER);
		f_name.setToolTipText("Enter the Father's Name");
		f_name.setBounds(130, 147, 390, 35);
		getContentPane().add(f_name);

		//Mother's Name
		m_name = new JTextField(10);
		m_name.setFont(new Font("SansSerif", Font.BOLD, 16));
		m_name.setHorizontalAlignment(SwingConstants.CENTER);
		m_name.setToolTipText("Enter the Mother's Name");
		m_name.setBounds(130, 194, 390, 35);
		getContentPane().add(m_name);

		//User Gender
		Gen = new JComboBox<String>(new String[]{"*** Gender ***", "Male", "Female", "Transgender"});
		Gen.setToolTipText("Choose your Gender");
		Gen.setFont(new Font("Tahoma", Font.PLAIN, 14));
		Gen.setBounds(130, 240, 146, 31);
		Gen.setBackground(Transparent);
		Gen.setBorder(Round_border);
		getContentPane().add(Gen);

		//User category
		categ = new JComboBox<String>(new String[]{"*** Category ***", "Gen", "OBC/PWD", "SC","ST"});
		categ.setToolTipText("Choose your Category");
		categ.setFont(new Font("Tahoma", Font.PLAIN, 14));
		categ.setBounds(307, 240, 213, 31);
		categ.setBorder(Round_border);
		categ.setBackground(Transparent);
		getContentPane().add(categ);

		JLabel l_dob = new JLabel("Date of Birth");
		l_dob.setHorizontalAlignment(JLabel.CENTER);
		l_dob.setBorder(Round_border);
		l_dob.setFont(new Font("SansSerif", Font.BOLD, 14));
		l_dob.setBounds(130,282,146,31);
		getContentPane().add(l_dob);
		//User Date of Birth
		dob = new JDateChooser();
		dob.setBounds(307,282,213,31);
		dob.setMaxSelectableDate(new Date());
		getContentPane().add(dob);

		//User Mobile
		mob = new JTextField(10);
		mob.setFont(new Font("SansSerif", Font.BOLD, 16));
		mob.setToolTipText("Enter the Mobile Number");
		mob.setHorizontalAlignment(SwingConstants.CENTER);
		mob.setBounds(130, 328, 390, 35);
		getContentPane().add(mob);

		//User Email
		email = new JTextField(10);
		email.setFont(new Font("SansSerif", Font.BOLD, 16));
		email.setToolTipText("Enter the Email id");
		email.setHorizontalAlignment(SwingConstants.CENTER);
		email.setBounds(130, 374, 390, 35);
		getContentPane().add(email);

		//User Password
		pass = new JTextField(10);
		pass.setFont(new Font("SansSerif", Font.BOLD, 16));
		pass.setToolTipText("Enter the Password");
		pass.setHorizontalAlignment(SwingConstants.CENTER);
		pass.setBounds(130, 420, 390, 35);
		getContentPane().add(pass);

		//User Confirm Password
		c_pass = new JPasswordField();
		c_pass.setFont(new Font("SansSerif", Font.BOLD, 16));
		c_pass.setToolTipText("Confirm Password");
		c_pass.setEchoChar((char)0);
		c_pass.setHorizontalAlignment(SwingConstants.CENTER);
		c_pass.setBounds(130, 465, 390, 35);
		c_pass.addMouseListener(new MouseInputAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				c_pass.setEchoChar('*');
			}
		});
		getContentPane().add(c_pass);
	}

	/**
	 * @create Register & reset buttons
	 */
	private void buttonInit() {
		//Register Button
		JButton reg = new JButton("Register");
		reg.setToolTipText("Click to register");
		reg.setFont(new Font("Tahoma", Font.BOLD, 13));
		reg.setBounds(130, 510, 146, 35);
		reg.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				chkAndRegister();
			}
		});
		getContentPane().add(reg);

		//Reset Button
		JButton rst = new JButton("Reset");
		rst.setToolTipText("Reset all the fields");
		rst.setFont(new Font("Tahoma", Font.BOLD, 13));
		rst.setBounds(374, 510, 146, 35);
		rst.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				settings();
			}
		});
		getContentPane().add(rst);
	}
	private void settings() {
		name.setText("");
		f_name.setText("");
		m_name.setText("");
		mob.setText("");
		email.setText("");
		pass.setText("");
		c_pass.setText("");
		setParameters(Transparent,Round_border,name,f_name,m_name,mob,email,pass,c_pass);
		Placeholder(name,f_name,m_name,mob,email,pass,c_pass);
		Gen.setSelectedIndex(0);
		categ.setSelectedIndex(0);
		dob.setDate(null);
	}
	/**
	 * @Check TextFields
	 * @Generate Error Messages
	 * or @Register user on SQL
	 */
	private void chkAndRegister() {
		if(!ChkErrors.regError(Gen,categ,dob,name,f_name,mob,m_name,email,pass,c_pass)){
			String date = new SimpleDateFormat("dd-MM-yyyy").format(dob.getDate());
			Aspirant.setUser(Gen.getSelectedIndex(),categ.getSelectedIndex(),name.getText(),f_name.getText(),m_name.getText(),date,mob.getText(),email.getText(),pass.getText());
			String s = DB.toStr(Aspirant.get("reg_no","email = '"+email.getText()+"' AND password = '" + pass.getText()+"'"));
			String sec = DB.toStr(Aspirant.get("sec_key","email = '"+email.getText()+"' AND password = '" + pass.getText()+"'"));
			JOptionPane.showMessageDialog(this,"You are registered successfully !!! \n Your Registration no. is " + s + " !!!\n Your Security key is " + sec ,"Registration",JOptionPane.INFORMATION_MESSAGE);
			dispose();
			new Login().setVisible(true);
		}
	}
}
