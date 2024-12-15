package MainFrames;

import Database.ChkErrors;
import Database.Colleges;
import Database.DB;
import GUI.GFrame;
import javax.swing.*;
import javax.swing.text.JTextComponent;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


public class CheckEligibility extends GFrame {

	/**
	 * Create the 
	 */
	public CheckEligibility() {
		setTitle("Check Eligibility - ");
		setLayout(null);
		setResizable(false);
		setPreferredSize(new Dimension(600,680));
		setContentPane(new JLabel("",resize(getClass().getClassLoader().getResource("Menu_bg1.jpg"),new Dimension(650,680)),CENTER));

		JLabel l1 = new JLabel("Check Eligibility");
		l1.setFont(new Font("MV Boli", Font.BOLD, 40));
		l1.setBounds(80, 50, 500, 50);

		JLabel l2 = new JLabel("Gender:");
		l2.setBounds(50, 150, 250, 20);
		l2.setFont(new Font("MV Boli", Font.BOLD, 20));
		
		JComboBox<String> cb = new JComboBox<String>(new String[]{"Male", "Female","TransGender"});
		cb.setBounds(260, 150, 90, 30);

		JLabel l3 = new JLabel("Category");
		l3.setFont(new Font("MV Boli", Font.BOLD, 20));
		l3.setBounds(50, 200, 250, 20);
		
		JComboBox<String> cb1 = new JComboBox<String>(new String[]{"Gen", "OBC/PWD", " SC", "ST"});
		cb1.setBounds(260, 200, 90, 30);

		JLabel l4 = new JLabel("12th Core Subject Marks");
		l4.setFont(new Font("MV Boli", Font.BOLD, 15));
		l4.setBounds(50, 250, 250, 20);

		JLabel l5 = new JLabel("Obtained marks");
		l5.setFont(new Font("MV Boli", Font.BOLD, 17));
		l5.setBounds(250, 250, 250, 20);

		JLabel l6 = new JLabel("Total Marks");
		l6.setFont(new Font("MV Boli", Font.BOLD, 17));
		l6.setBounds(400, 250, 250, 20);

		JLabel l7 = new JLabel("Subject 1");
		l7.setFont(new Font("MV Boli", Font.BOLD, 15));
		l7.setBounds(50, 300, 250, 20);

		JTextField tf1 = new JTextField();
		tf1.setBounds(250, 300, 80, 30);

		JTextField tf2 = new JTextField();
		tf2.setBounds(400, 300, 80, 30);


		JLabel l8 = new JLabel("Subject 2");
		l8.setFont(new Font("MV Boli", Font.BOLD, 15));
		l8.setBounds(50, 330, 250, 20);

		JTextField tf3 = new JTextField();
		tf3.setBounds(250, 330, 80, 30);
		JTextField tf4 = new JTextField();
		tf4.setBounds(400, 330, 80, 30);

		JLabel l9 = new JLabel("Subject 3");
		l9.setFont(new Font("MV Boli", Font.BOLD, 15));
		l9.setBounds(50, 360, 250, 20);

		JTextField tf5 = new JTextField();
		tf5.setBounds(250, 360, 80, 30);

		JTextField tf6 = new JTextField();
		tf6.setBounds(400, 360, 80, 30);

		JLabel l10 = new JLabel("Preferred College");
		l10.setFont(new Font("MV Boli", Font.BOLD, 15));
		l10.setBounds(50, 450, 250, 20);

		String condition;
		if(cb.getSelectedIndex() == 0)
			condition = "onlyGirls ='0'";
		else
			condition = "1";

		JComboBox<String> cb2 = new JComboBox<String>(DB.strArray(Colleges.get("name",condition)));
		cb2.setBounds(260, 450, 150, 30);

		JLabel l11 = new JLabel("Preferred Course");
		l11.setFont(new Font("MV Boli", Font.BOLD, 15));
		l11.setBounds(50, 500, 250, 20);

		JComboBox<String> cb3 = new JComboBox<>(DB.strArray(Colleges.get("courses", "name = '" + (String) cb2.getSelectedItem() + "'")));
		cb3.setBounds(260, 500, 150, 30);

		JButton b = new JButton("Reset");
		b.setBounds(50, 550, 150, 40);


		JButton b1 = new JButton("Check");
		b1.setBounds(250, 550, 150, 40);

		getContentPane().add(l1);
		getContentPane().add(l2);
		getContentPane().add(l3);
		getContentPane().add(l4);
		getContentPane().add(l5);
		getContentPane().add(l6);
		getContentPane().add(l7);
		getContentPane().add(l8);
		getContentPane().add(l9);
		getContentPane().add(l10);
		getContentPane().add(l11);
		getContentPane().add(cb1);
		getContentPane().add(cb2);
		getContentPane().add(cb3);
		getContentPane().add(cb);
		getContentPane().add(tf1);
		getContentPane().add(tf2);
		getContentPane().add(tf3);
		getContentPane().add(tf4);
		getContentPane().add(tf5);
		getContentPane().add(tf6);
		getContentPane().add(b);
		getContentPane().add(b1);

		setParameters(Transparent,Simple_border,tf1,tf2,tf3,tf4,tf5,tf6);

		b1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				 if(!ChkErrors.Empty(tf1,tf2,tf3,tf4,tf5,tf6)){
				 	float per = getPercent(tf1,tf2,tf3,tf4,tf5,tf6);
				 	if(cb.getSelectedIndex() != 0)
				 		per += 2;
				 	int i = cb1.getSelectedIndex();
				 	if(i == 2)
				 		per += 2;
				 	else if(i == 3)
				 		per += 4;
				 	else if(i == 4)
				 		per += 5;

				 	if(ChkErrors.chkpercent(per, (String) cb2.getSelectedItem(),cb3.getSelectedIndex()))
				 		JOptionPane.showMessageDialog(null,"Congratulations !!! You are eligible (^-^)","Eligible",JOptionPane.INFORMATION_MESSAGE);
				 	}
				 	else
				 		JOptionPane.showMessageDialog(null,"Please fill all the fields !!!");
			}
		});

		b.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
					tf1.setText("");
					tf2.setText("");
					tf3.setText("");
					tf4.setText("");
					tf5.setText("");
					tf6.setText("");
					cb3.setSelectedIndex(0);
					cb2.setSelectedIndex(0);
					cb1.setSelectedIndex(0);
					cb.setSelectedIndex(0);
			}
		});
		setMainbtn(360,600);
		pack();
	}

	private float getPercent(JTextComponent ...c) {
		float sum = 0.0f;
		for(int i = 0; i <c.length; i += 2){
			sum += Float.parseFloat(c[0].getText()) / Float.parseFloat(c[1].getText());
		}
		return sum * 100/3.0f;
	}
}
