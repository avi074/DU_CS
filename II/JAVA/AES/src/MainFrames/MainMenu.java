package MainFrames;

import GUI.GFrame;
import applyOnline.Login;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MainMenu extends GFrame implements ActionListener{

	private final JLabel bg;
	private JButton apply, eligible, cutOff, about;

	/**
	 * Create the frame.
	 */
	public MainMenu() {
		Dimension size = new Dimension(900,500);
		setResizable(false);
		setTitle("");
		setPreferredSize(size);
		
		bg = new JLabel(resize(getClass().getClassLoader().getResource("bg1.jpg"),size),CENTER);
		bg.setLayout(null);
		setContentPane(bg);
		
		JLabel heading = new JLabel("Admission Enquiry System");
		heading.setForeground(new Color(213, 70, 250));
		heading.setBounds(200, 6, 450, 75);
		heading.setBorder(BorderFactory.createCompoundBorder(Round_Title_border,BorderFactory.createRaisedBevelBorder()));
		heading.setHorizontalAlignment(CENTER);
		heading.setFont(new Font("Arial Narrow", Font.BOLD, 30));
		bg.add(heading);
		
		JLabel menu = new JLabel("MENU");
		menu.setForeground(new Color(51, 150, 255));
		menu.setHorizontalAlignment(0);
		menu.setBounds(400, 80, 100, 51);
		menu.setBorder(BorderFactory.createLoweredSoftBevelBorder());
		menu.setFont(new Font("Tahoma", Font.PLAIN, 30));
		bg.add(menu);
		
		buttonInit();
		pack();
	}

	private void buttonInit() {
		Color back = new Color(231, 132, 183, 180);
		Color back1 = new Color(0xD05489E5, true);
		apply = new JButton("APPLY ONLINE");
		apply.addActionListener(this);
		apply.setFont(new Font("Arial Narrow", Font.BOLD, 18));
		apply.setBounds(100, 211, 300, 50);
		apply.setBackground(back);
		bg.add(apply);

		cutOff = new JButton("CHECK CUTOFF");
		cutOff.addActionListener(this);
		cutOff.setFont(new Font("Arial Narrow", Font.BOLD, 18));
		cutOff.setBounds(450, 211, 300, 50);
		cutOff.setBackground(back1);
		bg.add(cutOff);

		eligible = new JButton("CHECK ELIGIBILITY");
		eligible.setFont(new Font("Arial Narrow", Font.BOLD, 18));
		eligible.setBounds(100, 313, 300, 50);
		eligible.addActionListener(this);
		eligible.setBackground(back1);
		bg.add(eligible);

		about = new JButton("ABOUT COLLEGES");
		about.addActionListener(this);
		about.setFont(new Font("Arial Narrow", Font.BOLD, 18));
		about.setBounds(450, 313, 300, 50);
		about.setBackground(back);
		bg.add(about);

		Animation(new Color(243, 121, 84),back,apply,about);
		Animation(new Color(119, 238, 186),back1,eligible,cutOff);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == apply)
			new Login().setVisible(true);
		else if (e.getSource() == eligible)
			new CheckEligibility().setVisible(true);
		else if (e.getSource() == cutOff)
			new Cutoff().setVisible(true);
		else if (e.getSource() == about)
			new AboutDU().setVisible(true);
		dispose();
	}
}
