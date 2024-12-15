package applyOnline;

import Database.Aspirant;
import Database.Colleges;
import Database.DB;
import GUI.GPanel;
import GUI.GTextArea;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Date;
import java.util.Vector;

@SuppressWarnings("all")
public class apply extends GPanel {
	private JTextField textField;

	/**
	 * Create the panel.
     * @param rs = ResultSet
     */
	public apply(ResultSet rs) {
		try {
		setLayout(null);
		setBounds(-60,-20,745,750);
		setReg_no(88,45,rs.getString("reg_no"));

		JLabel lblPrefferdC = new JLabel("Preferred Colleges");
		lblPrefferdC.setFont(new Font("Tahoma", Font.BOLD, 15));
		lblPrefferdC.setBounds(88, 162, 149, 40);
		add(lblPrefferdC);
		
		JLabel lblPreferredCourse = new JLabel("Preferred Courses");
		lblPreferredCourse.setFont(new Font("Tahoma", Font.BOLD, 15));
		lblPreferredCourse.setBounds(88, 222, 149, 40);
		add(lblPreferredCourse);
		
		textField = new JTextField("Note: If you haven't seen any course in the preferred courses that means you are not eligible for any course in that college !!!");
		textField.setForeground(Color.red);
		textField.setEditable(false);
		textField.setFont(new Font("Tahoma", Font.PLAIN, 10));
		textField.setBounds(88, 99, 600, 33);
		add(textField);

		int og = rs.getInt("gen") == 1 ? 0 : 1;
		
		JComboBox<String>[] comboBox = new JComboBox[2];
		comboBox[0]	= new JComboBox<>(Colleges.strArray(Colleges.get("name","onlyGirls = '" + og + "'")));
		comboBox[0].setFont(new Font("Tahoma", Font.PLAIN, 14));
		comboBox[0].setBounds(434, 162, 149, 33);
		add(comboBox[0]);

		comboBox[1] = new JComboBox<String>(DB.strArray(Colleges.get("courses","name = '" + comboBox[0].getSelectedItem()+"'")));
		comboBox[1].setFont(new Font("Tahoma", Font.PLAIN, 14));
		comboBox[1].setBounds(434, 222, 149, 33);
		add(comboBox[1]);
		
		JRadioButton rdbtnNewRadioButton = new JRadioButton("I Agree to these Terms & Conditions");
		rdbtnNewRadioButton.setFont(new Font("Tahoma", Font.PLAIN, 14));
		rdbtnNewRadioButton.setBounds(106, 633, 271, 40);
		add(rdbtnNewRadioButton);
		
		JButton btnNewButton = new JButton("APPLY");
		btnNewButton.setFont(new Font("Tahoma", Font.BOLD, 15));
		btnNewButton.setBounds(348, 692, 97, 27);
		btnNewButton.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				if(rdbtnNewRadioButton.isSelected()){
					String[] col = new String[]{"applied_colleges","applied_courses","applied_Date"};
					for(byte i = 0; i < 3; i++){
						try {
							Vector<String> s = new Vector<String>(Arrays.asList(DB.strArray(rs.getString(col[i]))));
							if(i < 2)
								s.add((String) comboBox[i].getSelectedItem());
							else
								s.add(new SimpleDateFormat("dd-MM-yyyy").format(new Date()));
							Aspirant.Update(col[i],DB.toStr(s.toString()),"reg_no = '"+rs.getString("reg_no")+"'");
						} catch (SQLException throwables) {
							DB.ShowError(throwables);
						}
						Colleges.reduceSeat((String) comboBox[0].getSelectedItem(),comboBox[1].getSelectedIndex());
					}
				}else
					JOptionPane.showMessageDialog(null,"Please read the terms & condition carefully !!!");
			}
		});
		add(btnNewButton);
		
		GTextArea txtrPleaseReadFollowing = new GTextArea(GTextArea.SCROLLBARS_NONE);
		txtrPleaseReadFollowing.setWrapping(true);
		txtrPleaseReadFollowing.setFont(new Font("Monospaced", Font.PLAIN, 16));
		txtrPleaseReadFollowing.setText("Please Read following Terms & Conditions:\n1. All the details filled by you should be correct and You are responsible for any mistakes.\n2. You can apply admission application only five times.\n3. Refunds can only be made to the same bank account or credit card from which originally payment was received.\n4. The University can cancel the application of the candidate if he/she is found to violate the rules and regulations.");
		txtrPleaseReadFollowing.setEditable(false);
		txtrPleaseReadFollowing.setBounds(88, 348, 550, 240);
		add(txtrPleaseReadFollowing);

		} catch (SQLException throwables) {
			DB.ShowError(throwables);
		}
	}
}
