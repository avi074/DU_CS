package applyOnline;

import Database.Aspirant;
import Database.ChkErrors;
import GUI.GFrame;
import Database.UserPref;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class Login extends GFrame implements ActionListener{

	private JTextField email;
	private JButton login, reg;
	private JCheckBox remember;
	private JPasswordField password;
	private boolean visible = false;

	public Login() {
		setTitle("Login - ");
		setResizable(false);
		setPreferredSize(new Dimension(535,515));

		labelInit();
		fieldInit();
		buttonInit();

		UserPref.getPref(email,password);
		setParameters(Transparent,Round_border,email,password);
		Placeholder(email,password);
		setMainbtn(395,440);
		pack();
	}
	private void labelInit() {
		JLabel bg = new JLabel(resize(getClass().getClassLoader().getResource("bg12.jpg"),new Dimension(650,650)));
		bg.setBounds(0,0,535,515);
		bg.setLayout(null);
		bg.setLabelFor(this);
		setContentPane(bg);

		JLabel heading = new JLabel("LOGIN");
		heading.setFont(new Font("Segoe Print", Font.BOLD, 26));
		heading.setHorizontalAlignment(CENTER);
		heading.setBounds(95, 11, 298, 53);
		getContentPane().add(heading);

		ImageIcon show = resize(getClass().getClassLoader().getResource("show.png"),new Dimension(40,38));

		JLabel showPassword = new JLabel();
		showPassword.setIcon(show);
		showPassword.setToolTipText("Show Password");
		showPassword.setBounds(395, 166, 40, 38);
		showPassword.setLabelFor(password);
		showPassword.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				visible = !visible;
				if(visible) {
					showPassword.setIcon(resize(getClass().getClassLoader().getResource("hide.png"),new Dimension(40,38)));
					password.setEchoChar((char)0);
				}
				else {
					showPassword.setIcon(show);
					password.setEchoChar('*');
				}
			}
		});
		getContentPane().add(showPassword);

		JLabel emailLogo = new JLabel(resize(getClass().getClassLoader().getResource("user_logo.png"),new Dimension(60,43)));
		emailLogo.setLabelFor(email);
		emailLogo.setHorizontalAlignment(CENTER);
		emailLogo.setBounds(35, 98, 60, 43);
		getContentPane().add(emailLogo);

		JLabel pwdLogo = new JLabel(resize(getClass().getClassLoader().getResource("pwd_logo.png"),new Dimension(40,40)));
		pwdLogo.setLabelFor(password);
		pwdLogo.setHorizontalAlignment(CENTER);
		pwdLogo.setBounds(44, 165, 40, 40);
		getContentPane().add(pwdLogo);

		JLabel resetPwd = new JLabel("Forgot Password?");
		resetPwd.setFont(new Font("Segoe UI", Font.BOLD, 13));
		resetPwd.setToolTipText("Click to reset password");
		resetPwd.setForeground(Color.white);
		resetPwd.setHorizontalAlignment(CENTER);
		resetPwd.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
		resetPwd.setBounds(295, 217, 140, 30);
		resetPwd.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				dispose();
				new ForgotPwd().setVisible(true);
			}
		});
		getContentPane().add(resetPwd);

		JLabel lblNewLabel = new JLabel("----------------- or ------------------");
		lblNewLabel.setFont(new Font("Tahoma", Font.BOLD, 14));
		lblNewLabel.setHorizontalAlignment(CENTER);
		lblNewLabel.setForeground(Color.white);
		lblNewLabel.setBounds(95, 322, 333, 20);
		getContentPane().add(lblNewLabel);
	}

	private void fieldInit() {
		email = new JTextField("",15);
		email.setFont(new Font("Tahoma", Font.PLAIN, 16));
		email.setHorizontalAlignment(CENTER);
		email.setForeground(Color.white);
		email.setToolTipText("Enter your Email ID");
		email.setBounds(95, 100, 340, 40);
		getContentPane().add(email);

		password = new JPasswordField("");
		password.setToolTipText("Enter the Password");
		password.setHorizontalAlignment(CENTER);
		password.setForeground(Color.white);
		password.setFont(new Font("Tahoma", Font.PLAIN, 16));
		password.setBounds(95, 164, 300, 40);
		getContentPane().add(password);
	}

	private void buttonInit() {
		Color c = new Color(206, 97, 236, 225);
		login = new JButton("Login");
		login.setToolTipText("Click to Login");
		login.setFont(new Font("Tahoma", Font.BOLD, 14));
		login.setBounds(95, 275, 333, 36);
		login.addActionListener(this);
		Animation(new Color(137, 21, 238, 215),c,login);
		getContentPane().add(login);

		reg = new JButton("Register");
		reg.setToolTipText("Click to register");
		reg.setFont(new Font("Tahoma", Font.BOLD, 14));
		reg.setBounds(95, 356, 333, 36);
		reg.addActionListener(this);
		Animation(new Color(59, 93, 245, 206),c,reg);
		getContentPane().add(reg);

		remember = new JCheckBox("Remember me ");
		remember.setFont(new Font("Segoe UI", Font.BOLD, 13));
		remember.setForeground(Color.white);
		remember.setBounds(95, 218, 140, 30);
		getContentPane().add(remember);

		setParameters(c,null,new Font("Tahoma", Font.BOLD, 14),login,reg);
	}
	@Override
	public void actionPerformed(ActionEvent e) {
		if(e.getSource().equals(reg)){
			new Register().setVisible(true);
			dispose();
		}
		else{
			String reg;
			if((!ChkErrors.fieldError(email,password))){
				reg = Aspirant.chkLogin(email.getText(), String.valueOf(password.getPassword()));
				if(!reg.isBlank()){
					if(remember.isSelected())
						UserPref.setPref(email,password);
					new Dashboard(reg).setVisible(true);
					dispose();
				}else
					JOptionPane.showMessageDialog(null,"Invalid email or password !!!","LoginError",JOptionPane.ERROR_MESSAGE);

			}
		}
	}
}