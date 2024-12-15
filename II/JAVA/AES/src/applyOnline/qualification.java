package applyOnline;

import Database.DB;
import GUI.GPanel;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.ResultSet;
import java.sql.SQLException;

public class qualification extends GPanel {
	private JTextField txtthRollNumber;
	private JTextField txtthBoard;
	private JTextField txtthPercent;
	private JTextField txtthRollNumber_1;
	private JTextField txtthBoard_1;
	private JTextField txtthPercent_1;
	private JTextField txtSubjectName;
	private JTextField txtSubjectName_1;
	private JTextField txtSubjectName_2;
	private JTextField txtSubjectObtmarks;
	private JTextField txtSubjectTotal;
	private JTextField txtSubjectTotal_1;
	private JTextField txtSubjectTotal_3;
	private JTextField txtSubjectObtmarks_2;
	private JTextField txtSubjectObtmarks_1;
	private JButton btn;
	private boolean active;
	private String[] sub,obt,total;

	/**
	 * Create the panel.
	 */
	public qualification(ResultSet rs) {
		try{
			String per_12 = rs.getString("12_percent");

			setBounds(-15, 0, 745, 750);
			setLayout(null);
			setReg_no(30,10,rs.getString("reg_no"));

			if(per_12 != null){
				sub = DB.strArray(rs.getString("12_subs"));
				obt = DB.strArray(rs.getString("12_subs_obt"));
				total = DB.strArray(rs.getString("12_subs_total"));
				active = false;
			}else {
				sub = obt = total = new String[]{"", "", ""};
				active = true;
			}

			JLabel lblthClass = new JLabel("10th CLASS");
			lblthClass.setFont(new Font("Tahoma", Font.PLAIN, 16));
			lblthClass.setBounds(53, 150, 101, 35);
			add(lblthClass);

			txtthRollNumber = new JTextField(rs.getString("10_roll"));
			txtthRollNumber.setFont(new Font("Tahoma", Font.PLAIN, 14));
			txtthRollNumber.setToolTipText("10th Roll number");
			txtthRollNumber.setEnabled(active);
			txtthRollNumber.setBounds(191, 150, 119, 35);
			add(txtthRollNumber);

			txtthBoard = new JTextField(rs.getString("10_board"));
			txtthBoard.setToolTipText("10th Board");
			txtthBoard.setEnabled(active);
			txtthBoard.setFont(new Font("Tahoma", Font.PLAIN, 14));
			txtthBoard.setBounds(330, 150, 119, 35);
			add(txtthBoard);

			txtthPercent = new JTextField(rs.getString("10_percent"));
			txtthPercent.setToolTipText("10th Percent");
			txtthPercent.setEnabled(active);
			txtthPercent.setFont(new Font("Tahoma", Font.PLAIN, 14));
			txtthPercent.setBounds(470, 150, 119, 35);
			add(txtthPercent);

			JLabel lblthClass_2 = new JLabel("12th CLASS");
			lblthClass_2.setFont(new Font("Tahoma", Font.PLAIN, 16));
			lblthClass_2.setBounds(53, 269, 101, 37);
			add(lblthClass_2);

			txtthRollNumber_1 = new JTextField(rs.getString("12_roll"));
			txtthRollNumber_1.setToolTipText("12th Roll number");
			txtthRollNumber_1.setFont(new Font("Tahoma", Font.PLAIN, 14));
			txtthRollNumber_1.setEnabled(active);
			txtthRollNumber_1.setBounds(191, 269, 119, 35);
			add(txtthRollNumber_1);

			txtthBoard_1 = new JTextField(rs.getString("12_board"));
			txtthBoard_1.setToolTipText("12th Board");
			txtthBoard_1.setFont(new Font("Tahoma", Font.PLAIN, 14));
			txtthBoard_1.setEnabled(active);
			txtthBoard_1.setBounds(330, 269, 119, 35);
			add(txtthBoard_1);

			txtthPercent_1 = new JTextField(per_12);
			txtthPercent_1.setEditable(false);
			txtthPercent_1.setToolTipText("12th Percent");
			txtthPercent_1.setFont(new Font("Tahoma", Font.PLAIN, 14));
			txtthPercent_1.setEnabled(false);
			txtthPercent_1.setBounds(470, 269, 119, 35);
			add(txtthPercent_1);

			JLabel lblthCoreOptional = new JLabel("12th Core/ Optional Subjects Marks");
			lblthCoreOptional.setFont(new Font("Tahoma", Font.PLAIN, 16));
			lblthCoreOptional.setBounds(53, 320, 268, 48);
			add(lblthCoreOptional);

			JLabel lblSubjectName = new JLabel("Subject Name");
			lblSubjectName.setFont(new Font("Tahoma", Font.PLAIN, 15));
			lblSubjectName.setBounds(53, 423, 119, 37);
			add(lblSubjectName);

			JLabel lblObtainedMarks = new JLabel("Obtained marks");
			lblObtainedMarks.setFont(new Font("Tahoma", Font.PLAIN, 15));
			lblObtainedMarks.setBounds(280, 423, 119, 37);
			add(lblObtainedMarks);

			JLabel lblTotalMarks = new JLabel("Total Marks");
			lblTotalMarks.setFont(new Font("Tahoma", Font.PLAIN, 15));
			lblTotalMarks.setBounds(425, 423, 119, 37);
			add(lblTotalMarks);

			txtSubjectName = new JTextField(sub[0]);
			txtSubjectName.setToolTipText("Subject1 Name");
			txtSubjectName.setFont(new Font("Tahoma", Font.PLAIN, 14));
			txtSubjectName.setEnabled(active);
			txtSubjectName.setBounds(53, 470, 119, 30);
			add(txtSubjectName);

			txtSubjectName_1 = new JTextField(sub[1]);
			txtSubjectName_1.setToolTipText("Subject2 Name");
			txtSubjectName_1.setFont(new Font("Tahoma", Font.PLAIN, 14));
			txtSubjectName_1.setEnabled(active);
			txtSubjectName_1.setBounds(53, 524, 119, 30);
			add(txtSubjectName_1);

			txtSubjectName_2 = new JTextField(sub[2]);
			txtSubjectName_2.setToolTipText("Subject3 Name");
			txtSubjectName_2.setFont(new Font("Tahoma", Font.PLAIN, 14));
			txtSubjectName_2.setEnabled(active);
			txtSubjectName_2.setBounds(53, 582, 119, 30);
			add(txtSubjectName_2);

			txtSubjectObtmarks = new JTextField(obt[0]);
			txtSubjectObtmarks.setToolTipText("Subject1 obtMarks");
			txtSubjectObtmarks.setFont(new Font("Tahoma", Font.PLAIN, 14));
			txtSubjectObtmarks.setEnabled(active);
			txtSubjectObtmarks.setBounds(280, 470, 119, 30);
			add(txtSubjectObtmarks);

			txtSubjectObtmarks_2 = new JTextField(obt[1]);
			txtSubjectObtmarks_2.setToolTipText("Subject2 obtMarks");
			txtSubjectObtmarks_2.setFont(new Font("Tahoma", Font.PLAIN, 14));
			txtSubjectObtmarks_2.setEnabled(active);
			txtSubjectObtmarks_2.setBounds(280, 524, 119, 30);
			add(txtSubjectObtmarks_2);

			txtSubjectObtmarks_1 = new JTextField(obt[2]);
			txtSubjectObtmarks_1.setToolTipText("Subject3 obtMarks");
			txtSubjectObtmarks_1.setFont(new Font("Tahoma", Font.PLAIN, 14));
			txtSubjectObtmarks_1.setEnabled(active);
			txtSubjectObtmarks_1.setBounds(280, 582, 119, 30);
			add(txtSubjectObtmarks_1);

			txtSubjectTotal = new JTextField(total[0]);
			txtSubjectTotal.setToolTipText("Subject1 Total");
			txtSubjectTotal.setFont(new Font("Tahoma", Font.PLAIN, 14));
			txtSubjectTotal.setEnabled(active);
			txtSubjectTotal.setBounds(425, 470, 119, 28);
			add(txtSubjectTotal);

			txtSubjectTotal_1 = new JTextField(total[1]);
			txtSubjectTotal_1.setToolTipText("Subject2 Total");
			txtSubjectTotal_1.setFont(new Font("Tahoma", Font.PLAIN, 14));
			txtSubjectTotal_1.setEnabled(active);
			txtSubjectTotal_1.setBounds(425, 524, 119, 28);
			add(txtSubjectTotal_1);

			txtSubjectTotal_3 = new JTextField(total[2]);
			txtSubjectTotal_3.setToolTipText("Subject3 Total");
			txtSubjectTotal_3.setFont(new Font("Tahoma", Font.PLAIN, 14));
			txtSubjectTotal_3.setEnabled(active);
			txtSubjectTotal_3.setBounds(425, 582, 119, 28);
			add(txtSubjectTotal_3);

			btn = new JButton("Edit");
			btn.setFont(new Font("Tahoma", Font.BOLD, 14));
			btn.setBounds(225,640, 172, 34);
			btn.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent e) {
					active = !active;
					change(active,txtSubjectName,txtSubjectName_1,txtSubjectName_2,txtSubjectObtmarks,txtSubjectObtmarks_1,txtSubjectObtmarks_2,txtSubjectTotal,txtSubjectTotal_1,txtSubjectTotal_3,txtthBoard,txtthBoard_1,txtthPercent,txtthRollNumber,txtthRollNumber_1);
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
		} catch (Exception throwables) {
			DB.ShowError(throwables);
		}
	}
}
