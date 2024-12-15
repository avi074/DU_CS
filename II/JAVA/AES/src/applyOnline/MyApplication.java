package applyOnline;

import Database.DB;
import GUI.GPanel;

import javax.swing.JPanel;
import javax.swing.JTable;
import javax.swing.JScrollPane;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

import java.awt.*;
import javax.swing.JTextField;
import javax.swing.table.DefaultTableModel;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.sql.ResultSet;
import java.sql.SQLException;
import javax.swing.SwingConstants;

public class MyApplication extends GPanel {
	private JTable table;
	private JTextField textField;

	/**
	 * Create the panel.
     * @param rs = Resultset for Aspirant Table
     */
	public MyApplication(ResultSet rs) {
		try {
		setLayout(null);
		setBounds(-20,-10,745,750);

		DefaultTableModel table_m = new DefaultTableModel(6,3);
		table_m.insertRow(0,new String[]{"Applied College","Applied Course","Applied Date"});

		if(rs.getString("applied_colleges") != null){
			String[] col = DB.strArray(rs.getString("applied_colleges"));
			String[] cours =  DB.strArray(rs.getString("applied_courses"));
			String[] date =  DB.strArray(rs.getString("applied_Date"));
			for (byte i = 0; i < col.length; i++)
				table_m.insertRow(i+1,new String[]{col[i],cours[i],date[i]});
		}

		table = new JTable();
		table.setFont(new Font("Tahoma", Font.BOLD, 12));
		table.setModel(table_m);
		table.setDragEnabled(false);
		table.setEnabled(true);
		table.setBounds(50,250,600,400);
		add(table);
		
		JLabel lblNewLabel = new JLabel("MY APPLICATIONS");
		lblNewLabel.setFont(new Font("Tahoma", Font.BOLD, 15));
		lblNewLabel.setBounds(297, 104, 154, 50);
		add(lblNewLabel);

		setReg_no(35,21,rs.getString("reg_no"));
		
		JButton btnDelete = new JButton("Delete Application");
		btnDelete.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(table.getSelectedRowCount()==1) {
					table_m.removeRow(table.getSelectedRow());
				}else {
					if(table.getRowCount()==0) {
						JOptionPane.showMessageDialog(null, "table is empty");
					}else {
						JOptionPane.showMessageDialog(null, "Please select any single row");
					}
				}
			}
		});
		btnDelete.setHorizontalAlignment(0);
		btnDelete.setFont(new Font("Tahoma", Font.BOLD, 12));
		btnDelete.setBounds(350, 680, 175, 30);
		add(btnDelete);

		} catch (SQLException throwables) {
			DB.ShowError(throwables);
		}
	}
}
