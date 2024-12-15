package Database;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Arrays;

public class Colleges extends DB {

    private static final String[] stmts = {"CREATE TABLE college( name text, courses text, percent text, seats text, onlyGirls boolean not null default 0);",
            "INSERT INTO `college`(`name`,`course`,`percent`,`seats`,`onlygirl') VALUES('?','?','?','?','?');",
    };

    public static void createTable(){
        try(Connection c = connect(); Statement stmt = c.createStatement()) {
            stmt.executeUpdate(stmts[0]);
            System.out.println("Table Created.");
        } catch (SQLException throwables) {
            ShowError(throwables);
        }
    }

    public static void insertTable(boolean OnlyGirls,String ...s){
        try(Connection c = connect(); PreparedStatement stmt = c.prepareStatement(stmts[1])) {
            for(int i = 0; i < s.length;i++)
                stmt.setString(i+1,s[i]);
            stmt.setBoolean(5,OnlyGirls);
            stmt.executeUpdate();
        } catch (SQLException throwables) {
            ShowError(throwables);
        }
    }

    public static String get(String field, String condition) {
       return getField("college",field,condition);
    }

    public static void update(String field,String value ,String condition){
        update("college",field,value,condition);
    }

    public static boolean reduceSeat(String cllg,int index){
        String[] seat = strArray(get("`seats`","name = '" + cllg +"'"));
        int s = Integer.parseInt(seat[index]);

        if(s == 0)
            return false;
        else{
            seat[index] = String.valueOf(s-1);
            update("seats",DB.toStr(seat) , " name = '" + cllg +"'");
            return true;
        }
    }

    public static String[] eligibleCourses(float per, String cllg) {
        String[] c = strArray(get("courses","name = '"+ cllg + "'"));
        for (byte i = 0; i < c.length; i++){
            if(per < Float.parseFloat(c[i]))
                c[i] = "[";
        }
        return strArray(c.toString());
    }
}