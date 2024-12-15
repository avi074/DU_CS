package MainFrames;

import GUI.GFrame;
import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.swing.table.DefaultTableModel;
import java.awt.*;

public class Cutoff extends GFrame {

	private JPanel contentPane;
	private JTextField txtCutoff;
	private JTable table;
	private JTable table_1;
	private JTextField txtSeats;

	/**
	 * Create the frame.
	 */
	public Cutoff() {
		setPreferredSize(new Dimension(872, 487));
		setResizable(false);

		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		txtCutoff = new JTextField(10);
		txtCutoff.setHorizontalAlignment(SwingConstants.CENTER);
		txtCutoff.setEditable(false);
		txtCutoff.setFont(new Font("Tahoma", Font.BOLD, 16));
		txtCutoff.setText("CUTOFF");
		txtCutoff.setBounds(341, 10, 94, 33);
		contentPane.add(txtCutoff);
		
		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setBounds(45, 77, 757, 125);
		contentPane.add(scrollPane);
		
		table = new JTable();
		table.setModel(new DefaultTableModel(
			new Object[][] {
				{"Gargi college", "85", "86", "80", "78", "80"},
				{"Hansraj College", "90", "91", "89", "86", "85"},
				{"Hindu college", "93", "94", "85", "85", "88"},
				{"Mirinda college", "89", "88", "84", "81", "84"},
				{"Ramanujan college", "84", "85", "86", "80", "82"},
			},
			new String[] {
				"COLLEGE", "B.A.(hons) English", "B.A.(hons) Hindi", "BCom (hons)", "BSc. (hons) CS", "BSc. (hons) Maths"
			}
		) {
			boolean[] columnEditables = new boolean[] {
				true, false, false, false, false, false
			};
			public boolean isCellEditable(int row, int column) {
				return columnEditables[column];
			}
		});
		table.getColumnModel().getColumn(0).setPreferredWidth(114);
		table.getColumnModel().getColumn(1).setResizable(false);
		table.getColumnModel().getColumn(1).setPreferredWidth(118);
		table.getColumnModel().getColumn(2).setResizable(false);
		table.getColumnModel().getColumn(2).setPreferredWidth(111);
		table.getColumnModel().getColumn(3).setResizable(false);
		table.getColumnModel().getColumn(3).setPreferredWidth(84);
		table.getColumnModel().getColumn(4).setResizable(false);
		table.getColumnModel().getColumn(4).setPreferredWidth(83);
		table.getColumnModel().getColumn(5).setResizable(false);
		table.getColumnModel().getColumn(5).setPreferredWidth(118);
		scrollPane.setViewportView(table);
		
		JScrollPane scrollPane_1 = new JScrollPane();
		scrollPane_1.setBounds(45, 267, 757, 125);
		contentPane.add(scrollPane_1);
		
		table_1 = new JTable();
		table_1.setModel(new DefaultTableModel(
			new Object[][] {
				{"Gargi college", "50", "55", "60", "50", "55"},
				{"Hansraj college", "55", "50", "55", "60", "60"},
				{"Hindu college", "55", "55", "60", "55", "60"},
				{"Miranda college", "55", "50", "55", "60", "55"},
				{"Ramanujan college", "50", "55", "60", "60", "55"},
			},
			new String[] {
				"College", "B.A. (hons) English", "B.A. (hons) Hindi", "B.Com (hons)", "BSc (hons) CS ", "BSc (hons) Maths"
			}
		) {
			boolean[] columnEditables = new boolean[] {
				false, false, false, false, false, false
			};
			public boolean isCellEditable(int row, int column) {
				return columnEditables[column];
			}
		});
		table_1.getColumnModel().getColumn(0).setResizable(false);
		table_1.getColumnModel().getColumn(0).setPreferredWidth(100);
		table_1.getColumnModel().getColumn(1).setResizable(false);
		table_1.getColumnModel().getColumn(1).setPreferredWidth(98);
		table_1.getColumnModel().getColumn(2).setResizable(false);
		table_1.getColumnModel().getColumn(2).setPreferredWidth(100);
		table_1.getColumnModel().getColumn(3).setResizable(false);
		table_1.getColumnModel().getColumn(3).setPreferredWidth(110);
		table_1.getColumnModel().getColumn(4).setResizable(false);
		table_1.getColumnModel().getColumn(4).setPreferredWidth(104);
		table_1.getColumnModel().getColumn(5).setResizable(false);
		table_1.getColumnModel().getColumn(5).setPreferredWidth(107);
		scrollPane_1.setViewportView(table_1);
		
		txtSeats = new JTextField();
		txtSeats.setHorizontalAlignment(SwingConstants.CENTER);
		txtSeats.setEditable(false);
		txtSeats.setText("SEATS");
		txtSeats.setFont(new Font("Tahoma", Font.BOLD, 16));
		txtSeats.setColumns(10);
		txtSeats.setBounds(341, 212, 87, 34);
		contentPane.add(txtSeats);

		setMainbtn(341,404);
		pack();
	}
}
