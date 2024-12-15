package Database;

import javax.swing.*;
import java.sql.*;
import java.util.Arrays;
import java.util.Stack;

public class DB {
	private static Connection conn;

	static Connection connect() {
		try {
			//Driver installation
			Class.forName("com.mysql.cj.jdbc.Driver");
			//Connection
			conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/delhiuniversity",
					"root", "");
		} catch (Exception e2) {
			ShowError(e2);
		}
		return conn;
	}

	public static void ShowError(Exception e) {
		JOptionPane.showMessageDialog(null, e.getMessage(), "ConnectionError !!!", JOptionPane.ERROR_MESSAGE);
	}

	//com.mysql.cj.jdbc.Driver-> new.
	protected static void setField(String database,String fields,String values){
		String query = "INSERT INTO `" + database + "` ("+ fields +") VALUES  (" + values + ")";
		try(Connection con = connect();Statement stmt = con.createStatement()) {
			stmt.executeUpdate(query);
		} catch (SQLException throwables) {
			ShowError(throwables);
		}
	}

	protected static String getField(String database, String field, String condition) {
		String query = "SELECT `" + field + "` FROM `"+ database +"` where " + condition ;
		Stack<String> set = new Stack<>();
		try (Connection c = connect(); ResultSet rset = c.createStatement().executeQuery(query)) {
			while (rset.next()) {
				set.add(rset.getString(field));
			}
		} catch (SQLException throwables) {
			ShowError(throwables);
		}
		return toStr(set.toString());
	}

	protected static void update(String database,String field,String value,String condition){
		String query = "UPDATE `" + database + "` SET `" + field+"` = '"+ value + "' where " + condition + ";";
		try(Connection con = connect(); PreparedStatement pstmt = con.prepareStatement(query)) {
			pstmt.executeUpdate();
		} catch (SQLException throwables) {
			ShowError(throwables);
		}
	}

	protected static void delete(String database, String condition){
		String query = "DELETE FROM `" + database + "` where " + condition;
		try(Connection con = connect(); Statement stmt = con.createStatement()) {
			stmt.executeUpdate(query);
		} catch (SQLException throwables) {
			ShowError(throwables);
		}
	}

	protected static ResultSet getTable(String database, String condition) {
		String query = "SELECT *  FROM `"+ database +"` where " + condition ;
		try {
			ResultSet rs = connect().createStatement().executeQuery(query);
			if(rs.next())
				return rs;
		} catch (SQLException throwables) {
			ShowError(throwables);
		}
		return null;
	}

	public static String[] strArray(String s) {
		return s.replace("[", "").replace("]", "").split(",");
	}
	public static String toStr(String ...o){
		return Arrays.toString(o).replace("[", "").replace("]", "");
	}
}